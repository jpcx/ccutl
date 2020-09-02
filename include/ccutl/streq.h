#ifndef CCUTL_STREQ_H_INCLUDED
#define CCUTL_STREQ_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link streq ccutl.streq\endlink -
/// true if all provided char ranges or null-terminated strings are equal
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
#include <tuple>
#include <utility>
#endif

#include "ccutl/detail_/config.h"
#include "ccutl/detail_/str.h"

#ifdef CCUTL_MODULES
export module ccutl.streq;
import std;
import ccutl.fwd;
export import std;
export import ccutl.fwd;
#else
#include "ccutl/fwd.h"
#endif

namespace ccutl::detail_::streq_ {
/// @addtogroup detail_
/// \{

using std::size_t;

/// checks if all Ts are stringlike
template <class... Ts>
concept stringlike_pack = (stringlike<Ts> && ...);

/// eq comparison of str_subscriptables
[[nodiscard]] constexpr inline bool
eq(str_subscriptable auto &&a, str_subscriptable auto &&b) {
  for (size_t i = 0;; ++i) {
    if (a[i] == '\0' and b[i] == '\0')
      return true;
    if (a[i] != b[i])
      return false;
  }
}

/// eq comparison of str_ranges to str_subscriptables
[[nodiscard]] constexpr inline bool
eq(str_range auto &&a, str_subscriptable auto &&b) {
  auto &&ita = a.begin();
  size_t ib  = 0;
  for (;; ++ita, ++ib) {
    if (*ita == '\0' and b[ib] == '\0')
      return true;
    if (*ita != b[ib])
      return false;
  }
}

/// eq comparison of str_subscriptables to str_ranges
[[nodiscard]] constexpr inline bool
eq(str_subscriptable auto &&a, str_range auto &&b) {
  return eq(fwd<decltype(b)>(b), fwd<decltype(a)>(a));
}

/// eq comparison of str_ranges
[[nodiscard]] constexpr inline bool
eq(str_range auto &&a, str_range auto &&b) {
  auto &&ita = a.begin();
  auto &&itb = b.begin();
  for (;; ++ita, ++itb) {
    if (*ita == '\0' and *itb == '\0')
      return true;
    if (*ita != *itb)
      return false;
  }
}

/// executes comparisons for all Strs...
template <stringlike_pack... Strs, size_t seq_first, size_t... seq_rest>
[[nodiscard]] constexpr inline bool
impl(std::index_sequence<seq_first, seq_rest...> &&, Strs &&...strs) {
  auto tup     = std::tuple{ccutl::fwd<Strs>(strs)...};
  auto &&first = std::get<0>(tup);

  return (eq(first, std::get<seq_rest>(tup)) && ...);
}

/// \}
} // namespace ccutl::detail_::streq_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// true if all provided char ranges or null-terminated strings are equal
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
///   #include "ccutl/streq.h"
///   // import ccutl.streq; //
///
///   streq("foo", "foo");                           // true
///   streq("foo", "bar");                           // false
///   streq("foo", std::string{"foo"});              // true
///   streq(std::string{"foo"}, std::string{"foo"}); // true
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  streq
template <detail_::streq_::stringlike_pack... Strs>
[[nodiscard]] inline constexpr bool
streq(Strs &&...strs) noexcept {
  return detail_::streq_::impl(
      std::index_sequence_for<Strs...>{}, fwd<Strs>(strs)...);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
