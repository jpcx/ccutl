#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.found_if]: checks if a predicate is true for any value in a range
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

#include <algorithm>

#include "ctl/fwd.h"

namespace CCUTL_NAMESPACE {

// thanks to https://en.cppreference.com/w/cpp/algorithm/ranges/find
// for the std::find_if documentation

/**
 * checks if a predicate is true for any value in a range
 * mirrors std::ranges::find_if
 *
 * \anchor found_if
 * \ingroup ccutl
 */
template <
    std::input_iterator I, std::sentinel_for<I> S, class Proj = std::identity,
    std::indirect_unary_predicate<std::projected<I, Proj>> Pred>
[[nodiscard]] inline constexpr bool
found_if(I first, S last, Pred pred = {}, Proj proj = {}) {
  return std::ranges::find_if(first, last, pred, proj) != last;
}

/**
 * checks if a predicate is true for any value in a range
 * mirrors std::ranges::find_if
 *
 * \anchor found_if
 * \ingroup ccutl
 */
template <
    std::ranges::input_range R, class Proj = std::identity,
    std::indirect_unary_predicate<
        std::projected<std::ranges::iterator_t<R>, Proj>>
        Pred>
[[nodiscard]] inline constexpr bool
found_if(R&& r, Pred pred = {}, Proj proj = {}) {
  return std::ranges::find_if(fwd<R>(r), pred, proj) != std::ranges::end(r);
}

} // namespace CCUTL_NAMESPACE
