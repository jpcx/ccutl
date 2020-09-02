////////////////////////////////////////////////////////////////////////////////
/// @brief Scans modules and builds a feature summary; writes README.md.in
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

const fs   = require('fs');
const path = require('path');

const MODULE_DIR = path.join(__dirname, '../include');

const README_PATH = path.join(__dirname, '../cmake/README.md.in');

function genDescription() {
  const res = [];

  function search(curPath) {
    for (const dirent of fs.readdirSync(curPath, {withFileTypes : true})) {
      const srcRelDir = path.relative(MODULE_DIR, curPath);
      if (dirent.isDirectory())
        search(path.join(curPath, dirent.name));
      else if (
          dirent.name.match(/\.h$/m) && !srcRelDir.match(/detail_/) &&
          !srcRelDir.match(/macros/))
        res.push([
          [
            path.relative(MODULE_DIR, curPath).replace(/\//g, '.'),
            dirent.name.replace(/.h$/m, '')
          ].filter(x => x)
              .join('.'),
          (() => {
            const _ = fs.readFileSync(path.join(curPath, dirent.name), 'utf8')
                          .match(/\/\/\/ @brief([\s\S]+)\/\/\/ @file/);
            if (_)
              return _[1]
                  .replace(/\\link[\s\S]*?\\endlink ?-?\n?/, '')
                  .trim()
                  .replace(/^#\s*/mg, '')
                  .replace(/\/\/\//g, '')
                  .replace(/(\s)+/g, '$1')
                  .trim();
            else
              return '';
          })()
        ]);
    }
  }
  search(MODULE_DIR);

  return res.sort((a, b) => a[0] > b[0] ? 1 : -1)
      .map(x => x.join(' | '))
      .join('\n');
}

fs.writeFileSync(
    README_PATH,
    fs.readFileSync(README_PATH, 'utf8')
        .replace(
            /^(## Synopsis\n\nModule \| Brief\n--- \| ---\n)[\s\S]*?(\n\nMacro \| Location \| Brief)/gm,
            '$1' + genDescription() + '$2'),
    'utf8')
