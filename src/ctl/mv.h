#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.mv]: shorthand for std::move
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

#include <type_traits>

#include "ctl/rmref.h"

namespace CCUTL_NAMESPACE {

/*

note: the following was copied from the C++ standard draft GitHub sources
      https://github.com/cplusplus/draft.git 60a9591

©ISO/IEC

20.2.4  forward/move helpers [forward]

...

  template <class T> constexpr remove_reference_t<T>&& move(T&& t) noexcept;

7   Returns: static_cast<remove_reference_t<T>&&>(t).

*/

/**
 * move an rvalue
 *
 * \anchor mv
 * \ingroup ccutl
 */
template <class T>
constexpr rmref<T>&&
mv(T&& t) noexcept {
  return static_cast<rmref<T>&&>(t);
}

} // namespace CCUTL_NAMESPACE
