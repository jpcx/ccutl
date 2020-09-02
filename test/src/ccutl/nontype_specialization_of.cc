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
//                                                                            //
//  You should have received a copy of the GNU General Public License        ///
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.  ////
////////////////////////////////////////////////////////////////////////////////

#ifdef CCUTL_MODULES
#ifdef TESTCCUTL_SINGLE
import ccutl.nontype_specialization_of;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/nontype_specialization_of.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <tuple>

namespace nontype_specialization_of_ {

template <auto... vs>
struct nontype_collection0 {
  static constexpr bool data = std::tuple{vs...};
};
template <auto... vs>
struct nontype_collection1 {
  static constexpr bool data = std::tuple{vs...};
};

} // namespace nontype_specialization_of_

TEST_SCOPE(
    ccutl.nontype_specialization_of,
    "Detects template specializations for nontype-parameter templates "
    "(<auto...>)") {
  using namespace ccutl;
  using namespace nontype_specialization_of_;
  STATIC_CHECK(nontype_specialization_of<
               nontype_collection0<1, 2, 3>, nontype_collection0>);
  STATIC_CHECK(!nontype_specialization_of<
               nontype_collection0<1, 2, 3>, nontype_collection1>);
  STATIC_CHECK(!nontype_specialization_of<
               nontype_collection1<1, 2, 3>, nontype_collection0>);
  STATIC_CHECK(nontype_specialization_of<
               nontype_collection1<1, 2, 3>, nontype_collection1>);
};
