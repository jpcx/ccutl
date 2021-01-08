#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.arg]: returns the passed arg by index, preserving reference qualifier
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

#include "ctl/fwd.h"

namespace CCUTL_NAMESPACE {

/*                                                        */ // clang-format off

// detail {{{
namespace detail {
namespace arg {
/// lvalue forwarder for final arg result
template <std::size_t targ, std::size_t i, class First, class... Rest>
requires (targ == i) && (std::is_lvalue_reference_v<First &&>)
[[nodiscard]] inline constexpr First &
impl(First&& first, Rest &&...) noexcept {
  return fwd<First>(first);
}

/// rvalue forwarder for final arg result
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
} // namespace arg
} // namespace detail
// detail }}}

/**
 * returns the passed arg by index, preserving reference qualifier
 * 
 * \code
 *   #include "ctl/arg.h"
 *
 *   char c  = 'c';
 *   auto &&x0 = ctl::arg<0>('a', "b", c); // (char)        'a'
 *   auto &&x1 = ctl::arg<1>('a', "b", c); // (char const*) "b"
 *   auto &&x2 = ctl::arg<2>('a', "b", c); // (char &)       c
 * \endcode
 *
 * \anchor arg
 * \ingroup ccutl
 */
template <std::size_t idx, class... Ts>
requires detail::arg::valid_indexable_pack<idx, Ts...>
[[nodiscard]] inline constexpr auto &&
arg(Ts &&... args) noexcept {
  return detail::arg::impl<idx, 0>(fwd<Ts>(args)...);
}

/*                                                        */ // clang-format on

// vim: fmr={{{,}}} fdm=marker

} // namespace CCUTL_NAMESPACE
