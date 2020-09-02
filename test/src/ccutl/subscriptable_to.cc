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
import ccutl.subscriptable_to;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/subscriptable_to.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string>
#include <string_view>

using ccutl::subscriptable_to;

TEST(
    ccutl.subscriptable_to, "describes a T whose subscript operator returns a "
                            "type convertible to SubType")
    << STATIC_REQUIRE(subscriptable_to<char *, char>)
    << STATIC_REQUIRE(subscriptable_to<char **, char *>)
    << STATIC_REQUIRE(!subscriptable_to<char **, int *>)
    << STATIC_REQUIRE(subscriptable_to<char *, const char>)
    << STATIC_REQUIRE(subscriptable_to<char **, const char *>)
    << STATIC_REQUIRE(!subscriptable_to<const char **, char *>)
    << STATIC_REQUIRE(subscriptable_to<int *, char>)
    << STATIC_REQUIRE(subscriptable_to<const char *, const char>)
    << STATIC_REQUIRE(subscriptable_to<char *const, char>)
    << STATIC_REQUIRE(subscriptable_to<char *const, const char>)
    << STATIC_REQUIRE(subscriptable_to<int *const, char>)
    << STATIC_REQUIRE(subscriptable_to<const char *const, const char>)
    << STATIC_REQUIRE(subscriptable_to<char *const volatile, char>)
    << STATIC_REQUIRE(subscriptable_to<char *const volatile, const char>)
    << STATIC_REQUIRE(subscriptable_to<int *const volatile, char>)
    << STATIC_REQUIRE(subscriptable_to<const char *const volatile, const char>)
    << STATIC_REQUIRE(subscriptable_to<char[], char>)
    << STATIC_REQUIRE(subscriptable_to<char[], const char>)
    << STATIC_REQUIRE(subscriptable_to<int[], char>)
    << STATIC_REQUIRE(subscriptable_to<const char[], const char>)
    << STATIC_REQUIRE(subscriptable_to<std::string, int>)
    << STATIC_REQUIRE(subscriptable_to<std::string, char>)
    << STATIC_REQUIRE(subscriptable_to<std::string, const char>)
    << STATIC_REQUIRE(subscriptable_to<std::string_view, int>)
    << STATIC_REQUIRE(subscriptable_to<std::string_view, char>)
    << STATIC_REQUIRE(subscriptable_to<std::string_view, const char>);
