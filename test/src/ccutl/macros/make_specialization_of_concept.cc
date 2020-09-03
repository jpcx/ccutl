/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @file
//                      |    |
//    __|   __|  |   |  __|  |
//   (     (     |   |  |    |
//  \___| \___| \__,_| \__| _|
//
//  ccutl Core Utilities
//  Copyright (C) 2020 Justin Collier <m@jpcx.dev>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the internalied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//                                                                             /
//  You should have received a copy of the GNU General Public License         //
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.   ///
////////////////////////////////////////////////////////////////////////////////

#ifdef CCUTL_MODULES
#include <ccutl/macros/make_specialization_of_concept.h>
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/macros/make_specialization_of_concept.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <array>
#include <tuple>
#include <vector>

namespace make_specialization_of_concept_ {

template <auto... vs>
struct nontype_collection {
  static constexpr bool data = std::tuple{vs...};
};

CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(
    type_specialization_of, (class... Ts), (Ts...));

CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(
    type_size_specialization_of, (class T, std::size_t sz), (T, sz));

CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT(
    nontype_specialization_of, (auto... vs), (vs...));

} // namespace make_specialization_of_concept_

TEST(
    ccutl.macros.make_specialization_of_concept,
    "Creates a concept that can detect template specializations")
    <<
    [] {
      using namespace make_specialization_of_concept_;
      STATIC_CHECK(type_specialization_of<std::vector<int>, std::vector>);
      STATIC_CHECK(!type_specialization_of<std::vector<int>, std::tuple>);
      STATIC_CHECK(type_size_specialization_of<std::array<int, 3>, std::array>);
      STATIC_CHECK(!type_size_specialization_of<std::tuple<int>, std::array>);
      STATIC_CHECK(nontype_specialization_of<
                   nontype_collection<1, 2, 3>, nontype_collection>);
    };
