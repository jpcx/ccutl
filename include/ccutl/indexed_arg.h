#ifndef CCUTL_INDEXED_ARG_H_INCLUDED
#define CCUTL_INDEXED_ARG_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link indexed_arg ccutl.indexed_arg\endlink -
/// returns the argument at index idx
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
///////////////////////////////////////////////////////////////////////////////

#ifdef CCUTL_MODULES
module;
#else
#include <type_traits>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.indexed_arg;
import std;
import ccutl.fwd;
export import std;
export import ccutl.fwd;
#else
#include "ccutl/fwd.h"
#endif

namespace ccutl::detail_::indexed_arg_ {

using ccutl::fwd;

/// @addtogroup detail_
/// \{

/*                                                        */ // clang-format off

/// lvalue forwarder for final indexed_arg result
template <std::size_t targ, std::size_t i, class First, class... Rest>
requires (targ == i) && (std::is_lvalue_reference_v<First &&>)
[[nodiscard]] inline constexpr First &
impl(First&& first, Rest &&...) noexcept {
  return fwd<First>(first);
}

/// rvalue forwarder for final indexed_arg result
template <std::size_t targ, std::size_t i, class First, class... Rest>
requires (targ == i) && (std::is_rvalue_reference_v<First &&>)
[[nodiscard]] inline constexpr First &&
impl(First&& first, Rest &&...) noexcept {
  return fwd<First>(first);
}

/// recursively pop_front arguments until incrementation is completed
template <std::size_t targ, std::size_t i, class First, class... Rest>
requires (targ != i)
[[nodiscard]] inline constexpr auto &&
impl(First &&, Rest &&... rest) noexcept {
  return impl<targ, i + 1>(fwd<Rest>(rest)...);
}

/// checks if idx is within range to be able to index Ts
template <std::size_t idx, class... Ts>
inline constexpr bool
    valid_indexable_pack = sizeof...(Ts) > 0 && idx < sizeof...(Ts);

/// \}

} // namespace indexed_arg_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/// returns the argument at index idx
///
/// @code
///   #include "ccutl/indexed_arg.h"
///   // import ccutl.indexed_arg; //
///
///   char c  = 'c';
///   auto &&x0 = ccutl::indexed_arg<0>('a', "b", c); // (char)         'a'
///   auto &&x1 = ccutl::indexed_arg<1>('a', "b", c); // (const char *) "b"
///   auto &&x2 = ccutl::indexed_arg<2>('a', "b", c); // (char &)        c
/// @endcode
///
/// @ingroup ccutl
/// @anchor  indexed_arg
template <std::size_t idx, class... Ts>
requires detail_::indexed_arg_::valid_indexable_pack<idx, Ts...>
[[nodiscard]] inline constexpr auto &&
indexed_arg(Ts &&... args) noexcept {
  return detail_::indexed_arg_::impl<idx, 0>(fwd<Ts>(args)...);
}

/*                                                        */ // clang-format on

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif