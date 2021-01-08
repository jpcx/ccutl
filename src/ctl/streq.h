#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.streq]: equality comparison of stringlike objects
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

#include <string_view>

#include "ctl/fwd.h"

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace streq {
/// defines types that may construct a string view
template <class T>
concept stringlike = requires(T&& v) {
  std::string_view{fwd<T>(v)};
};
/// compare two stringlike objects
template <stringlike A, stringlike B>
[[nodiscard]] inline constexpr bool
impl(A&& a, B&& b) noexcept {
  return std::string_view{fwd<A>(a)} == std::string_view{fwd<B>(b)};
}
/// compare more than two stringlike objects
template <stringlike First, stringlike... Rest>
requires(sizeof...(Rest) > 1) // clang-format off
[[nodiscard]] inline constexpr bool
impl(First&& first, Rest&&... rest) { // clang-format on
  return (impl(fwd<First>(first), fwd<Rest>(rest)) && ...);
}
} // namespace streq
} // namespace detail
// detail }}}

/**
 * equality comparison of stringlike objects
 *
 * \anchor streq
 * \ingroup ccutl
 */
template <detail::streq::stringlike... Strings> // clang-format off
requires(sizeof...(Strings) > 1)
[[nodiscard]] inline constexpr bool
streq(Strings&&... strings) noexcept { // clang-format on
  return detail::streq::impl(fwd<Strings>(strings)...);
};

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
