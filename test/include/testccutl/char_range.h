#ifndef TESTCCUTL_CHAR_RANGE_H_INCLUDED
#define TESTCCUTL_CHAR_RANGE_H_INCLUDED
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

using std::ranges::input_range;

template <size_t maxsz, class Char = char, bool range_includes_null = false>
class char_range {
 public:
  constexpr char_range(const Char *from) {
    size_t i = 0;
    for (; i < maxsz && from[i] != '\0'; ++i)
      data[i] = from[i];
    data[i] = '\0';
    len     = i;
  }

  constexpr Char *
  begin() {
    return data;
  }
  constexpr const Char *
  begin() const {
    return data;
  }
  constexpr Char *
  end() {
    if constexpr (range_includes_null)
      return data + len + 1;
    else
      return data + len;
  }
  constexpr const Char *
  end() const {
    if constexpr (range_includes_null)
      return data + len + 1;
    else
      return data + len;
  }

 private:
  Char data[maxsz + 1]{};
  size_t len = 0;
};

} // namespace testccutl

#endif
