#ifndef CCUTL_STR_NEQ_H_INCLUDED
#define CCUTL_STR_NEQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link str_neq ccutl.str_neq\endlink -
/// performs a lexicographical non-equality comarison of two stringlike objects
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
export module ccutl.str_neq;

import ccutl.str_eq;
export import ccutl.str_eq;
#else
#include "ccutl/str_eq.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// performs a lexicographical non-equality comarison of two stringlike objects
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
///   #include "ccutl/str_neq.h"
///   // import ccutl.str_neq; //
///
///   constexpr const char *foo = "foo";
///
///   ccutl::str_neq(foo, "foo");              // false
///   ccutl::str_neq(foo, "foobar");           // false
///   ccutl::str_neq(foo, std::string("bar")); // true
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  alphacmp
template <detail_::stringlike_pack... Strs>
[[nodiscard]] inline constexpr bool
str_neq(const Strs &...strs) noexcept {
  return !str_eq(strs...);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
