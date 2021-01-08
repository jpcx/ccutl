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

#include "ctl/typeof_concept.h"
#include "cctest.h"

#include <array>
#include <tuple>
#include <vector>

namespace typeof_concept_ {

template <auto... vs>
struct nontype_collection {
  static constexpr bool data = std::tuple{vs...};
};

CTL_TYPEOF_CONCEPT(type_typeof, (class... Ts), (Ts...));

CTL_TYPEOF_CONCEPT(type_size_typeof, (class T, std::size_t sz), (T, sz));

CTL_TYPEOF_CONCEPT(nontype_typeof, (auto... vs), (vs...));

} // namespace typeof_concept_

TEST("ccutl.typeof_concept") {
  using namespace typeof_concept_;
  static_assert(type_typeof<std::vector<int>, std::vector>);
  static_assert(!type_typeof<std::vector<int>, std::tuple>);
  static_assert(type_size_typeof<std::array<int, 3>, std::array>);
  static_assert(!type_size_typeof<std::tuple<int>, std::array>);
  static_assert(
      nontype_typeof<nontype_collection<1, 2, 3>, nontype_collection>);
};
