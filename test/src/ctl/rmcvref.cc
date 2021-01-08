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
    along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "cctest.h"

#include "ctl/rmcvref.h"

using namespace CCUTL_NAMESPACE;

template <class T>
static constexpr bool matches =
    std::is_same_v<std::remove_cvref_t<T>, rmcvref<T>>;

TEST("ccutl.rmcvref") {
  static_assert(matches<int>);
  static_assert(matches<int const>);
  static_assert(matches<int&>);
  static_assert(matches<int&&>);
  static_assert(matches<int const&>);
  static_assert(matches<int const&&>);
  static_assert(matches<int volatile>);
  static_assert(matches<int volatile&>);
  static_assert(matches<int volatile&&>);
  static_assert(matches<int volatile const&>);
  static_assert(matches<int volatile const&&>);
};
