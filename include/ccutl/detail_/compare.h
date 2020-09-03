#ifndef CCUTL_DETAIL_COMPARE_H_INCLUDED
#define CCUTL_DETAIL_COMPARE_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief detail helpers for ccutl comparison functions
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
import std;
import ccutl.noref;
#else
#include <compare>
#include <concepts>

#include "ccutl/noref.h"
#endif

#include "ccutl/detail_/config.h"

namespace ccutl::detail_ {
/// @addtogroup detail_
/// \{

/// represents a type pack of signed integrals
template <class... Ts>
concept signed_integrals = (std::signed_integral<Ts> && ...);
/// represents a type pack of unsigned integrals
template <class... Ts>
concept unsigned_integrals = (std::unsigned_integral<Ts> && ...);

/// represents a type pack of same-signed integrals
template <class... Ts>
concept same_signed_integrals =
    signed_integrals<Ts...> || unsigned_integrals<Ts...>;

/// represents a type pack of differently-signed integrals
template <class... Ts>
concept differently_signed_integrals = (std::is_integral_v<Ts> && ...) &&
                                       !same_signed_integrals<Ts...>;

/// requires a type to be strongly ordered with the other, OR a differently
/// signed integral than the other
template <class L, class R>
concept strongly_comparable_with =
    std::three_way_comparable_with<noref<L>, noref<R>, std::strong_ordering> or
    differently_signed_integrals<noref<L>, noref<R>>;

/// requires a type to be strongly ordered with the other and NOT
/// differently-signed integrals
template <class L, class R>
concept trivially_strongly_comparable_with =
    strongly_comparable_with<L, R> &&
    !differently_signed_integrals<noref<L>, noref<R>>;

/// \}
} // namespace ccutl::detail_

#endif
