/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
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
#ifdef TESTCCUTL_SINGLE
import ccutl.highest;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/highest.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <cmath>
#include <limits>

template <class T>
inline constexpr auto integral_matches_limits = ccutl::highest<T> ==
                                                std::numeric_limits<T>::max();

template <class T>
inline auto floating_matches_limits =
    !std::islessgreater(ccutl::highest<T>, std::numeric_limits<T>::max());

TEST(
    ccutl.highest,
    "represents the highest number possible for a given integral type")
    << STATIC_REQUIRE(integral_matches_limits<int>)
    << STATIC_REQUIRE(integral_matches_limits<short>)
    << STATIC_REQUIRE(integral_matches_limits<long>)
    << STATIC_REQUIRE(integral_matches_limits<long long>)
    << STATIC_REQUIRE(integral_matches_limits<unsigned int>)
    << STATIC_REQUIRE(integral_matches_limits<unsigned short>)
    << STATIC_REQUIRE(integral_matches_limits<unsigned long>)
    << STATIC_REQUIRE(integral_matches_limits<unsigned long long>);

TEST(
    ccutl.highest,
    "represents the highest number possible for a given floating point type")
    << DYNAMIC_REQUIRE(floating_matches_limits<float>)
    << DYNAMIC_REQUIRE(floating_matches_limits<double>)
    << DYNAMIC_REQUIRE(floating_matches_limits<long double>);
