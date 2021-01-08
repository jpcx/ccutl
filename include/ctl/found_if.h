//                                              ccutl.found_if feature guard {{{
#ifndef CCUTL_FOUND_IF_INCLUDED
#define CCUTL_FOUND_IF_INCLUDED
//                                              ccutl.found_if feature guard }}}
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

//                                              ccutl.found_if version guard {{{

#define CCUTL_FOUND_IF_VERSION_MAJOR 0
#define CCUTL_FOUND_IF_VERSION_MINOR 3
#define CCUTL_FOUND_IF_VERSION_PATCH 2

#elif CCUTL_FOUND_IF_VERSION_MAJOR != 0
#error   ccutl.found_if major version mismatch
#elif CCUTL_FOUND_IF_VERSION_MINOR != 3
#error   ccutl.found_if minor version mismatch
#elif CCUTL_FOUND_IF_VERSION_PATCH != 2
#warning ccutl.found_if patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                              ccutl.found_if version guard }}}
