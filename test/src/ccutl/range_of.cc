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
import ccutl.range_of;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/range_of.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string>
#include <string_view>
#include <vector>

using ccutl::range_of;

TEST(ccutl.range_of, "describes a range-type T that contains Contained")
    << STATIC_REQUIRE(range_of<std::string, char>)
    << STATIC_REQUIRE(!range_of<std::string, int>)
    << STATIC_REQUIRE(range_of<std::string_view, char>)
    << STATIC_REQUIRE(!range_of<std::string_view, int>)
    << STATIC_REQUIRE(range_of<std::vector<int>, int>)
    << STATIC_REQUIRE(!range_of<std::vector<float>, int>);
