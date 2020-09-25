#ifndef CCUTL_SAME_H_INCLUDED
#define CCUTL_SAME_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link same ccutl.same\endlink -
/// describes a set of types with no variation
/// @file
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

#ifdef CCUTL_MODULES
module;
#else
#include <type_traits>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.same;
import std;
import ccutl.type_at;
export import std;
export import ccutl.type_at;
#else
#include "ccutl/type_at.h"
#endif

namespace ccutl::detail_::same_ {

/// checks if First, Rest... are the same
///
/// @details
/// adheres to the spirit of the same_as conceptual redundancy;
/// (same_as = std::is_same_v<T, U> and std::is_same_v<U, T>)
/// all types are bidirectionally compared with each other
///
/// @ingroup detail_
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
        (std::is_same_v<type_at<i, First, Rest...>, Rest> && ...);
    // recurse with First pushed to end to ensure two-way comparison
    return this_comparison && impl<i + 1, Rest..., First>();
  }
}

} // namespace ccutl::detail_::same_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// describes a set of types with no variation
///
/// @code
///   #include "ccutl/same.h"
///   // import ccutl.same; //
///   static_assert( same<int, int,   int>);
///   static_assert(!same<int, int &, int>);
/// @endcode
///
/// @ingroup ccutl
/// @anchor  same
template <class... Ts>
concept same = sizeof...(Ts) > 0 and detail_::same_::impl<0, Ts...>();

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
