#ifndef CCUTL_MACROS_MAKE_SPECIALIZATION_OF_CONCEPT_H_INCLUDED
#define CCUTL_MACROS_MAKE_SPECIALIZATION_OF_CONCEPT_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief \link CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT
#///         CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT\endlink -
#/// Creates a concept that can detect template specializations.
#/// @file
#//                      |    |
#//    __|   __|  |   |  __|  |
#//   (     (     |   |  |    |
#//  \___| \___| \__,_| \__| _|
#//
#//  ccutl Core Utilities
#//  Copyright (C) 2020 Justin Collier <m@jpcx.dev>
#//
#//    This program is free software: you can redistribute it and/or modify
#//    it under the terms of the GNU General Public License as published by
#//    the Free Software Foundation, either version 3 of the License, or
#//    (at your option) any later version.
#//
#//    This program is distributed in the hope that it will be useful,
#//    but WITHOUT ANY WARRANTY; without even the internalied warranty of
#//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#//    GNU General Public License for more details.
#//                                                                           //
#//  You should have received a copy of the GNU General Public License       ///
#//  along with this program.  If not, see <https://www.gnu.org/licenses/>. ////
#///////////////////////////////////////////////////////////////////////////////
#
#include "ccutl/detail_/config.h"
#include "pputl/cat.h"
#include "pputl/tuple/args.h"
#
#/// Creates a concept that can detect template specializations.
#/// Different template parameter layouts require different SFINAE setups;
#/// use this macro to create a concept for a given parameter layout.
#///
#/// @ingroup ccutl
#/// @anchor  CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT
#///
#/// @param name                  - final name of the concept
#/// @param template_params_tuple - tupled template parameter types and names
#/// @param template_args_tuple   - tupled template argument invocation text
#///
#/// @note template parameter names cannot be `Template_` or `T_`
#///
#/// @code
#///   #include <vector>
#///   #include <tuple>
#///   #include <array>
#///
#///   #include <ccutl/make_specialization_of_concept.h>
#///
#///   // template<class T, template<class... Ts> class Template>
#///   // concept type_specialization_of = {sfinae};
#///   CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(
#///       type_specialization_of, (class... Ts), (Ts...));
#///
#///   constexpr bool ex0 = type_specialization_of<std::vector<int>,
#///                                               std::vector>;        // true
#///   constexpr bool ex1 = type_specialization_of<std::vector<int>,
#///                                               std::tuple>;         // false
#///
#///   // template<class T, template<class T, std::size_t sz> class Template>
#///   // concept type_size_specialization_of = {sfinae};
#///   CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(
#///       type_size_specialization_of, (class T, std::size_t sz), (T, sz));
#///
#///   constexpr bool ex2 = type_size_specialization_of<std::array<int, 3>,
#///                                                    std::array>;    // true
#///   constexpr bool ex3 = type_size_specialization_of<std::tuple<int>,
#///                                                    std::array>;    // false
#/// @endcode
#define CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(                                  \
    name, template_params_tuple, template_args_tuple)                          \
  namespace detail_ {                                                          \
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
  } /* namespace detail_ */                                                    \
                                                                               \
  template <                                                                   \
      class T_,                                                                \
      template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_>      \
  concept name =                                                               \
      detail_::PPUTL_CAT(name, _concept_)::test<Template_, T_>::result
#
#endif
