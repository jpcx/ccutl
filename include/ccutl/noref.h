#ifndef CCUTL_NOREF_H_INCLUDED
#define CCUTL_NOREF_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link noref ccutl.noref\endlink -
/// removes the topmost reference qualifiers on a type
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
//                                                                             /
//  You should have received a copy of the GNU General Public License         //
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.   ///
////////////////////////////////////////////////////////////////////////////////

#ifdef CCUTL_MODULES
module;
#else
#include <type_traits>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.noref;
import std;
export import std;
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// removes the topmost reference qualifiers on a type
///
/// @code
///   #include "ccutl/noref.h"
///   // import ccutl.noref; //
///
///   using x0 = ccutl::noref<int>;         // int
///   using x1 = ccutl::noref<int &>;       // int
///   using x2 = ccutl::noref<const int &>; // const int
///   using x3 = ccutl::noref<const int>;   // const int
///   using x4 = ccutl::noref<const int *>; // const int *
/// @endcode
///
/// @ingroup ccutl
/// @anchor  noref
template <class T>
using noref = std::remove_reference_t<T>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
