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
import ccutl.nontype_pack;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/nontype_pack.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <concepts>
#include <tuple>

namespace nontype_pack_ {
using namespace ccutl;

using std::same_as;

template <auto... vs>
using ntp = nontype_pack<vs...>;

template <int a, int b>
struct sum {
  static constexpr int value = a + b;
};
} // namespace nontype_pack_

TEST_SCOPE(
    ccutl.nontype_pack,
    "constructs a nontype_pack using the values from a non-type template") {
  using namespace nontype_pack_;
  constexpr auto v0 = nontype_pack{sum<1, 2>{}};
  constexpr auto v1 = nontype_pack{ntp<'f', 'o', 'o'>{}};
  STATIC_CHECK(same_as<decltype(v0), const ntp<1, 2>>);
  STATIC_CHECK(same_as<decltype(v1), const ntp<'f', 'o', 'o'>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a nontype_pack from the nontype arguments of a specialized type") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<>::from<sum, sum<1, 2>>, ntp<1, 2>>);
  STATIC_CHECK(same_as<ntp<>::from<sum, sum<3, 4>>, ntp<3, 4>>);
};

TEST_SCOPE(
    ccutl.nontype_pack, "specializes a template with the contained args") {
  using namespace nontype_pack_;
  using pack0 = ntp<1, 15>;
  using pack1 = ntp<17, 47>;
  using std::pair;
  using std::tuple;
  STATIC_CHECK(same_as<pack0::to<sum>, sum<1, 15>>);
  STATIC_CHECK(pack0::to<sum>::value == 16);
  STATIC_CHECK(same_as<pack1::to<sum>, sum<17, 47>>);
  STATIC_CHECK(pack1::to<sum>::value == 64);
};

TEST_SCOPE(ccutl.nontype_pack, "represents the number of values in the pack") {
  using namespace nontype_pack_;
  STATIC_CHECK(ntp<>::size == 0);
  STATIC_CHECK(ntp<0>::size == 1);
  STATIC_CHECK(ntp<0, 'a'>::size == 2);
};

TEST_SCOPE(
    ccutl.nontype_pack, "represents a type_pack of the types of each value") {
  using namespace nontype_pack_;
  STATIC_CHECK(
      same_as<nontype_pack<1, 2u, '3'>::types, type_pack<int, unsigned, char>>);
};

TEST_SCOPE(ccutl.nontype_pack, "represents the type of the (n-1)th value") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<nontype_pack<1, 2u, '3'>::type_at<0>, int>);
  STATIC_CHECK(same_as<nontype_pack<1, 2u, '3'>::type_at<1>, unsigned>);
  STATIC_CHECK(same_as<nontype_pack<1, 2u, '3'>::type_at<2>, char>);
};

TEST_SCOPE(ccutl.nontype_pack, "expands to the (n-1)th packed value") {
  using namespace nontype_pack_;
  STATIC_CHECK(ntp<0>::at<0> == 0);
  STATIC_CHECK(ntp<0, 'a'>::at<0> == 0);
  STATIC_CHECK(ntp<0, 'a'>::at<1> == 'a');
  STATIC_CHECK(ntp<0, 'a', nullptr>::at<0> == 0);
  STATIC_CHECK(ntp<0, 'a', nullptr>::at<1> == 'a');
  STATIC_CHECK(ntp<0, 'a', nullptr>::at<2> == nullptr);
};

TEST_SCOPE(
    ccutl.nontype_pack, "creates a new nontype_pack with value at back") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::push_back<0>, ntp<0, 0>>);
  STATIC_CHECK(same_as<ntp<0>::push_back<'a'>, ntp<0, 'a'>>);
  STATIC_CHECK(same_as<ntp<0, 'a'>::push_back<42ul>, ntp<0, 'a', 42ul>>);
  STATIC_CHECK(
      same_as<
          ntp<0, 'a', nullptr>::push_back<42ul>, ntp<0, 'a', nullptr, 42ul>>);
};

TEST_SCOPE(
    ccutl.nontype_pack, "creates a new nontype_pack with value at front") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::push_front<0>, ntp<0, 0>>);
  STATIC_CHECK(same_as<ntp<0>::push_front<'a'>, ntp<'a', 0>>);
  STATIC_CHECK(same_as<ntp<0, 'a'>::push_front<42ul>, ntp<42ul, 0, 'a'>>);
  STATIC_CHECK(
      same_as<
          ntp<0, 'a', nullptr>::push_front<42ul>, ntp<42ul, 0, 'a', nullptr>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a new nontype_pack with the last value removed") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::pop_back<>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 0u>::pop_back<>, ntp<0>>);
  STATIC_CHECK(same_as<ntp<0u, 0>::pop_back<>, ntp<0u>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_back<>, ntp<0, 'a'>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a new nontype_pack with the last `n_removed` values removed") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::pop_back<1>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 0>::pop_back<1>, ntp<0>>);
  STATIC_CHECK(same_as<ntp<0, 0>::pop_back<2>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0u, 0>::pop_back<1>, ntp<0u>>);
  STATIC_CHECK(same_as<ntp<0u, 0>::pop_back<2>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_back<1>, ntp<0, 'a'>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_back<2>, ntp<0>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_back<3>, ntp<>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a new nontype_pack with the first value removed") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::pop_front<>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 0>::pop_front<>, ntp<0>>);
  STATIC_CHECK(same_as<ntp<0, 0u>::pop_front<>, ntp<0u>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_front<>, ntp<'a', nullptr>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a new nontype_pack with the first `n_removed` values removed") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<0>::pop_front<1>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 0>::pop_front<1>, ntp<0>>);
  STATIC_CHECK(same_as<ntp<0, 0>::pop_front<2>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 0u>::pop_front<1>, ntp<0u>>);
  STATIC_CHECK(same_as<ntp<0, 0u>::pop_front<2>, ntp<>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_front<1>, ntp<'a', nullptr>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_front<2>, ntp<nullptr>>);
  STATIC_CHECK(same_as<ntp<0, 'a', nullptr>::pop_front<3>, ntp<>>);
};

TEST_SCOPE(
    ccutl.nontype_pack,
    "creates a new nontype_pack from a [begin, end) slice") {
  using namespace nontype_pack_;
  using pack = ntp<0, 'a', 42ul, nullptr, -15, 'z'>;
  STATIC_CHECK(same_as<pack::slice<0, 6>, pack>);
  STATIC_CHECK(same_as<pack::slice<1, 6>, ntp<'a', 42ul, nullptr, -15, 'z'>>);
  STATIC_CHECK(same_as<pack::slice<0, 5>, ntp<0, 'a', 42ul, nullptr, -15>>);
  STATIC_CHECK(same_as<pack::slice<0, 4>, ntp<0, 'a', 42ul, nullptr>>);
  STATIC_CHECK(same_as<pack::slice<1, 4>, ntp<'a', 42ul, nullptr>>);
  STATIC_CHECK(same_as<pack::slice<2, 5>, ntp<42ul, nullptr, -15>>);
  STATIC_CHECK(same_as<pack::slice<3, 6>, ntp<nullptr, -15, 'z'>>);
  STATIC_CHECK(same_as<pack::slice<4, 6>, ntp<-15, 'z'>>);
  STATIC_CHECK(same_as<pack::slice<3, 5>, ntp<nullptr, -15>>);
  STATIC_CHECK(same_as<pack::slice<2, 4>, ntp<42ul, nullptr>>);
  STATIC_CHECK(same_as<pack::slice<1, 3>, ntp<'a', 42ul>>);
  STATIC_CHECK(same_as<pack::slice<0, 2>, ntp<0, 'a'>>);
  STATIC_CHECK(same_as<pack::slice<0, 1>, ntp<0>>);
  STATIC_CHECK(same_as<pack::slice<1, 2>, ntp<'a'>>);
  STATIC_CHECK(same_as<pack::slice<2, 3>, ntp<42ul>>);
  STATIC_CHECK(same_as<pack::slice<3, 4>, ntp<nullptr>>);
  STATIC_CHECK(same_as<pack::slice<4, 5>, ntp<-15>>);
  STATIC_CHECK(same_as<pack::slice<5, 6>, ntp<'z'>>);
};

TEST_SCOPE(ccutl.nontype_pack, "concatenates two nontype_packs") {
  using namespace nontype_pack_;
  STATIC_CHECK(same_as<ntp<>::concat<ntp<'a'>>, ntp<'a'>>);
  STATIC_CHECK(same_as<ntp<0>::concat<ntp<'a'>>, ntp<0, 'a'>>);
  STATIC_CHECK(same_as<ntp<0, 42ul>::concat<ntp<'a'>>, ntp<0, 42ul, 'a'>>);
  STATIC_CHECK(
      same_as<ntp<0>::concat<ntp<'a', nullptr>>, ntp<0, 'a', nullptr>>);
  STATIC_CHECK(
      same_as<
          ntp<0, 42ul>::concat<ntp<'a', nullptr>>, ntp<0, 42ul, 'a', nullptr>>);
};
