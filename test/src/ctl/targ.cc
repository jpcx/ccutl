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

#include "ctl/rmcv.h"
#include "ctl/same.h"
#include "ctl/targ.h"

using namespace CCUTL_NAMESPACE;

TEST("ccutl.targ") {
  static_assert(same<targ<0, int>, int>);
  static_assert(same<targ<0, int, float>, int>);
  static_assert(same<targ<1, int, float>, float>);
  static_assert(same<targ<0, int, float, double>, int>);
  static_assert(same<targ<1, int, float, double>, float>);
  static_assert(same<targ<2, int, float, double>, double>);
};
