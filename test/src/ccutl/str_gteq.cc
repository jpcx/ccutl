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
import ccutl.str_gteq;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/range_of.h>
#include <ccutl/str_gteq.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string_view>

#include "testccutl/char_range.h"

using ccutl::str_gteq;
using std::string_view;
using std::wstring_view;
using testccutl::char_range;

static constexpr bool
char_gteq_checks(const char *l, const char *r) {
  using t0 = const char *;
  using t1 = char_range<15, char, false>;
  using t2 = char_range<15, char, true>;
  using t3 = string_view;

  return true                      //
         && str_gteq(t0{l}, t0{r}) //
         && str_gteq(t0{l}, t1{r}) //
         && str_gteq(t0{l}, t2{r}) //
         && str_gteq(t0{l}, t3{r}) //
         && str_gteq(t1{l}, t0{r}) //
         && str_gteq(t1{l}, t1{r}) //
         && str_gteq(t1{l}, t2{r}) //
         && str_gteq(t1{l}, t3{r}) //
         && str_gteq(t2{l}, t0{r}) //
         && str_gteq(t2{l}, t1{r}) //
         && str_gteq(t2{l}, t2{r}) //
         && str_gteq(t2{l}, t3{r}) //
         && str_gteq(t3{l}, t0{r}) //
         && str_gteq(t3{l}, t1{r}) //
         && str_gteq(t3{l}, t2{r}) //
         && str_gteq(t3{l}, t3{r}) //
      ;
}

static constexpr bool
wchar_gteq_checks(const wchar_t *wl, const wchar_t *wr) {
  using wt0 = const wchar_t *;
  using wt1 = char_range<15, wchar_t, false>;
  using wt2 = char_range<15, wchar_t, true>;
  using wt3 = wstring_view;

  return true                          //
         && str_gteq(wt0{wl}, wt0{wr}) //
         && str_gteq(wt0{wl}, wt1{wr}) //
         && str_gteq(wt0{wl}, wt2{wr}) //
         && str_gteq(wt0{wl}, wt3{wr}) //
         && str_gteq(wt1{wl}, wt0{wr}) //
         && str_gteq(wt1{wl}, wt1{wr}) //
         && str_gteq(wt1{wl}, wt2{wr}) //
         && str_gteq(wt1{wl}, wt3{wr}) //
         && str_gteq(wt2{wl}, wt0{wr}) //
         && str_gteq(wt2{wl}, wt1{wr}) //
         && str_gteq(wt2{wl}, wt2{wr}) //
         && str_gteq(wt2{wl}, wt3{wr}) //
         && str_gteq(wt3{wl}, wt0{wr}) //
         && str_gteq(wt3{wl}, wt1{wr}) //
         && str_gteq(wt3{wl}, wt2{wr}) //
         && str_gteq(wt3{wl}, wt3{wr}) //
      ;
}

static constexpr bool
char_wchar_gteq_checks(
    const char *l, const wchar_t *wl, const char *r, const wchar_t *wr) {
  using t0  = const char *;
  using wt0 = const wchar_t *;
  using t1  = char_range<15, char, false>;
  using wt1 = char_range<15, wchar_t, false>;
  using t2  = char_range<15, char, true>;
  using wt2 = char_range<15, wchar_t, true>;
  using t3  = string_view;
  using wt3 = wstring_view;

  return true                        //
         && str_gteq(t0{l}, wt0{wr}) //
         && str_gteq(wt0{wl}, t0{r}) //
         && str_gteq(t0{l}, wt1{wr}) //
         && str_gteq(wt0{wl}, t1{r}) //
         && str_gteq(t0{l}, wt2{wr}) //
         && str_gteq(wt0{wl}, t2{r}) //
         && str_gteq(t0{l}, wt3{wr}) //
         && str_gteq(wt0{wl}, t3{r}) //
         && str_gteq(t1{l}, wt0{wr}) //
         && str_gteq(wt1{wl}, t0{r}) //
         && str_gteq(t1{l}, wt1{wr}) //
         && str_gteq(wt1{wl}, t1{r}) //
         && str_gteq(t1{l}, wt2{wr}) //
         && str_gteq(wt1{wl}, t2{r}) //
         && str_gteq(t1{l}, wt3{wr}) //
         && str_gteq(wt1{wl}, t3{r}) //
         && str_gteq(t2{l}, wt0{wr}) //
         && str_gteq(wt2{wl}, t0{r}) //
         && str_gteq(t2{l}, wt1{wr}) //
         && str_gteq(wt2{wl}, t1{r}) //
         && str_gteq(t2{l}, wt2{wr}) //
         && str_gteq(wt2{wl}, t2{r}) //
         && str_gteq(t2{l}, wt3{wr}) //
         && str_gteq(wt2{wl}, t3{r}) //
         && str_gteq(t3{l}, wt0{wr}) //
         && str_gteq(wt3{wl}, t0{r}) //
         && str_gteq(t3{l}, wt1{wr}) //
         && str_gteq(wt3{wl}, t1{r}) //
         && str_gteq(t3{l}, wt2{wr}) //
         && str_gteq(wt3{wl}, t2{r}) //
         && str_gteq(t3{l}, wt3{wr}) //
         && str_gteq(wt3{wl}, t3{r}) //
      ;
}

static constexpr char foo[4]    = {'f', 'o', 'o', '\0'};
static constexpr char bar[4]    = {'b', 'a', 'r', '\0'};
static constexpr char foobar[7] = {'f', 'o', 'o', 'b', 'a', 'r', '\0'};

static constexpr wchar_t wfoo[4]    = {'f', 'o', 'o', '\0'};
static constexpr wchar_t wbar[4]    = {'b', 'a', 'r', '\0'};
static constexpr wchar_t wfoobar[7] = {'f', 'o', 'o', 'b', 'a', 'r', '\0'};

#define CHECK_CHAR_GTEQ(expected, lstr, rstr) \
  STATIC_CHECK(char_gteq_checks(lstr, rstr) == expected)

#define CHECK_WCHAR_GTEQ(expected, lstr, rstr) \
  STATIC_CHECK(wchar_gteq_checks(w##lstr, w##rstr) == expected)

#define CHECK_CHAR_WCHAR_GTEQ(expected, lstr, rstr) \
  STATIC_CHECK(char_wchar_gteq_checks(lstr, w##lstr, rstr, w##rstr) == expected)

#define DO_GTEQ_CHECKS(type)               \
  CHECK_##type##_GTEQ(true, foo, bar);     \
  CHECK_##type##_GTEQ(true, foo, foo);     \
  CHECK_##type##_GTEQ(true, foobar, foo);  \
  CHECK_##type##_GTEQ(true, foobar, bar);  \
  CHECK_##type##_GTEQ(false, bar, foo);    \
  CHECK_##type##_GTEQ(false, foo, foobar); \
  CHECK_##type##_GTEQ(false, bar, foobar)

TEST_SCOPE(
    ccutl.str_gteq, "lexicographically compares stringlike char objects") {
  DO_GTEQ_CHECKS(CHAR);
};

TEST_SCOPE(
    ccutl.str_gteq, "lexicographically compares stringlike wchar_t objects") {
  DO_GTEQ_CHECKS(WCHAR);
};

TEST_SCOPE(
    ccutl.str_gteq,
    "lexicographically compares stringlike char and wchar_t objects") {
  DO_GTEQ_CHECKS(CHAR_WCHAR);
};
