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

#include "cctest.h"

#include "ctl/pow10.h"

using namespace CCUTL_NAMESPACE;

template <std::floating_point N>
[[nodiscard]] static constexpr bool
islessgreater(N a, N b) noexcept {
  return a < b || a > b;
}

TEST("ccutl.pow10") {
  static_assert(pow10(0u) == 1);
  static_assert(pow10(1u) == 10);
  static_assert(pow10(2u) == 100);
  static_assert(pow10<unsigned>(0) == 1);
  static_assert(pow10<unsigned>(1) == 10);
  static_assert(pow10<unsigned>(2) == 100);
  static_assert(!islessgreater(pow10<double>(0), 1.0));
  static_assert(!islessgreater(pow10<double>(1), 10.0));
  static_assert(!islessgreater(pow10<double>(2), 100.0));
  static_assert(!islessgreater(pow10<double>(-1), 0.1));
  static_assert(!islessgreater(pow10<double>(-2), 0.01));
};
