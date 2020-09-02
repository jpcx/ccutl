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
import ccutl.strlen;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/strlen.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string_view>
#include <utility>

using std::move;
using std::string_view;
using std::wstring_view;

namespace strlen_ {
template <class Ch, std::size_t maxlen>
struct str_base {
  constexpr str_base(const Ch *s) {
    if constexpr (maxlen > 0)
      for (len_ = 0; s[len_] != '\0' and len_ < maxlen; ++len_)
        data_[len_] = s[len_];
    data_[len_] = '\0';
  }
  constexpr Ch *
  begin() {
    return &data_[0];
  }
  constexpr const Ch *
  begin() const {
    return &data_[0];
  }
  constexpr Ch *
  end() {
    return &data_[len_];
  }
  constexpr const Ch *
  end() const {
    return &data_[len_];
  }

 private:
  Ch data_[maxlen + 1] = {};
  std::size_t len_     = {};
};

template <std::size_t maxlen>
using str = str_base<char, maxlen>;

template <std::size_t maxlen>
using wstr = str_base<wchar_t, maxlen>;
} // namespace strlen_

using strlen_::str;
using strlen_::wstr;

using std::ranges::input_range;

static_assert(std::ranges::input_range<str<0>> and input_range<str<0>>);
static_assert(std::ranges::input_range<str<1>> and input_range<str<1>>);

static_assert(std::ranges::input_range<wstr<0>> and input_range<wstr<0>>);
static_assert(std::ranges::input_range<wstr<1>> and input_range<wstr<1>>);

constexpr inline auto cch0    = "";
constexpr inline auto cch1    = "a";
constexpr inline auto cch1_mv = "a";

constexpr inline wchar_t cwch0[1]    = {'\0'};
constexpr inline wchar_t cwch1[2]    = {'a', '\0'};
constexpr inline wchar_t cwch1_mv[2] = {'a', '\0'};

constexpr inline auto sv0    = string_view{""};
constexpr inline auto sv1    = string_view{"a"};
constexpr inline auto sv1_mv = string_view{"a"};

constexpr inline auto wsv0    = wstring_view{cwch0};
constexpr inline auto wsv1    = wstring_view{cwch1};
constexpr inline auto wsv1_mv = wstring_view{cwch1};

constexpr inline str<0> s0    = "";
constexpr inline str<1> s1    = "a";
constexpr inline str<1> s1_mv = "a";

constexpr inline wstr<0> ws0    = cwch0;
constexpr inline wstr<1> ws1    = cwch1;
constexpr inline wstr<1> ws1_mv = cwch1;

TEST(
    ccutl.strlen,
    "returns the length of any char range or null-terminated string")
    << STATIC_REQUIRE(ccutl::strlen("") == 0)
    << STATIC_REQUIRE(ccutl::strlen("a") == 1)
    << STATIC_REQUIRE(ccutl::strlen(cch0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(cch1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(cch1_mv)) == 1)
    << STATIC_REQUIRE(ccutl::strlen(cwch0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(cwch1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(cwch1_mv)) == 1)
    << STATIC_REQUIRE(ccutl::strlen(sv0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(sv1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(sv1_mv)) == 1)
    << STATIC_REQUIRE(ccutl::strlen(wsv0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(wsv1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(wsv1_mv)) == 1)
    << STATIC_REQUIRE(ccutl::strlen(s0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(s1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(s1_mv)) == 1)
    << STATIC_REQUIRE(ccutl::strlen(ws0) == 0)
    << STATIC_REQUIRE(ccutl::strlen(ws1) == 1)
    << STATIC_REQUIRE(ccutl::strlen(move(ws1_mv)) == 1);
