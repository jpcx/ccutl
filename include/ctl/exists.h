//                                                ccutl.exists feature guard {{{
#ifndef CCUTL_EXISTS_INCLUDED
#define CCUTL_EXISTS_INCLUDED
//                                                ccutl.exists feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.exists]: defines templates that are specializable by Ts...
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

//                                                        embedded libraries {{{
//                                             #include <pputl/tuple/args.h> {{{

#ifndef PPUTL_TUPLE_ARGS_H_INCLUDED
#define PPUTL_TUPLE_ARGS_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief \link PPUTL_TUPLE_ARGS PPUTL_TUPLE_ARGS\endlink -
#/// returns tuple elements as args
#/// @file
#//                          __    ___
#//                         /\ \__/\_ \
#//   _____   _____   __  __\ \ ,_\//\ \
#//  /\ '__`\/\ '__`\/\ \/\ \\ \ \/ \ \ \
#//  \ \ \_\ \ \ \_\ \ \ \_\ \\ \ \_ \_\ \_
#//   \ \ ,__/\ \ ,__/\ \____/ \ \__\/\____\
#//    \ \ \   \ \ \   \/___/   \/__/\/____/
#//     \/_/    \/_/
#//
#//  pputl Preprocessor Utilities
#//  Copyright (C) 2020, 2021 Justin Collier <m@jpcx.dev>
#//
#//	   This program is free software: you can redistribute it and/or modify
#//	   it under the terms of the GNU General Public License as published by
#//	   the Free Software Foundation, either version 3 of the License, or
#//	   (at your option) any later version.
#//
#//	   This program is distributed in the hope that it will be useful,
#//	   but WITHOUT ANY WARRANTY; without even the internalied warranty of
#//	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#//	   GNU General Public License for more details.
#//                                                                           //
#//  You should have received a copy of the GNU General Public License       ///
#//  along with this program.  If not, see <https://www.gnu.org/licenses/>. ////
#///////////////////////////////////////////////////////////////////////////////
#
#/// returns tuple elements as args
#///
#/// @ingroup tuple
#/// @anchor  PPUTL_TUPLE_ARGS
#/// @code
#///   #define TUP (3, 2, 1)
#///   PPUTL_AT(0, PPUTL_TUPLE_ARGS(TUP)) // 3
#/// @endcode
#define PPUTL_TUPLE_ARGS(tup) PPUTL_TUPLE_ARGS_RETURN tup
#
#define PPUTL_TUPLE_ARGS_RETURN(...) __VA_ARGS__
#
#endif

//                                             #include <pputl/tuple/args.h> }}}
//                                                        embedded libraries }}}

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

//                                                      ccutl.exists_concept {{{

//                                        ccutl.exists_concept feature guard {{{
#ifndef CCUTL_EXISTS_CONCEPT_INCLUDED
#define CCUTL_EXISTS_CONCEPT_INCLUDED
//                                        ccutl.exists_concept feature guard }}}

/**
 * creates a concept for specialization validity.
 * different template parameter layouts require different SFINAE setups;
 * use this macro to create a concept for a given parameter layout.
 *
 * see ccutl.exists for an example using a (class...) paramter layout.
 *
 * \param name                  - final name of the concept
 * \param template_params_tuple - tupled template parameter types and names
 * \param template_args_tuple   - tupled template argument invocation text
 *
 * \note template parameter names cannot be `Template_`
 *
 * \code
 *   #include <ctl/different.h>
 *   #include <ctl/same.h>
 *   #include <ctl/exists_concept.h>
 *
 *   // create the concept 'exists'
 *   CTL_EXISTS_CONCEPT(exists, (class... Ts), (Ts...));
 *
 *   // may only be specialized with templates that allow an int- type<int>
 *   template <template<class...> class IntableTemplate>
 *   requires exists<IntableTemplate, int>
 *   struct example;
 *
 *   template <ctl::same<int>>
 *   struct good;
 *
 *   template <ctl::different<int>>
 *   struct bad;
 *
 *   constexpr bool ex0 = exists<good, int>; // true
 *   constexpr bool ex1 = exists<bad,  int>; // false
 * \endcode
 *
 * \anchor exists_concept
 * \ingroup ccutl
 */
#define CTL_EXISTS_CONCEPT(name, template_params_tuple, template_args_tuple) \
  template <                                                                 \
      template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_,    \
      PPUTL_TUPLE_ARGS(template_params_tuple)>                               \
  concept name = requires {                                                  \
    typename Template_<PPUTL_TUPLE_ARGS(template_args_tuple)>;               \
  }

//                                        ccutl.exists_concept version guard {{{

#define CCUTL_EXISTS_CONCEPT_VERSION_MAJOR 0
#define CCUTL_EXISTS_CONCEPT_VERSION_MINOR 3
#define CCUTL_EXISTS_CONCEPT_VERSION_PATCH 0

#elif CCUTL_EXISTS_CONCEPT_VERSION_MAJOR != 0
#error   ccutl.exists_concept major version mismatch
#elif CCUTL_EXISTS_CONCEPT_VERSION_MINOR != 3
#error   ccutl.exists_concept minor version mismatch
#elif CCUTL_EXISTS_CONCEPT_VERSION_PATCH != 0
#warning ccutl.exists_concept patch version mismatch
#endif

//                                        ccutl.exists_concept version guard }}}

//                                                      ccutl.exists_concept }}}

// detail {{{
namespace detail {
namespace exists {
/// generated concept implementation for exists
CTL_EXISTS_CONCEPT(impl, (class... Ts), (Ts...));
} // namespace exists
} // namespace detail
// detail }}}

/**
 * defines templates that are specializable by Ts...
 *
 * \note may only be used with template structs, classes, and unions
 *
 * \code
 *   #include "ctl/exists.h"
 *   #include "ctl/same.h"
 *
 *   using std::tuple;
 *   template <ctl::same<int> T>
 *   struct foo {};
 *
 *   auto x0 = ctl::exists<foo, int>;      // true
 *   auto x1 = ctl::exists<foo, int, int>; // false
 *   auto x2 = ctl::exists<foo, long>;     // false
 * \endcode
 *
 * \anchor exists
 * \ingroup ccutl
 */
template <template <class...> class Template, class... Args>
concept exists = detail::exists::impl<Template, Args...>;

} // namespace CCUTL_NAMESPACE

//                                                ccutl.exists version guard {{{

#define CCUTL_EXISTS_VERSION_MAJOR 0
#define CCUTL_EXISTS_VERSION_MINOR 3
#define CCUTL_EXISTS_VERSION_PATCH 0

#elif CCUTL_EXISTS_VERSION_MAJOR != 0
#error   ccutl.exists major version mismatch
#elif CCUTL_EXISTS_VERSION_MINOR != 3
#error   ccutl.exists minor version mismatch
#elif CCUTL_EXISTS_VERSION_PATCH != 0
#warning ccutl.exists patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                ccutl.exists version guard }}}
