////                                                                      c++20
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
import ccutl.specializable_with;
import ccutl.same;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/same.h>
#include <ccutl/specializable_with.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <compare>

namespace specializable_with_ {
using namespace ccutl;
template <class...>
struct any;

template <class = void>
struct anysingle_or_none;

template <same<int> a, same<float> b>
struct intfloat;
} // namespace specializable_with_

TEST(
    ccutl.specializable_with,
    "describes a template that is specializable with given type template args")
    << [] {
         using namespace specializable_with_;
         STATIC_CHECK(specializable_with<any>);
         STATIC_CHECK(specializable_with<any, void>);
         STATIC_CHECK(specializable_with<any, int>);
         STATIC_CHECK(specializable_with<any, int, double>);

         STATIC_CHECK(specializable_with<anysingle_or_none>);
         STATIC_CHECK(specializable_with<anysingle_or_none, void>);
         STATIC_CHECK(specializable_with<anysingle_or_none, int>);
         STATIC_CHECK(!specializable_with<anysingle_or_none, int, double>);

         STATIC_CHECK(specializable_with<intfloat, int, float>);
         STATIC_CHECK(!specializable_with<intfloat>);
         STATIC_CHECK(!specializable_with<intfloat, int>);
         STATIC_CHECK(!specializable_with<intfloat, float, int>);
         STATIC_CHECK(!specializable_with<intfloat, float, int, long>);
       };
