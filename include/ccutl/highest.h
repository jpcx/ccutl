#ifndef CCUTL_HIGHEST_H_INCLUDED
#define CCUTL_HIGHEST_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link highest ccutl.highest\endlink -
/// represents the highest number possible for a given arithmetic type
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
#include <limits>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.highest;
import std;
import ccutl.specializes;
export import std;
export import ccutl.specializes;
#else
#include "ccutl/specializes.h"
#endif

namespace ccutl::detail_::highest_ {

using namespace ccutl;

/// checks if std::numeric_limits<Arithmetic>::max() is valid
///
/// @ingroup detail_
template <class T>
concept has_numeric_limits_max =
    specializes<T, std::numeric_limits> and requires() {
  { std::numeric_limits<T>::max() }
  ->std::convertible_to<T>;
};

/// naiive arithmetic concept that describes an integral or floating_point type
///
/// @ingroup detail_
template <class T>
concept arithmetic = std::integral<T> || std::floating_point<T>;

} // namespace ccutl::detail_::highest_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)
/*                                                        */ // clang-format off
/// represents the highest number possible for a given arithmetic type
///
/// @note mirrors std::numeric_limits<T>::max()
///
/// @code
///   #include "ccutl/highest.h"
///   // import ccutl.highest; //
///   auto x0 = ccutl::highest<int8_t>;  // 127
///   auto x1 = ccutl::highest<int16_t>; // 32767
///   auto x2 = ccutl::highest<float>;   // 3.40282e+38
/// @endcode
///
/// @ingroup ccutl
/// @anchor  highest
template <detail_::highest_::arithmetic Arithmetic>
requires detail_::highest_::has_numeric_limits_max<Arithmetic>
inline constexpr Arithmetic highest = std::numeric_limits<Arithmetic>::max();
/*                                                        */ // clang-format on
CCUTL_END_EXPORT_NAMESPACE                                   // ccutl

#endif
