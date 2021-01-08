//                                                  ccutl.icmp feature guard {{{
#ifndef CCUTL_ICMP_INCLUDED
#define CCUTL_ICMP_INCLUDED
//                                                  ccutl.icmp feature guard }}}
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include <compare>
#include <concepts>
#include <limits>
#include <type_traits>

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

//                                                             ccutl.highest {{{

//                                               ccutl.highest feature guard {{{
#ifndef CCUTL_HIGHEST_INCLUDED
#define CCUTL_HIGHEST_INCLUDED
//                                               ccutl.highest feature guard }}}

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
 *   auto x2 = ctl::highest<float>;   // 3.40282e+38
 * \endcode
 *
 * \anchor highest
 * \ingroup ccutl
 */
template <detail::highest::arithmetic Arithmetic>
requires detail::highest::has_numeric_limits_max<Arithmetic>
inline constexpr Arithmetic highest = std::numeric_limits<Arithmetic>::max();
/*                                                        */ // clang-format on

//                                               ccutl.highest version guard {{{

#define CCUTL_HIGHEST_VERSION_MAJOR 0
#define CCUTL_HIGHEST_VERSION_MINOR 3
#define CCUTL_HIGHEST_VERSION_PATCH 1

#elif CCUTL_HIGHEST_VERSION_MAJOR != 0
#error   ccutl.highest major version mismatch
#elif CCUTL_HIGHEST_VERSION_MINOR != 3
#error   ccutl.highest minor version mismatch
#elif CCUTL_HIGHEST_VERSION_PATCH != 1
#warning ccutl.highest patch version mismatch
#endif

//                                               ccutl.highest version guard }}}

//                                                             ccutl.highest }}}
//                                                               ccutl.rmref {{{

//                                                 ccutl.rmref feature guard {{{
#ifndef CCUTL_RMREF_INCLUDED
#define CCUTL_RMREF_INCLUDED
//                                                 ccutl.rmref feature guard }}}

/**
 * shorthand for std::remove_reference_t
 *
 * \anchor rmref
 * \ingroup ccutl
 */
template <class T>
using rmref = std::remove_reference_t<T>;

//                                                 ccutl.rmref version guard {{{

#define CCUTL_RMREF_VERSION_MAJOR 0
#define CCUTL_RMREF_VERSION_MINOR 3
#define CCUTL_RMREF_VERSION_PATCH 1

#elif CCUTL_RMREF_VERSION_MAJOR != 0
#error   ccutl.rmref major version mismatch
#elif CCUTL_RMREF_VERSION_MINOR != 3
#error   ccutl.rmref minor version mismatch
#elif CCUTL_RMREF_VERSION_PATCH != 1
#warning ccutl.rmref patch version mismatch
#endif

//                                                 ccutl.rmref version guard }}}

//                                                               ccutl.rmref }}}
//                                                                 ccutl.fwd {{{

//                                                   ccutl.fwd feature guard {{{
#ifndef CCUTL_FWD_INCLUDED
#define CCUTL_FWD_INCLUDED
//                                                   ccutl.fwd feature guard }}}

/*

note: the following was copied from the C++ standard draft GitHub sources
      https://github.com/cplusplus/draft.git 60a9591

©ISO/IEC

20.2.4  forward/move helpers [forward]

1 The library provides templated helper functions to simplify applying move
  semantics to an lvalue and to simplify the implementation of forwarding
  functions. All functions specified in this subclause are signal-safe
  (17.13.4).

  template <class T> constexpr T&& forward(remove_reference_t<T>& t) noexcept;
  template <class T> constexpr T&& forward(remove_reference_t<T>&& t) noexcept;

2   Mandates: For the second overload, is_lvalue_reference_v<T> is false.
3   Returns: static_cast<T&&>(t).

*/

/**
 * perfect forwarder for lvalues
 *
 * \anchor fwd
 * \ingroup ccutl
 */
template <class T>
constexpr T&&
fwd(rmref<T>& t) noexcept {
  return static_cast<T&&>(t);
}

/**
 * perfect forwarder for rvalues
 *
 * \anchor fwd
 * \ingroup ccutl
 */
template <class T>
constexpr T&&
fwd(rmref<T>&& t) noexcept {
  static_assert(
      !std::is_lvalue_reference_v<T>,
      "cannot instantiate an rvalue forwarder with an lvalue reference type");
  return static_cast<T&&>(t);
}

//                                                   ccutl.fwd version guard {{{

#define CCUTL_FWD_VERSION_MAJOR 0
#define CCUTL_FWD_VERSION_MINOR 3
#define CCUTL_FWD_VERSION_PATCH 1

#elif CCUTL_FWD_VERSION_MAJOR != 0
#error   ccutl.fwd major version mismatch
#elif CCUTL_FWD_VERSION_MINOR != 3
#error   ccutl.fwd minor version mismatch
#elif CCUTL_FWD_VERSION_PATCH != 1
#warning ccutl.fwd patch version mismatch
#endif

//                                                   ccutl.fwd version guard }}}

//                                                                 ccutl.fwd }}}

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

//                                                  ccutl.icmp version guard {{{

#define CCUTL_ICMP_VERSION_MAJOR 0
#define CCUTL_ICMP_VERSION_MINOR 3
#define CCUTL_ICMP_VERSION_PATCH 1

#elif CCUTL_ICMP_VERSION_MAJOR != 0
#error   ccutl.icmp major version mismatch
#elif CCUTL_ICMP_VERSION_MINOR != 3
#error   ccutl.icmp minor version mismatch
#elif CCUTL_ICMP_VERSION_PATCH != 1
#warning ccutl.icmp patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                  ccutl.icmp version guard }}}
