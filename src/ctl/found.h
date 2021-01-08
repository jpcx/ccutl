#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.found]: checks if a value is found within a range
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

#include <algorithm>

#include "ctl/fwd.h"

namespace CCUTL_NAMESPACE {

// thanks to https://en.cppreference.com/w/cpp/algorithm/ranges/find
// for the std::find documentation

/**
 * checks if a value is found within a range
 * mirrors std::ranges::find; returns boolean
 *
 * \anchor found
 * \ingroup ccutl
 */
template <
    std::input_iterator I, std::sentinel_for<I> S, class T,
    class Proj = std::identity> // clang-format off
requires std::indirect_binary_predicate<std::ranges::equal_to,
                                        std::projected<I, Proj>, T const*>
[[nodiscard]] inline constexpr bool
found(I first, S last, T const& value, Proj proj = {}) { // clang-format on
  return std::ranges::find(first, last, value, proj) != last;
}

/**
 * checks if a value is found within a range
 * mirrors std::ranges::find; returns boolean
 *
 * \anchor found
 * \ingroup ccutl
 */
template <std::ranges::input_range R, class T, class Proj = std::identity>
requires std::indirect_binary_predicate< // clang-format off
    std::ranges::equal_to, std::projected<std::ranges::iterator_t<R>, Proj>,
    T const*>
[[nodiscard]] inline constexpr bool
found(R&& r, T const& value, Proj proj = {}) { // clang-format on
  return std::ranges::find(fwd<R>(r), value, proj) != std::ranges::end(r);
}

} // namespace CCUTL_NAMESPACE
