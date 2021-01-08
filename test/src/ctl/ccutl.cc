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

#include "ctl/ccutl.h"

using namespace CCUTL_NAMESPACE;

TEST("ccutl") {
#ifndef CCUTL_ARG_INCLUDED
  static_assert(false, "ccutl.arg not found");
#endif
#ifndef CCUTL_DIFFERENT_INCLUDED
  static_assert(false, "ccutl.different not found");
#endif
#ifndef CCUTL_EXISTS_INCLUDED
  static_assert(false, "ccutl.exists not found");
#endif
#ifndef CCUTL_EXISTS_CONCEPT_INCLUDED
  static_assert(false, "ccutl.exists not found");
#endif
#ifndef CCUTL_FOUND_INCLUDED
  static_assert(false, "ccutl.found not found");
#endif
#ifndef CCUTL_FOUND_IF_INCLUDED
  static_assert(false, "ccutl.found_if not found");
#endif
#ifndef CCUTL_FWD_INCLUDED
  static_assert(false, "ccutl.fwd not found");
#endif
#ifndef CCUTL_HIGHEST_INCLUDED
  static_assert(false, "ccutl.highest not found");
#endif
#ifndef CCUTL_ICMP_INCLUDED
  static_assert(false, "ccutl.icmp not found");
#endif
#ifndef CCUTL_LOWEST_INCLUDED
  static_assert(false, "ccutl.lowest not found");
#endif
#ifndef CCUTL_MV_INCLUDED
  static_assert(false, "ccutl.mv not found");
#endif
#ifndef CCUTL_RMCV_INCLUDED
  static_assert(false, "ccutl.rmcv not found");
#endif
#ifndef CCUTL_RMCVREF_INCLUDED
  static_assert(false, "ccutl.rmcvref not found");
#endif
#ifndef CCUTL_RMREF_INCLUDED
  static_assert(false, "ccutl.rmref not found");
#endif
#ifndef CCUTL_SAME_INCLUDED
  static_assert(false, "ccutl.same not found");
#endif
#ifndef CCUTL_TARG_INCLUDED
  static_assert(false, "ccutl.targ not found");
#endif
#ifndef CCUTL_TYPE_PACK_INCLUDED
  static_assert(false, "ccutl.type not found");
#endif
#ifndef CCUTL_TYPEOF_INCLUDED
  static_assert(false, "ccutl.typeof not found");
#endif
#ifndef CCUTL_TYPEOF_CONCEPT_INCLUDED
  static_assert(false, "ccutl.typeof not found");
#endif
#ifndef CCUTL_VALUE_PACK_INCLUDED
  static_assert(false, "ccutl.value not found");
#endif
};
