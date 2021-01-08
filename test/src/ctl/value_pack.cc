/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.value_pack]: A transformable template nontype arg container
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

#include "ctl/value_pack.h"

#include <cctest.h>

#include <concepts>
#include <tuple>

using namespace CCUTL_NAMESPACE;

namespace value_pack_ {

using std::same_as;

template <auto... vs>
using ntp = value_pack<vs...>;

template <int a, int b>
struct sum {
  static constexpr int value = a + b;
};
} // namespace value_pack_

using namespace value_pack_;

TEST("ccutl.value_pack deduction") {
  constexpr auto v0 = value_pack{sum<1, 2>{}};
  constexpr auto v1 = value_pack{ntp<'f', 'o', 'o'>{}};
  static_assert(same_as<decltype(v0), const ntp<1, 2>>);
  static_assert(same_as<decltype(v1), const ntp<'f', 'o', 'o'>>);
};

TEST("ccutl.value_pack.from") {
  static_assert(same_as<ntp<>::from<sum, sum<1, 2>>, ntp<1, 2>>);
  static_assert(same_as<ntp<>::from<sum, sum<3, 4>>, ntp<3, 4>>);
};

TEST("ccutl.value_pack.to") {
  using pack0 = ntp<1, 15>;
  using pack1 = ntp<17, 47>;
  using std::pair;
  using std::tuple;
  static_assert(same_as<pack0::to<sum>, sum<1, 15>>);
  static_assert(pack0::to<sum>::value == 16);
  static_assert(same_as<pack1::to<sum>, sum<17, 47>>);
  static_assert(pack1::to<sum>::value == 64);
};

TEST("ccutl.value_pack.size") {
  static_assert(ntp<>::size == 0);
  static_assert(ntp<0>::size == 1);
  static_assert(ntp<0, 'a'>::size == 2);
};

TEST("ccutl.value_pack.types") {
  static_assert(
      same_as<value_pack<1, 2u, '3'>::types, type_pack<int, unsigned, char>>);
};

TEST("ccutl.value_pack.get_type") {
  static_assert(same_as<value_pack<1, 2u, '3'>::get_type<0>, int>);
  static_assert(same_as<value_pack<1, 2u, '3'>::get_type<1>, unsigned>);
  static_assert(same_as<value_pack<1, 2u, '3'>::get_type<2>, char>);
};

TEST("ccutl.value_pack.get") {
  static_assert(ntp<0>::get<0> == 0);
  static_assert(ntp<0, 'a'>::get<0> == 0);
  static_assert(ntp<0, 'a'>::get<1> == 'a');
  static_assert(ntp<0, 'a', nullptr>::get<0> == 0);
  static_assert(ntp<0, 'a', nullptr>::get<1> == 'a');
  static_assert(ntp<0, 'a', nullptr>::get<2> == nullptr);
};

TEST("ccutl.value_pack.push_back") {
  static_assert(same_as<ntp<0>::push_back<0>, ntp<0, 0>>);
  static_assert(same_as<ntp<0>::push_back<'a'>, ntp<0, 'a'>>);
  static_assert(same_as<ntp<0, 'a'>::push_back<42ul>, ntp<0, 'a', 42ul>>);
  static_assert(
      same_as<
          ntp<0, 'a', nullptr>::push_back<42ul>, ntp<0, 'a', nullptr, 42ul>>);
};

TEST("ccutl.value_pack.push_front") {
  static_assert(same_as<ntp<0>::push_front<0>, ntp<0, 0>>);
  static_assert(same_as<ntp<0>::push_front<'a'>, ntp<'a', 0>>);
  static_assert(same_as<ntp<0, 'a'>::push_front<42ul>, ntp<42ul, 0, 'a'>>);
  static_assert(
      same_as<
          ntp<0, 'a', nullptr>::push_front<42ul>, ntp<42ul, 0, 'a', nullptr>>);
};

TEST("ccutl.value_pack.pop_back") {
  static_assert(same_as<ntp<0>::pop_back<>, ntp<>>);
  static_assert(same_as<ntp<0, 0u>::pop_back<>, ntp<0>>);
  static_assert(same_as<ntp<0u, 0>::pop_back<>, ntp<0u>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_back<>, ntp<0, 'a'>>);

  static_assert(same_as<ntp<0>::pop_back<1>, ntp<>>);
  static_assert(same_as<ntp<0, 0>::pop_back<1>, ntp<0>>);
  static_assert(same_as<ntp<0, 0>::pop_back<2>, ntp<>>);
  static_assert(same_as<ntp<0u, 0>::pop_back<1>, ntp<0u>>);
  static_assert(same_as<ntp<0u, 0>::pop_back<2>, ntp<>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_back<1>, ntp<0, 'a'>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_back<2>, ntp<0>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_back<3>, ntp<>>);
};

TEST("ccutl.value_pack.pop_front") {
  static_assert(same_as<ntp<0>::pop_front<>, ntp<>>);
  static_assert(same_as<ntp<0, 0>::pop_front<>, ntp<0>>);
  static_assert(same_as<ntp<0, 0u>::pop_front<>, ntp<0u>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_front<>, ntp<'a', nullptr>>);

  static_assert(same_as<ntp<0>::pop_front<1>, ntp<>>);
  static_assert(same_as<ntp<0, 0>::pop_front<1>, ntp<0>>);
  static_assert(same_as<ntp<0, 0>::pop_front<2>, ntp<>>);
  static_assert(same_as<ntp<0, 0u>::pop_front<1>, ntp<0u>>);
  static_assert(same_as<ntp<0, 0u>::pop_front<2>, ntp<>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_front<1>, ntp<'a', nullptr>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_front<2>, ntp<nullptr>>);
  static_assert(same_as<ntp<0, 'a', nullptr>::pop_front<3>, ntp<>>);
};

TEST("ccutl.value_pack.slice") {
  using pack = ntp<0, 'a', 42ul, nullptr, -15, 'z'>;
  static_assert(same_as<pack::slice<0, 6>, pack>);
  static_assert(same_as<pack::slice<1, 6>, ntp<'a', 42ul, nullptr, -15, 'z'>>);
  static_assert(same_as<pack::slice<0, 5>, ntp<0, 'a', 42ul, nullptr, -15>>);
  static_assert(same_as<pack::slice<0, 4>, ntp<0, 'a', 42ul, nullptr>>);
  static_assert(same_as<pack::slice<1, 4>, ntp<'a', 42ul, nullptr>>);
  static_assert(same_as<pack::slice<2, 5>, ntp<42ul, nullptr, -15>>);
  static_assert(same_as<pack::slice<3, 6>, ntp<nullptr, -15, 'z'>>);
  static_assert(same_as<pack::slice<4, 6>, ntp<-15, 'z'>>);
  static_assert(same_as<pack::slice<3, 5>, ntp<nullptr, -15>>);
  static_assert(same_as<pack::slice<2, 4>, ntp<42ul, nullptr>>);
  static_assert(same_as<pack::slice<1, 3>, ntp<'a', 42ul>>);
  static_assert(same_as<pack::slice<0, 2>, ntp<0, 'a'>>);
  static_assert(same_as<pack::slice<0, 1>, ntp<0>>);
  static_assert(same_as<pack::slice<1, 2>, ntp<'a'>>);
  static_assert(same_as<pack::slice<2, 3>, ntp<42ul>>);
  static_assert(same_as<pack::slice<3, 4>, ntp<nullptr>>);
  static_assert(same_as<pack::slice<4, 5>, ntp<-15>>);
  static_assert(same_as<pack::slice<5, 6>, ntp<'z'>>);
};

TEST("ccutl.value_pack.concat") {
  static_assert(same_as<ntp<>::concat<ntp<'a'>>, ntp<'a'>>);
  static_assert(same_as<ntp<0>::concat<ntp<'a'>>, ntp<0, 'a'>>);
  static_assert(same_as<ntp<0, 42ul>::concat<ntp<'a'>>, ntp<0, 42ul, 'a'>>);
  static_assert(
      same_as<ntp<0>::concat<ntp<'a', nullptr>>, ntp<0, 'a', nullptr>>);
  static_assert(
      same_as<
          ntp<0, 42ul>::concat<ntp<'a', nullptr>>, ntp<0, 42ul, 'a', nullptr>>);
};
