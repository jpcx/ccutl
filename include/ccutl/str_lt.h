#ifndef CCUTL_STR_LT_H_INCLUDED
#define CCUTL_STR_LT_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link str_lt ccutl.str_lt\endlink -
/// performs a lexicographical less-than comarison of two stringlike objects
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
#include <ranges>
#endif

#include "ccutl/detail_/config.h"
#include "ccutl/detail_/str.h"

#ifdef CCUTL_MODULES
export module ccutl.str_lt;
import std;
export import std;
#endif

namespace ccutl::detail_::str_lt_ {
/// @addtogroup detail_
/// \{

using std::ranges::begin;
using std::ranges::end;

/// lexicographical lt comparison of str_subscriptables
[[nodiscard]] inline constexpr bool
lt(const str_subscriptable auto &a, const str_subscriptable auto &b) noexcept {
  size_t i = 0;
  for (; a[i] and b[i]; ++i)
    if (a[i] != b[i])
      return a[i] < b[i];

  // if (     a[i] == '\0'
  //      and b[i] == '\0') return false;
  // else                   return a[i] == '\0';
  return !(!a[i] && !b[i]) and !a[i];
}
/// lexicographical lt comparison of str_ranges to str_subscriptables
[[nodiscard]] inline constexpr bool
lt(const str_range auto &a, const str_subscriptable auto &b) noexcept {
  auto &&ita = begin(a);
  size_t ib  = 0;
  for (; !(ita == end(a) || !*ita) and b[ib]; ++ita, ++ib)
    if (*ita != b[ib])
      return *ita < b[ib];

  // if (     (ita == end(a) or *ita == '\0')
  //      and b[ib] == '\0')  return false;
  // else                     return     ita == end(a)
  //                                 or *ita == '\0';
  return !((ita == end(a) || !*ita) && !b[ib]) and (ita == end(a) || !*ita);
}
/// lexicographical lt comparison of str_subscriptables to str_ranges
[[nodiscard]] inline constexpr bool
lt(const str_subscriptable auto &a, const str_range auto &b) noexcept {
  size_t ia  = 0;
  auto &&itb = begin(b);
  for (; a[ia] and !(itb == end(b) || !*itb); ++ia, ++itb)
    if (a[ia] != *itb)
      return a[ia] < *itb;

  // if (     a[ia] == '\0'
  //      and (itb == end(b) or *itb == '\0')) return false;
  // else                                      return a[ia] == '\0';
  return !(a[ia] && (itb == end(b) || !*itb)) and !a[ia];
}
/// lexicographical lt comparison of str_ranges
[[nodiscard]] inline constexpr bool
lt(const str_range auto &a, const str_range auto &b) noexcept {
  auto &&ita = begin(a);
  auto &&itb = begin(b);
  for (; !(ita == end(a) || !*ita) and !(itb == end(b) || !*itb); ++ita, ++itb)
    if (*ita != *itb)
      return *ita < *itb;

  // if (     (ita == end(a) or *ita == '\0')
  //      and (itb == end(b) or *itb == '\0')) return false;
  // else                                      return     ita == end(a)
  //                                                  or *ita == '\0';
  return !((ita == end(a) || !*ita) && (itb == end(b) || !*itb)) and
         (ita == end(a) || !*ita);
}
/// \}
}; // namespace ccutl::detail_::str_lt_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// performs a lexicographical less-than comarison of two stringlike objects
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
///   #include "ccutl/str_lt.h"
///   // import ccutl.str_lt; //
///
///   constexpr const char *foo = "foo";
///
///   ccutl::str_lt(foo, "foo");              // false
///   ccutl::str_lt(foo, "foobar");           // true
///   ccutl::str_lt(foo, std::string("bar")); // false
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  alphacmp
template <detail_::stringlike Lhs, detail_::stringlike Rhs>
[[nodiscard]] inline constexpr bool
str_lt(const Lhs &l, const Rhs &r) noexcept {
  return detail_::str_lt_::lt(l, r);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
