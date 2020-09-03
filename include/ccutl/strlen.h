#ifndef CCUTL_STRLEN_H_INCLUDED
#define CCUTL_STRLEN_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link strlen ccutl.strlen\endlink -
/// returns the length of any char range or null-terminated string
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
export module ccutl.strlen;
import std;
import ccutl.fwd;
export import std;
export import ccutl.fwd;
#else
#include "ccutl/fwd.h"
#endif

namespace ccutl::detail_::strlen_ {
/// @addtogroup detail_
/// \{

using namespace std::ranges;

/// counts the length of a stringlike range
template <str_range Str>
[[nodiscard]] inline constexpr std::size_t
strlen(Str &&s) noexcept {
  std::size_t i = 0;
  for (auto &&it = begin(s);
       it != end(s) and *it != static_cast<range_value_t<Str>>('\0'); ++it, ++i)
    ;

  return i;
}

/// counts the length of a str_subscriptable
template <str_subscriptable Str>
[[nodiscard]] inline constexpr std::size_t
strlen(Str &&s) noexcept {
  std::size_t i = 0;
  for (; s[i] != static_cast<decltype(s[0])>('\0'); ++i)
    ;
  return i;
}

/// \}
} // namespace ccutl::detail_::strlen_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// returns the length of any char range or null-terminated string
///
/// @details
///   accepts any char input ranges or char-subscriptables (e.g. char *).
///   wchar_t is also supported.
///
/// @tparam Str stringlike type (char range or char-subscriptable)
/// @param  s   stringlike object
///
/// @returns length of string (size before null terminator)
///
/// @code
///   #include <string>
///   // import std; //
///   #include "ccutl/strlen.h"
///   // import ccutl.strlen; //
///
///   auto s = std::string{"bar"};
///
///   auto a = ccutl::strlen("foo"); // 3
///   auto b = ccutl::strlen(s);     // 3
/// @endcode
///
/// @see ccutl/detail_/str.h
///
/// @ingroup ccutl
/// @anchor  strlen
template <detail_::stringlike Str>
[[nodiscard]] inline constexpr std::size_t
strlen(Str &&s) noexcept {
  return detail_::strlen_::strlen(fwd<Str>(s));
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
