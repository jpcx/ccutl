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
//                                                                             /
//  You should have received a copy of the GNU General Public License         //
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.   ///
////////////////////////////////////////////////////////////////////////////////

#ifdef CCUTL_MODULES
#ifdef TESTCCUTL_SINGLE
import ccutl.nocv;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/nocv.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <concepts>

using namespace cctest;

template <class T>
constexpr inline auto matches =
    std::same_as<ccutl::nocv<T>, std::remove_cv_t<T>>;

TEST(ccutl.nocv, "removes the topmost cv qualifiers on a type")
    << (static_require<matches<int>>) << (static_require<matches<int &>>)
    << (static_require<matches<int &&>>) << (static_require<matches<const int>>)
    << (static_require<matches<const int &>>)
    << (static_require<matches<const int &&>>)
    << (static_require<matches<const volatile int>>)
    << (static_require<matches<const volatile int &>>)
    << (static_require<matches<const volatile int &&>>)
    << (static_require<matches<const volatile int &&>>)
    << (static_require<std::same_as<ccutl::nocv<int>, int>>)
    << (static_require<std::same_as<ccutl::nocv<int &>, int &>>)
    << (static_require<std::same_as<ccutl::nocv<const int &>, const int &>>)
    << (static_require<std::same_as<ccutl::nocv<const int>, int>>)
    << (static_require<std::same_as<ccutl::nocv<const int *>, const int *>>);
