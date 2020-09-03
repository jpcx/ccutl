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
import ccutl.type_pack;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/type_pack.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <concepts>
#include <tuple>

namespace type_pack_ {
using namespace ccutl;

using std::pair;
using std::same_as;
using std::tuple;

template <class... Ts>
using tp = type_pack<Ts...>;
} // namespace type_pack_

TEST(
    ccutl.type_pack,
    "constructs a type_pack using the types from a type template")
    << [] {
         using namespace type_pack_;
         constexpr auto v0 = type_pack{tuple<int, long>{}};
         constexpr auto v1 = type_pack{tp<char, char, short>{}};
         STATIC_CHECK(same_as<decltype(v0), const tp<int, long>>);
         STATIC_CHECK(same_as<decltype(v1), const tp<char, char, short>>);
       };

TEST(
    ccutl.type_pack,
    "creates a type_pack from the type arguments of a specialized type")
    <<
    [] {
      using namespace type_pack_;
      STATIC_CHECK(
          same_as<tp<>::from<tuple, tuple<int, float>>, tp<int, float>>);
      STATIC_CHECK(
          same_as<tp<>::from<tuple, tuple<char, u_short>>, tp<char, u_short>>);
    };

TEST(ccutl.type_pack, "specializes a template with the contained args") << [] {
  using namespace type_pack_;
  using pack0 = tp<int, float, long, double>;
  using pack1 = tp<int, float>;
  STATIC_CHECK(same_as<pack0::to<tuple>, tuple<int, float, long, double>>);
  STATIC_CHECK(same_as<pack1::to<pair>, pair<int, float>>);
};

TEST(ccutl.type_pack, "represents the number of types in the pack") << [] {
  using namespace type_pack_;
  STATIC_CHECK(tp<>::size == 0);
  STATIC_CHECK(tp<int>::size == 1);
  STATIC_CHECK(tp<int, float>::size == 2);
};

TEST(ccutl.type_pack, "expands to the (n-1)th packed type") << [] {
  using namespace type_pack_;
  STATIC_CHECK(same_as<tp<int>::at<0>, int>);
  STATIC_CHECK(same_as<tp<int, float>::at<0>, int>);
  STATIC_CHECK(same_as<tp<int, float>::at<1>, float>);
  STATIC_CHECK(same_as<tp<int, float, double>::at<0>, int>);
  STATIC_CHECK(same_as<tp<int, float, double>::at<1>, float>);
  STATIC_CHECK(same_as<tp<int, float, double>::at<2>, double>);
};

TEST(ccutl.type_pack, "creates a new type_pack with T at back") << [] {
  using namespace type_pack_;
  STATIC_CHECK(same_as<tp<int>::push_back<int>, tp<int, int>>);
  STATIC_CHECK(same_as<tp<int>::push_back<float>, tp<int, float>>);
  STATIC_CHECK(same_as<tp<int, float>::push_back<long>, tp<int, float, long>>);
  STATIC_CHECK(same_as<
               tp<int, float, double>::push_back<long>,
               tp<int, float, double, long>>);
};

TEST(ccutl.type_pack, "creates a new type_pack with T at front") << [] {
  using namespace type_pack_;
  STATIC_CHECK(same_as<tp<int>::push_front<int>, tp<int, int>>);
  STATIC_CHECK(same_as<tp<int>::push_front<float>, tp<float, int>>);
  STATIC_CHECK(same_as<tp<int, float>::push_front<long>, tp<long, int, float>>);
  STATIC_CHECK(same_as<
               tp<int, float, double>::push_front<long>,
               tp<long, int, float, double>>);
};

TEST(ccutl.type_pack, "creates a new type_pack with the last type removed") <<
    [] {
      using namespace type_pack_;
      STATIC_CHECK(same_as<tp<int>::pop_back<>, tp<>>);
      STATIC_CHECK(same_as<tp<int, int>::pop_back<>, tp<int>>);
      STATIC_CHECK(same_as<tp<const int, int>::pop_back<>, tp<const int>>);
      STATIC_CHECK(same_as<tp<int, float, double>::pop_back<>, tp<int, float>>);
    };

TEST(
    ccutl.type_pack,
    "creates a new type_pack with the last `n_removed` types removed")
    << [] {
         using namespace type_pack_;
         STATIC_CHECK(same_as<tp<int>::pop_back<1>, tp<>>);
         STATIC_CHECK(same_as<tp<int, int>::pop_back<1>, tp<int>>);
         STATIC_CHECK(same_as<tp<int, int>::pop_back<2>, tp<>>);
         STATIC_CHECK(same_as<tp<const int, int>::pop_back<1>, tp<const int>>);
         STATIC_CHECK(same_as<tp<const int, int>::pop_back<2>, tp<>>);
         STATIC_CHECK(
             same_as<tp<int, float, double>::pop_back<1>, tp<int, float>>);
         STATIC_CHECK(same_as<tp<int, float, double>::pop_back<2>, tp<int>>);
         STATIC_CHECK(same_as<tp<int, float, double>::pop_back<3>, tp<>>);
       };

TEST(ccutl.type_pack, "creates a new type_pack with the first type removed")
    << [] {
         using namespace type_pack_;
         STATIC_CHECK(same_as<tp<int>::pop_front<>, tp<>>);
         STATIC_CHECK(same_as<tp<int, int>::pop_front<>, tp<int>>);
         STATIC_CHECK(same_as<tp<int, const int>::pop_front<>, tp<const int>>);
         STATIC_CHECK(
             same_as<tp<int, float, double>::pop_front<>, tp<float, double>>);
       };

TEST(
    ccutl.type_pack,
    "creates a new type_pack with the first `n_removed` types removed")
    <<
    [] {
      using namespace type_pack_;
      STATIC_CHECK(same_as<tp<int>::pop_front<1>, tp<>>);
      STATIC_CHECK(same_as<tp<int, int>::pop_front<1>, tp<int>>);
      STATIC_CHECK(same_as<tp<int, int>::pop_front<2>, tp<>>);
      STATIC_CHECK(same_as<tp<int, const int>::pop_front<1>, tp<const int>>);
      STATIC_CHECK(same_as<tp<int, const int>::pop_front<2>, tp<>>);
      STATIC_CHECK(
          same_as<tp<int, float, double>::pop_front<1>, tp<float, double>>);
      STATIC_CHECK(same_as<tp<int, float, double>::pop_front<2>, tp<double>>);
      STATIC_CHECK(same_as<tp<int, float, double>::pop_front<3>, tp<>>);
    };

TEST(ccutl.type_pack, "creates a new type_pack from a [begin, end) slice")
    << [] {
         using namespace type_pack_;
         using pack = tp<int, float, long, double, char, const char>;
         STATIC_CHECK(same_as<pack::slice<0, 6>, pack>);
         STATIC_CHECK(
             same_as<
                 pack::slice<1, 6>, tp<float, long, double, char, const char>>);
         STATIC_CHECK(
             same_as<pack::slice<0, 5>, tp<int, float, long, double, char>>);
         STATIC_CHECK(same_as<pack::slice<0, 4>, tp<int, float, long, double>>);
         STATIC_CHECK(same_as<pack::slice<1, 4>, tp<float, long, double>>);
         STATIC_CHECK(same_as<pack::slice<2, 5>, tp<long, double, char>>);
         STATIC_CHECK(same_as<pack::slice<3, 6>, tp<double, char, const char>>);
         STATIC_CHECK(same_as<pack::slice<4, 6>, tp<char, const char>>);
         STATIC_CHECK(same_as<pack::slice<3, 5>, tp<double, char>>);
         STATIC_CHECK(same_as<pack::slice<2, 4>, tp<long, double>>);
         STATIC_CHECK(same_as<pack::slice<1, 3>, tp<float, long>>);
         STATIC_CHECK(same_as<pack::slice<0, 2>, tp<int, float>>);
         STATIC_CHECK(same_as<pack::slice<0, 1>, tp<int>>);
         STATIC_CHECK(same_as<pack::slice<1, 2>, tp<float>>);
         STATIC_CHECK(same_as<pack::slice<2, 3>, tp<long>>);
         STATIC_CHECK(same_as<pack::slice<3, 4>, tp<double>>);
         STATIC_CHECK(same_as<pack::slice<4, 5>, tp<char>>);
         STATIC_CHECK(same_as<pack::slice<5, 6>, tp<const char>>);
       };

TEST(ccutl.type_pack, "concatenates two type_packs") << [] {
  using namespace type_pack_;
  STATIC_CHECK(same_as<tp<>::concat<tp<float>>, tp<float>>);
  STATIC_CHECK(same_as<tp<int>::concat<tp<float>>, tp<int, float>>);
  STATIC_CHECK(same_as<tp<int, long>::concat<tp<float>>, tp<int, long, float>>);
  STATIC_CHECK(
      same_as<tp<int>::concat<tp<float, double>>, tp<int, float, double>>);
  STATIC_CHECK(same_as<
               tp<int, long>::concat<tp<float, double>>,
               tp<int, long, float, double>>);
};
