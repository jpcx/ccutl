////////////////////////////////////////////////////////////////////////////////
/// @brief Scans module dependencies and writes project_structure.cmake
//
//                      |    |
//    __|   __|  |   |  __|  |
//   (     (     |   |  |    |
//  \___| \___| \__,_| \__| _|
//
//  ccutl Core Utilities
//  Copyright (C) 2020 Justin Collier <m@jpcx.dev>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the internalied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//                                                                            //
//  You should have received a copy of the GNU General Public License        ///
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.  ////
////////////////////////////////////////////////////////////////////////////////

import * as fs from "fs";
import * as path from "path";

const ROOTDIR = path.join(__dirname, "../../");
const SRCDIR  = path.join(ROOTDIR, "include");
const SRCEXT  = "h";

const MANUAL_DEPS = {
  "ccutl.str_eq" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.str_gt" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.str_gteq" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.str_lt" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.str_lteq" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.str_neq" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.strlen" : [ "ccutl.subscriptable_to", "ccutl.noref" ],
  "ccutl.eq" : [ "ccutl.noref" ],
  "ccutl.gt" : [ "ccutl.noref" ],
  "ccutl.gteq" : [ "ccutl.noref" ],
  "ccutl.lt" : [ "ccutl.noref" ],
  "ccutl.lteq" : [ "ccutl.noref" ],
  "ccutl.neq" : [ "ccutl.noref" ],
};

type ModuleName   = string;
type ModuleSet    = Set<ModuleName>;
type Dependencies = {
  [moduleName: string]: ModuleSet;
};
type SortedDeps = Array<[ ModuleName, ModuleSet ]>;

function genDeps(): Dependencies {
  const deps: Dependencies = {};

  const depthMatcher = /^\s*?(?:export )?import ([\w.]+?);$/gm;
  function scanDeps(content: string): Set<ModuleName> {
    const imports: Set<ModuleName> = new Set();
    depthMatcher.lastIndex         = 0;
    for (let m = depthMatcher.exec(content); m !== null;
         m     = depthMatcher.exec(content))
      if (!m[1].match(/std/m))
        imports.add(m[1]);
    return imports;
  }

  function search(dir = SRCDIR) {
    const dirents   = fs.readdirSync(dir, {withFileTypes : true});
    const srcRelDir = path.relative(SRCDIR, dir);
    for (const dent of dirents)
      if (dent.isDirectory())
        search(path.join(dir, dent.name));
      else if (
          dent.name.match(/\.h/m) && !srcRelDir.match(/detail_/) &&
          !srcRelDir.match(/macros/)) {
        const name       = dent.name;
        const moduleName = [
          srcRelDir.replace(/\//g, "."),
          dent.name.replace(/\.h/m, ""),
        ].filter((x) => x).join(".");
        const content    = fs.readFileSync(path.join(dir, name), "utf8");
        deps[moduleName] = scanDeps(content);
      }
  }
  search();

  for (const [key, manualdeps] of Object.entries(MANUAL_DEPS))
    if (deps[key])
      for (const dep of manualdeps)
        deps[key].add(dep);
    else
      deps[key] = new Set(manualdeps);

  return deps;
}

function reduceRedundantDeps(dependencies: Dependencies): Dependencies {
  const result: Dependencies = {};
  for (const [mod, deps] of Object.entries(dependencies)) {
    const depsArray = Array.from(deps);
    let end         = depsArray.length;
    for (let i = 0; i < end; ++i) {
      const curDep = depsArray[i];

      const recurseReduceDeps = (depdeps: ModuleName[]) => {
        for (const depdep of depdeps) {
          if (depsArray.includes(depdep)) {
            const removeIdx = depsArray.findIndex((x) => x === depdep);
            depsArray.splice(removeIdx, 1);
            if (removeIdx <= i)
              --i;

            --end;
          }
          if (dependencies[depdep].size)
            recurseReduceDeps(Array.from(dependencies[depdep]));
        }
      };

      recurseReduceDeps(Array.from(dependencies[curDep]));
    }

    result[mod] = new Set(depsArray);
  }
  return result;
}

function sortDeps(deps: Dependencies): SortedDeps {
  const sorted: SortedDeps = [];

  function insertSorted([ name, set ]: [ ModuleName, Set<ModuleName>]) {
    let insIdx = 0;
    for (let i = 0; i < sorted.length; ++i) {
      const [sname, sset] = sorted[i];
      if (set.has(sname))
        insIdx = i + 1;
    }
    sorted.splice(insIdx, 0, [ name, set ]);
  }

  Object.entries(deps).forEach(insertSorted);
  return sorted;
}

function writeDeps(sortedDeps: SortedDeps) {
  const cmakeListsPath =
      path.join(ROOTDIR, "cmake/project_module_structure.cmake");
  const content = fs.readFileSync(cmakeListsPath, "utf8");

  const modules: ModuleSet       = new Set();
  const moduleCommands: string[] = [];
  for (const [name, set] of sortedDeps) {
    modules.add(name);
    if (set.size) {
      let cmd = "";
      cmd += `add_module (${name}\n`;
      cmd += Array.from(set).map((x) => `            ${x}`).join("\n");
      cmd += ")";
      moduleCommands.push(cmd);
    } else
      moduleCommands.push(`add_module (${name})`);
  }

  fs.writeFileSync(
      cmakeListsPath,
      content.replace(
          /^(# begin project modules)$([\s\S]+?)^(# end project modules)$/m,
          "$1\n" + moduleCommands.join("\n") + "\n$3"));
  return modules;
}

class Pipeline<Stream extends any> {
  public pipe(fn: (arg?: Stream) => any) {
    const stream = this.stream === null ? fn() : fn(this.stream);
    return new Pipeline<typeof stream>(stream);
  }

  constructor(input?: Stream) {
    if (input !== undefined)
      this.stream = input;
    else
      this.stream = null;
  }

  private stream = null;
}

new Pipeline()
    .pipe(genDeps)
    .pipe(reduceRedundantDeps)
    .pipe(sortDeps)
    .pipe(writeDeps);
