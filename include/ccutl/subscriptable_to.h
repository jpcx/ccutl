#ifndef CCUTL_SUBSCRIPTABLE_TO_H_INCLUDED
#define CCUTL_SUBSCRIPTABLE_TO_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link subscriptable_to ccutl.subscriptable_to\endlink -
/// describes a T whose subscript operator returns a type convertible to SubType
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
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.subscriptable_to;
import std;
import ccutl.nocvref;
export import std;
export import ccutl.nocvref;
#else
#include "ccutl/nocvref.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// describes a T whose subscript operator returns a type convertible to SubType
///
/// @code
///   #include "ccutl/subscriptable_to.h"
///   // import ccutl.subscriptable_to; //
///
///   static_assert( ccutl::subscriptable_to<char *, char>);
///   static_assert( ccutl::subscriptable_to<char (&)[3], char>);
///   static_assert( ccutl::subscriptable_to<char *, const char>);
///   static_assert( ccutl::subscriptable_to<const char *, char>);
///   static_assert(!ccutl::subscriptable_to<const char **, char *>);
///   static_assert(!ccutl::subscriptable_to<char **, int *>);
/// @endcode
///
/// @ingroup ccutl
/// @anchor  subscriptable_to
template <class T, class SubType>
concept subscriptable_to = requires(const nocvref<std::decay_t<T>> &v) {
  { v[0] }
  ->std::convertible_to<SubType>;
};

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
