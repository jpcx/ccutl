#ifndef CCUTL_SPECIALIZES_H_INCLUDED
#define CCUTL_SPECIALIZES_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link specializes ccutl.specializes\endlink -
/// requires that a type may be used to specialize a given template
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
export module ccutl.specializes;
import ccutl.same;
export import ccutl.same;
#else
#include "ccutl/same.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// requires that a type may be used to specialize a given template
///
/// @note may only be used with template structs, classes, and unions
///
/// @code
///   #include "ccutl/different.h"
///   // import ccutl.different; //
///   #include "ccutl/same.h"
///   // import ccutl.same; //
///   #include "ccutl/specializes.h"
///   // import ccutl.specializes; //
///
///   template <ccutl::same<int>>
///   struct only_int;
///
///   template <ccutl::different<int>>
///   struct anything_but_int;
///
///   template <specializes<only_int> MustBeInt>
///   struct give_me_int;
///   template <specializes<anything_but_int> MustNotBeInt>
///   struct no_int_please;
///
///   constexpr bool res0 = give_me_int<int>;     // OK
///   constexpr bool res1 = give_me_int<float>;   // Error
///   constexpr bool res2 = no_int_please<int>;   // Error
///   constexpr bool res3 = no_int_please<float>; // OK
/// @endcode
///
/// @ingroup ccutl
/// @anchor  specializes
template <class Arg, template <class...> class Template>
concept specializes = requires() {
  typename Template<Arg>;
};

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
