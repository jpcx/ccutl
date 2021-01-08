#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.typeof]: defines types that are template<class...> specializations
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

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace typeof { // clang-format off
/// generated concept implementation for typeof
CTL_TYPEOF_CONCEPT(impl, (class... Ts), (Ts...)); // clang-format on
} // namespace typeof
} // namespace detail
// detail }}}

/**
 * Detects template specializations for type-parameter templates (<class...>)
 *
 * \code
 *   #include <tuple>
 *   #include "ctl/typeof.h"
 *   using std::tuple;
 *   auto x0 = ctl::typeof<tuple<int, int>, tuple>; // true
 *   auto x1 = ctl::typeof<tuple<int, int>, pair>;  // false
 * \endcode
 *
 * \anchor typeof
 * \ingroup ccutl
 */
template <class T, template <class...> class Template>
concept typeof = detail::typeof ::impl<T, Template>;

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
