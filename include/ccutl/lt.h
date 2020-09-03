#ifndef CCUTL_LT_H_INCLUDED
#define CCUTL_LT_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link lt ccutl.lt\endlink -
/// less-than comparison of two strongly-ordered three-way comparables or
/// differently-signed integrals
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
#include <compare>
#endif

#include "ccutl/detail_/compare.h"
#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.lt;
import std;
import ccutl.highest;
export import std;
export import ccutl.highest;
#else
#include "ccutl/highest.h"
#endif

namespace ccutl::detail_::lt_ {
/// @addtogroup detail_
/// \{

/// lt comparison of (non-different-signed-int) strongly ordered types
template <class L, trivially_strongly_comparable_with<L> R>
[[nodiscard]] constexpr bool
impl(L l, R r) {
  return (l <=> r) < nullptr;
}

/// lt comparison of signed <=> unsigned
template <std::signed_integral L, std::unsigned_integral R>
[[nodiscard]] constexpr bool
impl(L l, R r) {
  if (l < 0)
    return true;
  else {
    if constexpr (ccutl::highest<L> >= ccutl::highest<R>)
      return l < static_cast<L>(r);
    else
      return static_cast<R>(l) < r;
  }
}

/// lt comparison of unsigned <=> signed
template <std::unsigned_integral L, std::signed_integral R>
[[nodiscard]] constexpr bool
impl(L l, R r) {
  if (r < 0)
    return false;
  else {
    if constexpr (ccutl::highest<L> < ccutl::highest<R>)
      return static_cast<R>(l) < r;
    else
      return l < static_cast<L>(r);
  }
}

/// \}
} // namespace ccutl::detail_::lt_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// less-than comparison of two strongly-ordered three-way comparables or
/// differently-signed integrals
///
/// @see https://en.cppreference.com/w/cpp/utility/compare/strong_ordering
/// @see https://en.cppreference.com/w/cpp/utility/compare/three_way_comparable
///
/// @param l  - left-hand  side
/// @param r  - right-hand side
///
/// @returns result of strong less-than comparison
///
/// @code
///   #include "ccutl/lt.h"
///   // import ccutl.lt; //
///
///   struct intholder {
///     int value = 0;
///     constexpr std::strong_ordering
///     operator<=>(const intholder &) const = default;
///   };
///
///   ccutl::lt(0, 0);                         // false
///   ccutl::lt(0, 0u);                        // false
///   ccutl::lt(0u, 0);                        // false
///   ccutl::lt(0u, 0u);                       // false
///
///   ccutl::lt(0, 1);                         // true
///   ccutl::lt(1, 0u);                        // false
///   ccutl::lt(0u, 1);                        // true
///
///   ccutl::lt(0, 1u);                        // true
///   ccutl::lt(1u, 0);                        // false
///   ccutl::lt(1u, 1u);                       // false
///
///   ccutl::lt(-1, -1);                       // false
///   ccutl::lt(-1, 0u);                       // true
///   ccutl::lt(0u, -1);                       // false
///
///   ccutl::lt(-1, 1);                        // true
///   ccutl::lt(1, -1);                        // false
///
///   ccutl::lt(intholder{0}, intholder{0});   // false
///   ccutl::lt(intholder{0}, intholder{1});   // true
///   ccutl::lt(intholder{1}, intholder{1});   // false
///   ccutl::lt(intholder{1}, intholder{-1});  // false
///   ccutl::lt(intholder{-1}, intholder{1});  // true
///   ccutl::lt(intholder{-1}, intholder{-1}); // false
/// @endcode
///
/// @ingroup ccutl
/// @anchor  lt
/// @see ccutl/detail_/compare.h
template <class L, detail_::strongly_comparable_with<L> R>
[[nodiscard]] constexpr bool
lt(L l, R r) noexcept {
  return detail_::lt_::impl(l, r);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
