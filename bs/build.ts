/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [internal.bs]: internal build system for the ccutl Core Utilities library
    Copyright (C) 2020, 2021 Justin Collier

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the internalied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. */

import * as fs from "fs";
import * as path from "path";

namespace Project {
  /// name of the project
  export const name = "ccutl";
  /// version data for header guards
  export const version = [0, 4, 0];
  /// root of the project (parent directory)
  export const rootDir = path.join(__dirname, "../");
  /// directory of the project headers (pre-bs)
  export const srcDir = path.join(rootDir, "src");
  /// a list of header-only library include dirs for verbatum copying
  export const libDirs = ["libs/pputl/include"].map((x) =>
    path.join(rootDir, x)
  );
  /// directory of the exported project headers
  export const outputDir = path.join(rootDir, "include");
  /// path of the root README.md
  export const readmePath = path.join(rootDir, "README.md");
  /// a list of class features; doxygen treats these differently
  export const classes = ["ccutl.type_pack", "ccutl.value_pack"];
}

enum HeaderType {
  project,
  lib,
  system,
}

const PROJECT_HEADERS: ProjectHeader[] = [];
const LIB_HEADERS: LibHeader[] = [];
const SYSTEM_HEADERS: SystemHeader[] = [];
const DEPENDENCIES: Map<Header, Set<Header>> = new Map();

function depend(dependent: Header, dependency: Header) {
  const exist = DEPENDENCIES.get(dependent);
  if (!exist)
    throw new Error(
      "logic error; dependency set should have been made by Header constructor"
    );
  else exist.add(dependency);
}
function depends(target: Header, possibleDependency: Header) {
  return DEPENDENCIES.get(target).has(possibleDependency);
}

function createOrGetProjectHeader(relPath: string): ProjectHeader {
  const existing = PROJECT_HEADERS.find((x) => x.relPath === relPath);
  if (existing) return existing;
  return new ProjectHeader(relPath);
}
function createOrGetLibHeader(relPath: string): LibHeader {
  const existing = LIB_HEADERS.find((x) => x.relPath === relPath);
  if (existing) return existing;
  return new LibHeader(relPath);
}
function createOrGetSystemHeader(relPath: string): SystemHeader {
  const existing = SYSTEM_HEADERS.find((x) => x.relPath === relPath);
  if (existing) return existing;
  return new SystemHeader(relPath);
}

class Header {
  public relPath: string;
  public type: HeaderType;

  public toString(isToplevel: boolean = true) {
    /// this relies on sorted dependencies!!!
    const genIncludes = (): [string[], string[]] => {
      if (!isToplevel) return [[], []];
      const projectDeps: ProjectHeader[] = [];
      const libDeps: LibHeader[] = [];
      const systemDeps: SystemHeader[] = [];
      for (const dep of Array.from(DEPENDENCIES.get(this))) {
        switch (dep.type) {
          case HeaderType.project:
            if (!projectDeps.find((x) => x.relPath === dep.relPath))
              projectDeps.push(<ProjectHeader>dep);
            break;
          case HeaderType.lib:
            if (!libDeps.find((x) => x.relPath == dep.relPath))
              libDeps.push(dep);
            break;
          case HeaderType.system:
            if (!systemDeps.find((x) => x.relPath === dep.relPath))
              systemDeps.push(dep);
            break;
        }
      }
      let extIncs: string[] = [];
      let intIncs: string[] = [];
      for (const inc of systemDeps) extIncs.push(inc.toString(false).trim());

      if (libDeps.length) {
        extIncs.push("\n");
        extIncs.push(`// ${"embedded libraries".padStart(80 - 7)} {{{`);
        for (const inc of libDeps) extIncs.push(inc.toString(false));
        extIncs.push(`// ${"embedded libraries".padStart(80 - 7)} }}}`);
      }

      for (const inc of projectDeps) intIncs.push(inc.toString(false));

      return [extIncs, intIncs];
    };

    let s: string = "";
    if (isToplevel && this.copyright.length) s += this.copyright + "\n\n";
    const [extIncs, intIncs] = genIncludes();
    if (extIncs.length) {
      s += extIncs.join("\n");
      s += "\n\n";
    }
    if (this.type === HeaderType.project && isToplevel) {
      s += "#ifndef CCUTL_NAMESPACE\n";
      s += "#define CCUTL_NAMESPACE ctl\n";
      s += "#endif\n";
      s += "\n";
      s += "namespace CCUTL_NAMESPACE {\n";
      s += "\n";
    }
    if (intIncs.length) {
      s += intIncs
        .join("\n")
        .replace(/^namespace CCUTL_NAMESPACE {$/m, "")
        .replace(/^} \/\/ namespace CCUTL_NAMESPACE$/m, "");
      s += "\n";
    }
    if (this.body.length) {
      s +=
        this.body
          .replace(/^namespace CCUTL_NAMESPACE {$/m, "")
          .replace(/^} \/\/ namespace CCUTL_NAMESPACE$/m, "") + "\n";
    }
    if (this.type === HeaderType.project && isToplevel) {
      s += "} // namespace CCUTL_NAMESPACE\n";
      s += "\n";
    }
    s = this.guard(s, isToplevel);
    s = s.replace(/\n{3,}/g, "\n\n");

    if (!isToplevel && this.type !== HeaderType.system) return this.vimfold(s);
    else return s;
  }

  protected constructor({
    type,
    name,
    relPath,
    copyright,
    included,
    body,
  }: {
    type: HeaderType;
    name: string;
    relPath: string;
    copyright: string;
    included: Header[];
    body: string;
  }) {
    DEPENDENCIES.set(this, new Set());
    for (const inc of included) depend(this, inc);
    this.type = type;
    this.name = name;
    this.relPath = relPath;
    this.copyright = copyright;
    this.body = body;
  }

  private name: string;
  private copyright: string;
  private body: string;

  private guard(s: string, isTopLevel: boolean): string {
    // if name is empty, type is either a headerlib or system; use their guard
    if (this.name === "") return s;
    // remove vim commands
    s = s.replace(/^\/\/ vim: .+$/gm, "");

    const cleanName = this.name
      .toLowerCase()
      .replace(/^ccutl_/m, "ccutl.")
      .replace(/^ccutl\.detail_/m, "internal.");
    const errName = cleanName.match(/^internal\./m)
      ? "ccutl: " + cleanName
      : cleanName;
    const guardHeader = [
      `// ${cleanName.padStart(80 - 21)} feature guard {{{`,
      `#ifndef ${this.name}_INCLUDED`,
      `#define ${this.name}_INCLUDED`,
      `// ${cleanName.padStart(80 - 21)} feature guard }}}`,
    ];
    const guardFooter = [
      `// ${cleanName.padStart(80 - 21)} version guard {{{`,
      "",
      `#define ${this.name}_VERSION_MAJOR ${Project.version[0]}`,
      `#define ${this.name}_VERSION_MINOR ${Project.version[1]}`,
      `#define ${this.name}_VERSION_PATCH ${Project.version[2]}`,
      "",
      `#elif ${this.name}_VERSION_MAJOR != ${Project.version[0]}`,
      `#error   ${errName} major version mismatch`,
      `#elif ${this.name}_VERSION_MINOR != ${Project.version[1]}`,
      `#error   ${errName} minor version mismatch`,
      `#elif ${this.name}_VERSION_PATCH != ${Project.version[2]}`,
      `#warning ${errName} patch version mismatch`,
      "#endif",
      isTopLevel ? "\n// vim: fmr={{{,}}} fdm=marker\n" : "",
      `// ${cleanName.padStart(80 - 21)} version guard }}}`,
    ];

    return (
      guardHeader.join("\n") +
      "\n" +
      (isTopLevel ? "" : "\n") +
      s +
      "\n\n" +
      guardFooter.join("\n")
    );
  }

  private vimfold(s: string): string {
    let incstmt: string = "";
    if (this.type === HeaderType.project) {
      const cleanName = this.name
        .toLowerCase()
        .replace(/^ccutl_/m, "ccutl.")
        .replace(/^ccutl\.detail_/m, "internal.");
      incstmt = cleanName;
    } else {
      incstmt = `#include <${this.relPath}>`;
    }
    return `// ${incstmt.padStart(80 - 7)} {{{\n\n${s}\n\n// ${incstmt.padStart(
      80 - 7
    )} }}}`;
  }
}

class ProjectHeader extends Header {
  public featureName: string;
  public featureDescr: string;
  constructor(relPath: string) {
    if (PROJECT_HEADERS.find((x) => x.relPath === relPath))
      throw new Error(
        `project header ${relPath} already exists in registry. please construct using createOrGetProjectHeader`
      );
    // read the file
    let lines = (() => {
      let p = path.join(Project.srcDir, relPath);
      if (!fs.existsSync(p)) p = path.join(Project.rootDir, relPath);

      if (!fs.existsSync(p))
        throw new Error(`could not find project header at ${relPath}`);

      return fs.readFileSync(p, "utf8").trim().split("\n");
    })();
    // get the name from the header guard and delete the guard from lines
    const name = (() => {
      if (lines.shift() != "#pragma once")
        throw new Error("source files must use #pragma once");
      return relPath
        .replace(/^ctl/m, "CCUTL")
        .replace(/\//g, "_")
        .replace(/\.h$/m, "")
        .toUpperCase()
        .replace(/^CCUTL_CCUTL$/m, "CCUTL");
    })();
    // get the copyright block comment and delete the comment from lines
    const copyright = (() => {
      if (!lines[0].match(/^\/\*\s+C\+\+20$/m))
        throw new Error(
          `bad copyright text for ${relPath}; expected "\/\*\s+C\+\+20"`
        );
      const crlines: string[] = [];
      // copy over all copyright lines until (excluding) the block comment close
      let ln: string;
      for (ln = lines.shift(); !ln.match(/\*\/$/m); ln = lines.shift())
        crlines.push(ln);
      // verfiy that the end was found
      if (!ln.match(/\*\/$/m))
        throw new Error(`could not find end of copyright text for ${relPath}`);
      // push the block comment close
      crlines.push(ln);
      return crlines.join("\n");
    })();
    // collect includes and delete each include line
    const includes = (() => {
      const incs: Header[] = [];

      const removedIncLines: string[] = [];

      for (const ln of lines) {
        const m = ln.match(/^#include [<"](.+?)[>"]$/m);
        if (!m) removedIncLines.push(ln);
        else {
          // do not add detail config
          if (m[1].match(/^src\/ctl\/detail\/config\.h$/m)) continue;
          let proj: ProjectHeader;
          try {
            proj = createOrGetProjectHeader(m[1]);
            incs.push(proj);
            continue;
          } catch (e) {}
          let lib: LibHeader;
          try {
            lib = createOrGetLibHeader(m[1]);
            incs.push(lib);
          } catch (e) {
            if ((<Error>e).message.match(/^found more than one/m)) throw e;
            else incs.push(createOrGetSystemHeader(m[1]));
          }
        }
      }

      lines = removedIncLines;

      return incs;
    })();
    // store the body
    const body = lines
      .join("\n")
      .trim()
      .replace(/\n{3,}/g, "\n\n");
    super({
      type: HeaderType.project,
      name,
      copyright,
      included: includes,
      body,
      relPath,
    });
    this.featureName = name
      .toLowerCase()
      .replace(/^ccutl_/m, "ccutl.")
      .replace(/^ccutl\.detail/m, "internal");
    this.featureDescr = copyright.split("\n").reduce((a, v) => {
      const m = v.match(/\[.*?\]: (.*)/m);
      if (m) return m[1].trim();
      else return a;
    }, "");
    PROJECT_HEADERS.push(this);
  }
}
class LibHeader extends Header {
  constructor(relPath: string) {
    if (LIB_HEADERS.find((x) => x.relPath === relPath))
      throw new Error(
        `lib header ${relPath} already exists in registry. please construct using createOrGetLibHeader`
      );
    const foundPaths: string[] = Project.libDirs.reduce((a, libi) => {
      const p = path.join(libi, relPath);
      if (fs.existsSync(p)) a.push(p);
      return a;
    }, []);
    if (foundPaths.length === 1) {
      const incs: Header[] = [];
      const inLines = fs.readFileSync(foundPaths[0], "utf8").split("\n");
      const outLines: string[] = [];
      for (const ln of inLines) {
        const m = ln.match(/^#include [<"](.+?)[>"]$/m);
        if (!m) outLines.push(ln);
        else {
          let lib: LibHeader;
          try {
            lib = createOrGetLibHeader(m[1]);
            incs.push(lib);
          } catch (e) {
            if ((<Error>e).message.match(/^found more than one/m)) throw e;
            else incs.push(createOrGetSystemHeader(m[1]));
          }
        }
      }
      super({
        type: HeaderType.lib,
        name: "",
        relPath,
        copyright: "",
        included: incs,
        body: outLines.join("\n"),
      });
    } else if (foundPaths.length === 0) {
      throw new Error(`could not find library header for ${relPath}`);
    } else {
      throw new Error(`found more than one library header for ${relPath}`);
    }
    LIB_HEADERS.push(this);
  }
}
class SystemHeader extends Header {
  constructor(relPath: string) {
    if (SYSTEM_HEADERS.find((x) => x.relPath === relPath))
      throw new Error(
        `system header ${relPath} already exists in registry. please construct using createOrGetSystemHeader`
      );
    super({
      type: HeaderType.system,
      name: "",
      relPath,
      copyright: "",
      included: [],
      body: `#include <${relPath}>`,
    });
    SYSTEM_HEADERS.push(this);
  }
}

/// get all contents recursively within INTERNAL_INCLUDE_DIR
/// side-effects: creates header objects for all included files recursively
///               (constructors populate [PROJECT, LIB, SYSTEM]_HEADERS)
function collectProjectHeaders(): void {
  function recurse(cur: string = Project.srcDir) {
    const avail = fs.readdirSync(cur, { withFileTypes: true });
    for (const v of avail) {
      const next = path.join(cur, v.name);
      if (v.isDirectory()) recurse(next);
      else if (v.name.match(/\.h$/m))
        createOrGetProjectHeader(path.relative(Project.srcDir, next));
    }
  }
  recurse();
}

function expandDependencies(): void {
  function recurse(dept: Header, dep: Header) {
    depend(dept, dep);
    const deps = DEPENDENCIES.get(dep);
    for (const dep_ of Array.from(deps)) recurse(dept, dep_);
  }
  for (const [dept, deps] of Array.from(DEPENDENCIES.entries()))
    deps.forEach((dep) => recurse(dept, dep));
}

/// sort dependencies such that no depended dep follows its dependenent
function sortDependencies(): void {
  for (const dep of Array.from(DEPENDENCIES.keys())) {
    const input = Array.from(DEPENDENCIES.get(dep));
    const sorted: Header[] = [];

    while (input.length) {
      for (let i = 0; i < input.length; ++i) {
        const depdep = input[i];
        if (!input.some((x) => depends(depdep, x))) {
          sorted.push(depdep);
          input.splice(i, 1);
        }
      }
    }

    const projectSorted: Header[] = [];
    const libSorted: Header[] = [];
    const systemSorted: Header[] = [];

    for (const h of sorted) {
      switch (h.type) {
        case HeaderType.project:
          projectSorted.push(h);
          break;
        case HeaderType.lib:
          libSorted.push(h);
          break;
        case HeaderType.system:
          systemSorted.push(h);
          break;
      }
    }

    systemSorted.sort((a, b) =>
      a.relPath < b.relPath ? -1 : a.relPath > b.relPath ? 1 : 0
    );

    DEPENDENCIES.set(
      dep,
      new Set([...systemSorted, ...libSorted, ...projectSorted])
    );
  }
}

function populateReadmeFeatures(): void {
  const sortedFeats = [...PROJECT_HEADERS];
  sortedFeats.sort((a, b) =>
    a.featureName < b.featureName ? -1 : a.featureName > b.featureName ? 1 : 0
  );
  let s = "";
  s += "Feature | About | Links\n";
  s += "--- | --- | ---\n";
  for (const feat of sortedFeats) {
    // pardon the spaghetti
    const docsLink = () => {
      if (Project.classes.includes(feat.featureName))
        return `https://jpcx.github.io/ccutl/structctl_1_1${feat.featureName
          .replace(/^ccutl\./m, "")
          .replace(/_/g, "__")}.html`;
      else
        return `http://jpcx.github.io/ccutl#${feat.featureName.replace(
          /^ccutl\./m,
          ""
        )}`;
    };
    if (!feat.featureName.match(/^internal/m) && feat.featureName !== "ccutl") {
      s += `[${feat.featureName.replace(
        /_/g,
        "\\_"
      )}](https://github.com/jpcx/ccutl/blob/master/src/${feat.relPath.replace(
        /_/g,
        "\\_"
      )}) | ${feat.featureDescr.replace(
        /([<>_])/g,
        "\\$1"
      )} | \\[[?](${docsLink().replace(
        /_/g,
        "\\_"
      )})\\] \\[[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/${feat.relPath.replace(
        /_/g,
        "\\_"
      )})\\]\n`;
    }
  }
  fs.writeFileSync(
    Project.readmePath,
    fs
      .readFileSync(Project.readmePath, "utf8")
      .replace(
        /^### Synopsis\n[\s\S]+?^### Examples\n/m,
        `### Synopsis\n\n_note: each \`include/\` header is independent; use the raw links for direct download_\n\n${s.trim()}\n\n### Examples\n`
      ),
    "utf8"
  );
}

// main:
(() => {
  // generate Header objects for all project headers and dependencies
  collectProjectHeaders();
  expandDependencies();
  sortDependencies();
  // delete and recreate destination directory
  if (fs.existsSync(Project.outputDir))
    fs.rmdirSync(Project.outputDir, { recursive: true });
  fs.mkdirSync(Project.outputDir);
  // write all of the non-detail headers to the output directory
  for (const h of PROJECT_HEADERS) {
    // skip if detail
    if (h.relPath.match(/^ctl\/detail\//m)) continue;
    const outpath = path.join(path.join(Project.outputDir, h.relPath));
    // make sure the parent dir exists
    fs.mkdirSync(path.join(outpath, "../"), { recursive: true });
    fs.writeFileSync(
      path.join(path.join(Project.outputDir, h.relPath)),
      h.toString() + "\n"
    );
  }
  populateReadmeFeatures();
})();
