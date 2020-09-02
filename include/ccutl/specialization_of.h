#ifndef CCUTL_SPECIALIZATION_OF_H_INCLUDED
#define CCUTL_SPECIALIZATION_OF_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link specialization_of ccutl.specialization_of\endlink -
/// detects template specializations for type-parameter templates (<class...>)
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
#include "ccutl/macros/make_specialization_of_concept.h"

#ifdef CCUTL_MODULES
export module ccutl.specialization_of;
#endif

namespace ccutl::detail_::specialization_of_ {
/// generated concept implementation for specialization_of
///
/// @ingroup detail_
CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(impl, (class... Ts), (Ts...));
}

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// Detects template specializations for type-parameter templates (<class...>)
///
/// @note may only be used with template structs, classes, and unions
///
/// @code
///   #include <tuple>
///   // import std; //
///   #include "ccutl/specialization_of.h"
///   // import ccutl.specialization_of; //
///   using std::tuple;
///   auto x0 = ccutl::specialization_of<tuple<int, int>, tuple>; // true
///   auto x1 = ccutl::specialization_of<tuple<int, int>, pair>;  // false
/// @endcode
///
/// @ingroup ccutl
/// @anchor  specialization_of
template <class T, template <class...> class Template>
concept specialization_of = detail_::specialization_of_::impl<T, Template>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
