//                                               ccutl.highest feature guard {{{
#ifndef CCUTL_HIGHEST_INCLUDED
#define CCUTL_HIGHEST_INCLUDED
//                                               ccutl.highest feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.highest]: expands to the highest value of a given arithmetic type
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

#include <concepts>
#include <limits>

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace highest {
/// checks if std::numeric_limits<Arithmetic>::max() is valid
template <class T>
concept has_numeric_limits_max = requires {
  { std::numeric_limits<T>::max() }
  ->std::convertible_to<T>;
};

/// naiive arithmetic concept that describes an integral or floating_point type
template <class T>
concept arithmetic = std::integral<T> || std::floating_point<T>;
} // namespace highest
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off
/**
 * represents the highest number possible for a given arithmetic type
 *
 * \note mirrors std::numeric_limits<T>::max()
 *
 * \code
 *   #include "ctl/highest.h"
 *   auto x0 = ctl::highest<int8_t>;  // 127
 *   auto x1 = ctl::highest<int16_t>; // 32767
 *   auto x2 = ctl::highest<float>;   // 3.40283e+38
 * \endcode
 *
 * \anchor highest
 * \ingroup ccutl
 */
template <detail::highest::arithmetic Arithmetic>
requires detail::highest::has_numeric_limits_max<Arithmetic>
inline constexpr Arithmetic highest = std::numeric_limits<Arithmetic>::max();
/*                                                        */ // clang-format on

} // namespace CCUTL_NAMESPACE

//                                               ccutl.highest version guard {{{

#define CCUTL_HIGHEST_VERSION_MAJOR 0
#define CCUTL_HIGHEST_VERSION_MINOR 3
#define CCUTL_HIGHEST_VERSION_PATCH 2

#elif CCUTL_HIGHEST_VERSION_MAJOR != 0
#error   ccutl.highest major version mismatch
#elif CCUTL_HIGHEST_VERSION_MINOR != 3
#error   ccutl.highest minor version mismatch
#elif CCUTL_HIGHEST_VERSION_PATCH != 2
#warning ccutl.highest patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                               ccutl.highest version guard }}}
