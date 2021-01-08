/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl]: a C++ utilities library focused on flexibility and expressibility
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

const fs = require('fs');
const path = require('path');

// I/O Helpers

function readContent() {
  // {path: content}
  const result = {};

  function recurse(curPath = path.join(__dirname, '../')) {
    for (const child of fs.readdirSync(
             curPath, {encoding : 'utf8', withFileTypes : true})) {
      if (child.isDirectory()) {
        recurse(path.join(curPath, child.name));
      } else if ((child.name.match(/\.html$/m) &&
                  !child.name.match(/ccutl_8h(?:_source)?.html/)) ||
                 (child.name.match(/\.js$/m) &&
                  !child.name.match(/fixes.js/))) {
        const p = path.join(curPath, child.name);
        result[p] = fs.readFileSync(p, 'utf8');
      }
    }
  }
  recurse();

  return result;
}

function writeContent(content) {
  for (const [loc, text] of Object.entries(content)) {
    fs.writeFileSync(loc, text, 'utf8');
  }
}

// Manipulation Helpers

function globalSearchReplace(content, searchValue, replaceValue) {
  for (const [loc, text] of Object.entries(content)) {
    content[loc] = text.replace(searchValue, replaceValue)
  }
}

// Fixes

function fixNamespace(content) {
  globalSearchReplace(content, /CCUTL_NAMESPACE/g, 'ctl');
  globalSearchReplace(content, /CCUTL__NAMESPACE/g, 'ctl');
  for (const loc of Object.keys(content)) {
    if (loc.match(/CCUTL__NAMESPACE/g)) {
      fs.unlinkSync(loc);
      const newloc = loc.replace(/CCUTL__NAMESPACE/g, 'ctl')
      content[newloc] = content[loc];
      delete content[loc];
    }
  }
}

function fixProjectTitle(content) {
  globalSearchReplace(content, /<title>ccutl: Ccutl<\/title>/g,
                      '<title>ccutl Core Utilities</title>');
  globalSearchReplace(
      content,
      /<div class="headertitle">\s*<div class="title">Ccutl<\/div>\s*<\/div>/g,
      '');
}

function setGroupAsIndex(content) {
  globalSearchReplace(content, /group__ccutl.html/g, 'index.html')
  const index = path.join(path.join(__dirname, '../'), 'index.html');
  const ccutl = path.join(path.join(__dirname, '../'), 'group__ccutl.html');
  content[index] = content[ccutl];
  delete content[ccutl];
  fs.unlinkSync(ccutl);
}

function applyFixes(content) {
  console.log('  Fixing titles...');
  fixNamespace(content);
  fixProjectTitle(content);
  setGroupAsIndex(content);
}

// main

console.log('reading content...');
const content = readContent();
console.log('applying fixes...');
applyFixes(content);
console.log('writing files...');
writeContent(content);

console.log('done!');
