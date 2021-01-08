/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

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

#include <string_view>

#include "cctest.h"

#include "ctl/found.h"

using namespace CCUTL_NAMESPACE;
using namespace std;

TEST("ccutl.found") {
  constexpr std::string_view s{"foo"};
  static_assert(found(s.begin(), s.end(), 'f'));
  static_assert(found(s.begin(), s.end(), 'o'));
  static_assert(!found(s.begin(), s.end(), 'e'));

  static_assert(found(s, 'f'));
  static_assert(found(s, 'o'));
  static_assert(!found(s, 'e'));
};
