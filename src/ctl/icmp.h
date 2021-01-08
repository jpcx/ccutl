#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.icmp]: performs a three-way comparison of two integrals of any sign
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

#include <compare>
#include <concepts>

#include "ctl/fwd.h"
#include "ctl/highest.h"

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace icmp {
/// eq comparison of signed integrals
template <std::signed_integral L, std::signed_integral R>
[[nodiscard]] inline constexpr std::strong_ordering
impl(L l, R r) {
  return l <=> r;
}
/// eq comparison of unsigned integrals
template <std::unsigned_integral L, std::unsigned_integral R>
[[nodiscard]] inline constexpr std::strong_ordering
impl(L l, R r) {
  return l <=> r;
}
/// eq comparison of signed <=> unsigned
template <std::signed_integral L, std::unsigned_integral R>
[[nodiscard]] inline constexpr std::strong_ordering
impl(L l, R r) {
  if (l < 0)
    return std::strong_ordering::less;
  else {
    if constexpr (ctl::highest<L> >= ctl::highest<R>)
      return impl(l, static_cast<L>(r));
    else
      return impl(static_cast<R>(l), r);
  }
}
/// eq comparison of unsigned <=> signed
template <std::unsigned_integral L, std::signed_integral R>
[[nodiscard]] inline constexpr std::strong_ordering
impl(L l, R r) {
  if (r < 0)
    return std::strong_ordering::greater;
  else {
    if constexpr (ctl::highest<L> < ctl::highest<R>)
      return impl(static_cast<R>(l), r);
    else
      return impl(l, static_cast<L>(r));
  }
}
} // namespace icmp
} // namespace detail
// detail }}}

/**
 * performs a three-way comparison of two integrals of any sign
 *
 * \param l  - left-hand  side
 * \param r  - right-hand side
 *
 * \returns result of strongly ordered three-way comparison
 *
 * \code
 *   #include "ctl/icmp.h"
 *
 *   ctl::icmp(0, 0);     // strong_ordering::equal
 *   ctl::icmp(0, 0u);    // strong_ordering::equal
 *   ctl::icmp(0u, 0);    // strong_ordering::equal
 *   ctl::icmp(0u, 0u);   // strong_ordering::equal
 *
 *   ctl::icmp(0, 1);     // strong_ordering::less
 *   ctl::icmp(1, 0u);    // strong_ordering::greater
 *   ctl::icmp(0u, 1);    // strong_ordering::less
 *
 *   ctl::icmp(0, 1u);    // strong_ordering::less
 *   ctl::icmp(1u, 0);    // strong_ordering::greater
 *   ctl::icmp(1u, 1u);   // strong_ordering::equal
 *
 *   ctl::icmp(-1, -1);   // strong_ordering::equal
 *   ctl::icmp(-1, 0u);   // strong_ordering::less
 *   ctl::icmp(0u, -1);   // strong_ordering::greater
 *
 *   ctl::icmp(-1, 1);    // strong_ordering::less
 *   ctl::icmp(1, -1);    // strong_ordering::greater
 * \endcode
 *
 * \anchor icmp
 * \ingroup ccutl
 */
template <std::integral L, std::integral R>
[[nodiscard]] inline constexpr std::strong_ordering
icmp(L l, R r) noexcept {
  return detail::icmp::impl(l, r);
}

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
