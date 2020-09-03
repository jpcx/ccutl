#ifndef CCUTL_DIFFERENT_H_INCLUDED
#define CCUTL_DIFFERENT_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link different ccutl.different\endlink -
/// describes a set of types with at least one variation
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

#ifdef CCUTL_MODULES
export module ccutl.different;
import ccutl.same;
export import ccutl.same;
#else
#include "ccutl/same.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// describes a set of types with at least one variation
///
/// @code
///   #include "ccutl/different.h"
///   // import ccutl.different; //
///   auto x0 = different<int, int, int>;   // false
///   auto x1 = different<int, int &, int>; // true
/// @endcode
///
/// @ingroup ccutl
/// @anchor  different
template <class... Ts>
concept different = !same<Ts...>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
