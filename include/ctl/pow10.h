//                                                 ccutl.pow10 feature guard {{{
#ifndef CCUTL_POW10_INCLUDED
#define CCUTL_POW10_INCLUDED
//                                                 ccutl.pow10 feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.pow10]: 10^n for unsigned integrals and floating points
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

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

/**
 * Raises 10 to an unsigned intgral power.
 *
 * @tparam Res resulting unsigned_integral type
 * @tparam Exp unsigned_integral exponent
 * @param  n power to raise
 * @return 10^n
 */
template <std::unsigned_integral Res, std::unsigned_integral Exp>
[[nodiscard]] inline constexpr Res
pow10(Exp n) noexcept {
  Res res = 1;
  for (Exp i = 0; i < n; ++i)
    res *= 10;
  return res;
}

/**
 * Raises 10 to an unsigned intgral power.
 *
 * @tparam Res resulting unsigned_integral type
 * @param  n power to raise
 * @return 10^n
 */
template <std::unsigned_integral Res>
[[nodiscard]] inline constexpr Res
pow10(Res n) noexcept {
  return pow10<Res, Res>(n);
}

/**
 * Raises 10 to a floating point power.
 *
 * @tparam Res resulting floating_point type
 * @tparam Exp unsigned_integral exponent
 * @param  n power to raise
 * @return 10^n
 */
template <std::floating_point Res, std::integral Exp>
[[nodiscard]] inline constexpr Res
pow10(Exp n) noexcept {
  Res res = 1;
  if (n >= 0) {
    for (Exp i = 0; i < n; ++i)
      res *= 10;
  } else {
    for (Exp i = 0; i > n; --i)
      res /= 10;
  }
  return res;
}

} // namespace CCUTL_NAMESPACE

//                                                 ccutl.pow10 version guard {{{

#define CCUTL_POW10_VERSION_MAJOR 0
#define CCUTL_POW10_VERSION_MINOR 4
#define CCUTL_POW10_VERSION_PATCH 0

#elif CCUTL_POW10_VERSION_MAJOR != 0
#error   ccutl.pow10 major version mismatch
#elif CCUTL_POW10_VERSION_MINOR != 4
#error   ccutl.pow10 minor version mismatch
#elif CCUTL_POW10_VERSION_PATCH != 0
#warning ccutl.pow10 patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                 ccutl.pow10 version guard }}}
