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
import ccutl.range_of;
import ccutl.streq;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/range_of.h>
#include <ccutl/streq.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string>
#include <string_view>

namespace test_streq {

template <size_t maxsz>
class char_range {
 public:
  constexpr char_range(const char *from) {
    size_t i = 0;
    for (; i < maxsz && from[i] != '\0'; ++i)
      data[i] = from[i];
    data[i] = '\0';
    len     = i + 1;
  }

  constexpr const char *
  begin() {
    return data;
  }
  constexpr const char *
  end() {
    return data + len;
  }

 private:
  char data[maxsz + 1]{};
  size_t len = 0;
};

using std::ranges::input_range;
static_assert(
    ccutl::range_of<char_range<0>, char> and input_range<char_range<0>>);
static_assert(
    ccutl::range_of<char_range<1>, char> and input_range<char_range<1>>);

template <std::same_as<const char *>... CharPtrs>
constexpr inline bool
static_cases(CharPtrs... s) {
  using ccutl::streq;
  using std::string_view;
  return streq(s...) && streq(string_view(s)...) &&
         streq(char_range<15>(s)...) && streq(s..., string_view(s)...) &&
         streq(string_view(s)..., s...) &&
         streq(s..., string_view(s)..., char_range<15>(s)...) &&
         streq(s..., char_range<15>(s)..., string_view(s)...) &&
         streq(char_range<15>(s)..., s..., string_view(s)...) &&
         streq(char_range<15>(s)..., string_view(s)..., s...) &&
         streq(string_view(s)..., s..., char_range<15>(s)...) &&
         streq(string_view(s)..., char_range<15>(s)..., s...);
}

template <std::same_as<const char *>... CharPtrs>
inline bool
dynamic_cases(CharPtrs... s) {
  using ccutl::streq;
  using std::string;
  return streq(s...) && streq(string(s)...) && streq(char_range<15>(s)...) &&
         streq(s..., string(s)...) && streq(string(s)..., s...) &&
         streq(s..., string(s)..., char_range<15>(s)...) &&
         streq(s..., char_range<15>(s)..., string(s)...) &&
         streq(char_range<15>(s)..., s..., string(s)...) &&
         streq(char_range<15>(s)..., string(s)..., s...) &&
         streq(string(s)..., s..., char_range<15>(s)...) &&
         streq(string(s)..., char_range<15>(s)..., s...);
}

} // namespace test_streq

TEST(ccutl.streq, "true if all provided static strings are equal") << [] {
  STATIC_CHECK(test_streq::static_cases(""));
  STATIC_CHECK(test_streq::static_cases("", ""));
  STATIC_CHECK(test_streq::static_cases("", "", ""));
  STATIC_CHECK(test_streq::static_cases("foo"));
  STATIC_CHECK(test_streq::static_cases("foo", "foo"));
  STATIC_CHECK(test_streq::static_cases("foo", "foo", "foo"));
  STATIC_CHECK(!test_streq::static_cases("foo", "bar"));
  STATIC_CHECK(!test_streq::static_cases("foo", "bar", "foo"));
  STATIC_CHECK(!test_streq::static_cases("foo", "foo", "bar"));
  STATIC_CHECK(!test_streq::static_cases("foo", "fo"));
  STATIC_CHECK(!test_streq::static_cases("foo", "fo", "foo"));
  STATIC_CHECK(!test_streq::static_cases("foo", "foo", "fo"));
  STATIC_CHECK(!test_streq::static_cases("fo", "foo"));
  STATIC_CHECK(!test_streq::static_cases("fo", "foo", "fo"));
  STATIC_CHECK(!test_streq::static_cases("fo", "fo", "foo"));
  STATIC_CHECK(!test_streq::static_cases("", "foo"));
  STATIC_CHECK(!test_streq::static_cases("", "foo", ""));
  STATIC_CHECK(!test_streq::static_cases("", "", "foo"));
  STATIC_CHECK(!test_streq::static_cases("foo", ""));
  STATIC_CHECK(!test_streq::static_cases("foo", "", ""));
};

TEST(ccutl.streq, "true if all provided static/dynamic strings are equal")
    << [] {
         DYNAMIC_CHECK(test_streq::dynamic_cases(""));
         DYNAMIC_CHECK(test_streq::dynamic_cases("", ""));
         DYNAMIC_CHECK(test_streq::dynamic_cases("", "", ""));
         DYNAMIC_CHECK(test_streq::dynamic_cases("foo"));
         DYNAMIC_CHECK(test_streq::dynamic_cases("foo", "foo"));
         DYNAMIC_CHECK(test_streq::dynamic_cases("foo", "foo", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "bar"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "bar", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "foo", "bar"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "fo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "fo", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "foo", "fo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("fo", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("fo", "foo", "fo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("fo", "fo", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("", "foo", ""));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("", "", "foo"));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", ""));
         DYNAMIC_CHECK(!test_streq::dynamic_cases("foo", "", ""));
         CLOSE_SCOPE;
       };
