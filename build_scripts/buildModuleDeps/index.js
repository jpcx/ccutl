"use strict";
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
exports.__esModule = true;
var fs = require("fs");
var path = require("path");
var ROOTDIR = path.join(__dirname, '../../');
var SRCDIR = path.join(ROOTDIR, 'include');
var SRCEXT = 'h';
function genDeps() {
    var deps = {};
    var depthMatcher = /^\s*?(?:export )?import ([\w.]+?);$/gm;
    function scanDeps(content) {
        var imports = new Set();
        depthMatcher.lastIndex = 0;
        for (var m = depthMatcher.exec(content); m !== null; m = depthMatcher.exec(content))
            if (!m[1].match(/std/m))
                imports.add(m[1]);
        return imports;
    }
    function search(dir) {
        if (dir === void 0) { dir = SRCDIR; }
        var dirents = fs.readdirSync(dir, { withFileTypes: true });
        var srcRelDir = path.relative(SRCDIR, dir);
        for (var _i = 0, dirents_1 = dirents; _i < dirents_1.length; _i++) {
            var dent = dirents_1[_i];
            if (dent.isDirectory())
                search(path.join(dir, dent.name));
            else if (dent.name.match(/\.h/m) && !srcRelDir.match(/detail_/) &&
                !srcRelDir.match(/macros/)) {
                var name_1 = dent.name;
                var moduleName = [srcRelDir.replace(/\//g, '.'), dent.name.replace(/\.h/m, '')]
                    .filter(function (x) { return x; })
                    .join('.');
                var content = fs.readFileSync(path.join(dir, name_1), 'utf8');
                deps[moduleName] = scanDeps(content);
            }
        }
    }
    search();
    return deps;
}
function reduceRedundantDeps(dependencies) {
    var result = {};
    var _loop_1 = function (mod, deps) {
        var depsArray = Array.from(deps);
        var end = depsArray.length;
        var _loop_2 = function (i) {
            var curDep = depsArray[i];
            var recurseReduceDeps = function (depdeps) {
                var _loop_3 = function (depdep) {
                    if (depsArray.includes(depdep)) {
                        var removeIdx = depsArray.findIndex(function (x) { return x === depdep; });
                        depsArray.splice(removeIdx, 1);
                        if (removeIdx <= i)
                            --i;
                        --end;
                    }
                    if (dependencies[depdep].size)
                        recurseReduceDeps(Array.from(dependencies[depdep]));
                };
                for (var _i = 0, depdeps_1 = depdeps; _i < depdeps_1.length; _i++) {
                    var depdep = depdeps_1[_i];
                    _loop_3(depdep);
                }
            };
            recurseReduceDeps(Array.from(dependencies[curDep]));
            out_i_1 = i;
        };
        var out_i_1;
        for (var i = 0; i < end; ++i) {
            _loop_2(i);
            i = out_i_1;
        }
        result[mod] = new Set(depsArray);
    };
    for (var _i = 0, _a = Object.entries(dependencies); _i < _a.length; _i++) {
        var _b = _a[_i], mod = _b[0], deps = _b[1];
        _loop_1(mod, deps);
    }
    return result;
}
function sortDeps(deps) {
    var sorted = [];
    function insertSorted(_a) {
        var name = _a[0], set = _a[1];
        var insIdx = 0;
        for (var i = 0; i < sorted.length; ++i) {
            var _b = sorted[i], sname = _b[0], sset = _b[1];
            if (set.has(sname))
                insIdx = i + 1;
        }
        sorted.splice(insIdx, 0, [name, set]);
    }
    Object.entries(deps).forEach(insertSorted);
    return sorted;
}
function writeDeps(sortedDeps) {
    var cmakeListsPath = path.join(ROOTDIR, 'cmake/project_module_structure.cmake');
    var content = fs.readFileSync(cmakeListsPath, 'utf8');
    var modules = new Set();
    var moduleCommands = [];
    for (var _i = 0, sortedDeps_1 = sortedDeps; _i < sortedDeps_1.length; _i++) {
        var _a = sortedDeps_1[_i], name_2 = _a[0], set = _a[1];
        modules.add(name_2);
        if (set.size) {
            var cmd = '';
            cmd += "add_module (" + name_2 + "\n";
            cmd += Array.from(set).map(function (x) { return "            " + x; }).join('\n');
            cmd += ')';
            moduleCommands.push(cmd);
        }
        else
            moduleCommands.push("add_module (" + name_2 + ")");
    }
    fs.writeFileSync(cmakeListsPath, content.replace(/^(# begin project modules)$([\s\S]+?)^(# end project modules)$/m, '$1\n' + moduleCommands.join('\n') + '\n$3'));
    return modules;
}
var Pipeline = /** @class */ (function () {
    function Pipeline(input) {
        this.stream = null;
        if (input !== undefined)
            this.stream = input;
        else
            this.stream = null;
    }
    Pipeline.prototype.pipe = function (fn) {
        var stream = this.stream === null ? fn() : fn(this.stream);
        return new Pipeline(stream);
    };
    return Pipeline;
}());
new Pipeline()
    .pipe(genDeps)
    .pipe(reduceRedundantDeps)
    .pipe(sortDeps)
    .pipe(writeDeps);
