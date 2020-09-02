#ifndef CCUTL_NONTYPE_SPECIALIZATION_OF_H_INCLUDED
#define CCUTL_NONTYPE_SPECIALIZATION_OF_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief
/// \link nontype_specialization_of ccutl.nontype_specialization_of\endlink -
/// detects template specializations for nontype-parameter templates (<auto...>)
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
export module ccutl.nontype_specialization_of;
#endif

namespace ccutl::detail_::nontype_specialization_of_ {
/// generated concept implementation for nontype_specialization_of
///
/// @ingroup detail_
CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(impl, (auto... vs), (vs...));
}

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// Detects template specializations for nontype-parameter templates (<auto...>)
///
/// @note may only be used with template structs, classes, and unions
///
/// @code
///   #include "ccutl/nontype_specialization_of.h"
///   // import ccutl.nontype_specialization_of; //
///
///   using ccutl::nontype_specialization_of;
///
///   template <int... vs>
///   struct tplarray {
///     static constexpr int data[1 + sizeof...(vs)]{vs...};
///   };
///
///   template <int... vs>
///   struct tplsum {
///     static constexpr int value = (vs + ...);
///   };
///
///   static_assert( nontype_specialization_of<tplarray<4, 5>, tplarray>);
///   static_assert(!nontype_specialization_of<tplarray<4, 5>, tplsum>);
///   static_assert(!nontype_specialization_of<tplsum<4, 5>, tplarray>);
///   static_assert( nontype_specialization_of<tplsum<4, 5>, tplsum>);
/// @endcode
///
/// @ingroup ccutl
/// @anchor  nontype_specialization_of
template <class T, template <auto...> class Template>
concept nontype_specialization_of =
    detail_::nontype_specialization_of_::impl<T, Template>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
