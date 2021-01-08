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

#include <cmath>
#include <limits>

#include "ctl/lowest.h"

using namespace CCUTL_NAMESPACE;

template <class T>
inline constexpr auto
    integral_matches_limits = lowest<T> == std::numeric_limits<T>::lowest();

template <class T>
inline auto floating_matches_limits =
    !std::islessgreater(lowest<T>, std::numeric_limits<T>::lowest());

TEST("ccutl.lowest") {
  static_assert(integral_matches_limits<int>);
  static_assert(integral_matches_limits<short>);
  static_assert(integral_matches_limits<long>);
  static_assert(integral_matches_limits<long long>);
  static_assert(integral_matches_limits<unsigned int>);
  static_assert(integral_matches_limits<unsigned short>);
  static_assert(integral_matches_limits<unsigned long>);
  static_assert(integral_matches_limits<unsigned long long>);

  ASSERT(floating_matches_limits<float>);
  ASSERT(floating_matches_limits<double>);
  ASSERT(floating_matches_limits<long double>);
};
