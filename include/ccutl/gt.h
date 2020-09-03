#ifndef CCUTL_GT_H_INCLUDED
#define CCUTL_GT_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link gt ccutl.gt\endlink -
/// greater-than comparison of two strongly-ordered three-way comparables or
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
#endif

#include "ccutl/detail_/compare.h"
#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.gt;
import ccutl.eq;
import ccutl.lt;
export import ccutl.eq;
export import ccutl.lt;
#else
#include "ccutl/eq.h"
#include "ccutl/lt.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// greater-than comparison of two strongly-ordered three-way comparables or
/// differently-signed integrals
///
/// @see https://en.cppreference.com/w/cpp/utility/compare/strong_ordering
/// @see https://en.cppreference.com/w/cpp/utility/compare/three_way_comparable
///
/// @param l  - left-hand  side
/// @param r  - right-hand side
///
/// @returns result of strong greater-than comparison
///
/// @code
///   #include "ccutl/gt.h"
///   // import ccutl.gt; //
///
///   struct intholder {
///     int value = 0;
///     constexpr std::strong_ordering
///     operator<=>(const intholder &) const = default;
///   };
///
///   ccutl::gt(0, 0);                         // false
///   ccutl::gt(0, 0u);                        // false
///   ccutl::gt(0u, 0);                        // false
///   ccutl::gt(0u, 0u);                       // false
///
///   ccutl::gt(0, 1);                         // false
///   ccutl::gt(1, 0u);                        // true
///   ccutl::gt(0u, 1);                        // false
///
///   ccutl::gt(0, 1u);                        // false
///   ccutl::gt(1u, 0);                        // true
///   ccutl::gt(1u, 1u);                       // false
///
///   ccutl::gt(-1, -1);                       // false
///   ccutl::gt(-1, 0u);                       // false
///   ccutl::gt(0u, -1);                       // true
///
///   ccutl::gt(-1, 1);                        // false
///   ccutl::gt(1, -1);                        // true
///
///   ccutl::gt(intholder{0}, intholder{0});   // false
///   ccutl::gt(intholder{0}, intholder{1});   // false
///   ccutl::gt(intholder{1}, intholder{1});   // false
///   ccutl::gt(intholder{1}, intholder{-1});  // true
///   ccutl::gt(intholder{-1}, intholder{1});  // false
///   ccutl::gt(intholder{-1}, intholder{-1}); // false
/// @endcode
///
/// @ingroup ccutl
/// @anchor  gt
/// @see ccutl/detail_/compare.h
template <class L, detail_::strongly_comparable_with<L> R>
[[nodiscard]] constexpr bool
gt(L l, R r) noexcept {
  return !lt(l, r) && !eq(l, r);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
