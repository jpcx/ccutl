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

#include "ctl/exists.h"
#include "ctl/different.h"
#include "ctl/same.h"

#include <cctest.h>

using namespace CCUTL_NAMESPACE;

namespace exists_ {

template <template <class...> class IntableTemplate>
requires exists<IntableTemplate, int> struct example;

template <ctl::same<int>>
struct need_int;

template <ctl::different<int>>
struct need_no_int;

} // namespace exists_

TEST("ccutl.exists") {
  using namespace exists_;
  static_assert(exists<need_int, int>);
  static_assert(!exists<need_int, float>);
  static_assert(!exists<need_int, int, int>);
  static_assert(exists<need_no_int, float>);
  static_assert(!exists<need_no_int, int>);
  static_assert(!exists<need_no_int, float, float>);
};
