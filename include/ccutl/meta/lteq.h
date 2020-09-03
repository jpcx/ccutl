#ifndef CCUTL_META_LTEQ_H_INCLUDED
#define CCUTL_META_LTEQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link meta_lteq ccutl.meta.lteq\endlink -
/// template less-than-or-equal-to comparison of two strongly-ordered three-way
/// comparables or differently-signed integrals
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
export module ccutl.meta.lteq;
import ccutl.lteq;
export import ccutl.lteq;
#else
#include "ccutl/lteq.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl::meta)

/*                                                        */ // clang-format off
/// template less-than-or-equal-to comparison of two strongly-ordered three-way
/// comparables or differently-signed integrals
///
/// @see https://en.cppreference.com/w/cpp/utility/compare/strong_ordering
/// @see https://en.cppreference.com/w/cpp/utility/compare/three_way_comparable
///
/// @details for use in contexts that do not support function calls
/// @note uses \link lteq ccutl.lteq\endlink for comparisons
///
/// @tparam l - left-hand  side value
/// @tparam r - right-hand side value
///
/// @returns result of strong less-than-or-equal-to comparison
///
/// @code
///   import ccutl.meta.lteq;
///
///   ccutl::meta::lteq<0, 0>;   // true
///   ccutl::meta::lteq<0, 0u>;  // true
///   ccutl::meta::lteq<0u, 0>;  // true
///   ccutl::meta::lteq<0u, 0u>; // true
///
///   ccutl::meta::lteq<0, 1>;   // true
///   ccutl::meta::lteq<1, 0u>;  // false
///   ccutl::meta::lteq<0u, 1>;  // true
///
///   ccutl::meta::lteq<0, 1u>;  // true
///   ccutl::meta::lteq<1u, 0>;  // false
///   ccutl::meta::lteq<1u, 1u>; // true
///
///   ccutl::meta::lteq<-1, -1>; // true
///   ccutl::meta::lteq<-1, 0u>; // true
///   ccutl::meta::lteq<0u, -1>; // false
///
///   ccutl::meta::lteq<-1, 1>;  // true
///   ccutl::meta::lteq<1, -1>;  // false
/// @endcode
///
/// @ingroup meta
/// @anchor  meta_lteq
/// @see \link lteq ccutl.lteq\endlink
/// @see ccutl/detail_/compare.h
template <auto l, auto r>
requires detail_::strongly_comparable_with<decltype(l), decltype(r)>
inline constexpr bool lteq = ccutl::lteq(l, r); /*          */ // clang-format on

CCUTL_END_EXPORT_NAMESPACE // ccutl::meta

#endif
