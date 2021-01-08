#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.typeof_concept]: creates a template spec-detection concept
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

#include <pputl/cat.h>
#include <pputl/tuple/args.h>

#include "src/ctl/detail/config.h"

/**
 * creates a template spececialization detection concept.
 * different template parameter layouts require different SFINAE setups;
 * use this macro to create a concept for a given parameter layout.
 *
 * see ccutl.typeof for an example using a (class...) paramter layout.
 *
 * \param name                  - final name of the concept
 * \param template_params_tuple - tupled template parameter types and names
 * \param template_args_tuple   - tupled template argument invocation text
 *
 * \note template parameter names cannot be `Template_` or `T_`
 *
 * \code
 *   #include <vector>
 *   #include <tuple>
 *   #include <array>
 *
 *   #include <ctl/typeof_concept.h>
 *
 *   using std::vector;
 *   using std::array;
 *   using std::tuple;
 *
 *   // template<class T, template<class... Ts> class Template>
 *   // concept type_typeof = {sfinae};
 *   CTL_TYPEOF_CONCEPT(type_typeof, (class... Ts), (Ts...));
 *
 *   constexpr bool ex0 = type_typeof<vector<int>, vector>; // true
 *   constexpr bool ex1 = type_typeof<vector<int>, tuple>;  // false
 *
 *   // template<class T, template<class T, std::size_t sz> class Template>
 *   // concept type_size_typeof = {sfinae};
 *   CTL_TYPEOF_CONCEPT(type_size_typeof, (class T, std::size_t sz), (T, sz));
 *
 *   constexpr bool ex2 = type_size_typeof<array<int, 3>, array>; // true
 *   constexpr bool ex3 = type_size_typeof<tuple<int>, array>;    // false
 * \endcode
 *
 * \anchor typeof_concept
 * \ingroup ccutl
 */
#define CTL_TYPEOF_CONCEPT(name, template_params_tuple, template_args_tuple)   \
  namespace detail {                                                           \
  namespace PPUTL_CAT(name, _concept_) {                                       \
                                                                               \
    template <template <PPUTL_TUPLE_ARGS(template_params_tuple)> class, class> \
    struct test {                                                              \
      static constexpr bool result = false;                                    \
    };                                                                         \
                                                                               \
    template <                                                                 \
        template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_,    \
        PPUTL_TUPLE_ARGS(template_params_tuple)>                               \
    struct test<Template_, Template_<PPUTL_TUPLE_ARGS(template_args_tuple)>> { \
      static constexpr bool result = true;                                     \
    };                                                                         \
                                                                               \
  } /* namespace PPUTL_CAT(name, _concept_) */                                 \
  } /* namespace detail */                                                     \
                                                                               \
  template <                                                                   \
      class T_,                                                                \
      template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_>      \
  concept name =                                                               \
      detail::PPUTL_CAT(name, _concept_)::test<Template_, T_>::result
