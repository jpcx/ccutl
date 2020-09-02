#ifndef CCUTL_RANGE_OF_H_INCLUDED
#define CCUTL_RANGE_OF_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link range_of ccutl.range_of\endlink -
/// describes a range-type T that contains Contained
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
#include <concepts>
#include <ranges>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.range_of;
import std;
export import std;
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// describes a range-type T that contains Contained
///
/// @code
///   #include <string>
///   // import std; //
///   #include "ccutl/range_of.h"
///   // import ccutl.range_of; //
///
///   static_assert( ccutl::range_of<std::string, char>);
///   static_assert(!ccutl::range_of<std::string, char &>);
///   static_assert(!ccutl::range_of<std::string, const char>);
///   static_assert(!ccutl::range_of<std::string, int>);
/// @endcode
///
/// @ingroup ccutl
/// @anchor  range_of
template <class T, class Contained>
concept range_of = std::ranges::range<T>
    &&std::same_as<std::ranges::range_value_t<T>, Contained>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
