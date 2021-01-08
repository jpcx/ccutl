/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    Copyright (C) 2020, 2021 Justin Collier

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the internalied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include "cctest.h"

#include "ctl/arg.h"
#include "ctl/same.h"

using namespace CCUTL_NAMESPACE;

namespace arg_ {

struct noncopyable {
  noncopyable()                   = default;
  noncopyable(const noncopyable&) = delete;
  noncopyable(noncopyable&&)      = delete;
};

} // namespace arg_

TEST("ccutl.arg") {
  using arg_::noncopyable;
  int lv = 1;
  noncopyable nocopy{};
  static_assert(arg<0>(1) == 1);
  static_assert(same<decltype(arg<0>(1)), int&&>);
  static_assert(same<decltype(arg<0>(lv)), int&>);
  static_assert(same<decltype(arg<0>(nocopy)), noncopyable&>);
  static_assert(arg<0>(1, 2) == 1);
  static_assert(same<decltype(arg<0>(1, 2)), int&&>);
  static_assert(same<decltype(arg<0>(lv, lv)), int&>);
  static_assert(same<decltype(arg<0>(nocopy, nocopy)), noncopyable&>);
  static_assert(arg<1>(1, 2) == 2);
  static_assert(same<decltype(arg<1>(1, 2)), int&&>);
  static_assert(same<decltype(arg<1>(lv, lv)), int&>);
  static_assert(same<decltype(arg<1>(nocopy, nocopy)), noncopyable&>);
  static_assert(arg<0>(1, 2, 3) == 1);
  static_assert(same<decltype(arg<0>(1, 2, 3)), int&&>);
  static_assert(same<decltype(arg<0>(lv, lv, lv)), int&>);
  static_assert(same<decltype(arg<0>(nocopy, nocopy, nocopy)), noncopyable&>);
  static_assert(arg<1>(1, 2, 3) == 2);
  static_assert(same<decltype(arg<1>(1, 2, 3)), int&&>);
  static_assert(same<decltype(arg<1>(lv, lv, lv)), int&>);
  static_assert(same<decltype(arg<1>(nocopy, nocopy, nocopy)), noncopyable&>);
  static_assert(arg<2>(1, 2, 3) == 3);
  static_assert(same<decltype(arg<2>(1, 2, 3)), int&&>);
  static_assert(same<decltype(arg<2>(lv, lv, lv)), int&>);
  static_assert(same<decltype(arg<2>(nocopy, nocopy, nocopy)), noncopyable&>);
};
