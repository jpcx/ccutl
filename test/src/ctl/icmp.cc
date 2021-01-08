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

#include <cctest.h>

#include "ctl/icmp.h"

using namespace CCUTL_NAMESPACE;

TEST("ccutl.icmp") {
  static_assert(icmp(0, 0) == std::strong_ordering::equal);
  static_assert(icmp(0, 0u) == std::strong_ordering::equal);
  static_assert(icmp(0u, 0) == std::strong_ordering::equal);
  static_assert(icmp(0u, 0u) == std::strong_ordering::equal);

  static_assert(icmp(0, 1) == std::strong_ordering::less);
  static_assert(icmp(1, 0u) == std::strong_ordering::greater);
  static_assert(icmp(0u, 1) == std::strong_ordering::less);

  static_assert(icmp(0, 1u) == std::strong_ordering::less);
  static_assert(icmp(1u, 0) == std::strong_ordering::greater);
  static_assert(icmp(1u, 1u) == std::strong_ordering::equal);

  static_assert(icmp(-1, -1) == std::strong_ordering::equal);
  static_assert(icmp(-1, 0u) == std::strong_ordering::less);
  static_assert(icmp(0u, -1) == std::strong_ordering::greater);

  static_assert(icmp(-1, 1) == std::strong_ordering::less);
  static_assert(icmp(1, -1) == std::strong_ordering::greater);
};
