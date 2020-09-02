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
import ccutl.indexed_arg;
import ccutl.same;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/indexed_arg.h>
#include <ccutl/same.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

namespace indexed_arg_ {

struct noncopyable {
  noncopyable()                    = default;
  noncopyable(const noncopyable &) = delete;
  noncopyable(noncopyable &&)      = delete;
};

} // namespace indexed_arg_

TEST_SCOPE(ccutl.indexed_arg, "returns the argument at index idx") {
  using ccutl::indexed_arg;
  using ccutl::same;
  using indexed_arg_::noncopyable;
  int lv = 1;
  noncopyable nocopy{};
  STATIC_CHECK(indexed_arg<0>(1) == 1);
  STATIC_CHECK(same<decltype(indexed_arg<0>(1)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<0>(lv)), int &>);
  STATIC_CHECK(same<decltype(indexed_arg<0>(nocopy)), noncopyable &>);
  STATIC_CHECK(indexed_arg<0>(1, 2) == 1);
  STATIC_CHECK(same<decltype(indexed_arg<0>(1, 2)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<0>(lv, lv)), int &>);
  STATIC_CHECK(same<decltype(indexed_arg<0>(nocopy, nocopy)), noncopyable &>);
  STATIC_CHECK(indexed_arg<1>(1, 2) == 2);
  STATIC_CHECK(same<decltype(indexed_arg<1>(1, 2)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<1>(lv, lv)), int &>);
  STATIC_CHECK(same<decltype(indexed_arg<1>(nocopy, nocopy)), noncopyable &>);
  STATIC_CHECK(indexed_arg<0>(1, 2, 3) == 1);
  STATIC_CHECK(same<decltype(indexed_arg<0>(1, 2, 3)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<0>(lv, lv, lv)), int &>);
  STATIC_CHECK(
      same<decltype(indexed_arg<0>(nocopy, nocopy, nocopy)), noncopyable &>);
  STATIC_CHECK(indexed_arg<1>(1, 2, 3) == 2);
  STATIC_CHECK(same<decltype(indexed_arg<1>(1, 2, 3)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<1>(lv, lv, lv)), int &>);
  STATIC_CHECK(
      same<decltype(indexed_arg<1>(nocopy, nocopy, nocopy)), noncopyable &>);
  STATIC_CHECK(indexed_arg<2>(1, 2, 3) == 3);
  STATIC_CHECK(same<decltype(indexed_arg<2>(1, 2, 3)), int &&>);
  STATIC_CHECK(same<decltype(indexed_arg<2>(lv, lv, lv)), int &>);
  STATIC_CHECK(
      same<decltype(indexed_arg<2>(nocopy, nocopy, nocopy)), noncopyable &>);
};
