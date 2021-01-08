//                                                   ccutl.arg feature guard {{{
#ifndef CCUTL_ARG_INCLUDED
#define CCUTL_ARG_INCLUDED
//                                                   ccutl.arg feature guard }}}
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include <type_traits>

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

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
#define CCUTL_RMREF_VERSION_PATCH 2

#elif CCUTL_RMREF_VERSION_MAJOR != 0
#error   ccutl.rmref major version mismatch
#elif CCUTL_RMREF_VERSION_MINOR != 3
#error   ccutl.rmref minor version mismatch
#elif CCUTL_RMREF_VERSION_PATCH != 2
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
#define CCUTL_FWD_VERSION_PATCH 2

#elif CCUTL_FWD_VERSION_MAJOR != 0
#error   ccutl.fwd major version mismatch
#elif CCUTL_FWD_VERSION_MINOR != 3
#error   ccutl.fwd minor version mismatch
#elif CCUTL_FWD_VERSION_PATCH != 2
#warning ccutl.fwd patch version mismatch
#endif

//                                                   ccutl.fwd version guard }}}

//                                                                 ccutl.fwd }}}

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

} // namespace CCUTL_NAMESPACE

//                                                   ccutl.arg version guard {{{

#define CCUTL_ARG_VERSION_MAJOR 0
#define CCUTL_ARG_VERSION_MINOR 3
#define CCUTL_ARG_VERSION_PATCH 2

#elif CCUTL_ARG_VERSION_MAJOR != 0
#error   ccutl.arg major version mismatch
#elif CCUTL_ARG_VERSION_MINOR != 3
#error   ccutl.arg minor version mismatch
#elif CCUTL_ARG_VERSION_PATCH != 2
#warning ccutl.arg patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                   ccutl.arg version guard }}}
