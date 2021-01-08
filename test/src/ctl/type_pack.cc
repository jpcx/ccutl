/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

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

#include <tuple>

#include "cctest.h"
#include "ctl/type_pack.h"

using namespace CCUTL_NAMESPACE;

namespace type_pack_ {
using std::pair;
using std::same_as;
using std::tuple;

template <class... Ts>
using tp = type_pack<Ts...>;
} // namespace type_pack_

using namespace type_pack_;

TEST("ccutl.type_pack deduction") {
  constexpr auto v0 = type_pack{tuple<int, long>{}};
  constexpr auto v1 = type_pack{tp<char, char, short>{}};
  static_assert(same_as<decltype(v0), const tp<int, long>>);
  static_assert(same_as<decltype(v1), const tp<char, char, short>>);
};

TEST("ccutl.type_pack.from") {
  static_assert(same_as<tp<>::from<tuple, tuple<int, float>>, tp<int, float>>);
  static_assert(
      same_as<tp<>::from<tuple, tuple<char, u_short>>, tp<char, u_short>>);
};

TEST("ccutl.type_pack.to") {
  using pack0 = tp<int, float, long, double>;
  using pack1 = tp<int, float>;
  static_assert(same_as<pack0::to<tuple>, tuple<int, float, long, double>>);
  static_assert(same_as<pack1::to<pair>, pair<int, float>>);
};

TEST("ccutl.type_pack.size") {
  static_assert(tp<>::size == 0);
  static_assert(tp<int>::size == 1);
  static_assert(tp<int, float>::size == 2);
};

TEST("ccutl.type_pack.get") {
  static_assert(same_as<tp<int>::get<0>, int>);
  static_assert(same_as<tp<int, float>::get<0>, int>);
  static_assert(same_as<tp<int, float>::get<1>, float>);
  static_assert(same_as<tp<int, float, double>::get<0>, int>);
  static_assert(same_as<tp<int, float, double>::get<1>, float>);
  static_assert(same_as<tp<int, float, double>::get<2>, double>);
};

TEST("ccutl.type_pack.push_back") {
  static_assert(same_as<tp<int>::push_back<int>, tp<int, int>>);
  static_assert(same_as<tp<int>::push_back<float>, tp<int, float>>);
  static_assert(same_as<tp<int, float>::push_back<long>, tp<int, float, long>>);
  static_assert(same_as<
                tp<int, float, double>::push_back<long>,
                tp<int, float, double, long>>);
};

TEST("ccutl.type_pack.push_front") {
  static_assert(same_as<tp<int>::push_front<int>, tp<int, int>>);
  static_assert(same_as<tp<int>::push_front<float>, tp<float, int>>);
  static_assert(
      same_as<tp<int, float>::push_front<long>, tp<long, int, float>>);
  static_assert(same_as<
                tp<int, float, double>::push_front<long>,
                tp<long, int, float, double>>);
};

TEST("ccutl.type_pack.pop_back") {
  static_assert(same_as<tp<int>::pop_back<>, tp<>>);
  static_assert(same_as<tp<int, int>::pop_back<>, tp<int>>);
  static_assert(same_as<tp<const int, int>::pop_back<>, tp<const int>>);
  static_assert(same_as<tp<int, float, double>::pop_back<>, tp<int, float>>);

  static_assert(same_as<tp<int>::pop_back<1>, tp<>>);
  static_assert(same_as<tp<int, int>::pop_back<1>, tp<int>>);
  static_assert(same_as<tp<int, int>::pop_back<2>, tp<>>);
  static_assert(same_as<tp<const int, int>::pop_back<1>, tp<const int>>);
  static_assert(same_as<tp<const int, int>::pop_back<2>, tp<>>);
  static_assert(same_as<tp<int, float, double>::pop_back<1>, tp<int, float>>);
  static_assert(same_as<tp<int, float, double>::pop_back<2>, tp<int>>);
  static_assert(same_as<tp<int, float, double>::pop_back<3>, tp<>>);
};

TEST("ccutl.type_pack.pop_front") {
  static_assert(same_as<tp<int>::pop_front<>, tp<>>);
  static_assert(same_as<tp<int, int>::pop_front<>, tp<int>>);
  static_assert(same_as<tp<int, const int>::pop_front<>, tp<const int>>);
  static_assert(
      same_as<tp<int, float, double>::pop_front<>, tp<float, double>>);

  static_assert(same_as<tp<int>::pop_front<1>, tp<>>);
  static_assert(same_as<tp<int, int>::pop_front<1>, tp<int>>);
  static_assert(same_as<tp<int, int>::pop_front<2>, tp<>>);
  static_assert(same_as<tp<int, const int>::pop_front<1>, tp<const int>>);
  static_assert(same_as<tp<int, const int>::pop_front<2>, tp<>>);
  static_assert(
      same_as<tp<int, float, double>::pop_front<1>, tp<float, double>>);
  static_assert(same_as<tp<int, float, double>::pop_front<2>, tp<double>>);
  static_assert(same_as<tp<int, float, double>::pop_front<3>, tp<>>);
};

TEST("ccutl.type_pack.slice") {
  using pack = tp<int, float, long, double, char, const char>;
  static_assert(same_as<pack::slice<0, 6>, pack>);
  static_assert(
      same_as<pack::slice<1, 6>, tp<float, long, double, char, const char>>);
  static_assert(same_as<pack::slice<0, 5>, tp<int, float, long, double, char>>);
  static_assert(same_as<pack::slice<0, 4>, tp<int, float, long, double>>);
  static_assert(same_as<pack::slice<1, 4>, tp<float, long, double>>);
  static_assert(same_as<pack::slice<2, 5>, tp<long, double, char>>);
  static_assert(same_as<pack::slice<3, 6>, tp<double, char, const char>>);
  static_assert(same_as<pack::slice<4, 6>, tp<char, const char>>);
  static_assert(same_as<pack::slice<3, 5>, tp<double, char>>);
  static_assert(same_as<pack::slice<2, 4>, tp<long, double>>);
  static_assert(same_as<pack::slice<1, 3>, tp<float, long>>);
  static_assert(same_as<pack::slice<0, 2>, tp<int, float>>);
  static_assert(same_as<pack::slice<0, 1>, tp<int>>);
  static_assert(same_as<pack::slice<1, 2>, tp<float>>);
  static_assert(same_as<pack::slice<2, 3>, tp<long>>);
  static_assert(same_as<pack::slice<3, 4>, tp<double>>);
  static_assert(same_as<pack::slice<4, 5>, tp<char>>);
  static_assert(same_as<pack::slice<5, 6>, tp<const char>>);
};

TEST("ccutl.type_pack.concat") {
  static_assert(same_as<tp<>::concat<tp<float>>, tp<float>>);
  static_assert(same_as<tp<int>::concat<tp<float>>, tp<int, float>>);
  static_assert(
      same_as<tp<int, long>::concat<tp<float>>, tp<int, long, float>>);
  static_assert(
      same_as<tp<int>::concat<tp<float, double>>, tp<int, float, double>>);
  static_assert(same_as<
                tp<int, long>::concat<tp<float, double>>,
                tp<int, long, float, double>>);
};
