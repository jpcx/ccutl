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
import ccutl.same;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/same.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

TEST(ccutl.indexed_type, "represents the type template argument at index idx")
    << STATIC_REQUIRE(ccutl::same<ccutl::indexed_type<0, int>, int>)
    << STATIC_REQUIRE(ccutl::same<ccutl::indexed_type<0, int, float>, int>)
    << STATIC_REQUIRE(ccutl::same<ccutl::indexed_type<1, int, float>, float>)
    << STATIC_REQUIRE(
           ccutl::same<ccutl::indexed_type<0, int, float, double>, int>)
    << STATIC_REQUIRE(
           ccutl::same<ccutl::indexed_type<1, int, float, double>, float>)
    << STATIC_REQUIRE(
           ccutl::same<ccutl::indexed_type<2, int, float, double>, double>);
