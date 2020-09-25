#ifndef CCUTL_STR_GTEQ_H_INCLUDED
#define CCUTL_STR_GTEQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link str_gteq ccutl.str_gteq\endlink -
/// performs a lexicographical gteq comarison of two stringlike objects
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

#include "ccutl/detail_/config.h"
#include "ccutl/detail_/str.h"

#ifdef CCUTL_MODULES
export module ccutl.str_gteq;

import ccutl.str_eq;
import ccutl.str_gt;
export import ccutl.str_eq;
export import ccutl.str_gt;
#else
#include "ccutl/str_eq.h"
#include "ccutl/str_gt.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// performs a lexicographical gteq comarison of two stringlike objects
///
/// @details
///   accepts any char input ranges or char-subscriptables (e.g. char *).
///   wchar_t is also supported.
///   compares until range-end or null terminator.
///
/// @param strs any char input ranges or char pointers
///
/// @code
///   #include <string>
///   // import std; //
///   #include "ccutl/str_gteq.h"
///   // import ccutl.str_gteq; //
///
///   constexpr const char *foo = "foo";
///
///   ccutl::str_gteq(foo, "foo");              // true
///   ccutl::str_gteq(foo, "foobar");           // false
///   ccutl::str_gteq(foo, std::string("bar")); // true
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  alphacmp
template <detail_::stringlike Lhs, detail_::stringlike Rhs>
[[nodiscard]] inline constexpr bool
str_gteq(const Lhs &l, const Rhs &r) noexcept {
  return str_gt(l, r) or str_eq(l, r);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
