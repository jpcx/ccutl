#ifndef CCUTL_DETAIL_STR_H_INCLUDED
#define CCUTL_DETAIL_STR_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief detail helpers for ccutl string functions
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
import std;
import ccutl.subscriptable_to;
#else
#include <ranges>

#include "ccutl/subscriptable_to.h"
#endif

#include "ccutl/detail_/config.h"

namespace ccutl::detail_ {

/// @addtogroup detail_
/// \{

/// specifies a type that is an input range of values convertible to const char
template <class T>
concept str_range = std::ranges::input_range<T>
    and std::convertible_to<std::ranges::range_value_t<T>, const char>;

/// specifies a type that is subscriptable to const char and is not a range
template <class T>
concept str_subscriptable =
    (subscriptable_to<T, const char> ||
     subscriptable_to<T, const wchar_t>)&&!str_range<T>;

/// specifies a const char range or subscriptable type
template <class T>
concept stringlike = str_range<T> || str_subscriptable<T>;

/// \}
} // namespace ccutl::detail_

#endif
