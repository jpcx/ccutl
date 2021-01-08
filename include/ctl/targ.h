//                                                  ccutl.targ feature guard {{{
#ifndef CCUTL_TARG_INCLUDED
#define CCUTL_TARG_INCLUDED
//                                                  ccutl.targ feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.targ]: represents the passed type-template-arg by index
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

#include <cstdint>

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace targ {
/// primary template for targ_::impl
template <std::size_t, std::size_t, class...>
struct impl;
/// end of iteration; type represents first type
template <std::size_t targ, class First, class... Rest>
struct impl<targ, targ, First, Rest...> {
  using type = First;
};
/// iterates until i reaches target
template <std::size_t targ, std::size_t i, class First, class... Rest>
struct impl<targ, i, First, Rest...> {
  using type = typename impl<targ, i + 1, Rest...>::type;
};
/// helper typedef for impl::type
template <std::size_t targ, class... Pack>
using type = typename impl<targ, 0, Pack...>::type;
/// checks if idx can be used to index Ts...
template <std::size_t idx, class... Ts>
inline constexpr bool
    valid_indexable_pack = sizeof...(Ts) > 0 && idx < sizeof...(Ts);
} // namespace targ
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off

/**
 * represents the type template argument at index idx
 *
 * \code
 *   #include "ctl/targ.h"
 *   using x0 = ctl::targ<0, int, float, double>; // int
 *   using x1 = ctl::targ<1, int, float, double>; // float
 *   using x2 = ctl::targ<2, int, float, double>; // double
 * \endcode
 *
 * \anchor targ
 * \ingroup ccutl
 */
template <std::size_t idx, class... Ts>
requires detail::targ::valid_indexable_pack<idx, Ts...>
using targ = detail::targ::type<idx, Ts...>;

/*                                                        */ // clang-format on

} // namespace CCUTL_NAMESPACE

//                                                  ccutl.targ version guard {{{

#define CCUTL_TARG_VERSION_MAJOR 0
#define CCUTL_TARG_VERSION_MINOR 3
#define CCUTL_TARG_VERSION_PATCH 2

#elif CCUTL_TARG_VERSION_MAJOR != 0
#error   ccutl.targ major version mismatch
#elif CCUTL_TARG_VERSION_MINOR != 3
#error   ccutl.targ minor version mismatch
#elif CCUTL_TARG_VERSION_PATCH != 2
#warning ccutl.targ patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                  ccutl.targ version guard }}}
