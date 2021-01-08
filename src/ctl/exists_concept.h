#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.exists_concept]: creates a concept for specialization validity
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

#include <pputl/tuple/args.h>

#include "src/ctl/detail/config.h"

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
