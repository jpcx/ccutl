#ifndef CCUTL_EQ_H_INCLUDED
#define CCUTL_EQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link eq ccutl.eq\endlink -
/// equality comparison of two strongly-ordered three-way comparables or
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
#include <concepts>
#endif

#include "ccutl/detail_/compare.h"
#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.eq;
import std;
import ccutl.highest;
import ccutl.fwd;
export import std;
export import ccutl.highest;
export import ccutl.fwd;
#else
#include "ccutl/fwd.h"
#include "ccutl/highest.h"
#endif

namespace ccutl::detail_::eq_ {

/// @addtogroup detail_
/// \{

/// eq comparison of (non-different-signed-int) strongly ordered types
template <class L, trivially_strongly_comparable_with<L> R>
[[nodiscard]] inline constexpr bool
eq_impl(L &&l, R &&r) {
  return (l <=> r) == nullptr;
}

/// eq comparison of signed <=> unsigned
template <std::signed_integral L, std::unsigned_integral R>
[[nodiscard]] inline constexpr bool
eq_impl(L l, R r) {
  if (l < 0)
    return false;
  else {
    if constexpr (ccutl::highest<L> >= ccutl::highest<R>)
      return l == static_cast<L>(r);
    else
      return static_cast<R>(l) == r;
  }
}

/// eq comparison of unsigned <=> signed
template <std::unsigned_integral L, std::signed_integral R>
[[nodiscard]] inline constexpr bool
eq_impl(L l, R r) {
  if (r < 0)
    return false;
  else {
    if constexpr (ccutl::highest<L> < ccutl::highest<R>)
      return static_cast<R>(l) == r;
    else
      return l == static_cast<L>(r);
  }
}

/// \}

} // namespace ccutl::detail_::eq_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// equality comparison of two strongly-ordered three-way comparables or
/// differently-signed integrals
///
/// @see https://en.cppreference.com/w/cpp/utility/compare/strong_ordering
/// @see https://en.cppreference.com/w/cpp/utility/compare/three_way_comparable
///
/// @param l  - left-hand  side
/// @param r  - right-hand side
///
/// @returns result of strong equality comparison
///
/// @code
///   #include "ccutl/eq.h"
///   // import ccutl.eq; //
///
///   struct intholder {
///     int value = 0;
///     constexpr std::strong_ordering
///     operator<=>(const intholder &) const = default;
///   };
///
///   ccutl::eq(0, 0);                         // true
///   ccutl::eq(0, 0u);                        // true
///   ccutl::eq(0u, 0);                        // true
///   ccutl::eq(0u, 0u);                       // true
///
///   ccutl::eq(0, 1);                         // false
///   ccutl::eq(1, 0u);                        // false
///   ccutl::eq(0u, 1);                        // false
///
///   ccutl::eq(0, 1u);                        // false
///   ccutl::eq(1u, 0);                        // false
///   ccutl::eq(1u, 1u);                       // true
///
///   ccutl::eq(-1, -1);                       // true
///   ccutl::eq(-1, 0u);                       // false
///   ccutl::eq(0u, -1);                       // false
///
///   ccutl::eq(-1, 1);                        // false
///   ccutl::eq(1, -1);                        // false
///
///   ccutl::eq(intholder{0}, intholder{0});   // true
///   ccutl::eq(intholder{0}, intholder{1});   // false
///   ccutl::eq(intholder{1}, intholder{1});   // true
///   ccutl::eq(intholder{1}, intholder{-1});  // false
///   ccutl::eq(intholder{-1}, intholder{1});  // false
///   ccutl::eq(intholder{-1}, intholder{-1}); // true
/// @endcode
///
/// @ingroup ccutl
/// @anchor  eq
/// @see ccutl/detail_/compare.h
template <class L, detail_::strongly_comparable_with<L> R>
[[nodiscard]] inline constexpr bool
eq(L &&l, R &&r) noexcept {
  return detail_::eq_::eq_impl(fwd<L>(l), fwd<R>(r));
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
