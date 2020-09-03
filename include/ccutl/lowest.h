#ifndef CCUTL_LOWEST_H_INCLUDED
#define CCUTL_LOWEST_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link lowest ccutl.lowest\endlink -
/// represents the lowest number possible for a given arithmetic type
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
export module ccutl.lowest;
import std;
import ccutl.specializes;
export import std;
export import ccutl.specializes;
#else
#include "ccutl/specializes.h"
#endif

namespace ccutl::detail_::lowest_ {

using namespace ccutl;

/// @addtogroup detail_
/// \{

/// checks if std::numeric_limits<T>::max() is well-formed
template <class T>
concept has_numeric_limits_lowest =
    specializes<T, std::numeric_limits> &&requires() {
  { std::numeric_limits<T>::lowest() }
  ->std::convertible_to<T>;
};

/// naiive arithmetic concept that describes an integral or floating_point type
template <class T>
concept arithmetic = std::integral<T> || std::floating_point<T>;

/// \}

} // namespace ccutl::detail_::lowest_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/*                                                        */ // clang-format off
/// represents the lowest number possible for a given arithmetic type
///
/// @note mirrors std::numeric_limits<T>::lowest()
///
/// @code
///   #include "ccutl/lowest.h"
///   // import ccutl.lowest; //
///   auto x0 = ccutl::lowest<int8_t>;  // -128
///   auto x1 = ccutl::lowest<int16_t>; // -32768
///   auto x2 = ccutl::lowest<float>;   // -3.40282e+38
/// @endcode
///
/// @ingroup ccutl
/// @anchor  lowest
template <detail_::lowest_::arithmetic Arithmetic>
requires detail_::lowest_::has_numeric_limits_lowest<Arithmetic>
inline constexpr Arithmetic lowest = std::numeric_limits<Arithmetic>::lowest();
/*                                                        */ // clang-format on
CCUTL_END_EXPORT_NAMESPACE                                   // ccutl

#endif
