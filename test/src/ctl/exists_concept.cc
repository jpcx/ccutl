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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include "ctl/exists_concept.h"
#include "ctl/different.h"
#include "ctl/same.h"

#include <cctest.h>

namespace exists_concept_ {

CTL_EXISTS_CONCEPT(exists, (class... Ts), (Ts...));

template <template <class...> class IntableTemplate>
requires exists<IntableTemplate, int> struct example;

template <ctl::same<int>>
struct good;

template <ctl::different<int>>
struct bad;

} // namespace exists_concept_

TEST("ccutl.exists_concept") {
  using namespace exists_concept_;
  static_assert(exists<good, int>);
  static_assert(!exists<bad, int>);
};
