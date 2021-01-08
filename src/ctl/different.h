#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.different]: describes a set of types with at least one variation
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

#include "ctl/same.h"

namespace CCUTL_NAMESPACE {

/**
 * describes a set of types with at least one variation
 *
 * \code
 *   #include "ctl/different.h"
 *   auto x0 = ctl::different<int, int, int>;   // false
 *   auto x1 = ctl::different<int, int &, int>; // true
 * \endcode
 *
 * \anchor different
 * \ingroup ccutl
 */
template <class... Ts>
concept different = !same<Ts...>;

} // namespace CCUTL_NAMESPACE
