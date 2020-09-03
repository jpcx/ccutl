#ifndef CCUTL_FWD_H_INCLUDED
#define CCUTL_FWD_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link fwd ccutl.fwd\endlink -
/// perfect reference forwarder
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
module;
#else
#include <type_traits>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.fwd;
import std;
import ccutl.noref;
export import std;
export import ccutl.noref;
#else
#include "ccutl/noref.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

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

/// perfect forwarder for lvalues
///
/// @ingroup ccutl
/// @anchor  fwd_lvalues
template <class T>
constexpr T &&
fwd(noref<T> &t) noexcept {
  return static_cast<T &&>(t);
}

/// perfect forwarder for rvalues
///
/// @ingroup ccutl
/// @anchor  fwd_rvalues
template <class T>
constexpr T &&
fwd(noref<T> &&t) noexcept {
  static_assert(
      !std::is_lvalue_reference_v<T>,
      "cannot instantiate an rvalue forwarder with an lvalue reference type");
  return static_cast<T &&>(t);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
