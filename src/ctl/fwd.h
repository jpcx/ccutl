#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.fwd]: shorthand for std::forward
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

#include <type_traits>

#include "ctl/rmref.h"

namespace CCUTL_NAMESPACE {

/*

note: the following was copied from the C++ standard draft GitHub sources
      https://github.com/cplusplus/draft.git 60a9591

©ISO/IEC

20.2.4  forward/move helpers [forward]

1 The library provides templated helper functions to simplify applying move
  semantics to an lvalue and to simplify the implementation of forwarding
  functions. All functions specified in this subclause are signal-safe
  (17.13.4).

  template <class T> constexpr T&& forward(remove_reference_t<T>& t) noexcept;
  template <class T> constexpr T&& forward(remove_reference_t<T>&& t) noexcept;

2   Mandates: For the second overload, is_lvalue_reference_v<T> is false.
3   Returns: static_cast<T&&>(t).

*/

/**
 * perfect forwarder for lvalues
 *
 * \anchor fwd
 * \ingroup ccutl
 */
template <class T>
constexpr T&&
fwd(rmref<T>& t) noexcept {
  return static_cast<T&&>(t);
}

/**
 * perfect forwarder for rvalues
 *
 * \anchor fwd
 * \ingroup ccutl
 */
template <class T>
constexpr T&&
fwd(rmref<T>&& t) noexcept {
  static_assert(
      !std::is_lvalue_reference_v<T>,
      "cannot instantiate an rvalue forwarder with an lvalue reference type");
  return static_cast<T&&>(t);
}

} // namespace CCUTL_NAMESPACE
