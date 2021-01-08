#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.same]: describes a set of types with no variation
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

#include <type_traits>

#include "ctl/targ.h"

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace same {
/// checks if First, Rest... are the same
/// adheres to the spirit of the same_as conceptual redundancy;
/// (same_as = std::is_same_v<T, U> and std::is_same_v<U, T>)
/// all types are bidirectionally compared with each other
template <std::size_t i, class First, class... Rest>
[[nodiscard]] inline constexpr bool
impl() noexcept {
  if constexpr (i == sizeof...(Rest)) {
    return true;
  } else if constexpr (sizeof...(Rest) == 1) {
    // pack is not really expanded with the ellipses (sizeof 1)
    return (std::is_same_v<First, Rest> && ...);
  } else /* i < sizeof...(Rest) and sizeof...(Rest) > 1 */ {
    constexpr bool this_comparison =
        (std::is_same_v<ctl::targ<i, First, Rest...>, Rest> && ...);
    // recurse with First pushed to end to ensure two-way comparison
    return this_comparison && impl<i + 1, Rest..., First>();
  }
}
} // namespace same
} // namespace detail
// detail }}}

/**
 * describes a set of types with no variation
 *
 * \code
 *   #include "ctl/same.h"
 *   static_assert( same<int, int,   int>);
 *   static_assert(!same<int, int &, int>);
 * \endcode
 *
 * \anchor same
 * \ingroup ccutl
 */
template <class... Ts>
concept same = sizeof...(Ts) > 0 and detail::same::impl<0, Ts...>();

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
