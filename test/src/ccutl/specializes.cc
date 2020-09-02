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
import ccutl.different;
import ccutl.same;
import ccutl.specializes;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/different.h>
#include <ccutl/same.h>
#include <ccutl/specializes.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

namespace specializable_with_types {

template <ccutl::same<int>>
struct only_int;

template <ccutl::different<int>>
struct anything_but_int;

} // namespace specializable_with_types

using namespace specializable_with_types;
using ccutl::specializes;

TEST(
    ccutl.specializes,
    "requires that a type may be used to specialize a given template")
    << STATIC_REQUIRE(specializes<int, only_int>)
    << STATIC_REQUIRE(specializes<float, anything_but_int>)
    << STATIC_REQUIRE(!specializes<float, only_int>)
    << STATIC_REQUIRE(!specializes<int, anything_but_int>);
