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
import ccutl.boolean_testable;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/boolean_testable.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <bitset>
#include <type_traits>

TEST(
    ccutl.boolean_testable,
    "describes a bool-convertible B that is capable of usual logic operations")
    << [] {
         using ccutl::boolean_testable;
         STATIC_CHECK(boolean_testable<bool>);
         STATIC_CHECK(!boolean_testable<void>);
         STATIC_CHECK(boolean_testable<std::true_type>);
         STATIC_CHECK(boolean_testable<std::bitset<0>::reference>);
         STATIC_CHECK(boolean_testable<int *>);
       };
