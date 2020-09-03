#ifndef TESTCCUTL_COMPARE_H_INCLUDED
#define TESTCCUTL_COMPARE_H_INCLUDED
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

#include <compare>

namespace testccutl {
namespace compare {

struct intholder {
  int value = 0;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
  constexpr std::strong_ordering
  operator<=>(const intholder &) const = default;
#pragma clang diagnostic pop
};
static_assert(std::three_way_comparable_with<intholder, intholder>);

} // namespace compare
} // namespace testccutl

#endif
