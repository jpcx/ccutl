#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.lowest]: expands to the lowest value of a given arithmetic type
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

#include <concepts>
#include <limits>

#include "ctl/exists.h"

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace lowest {
/// checks if std::numeric_limits<Arithmetic>::lowest() is valid
template <class T>
concept has_numeric_limits_lowest =
    ctl::exists<std::numeric_limits, T>and requires() {
  { std::numeric_limits<T>::lowest() }
  ->std::convertible_to<T>;
};
/// naiive arithmetic concept that describes an integral or floating_point type
template <class T>
concept arithmetic = std::integral<T> || std::floating_point<T>;
} // namespace lowest
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off
/**
 * represents the lowest number possible for a given arithmetic type
 *
 * \note mirrors std::numeric_limits<T>::lowest()
 *
 * \code
 *   #include "ctl/lowest.h"
 *   auto x0 = ctl::lowest<int8_t>;  // 127
 *   auto x1 = ctl::lowest<int16_t>; // 32767
 *   auto x2 = ctl::lowest<float>;   // 3.40282e+38
 * \endcode
 *
 * \anchor lowest
 * \ingroup ccutl
 */
template <detail::lowest::arithmetic Arithmetic>
requires detail::lowest::has_numeric_limits_lowest<Arithmetic>
inline constexpr Arithmetic lowest = std::numeric_limits<Arithmetic>::lowest();
/*                                                        */ // clang-format on

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
