#ifndef CCUTL_SPECIALIZABLE_WITH_H_INCLUDED
#define CCUTL_SPECIALIZABLE_WITH_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link specializable_with ccutl.specializable_with\endlink -
/// describes a template that is specializable with given type template args
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
export module ccutl.specializable_with;
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// describes a template that is specializable with given type template args
///
/// @note may only be used with template structs, classes, and unions
///
/// @code
///   #include "ccutl/different.h"
///   // import ccutl.different; //
///   #include "ccutl/same.h"
///   // import ccutl.same; //
///   #include "ccutl/specializable_with.h"
///   // import ccutl.specializable_with; //
///
///   // may only be specialized with templates that allow an int- type<int>
///   template <template<class...> class IntableTemplate>
///   requires ccutl::specializable_with<IntableTemplate, int>
///   struct example;
///
///   template <ccutl::same<int>>
///   struct good;
///
///   template <ccutl::different<int>>
///   struct bad;
///
///   constexpr bool ex0 = ccutl::specializable_with<good, int>; // true
///   constexpr bool ex1 = ccutl::specializable_with<bad,  int>; // false
/// @endcode
///
/// @ingroup ccutl
/// @anchor  specializable_with
template <template <class...> class Template, class... Args>
concept specializable_with = requires() {
  typename Template<Args...>;
};

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
