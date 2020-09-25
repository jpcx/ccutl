#ifndef CCUTL_STR_EQ_H_INCLUDED
#define CCUTL_STR_EQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link str_eq ccutl.str_eq\endlink -
/// performs a lexicographical equality comparison of two stringlike objects
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
#include <tuple>
#include <utility>
#endif

#include "ccutl/detail_/config.h"
#include "ccutl/detail_/str.h"

#ifdef CCUTL_MODULES
export module ccutl.str_eq;
import std;
import ccutl.arg_at;
export import std;
export import ccutl.arg_at;
#else
#include "ccutl/arg_at.h"
#include "ccutl/fwd.h"
#endif

namespace ccutl::detail_::str_eq_ {
/// @addtogroup detail_
/// \{

using std::size_t;
using std::ranges::begin;
using std::ranges::end;

/// lexicographical eq comparison of str_subscriptables
[[nodiscard]] constexpr inline bool
eq(const str_subscriptable auto &a, const str_subscriptable auto &b) noexcept {
  size_t i = 0;
  for (; a[i] and b[i]; ++i) {
    if (a[i] != b[i])
      return false;
  }
  return a[i] == b[i];
}

/// lexicographical eq comparison of str_ranges to str_subscriptables
[[nodiscard]] constexpr inline bool
eq(const str_range auto &a, const str_subscriptable auto &b) noexcept {
  auto &&ita = begin(a);
  size_t ib  = 0;
  for (; !(ita == end(a) || !*ita) and b[ib]; ++ita, ++ib) {
    if (*ita != b[ib])
      return false;
  }
  return (ita == end(a) || !*ita) and !b[ib];
}

/// lexicographical eq comparison of str_subscriptables to str_ranges
[[nodiscard]] constexpr inline bool
eq(const str_subscriptable auto &a, const str_range auto &b) noexcept {
  return eq(b, a);
}

/// lexicographical eq comparison of str_ranges
[[nodiscard]] constexpr inline bool
eq(const str_range auto &a, const str_range auto &b) noexcept {
  auto &&ita = begin(a);
  auto &&itb = begin(b);
  for (; !(ita == end(a) || !*ita) and !(itb == end(b) || !*itb);
       ++ita, ++itb) {
    if (*ita != *itb)
      return false;
  }
  return (ita == end(a) || *ita == 0) and (itb == end(b) || *itb == 0);
}

/// executes comparisons for all Strs...
template <stringlike_pack... Strs, size_t seq_first, size_t... seq_rest>
[[nodiscard]] constexpr inline bool
impl(
    std::index_sequence<seq_first, seq_rest...> &&,
    const Strs &...strs) noexcept {
  return (eq(arg_at<0>(strs...), arg_at<seq_rest>(strs...)) and ...);
}

/// \}
} // namespace ccutl::detail_::str_eq_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// performs a lexicographical equality comparison of two stringlike objects
///
/// @details
///   accepts any char input ranges or char-subscriptables (e.g. char *).
///   wchar_t is also supported.
///
/// @param strs any char input ranges or char pointers
///
/// @code
///   #include <string>
///   // import std; //
///   #include "ccutl/str_eq.h"
///   // import ccutl.str_eq; //
///
///   ccutl::str_eq("foo", "foo");                           // true
///   ccutl::str_eq("foo", "bar", "foo");                    // false
///   ccutl::str_eq("foo", "bar");                           // false
///   ccutl::str_eq("foo", std::string{"foo"});              // true
///   ccutl::str_eq(std::string{"foo"}, std::string{"foo"}); // true
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  str_eq
template <detail_::stringlike_pack... Strs>
[[nodiscard]] inline constexpr bool
str_eq(const Strs &...strs) noexcept {
  return detail_::str_eq_::impl(std::index_sequence_for<Strs...>{}, strs...);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
