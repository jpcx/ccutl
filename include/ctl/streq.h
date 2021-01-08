//                                                 ccutl.streq feature guard {{{
#ifndef CCUTL_STREQ_INCLUDED
#define CCUTL_STREQ_INCLUDED
//                                                 ccutl.streq feature guard }}}
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

//                                                 ccutl.streq version guard {{{

#define CCUTL_STREQ_VERSION_MAJOR 0
#define CCUTL_STREQ_VERSION_MINOR 3
#define CCUTL_STREQ_VERSION_PATCH 1

#elif CCUTL_STREQ_VERSION_MAJOR != 0
#error   ccutl.streq major version mismatch
#elif CCUTL_STREQ_VERSION_MINOR != 3
#error   ccutl.streq minor version mismatch
#elif CCUTL_STREQ_VERSION_PATCH != 1
#warning ccutl.streq patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                 ccutl.streq version guard }}}
