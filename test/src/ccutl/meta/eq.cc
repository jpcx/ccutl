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
import ccutl.meta.eq;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/meta/eq.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <compare>

TEST(
    ccutl.meta.eq,
    "template equality comparison of two strongly-ordered three-way "
    "comparables or differently-signed integrals")
    << [] {
         using namespace ccutl;
         STATIC_CHECK(meta::eq<0, 0>);
         STATIC_CHECK(meta::eq<0, 0u>);
         STATIC_CHECK(meta::eq<0u, 0>);
         STATIC_CHECK(meta::eq<0u, 0u>);

         STATIC_CHECK(!meta::eq<0, 1>);
         STATIC_CHECK(!meta::eq<1, 0u>);
         STATIC_CHECK(!meta::eq<0u, 1>);

         STATIC_CHECK(!meta::eq<0, 1u>);
         STATIC_CHECK(!meta::eq<1u, 0>);
         STATIC_CHECK(meta::eq<1u, 1u>);

         STATIC_CHECK(meta::eq<-1, -1>);
         STATIC_CHECK(!meta::eq<-1, 0u>);
         STATIC_CHECK(!meta::eq<0u, -1>);

         STATIC_CHECK(!meta::eq<-1, 1>);
         STATIC_CHECK(!meta::eq<1, -1>);
       };
