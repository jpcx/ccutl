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
import ccutl.str_eq;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/range_of.h>
#include <ccutl/str_eq.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string_view>

#include "testccutl/char_range.h"

using namespace cctest;

using ccutl::str_eq;
using std::string_view;
using std::wstring_view;
using testccutl::char_range;

static constexpr char foo[4]    = {'f', 'o', 'o', '\0'};
static constexpr char bar[4]    = {'b', 'a', 'r', '\0'};
static constexpr char foobar[7] = {'f', 'o', 'o', 'b', 'a', 'r', '\0'};

static constexpr wchar_t wfoo[4]    = {'f', 'o', 'o', '\0'};
static constexpr wchar_t wbar[4]    = {'b', 'a', 'r', '\0'};
static constexpr wchar_t wfoobar[7] = {'f', 'o', 'o', 'b', 'a', 'r', '\0'};

// clang-format off
#define REQUIRE_EQ(s)                                                                                        \
  << (static_require<str_eq(s)>)                                                                             \
  << (static_require<str_eq(s, s)>)                                                                          \
  << (static_require<str_eq(s, #s)>)                                                                         \
  << (static_require<str_eq(s, w##s)>)                                                                       \
  << (static_require<str_eq(s, string_view{s})>)                                                             \
  << (static_require<str_eq(s, wstring_view{w##s})>)                                                         \
  << (static_require<str_eq(s, char_range<15, char, false>{s})>)                                             \
  << (static_require<str_eq(s, char_range<15, char, true>{s})>)                                              \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s})>)                                       \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s})>)                                        \
  << (static_require<str_eq(#s, s)>)                                                                         \
  << (static_require<str_eq(#s, #s)>)                                                                        \
  << (static_require<str_eq(#s, w##s)>)                                                                      \
  << (static_require<str_eq(#s, string_view{s})>)                                                            \
  << (static_require<str_eq(#s, wstring_view{w##s})>)                                                        \
  << (static_require<str_eq(#s, char_range<15, char, false>{s})>)                                            \
  << (static_require<str_eq(#s, char_range<15, char, true>{s})>)                                             \
  << (static_require<str_eq(#s, char_range<15, wchar_t, false>{w##s})>)                                      \
  << (static_require<str_eq(#s, char_range<15, wchar_t, true>{w##s})>)                                       \
  << (static_require<str_eq(w##s, s)>)                                                                       \
  << (static_require<str_eq(w##s, #s)>)                                                                      \
  << (static_require<str_eq(w##s, w##s)>)                                                                    \
  << (static_require<str_eq(w##s, string_view{s})>)                                                          \
  << (static_require<str_eq(w##s, wstring_view{w##s})>)                                                      \
  << (static_require<str_eq(w##s, char_range<15, char, false>{s})>)                                          \
  << (static_require<str_eq(w##s, char_range<15, char, true>{s})>)                                           \
  << (static_require<str_eq(w##s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<str_eq(w##s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<str_eq(string_view{s}, s)>)                                                             \
  << (static_require<str_eq(string_view{s}, #s)>)                                                            \
  << (static_require<str_eq(string_view{s}, w##s)>)                                                          \
  << (static_require<str_eq(string_view{s}, string_view{s})>)                                                \
  << (static_require<str_eq(string_view{s}, wstring_view{w##s})>)                                            \
  << (static_require<str_eq(string_view{s}, char_range<15, char, false>{s})>)                                \
  << (static_require<str_eq(string_view{s}, char_range<15, char, true>{s})>)                                 \
  << (static_require<str_eq(string_view{s}, char_range<15, wchar_t, false>{w##s})>)                          \
  << (static_require<str_eq(string_view{s}, char_range<15, wchar_t, true>{w##s})>)                           \
  << (static_require<str_eq(wstring_view{w##s}, s)>)                                                         \
  << (static_require<str_eq(wstring_view{w##s}, #s)>)                                                        \
  << (static_require<str_eq(wstring_view{w##s}, w##s)>)                                                      \
  << (static_require<str_eq(wstring_view{w##s}, string_view{s})>)                                            \
  << (static_require<str_eq(wstring_view{w##s}, wstring_view{w##s})>)                                        \
  << (static_require<str_eq(wstring_view{w##s}, char_range<15, char, false>{s})>)                            \
  << (static_require<str_eq(wstring_view{w##s}, char_range<15, char, true>{s})>)                             \
  << (static_require<str_eq(wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                      \
  << (static_require<str_eq(wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                       \
  << (static_require<str_eq(char_range<15, char, false>{s}, s)>)                                             \
  << (static_require<str_eq(char_range<15, char, false>{s}, #s)>)                                            \
  << (static_require<str_eq(char_range<15, char, false>{s}, w##s)>)                                          \
  << (static_require<str_eq(char_range<15, char, false>{s}, string_view{s})>)                                \
  << (static_require<str_eq(char_range<15, char, false>{s}, wstring_view{w##s})>)                            \
  << (static_require<str_eq(char_range<15, char, false>{s}, char_range<15, char, false>{s})>)                \
  << (static_require<str_eq(char_range<15, char, false>{s}, char_range<15, char, true>{s})>)                 \
  << (static_require<str_eq(char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)          \
  << (static_require<str_eq(char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)           \
  << (static_require<str_eq(char_range<15, char, true>{s}, s)>)                                              \
  << (static_require<str_eq(char_range<15, char, true>{s}, #s)>)                                             \
  << (static_require<str_eq(char_range<15, char, true>{s}, w##s)>)                                           \
  << (static_require<str_eq(char_range<15, char, true>{s}, string_view{s})>)                                 \
  << (static_require<str_eq(char_range<15, char, true>{s}, wstring_view{w##s})>)                             \
  << (static_require<str_eq(char_range<15, char, true>{s}, char_range<15, char, false>{s})>)                 \
  << (static_require<str_eq(char_range<15, char, true>{s}, char_range<15, char, true>{s})>)                  \
  << (static_require<str_eq(char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)           \
  << (static_require<str_eq(char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)            \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, s)>)                                       \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, #s)>)                                      \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, w##s)>)                                    \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, string_view{s})>)                          \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                      \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)          \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)           \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>)    \
  << (static_require<str_eq(char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)     \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, s)>)                                        \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, #s)>)                                       \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, w##s)>)                                     \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, string_view{s})>)                           \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                       \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)           \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)            \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)     \
  << (static_require<str_eq(char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)      \
                                                                                                             \
  << (static_require<str_eq(s, s, s)>)                                                                       \
  << (static_require<str_eq(s, s, #s)>)                                                                      \
  << (static_require<str_eq(s, s, w##s)>)                                                                    \
  << (static_require<str_eq(s, s, string_view{s})>)                                                          \
  << (static_require<str_eq(s, s, wstring_view{w##s})>)                                                      \
  << (static_require<str_eq(s, s, char_range<15, char, false>{s})>)                                          \
  << (static_require<str_eq(s, s, char_range<15, char, true>{s})>)                                           \
  << (static_require<str_eq(s, s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<str_eq(s, s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<str_eq(s, #s, s)>)                                                                      \
  << (static_require<str_eq(s, #s, #s)>)                                                                     \
  << (static_require<str_eq(s, #s, w##s)>)                                                                   \
  << (static_require<str_eq(s, #s, string_view{s})>)                                                         \
  << (static_require<str_eq(s, #s, wstring_view{w##s})>)                                                     \
  << (static_require<str_eq(s, #s, char_range<15, char, false>{s})>)                                         \
  << (static_require<str_eq(s, #s, char_range<15, char, true>{s})>)                                          \
  << (static_require<str_eq(s, #s, char_range<15, wchar_t, false>{w##s})>)                                   \
  << (static_require<str_eq(s, #s, char_range<15, wchar_t, true>{w##s})>)                                    \
  << (static_require<str_eq(s, w##s, s)>)                                                                    \
  << (static_require<str_eq(s, w##s, #s)>)                                                                   \
  << (static_require<str_eq(s, w##s, w##s)>)                                                                 \
  << (static_require<str_eq(s, w##s, string_view{s})>)                                                       \
  << (static_require<str_eq(s, w##s, wstring_view{w##s})>)                                                   \
  << (static_require<str_eq(s, w##s, char_range<15, char, false>{s})>)                                       \
  << (static_require<str_eq(s, w##s, char_range<15, char, true>{s})>)                                        \
  << (static_require<str_eq(s, w##s, char_range<15, wchar_t, false>{w##s})>)                                 \
  << (static_require<str_eq(s, w##s, char_range<15, wchar_t, true>{w##s})>)                                  \
  << (static_require<str_eq(s, string_view{s}, s)>)                                                          \
  << (static_require<str_eq(s, string_view{s}, #s)>)                                                         \
  << (static_require<str_eq(s, string_view{s}, w##s)>)                                                       \
  << (static_require<str_eq(s, string_view{s}, string_view{s})>)                                             \
  << (static_require<str_eq(s, string_view{s}, wstring_view{w##s})>)                                         \
  << (static_require<str_eq(s, string_view{s}, char_range<15, char, false>{s})>)                             \
  << (static_require<str_eq(s, string_view{s}, char_range<15, char, true>{s})>)                              \
  << (static_require<str_eq(s, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                       \
  << (static_require<str_eq(s, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                        \
  << (static_require<str_eq(s, wstring_view{w##s}, s)>)                                                      \
  << (static_require<str_eq(s, wstring_view{w##s}, #s)>)                                                     \
  << (static_require<str_eq(s, wstring_view{w##s}, w##s)>)                                                   \
  << (static_require<str_eq(s, wstring_view{w##s}, string_view{s})>)                                         \
  << (static_require<str_eq(s, wstring_view{w##s}, wstring_view{w##s})>)                                     \
  << (static_require<str_eq(s, wstring_view{w##s}, char_range<15, char, false>{s})>)                         \
  << (static_require<str_eq(s, wstring_view{w##s}, char_range<15, char, true>{s})>)                          \
  << (static_require<str_eq(s, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                   \
  << (static_require<str_eq(s, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                    \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, s)>)                                          \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, #s)>)                                         \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, w##s)>)                                       \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, string_view{s})>)                             \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, wstring_view{w##s})>)                         \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)             \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)              \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)       \
  << (static_require<str_eq(s, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)        \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, s)>)                                           \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, #s)>)                                          \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, w##s)>)                                        \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, string_view{s})>)                              \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, wstring_view{w##s})>)                          \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)              \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)               \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)        \
  << (static_require<str_eq(s, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)         \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, s)>)                                    \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, #s)>)                                   \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, w##s)>)                                 \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                       \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                   \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)       \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)        \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>) \
  << (static_require<str_eq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)  \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, s)>)                                     \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, #s)>)                                    \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, w##s)>)                                  \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                        \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                    \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)        \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)         \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)  \
  << (static_require<str_eq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)

#define REQUIRE_NEQ(s, n)                                                                                        \
  << (static_require<!str_eq(n, s)>)                                                                             \
  << (static_require<!str_eq(n, s, s)>)                                                                          \
  << (static_require<!str_eq(n, s, #s)>)                                                                         \
  << (static_require<!str_eq(n, s, w##s)>)                                                                       \
  << (static_require<!str_eq(n, s, string_view{s})>)                                                             \
  << (static_require<!str_eq(n, s, wstring_view{w##s})>)                                                         \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s})>)                                             \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s})>)                                              \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s})>)                                       \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s})>)                                        \
  << (static_require<!str_eq(n, #s, s)>)                                                                         \
  << (static_require<!str_eq(n, #s, #s)>)                                                                        \
  << (static_require<!str_eq(n, #s, w##s)>)                                                                      \
  << (static_require<!str_eq(n, #s, string_view{s})>)                                                            \
  << (static_require<!str_eq(n, #s, wstring_view{w##s})>)                                                        \
  << (static_require<!str_eq(n, #s, char_range<15, char, false>{s})>)                                            \
  << (static_require<!str_eq(n, #s, char_range<15, char, true>{s})>)                                             \
  << (static_require<!str_eq(n, #s, char_range<15, wchar_t, false>{w##s})>)                                      \
  << (static_require<!str_eq(n, #s, char_range<15, wchar_t, true>{w##s})>)                                       \
  << (static_require<!str_eq(n, w##s, s)>)                                                                       \
  << (static_require<!str_eq(n, w##s, #s)>)                                                                      \
  << (static_require<!str_eq(n, w##s, w##s)>)                                                                    \
  << (static_require<!str_eq(n, w##s, string_view{s})>)                                                          \
  << (static_require<!str_eq(n, w##s, wstring_view{w##s})>)                                                      \
  << (static_require<!str_eq(n, w##s, char_range<15, char, false>{s})>)                                          \
  << (static_require<!str_eq(n, w##s, char_range<15, char, true>{s})>)                                           \
  << (static_require<!str_eq(n, w##s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<!str_eq(n, w##s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<!str_eq(n, string_view{s}, s)>)                                                             \
  << (static_require<!str_eq(n, string_view{s}, #s)>)                                                            \
  << (static_require<!str_eq(n, string_view{s}, w##s)>)                                                          \
  << (static_require<!str_eq(n, string_view{s}, string_view{s})>)                                                \
  << (static_require<!str_eq(n, string_view{s}, wstring_view{w##s})>)                                            \
  << (static_require<!str_eq(n, string_view{s}, char_range<15, char, false>{s})>)                                \
  << (static_require<!str_eq(n, string_view{s}, char_range<15, char, true>{s})>)                                 \
  << (static_require<!str_eq(n, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                          \
  << (static_require<!str_eq(n, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                           \
  << (static_require<!str_eq(n, wstring_view{w##s}, s)>)                                                         \
  << (static_require<!str_eq(n, wstring_view{w##s}, #s)>)                                                        \
  << (static_require<!str_eq(n, wstring_view{w##s}, w##s)>)                                                      \
  << (static_require<!str_eq(n, wstring_view{w##s}, string_view{s})>)                                            \
  << (static_require<!str_eq(n, wstring_view{w##s}, wstring_view{w##s})>)                                        \
  << (static_require<!str_eq(n, wstring_view{w##s}, char_range<15, char, false>{s})>)                            \
  << (static_require<!str_eq(n, wstring_view{w##s}, char_range<15, char, true>{s})>)                             \
  << (static_require<!str_eq(n, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                      \
  << (static_require<!str_eq(n, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                       \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, s)>)                                             \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, #s)>)                                            \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, w##s)>)                                          \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, string_view{s})>)                                \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, wstring_view{w##s})>)                            \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)                \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)                 \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)          \
  << (static_require<!str_eq(n, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)           \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, s)>)                                              \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, #s)>)                                             \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, w##s)>)                                           \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, string_view{s})>)                                 \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, wstring_view{w##s})>)                             \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)                 \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)                  \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)           \
  << (static_require<!str_eq(n, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)            \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, s)>)                                       \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, #s)>)                                      \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, w##s)>)                                    \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                          \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                      \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)          \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)           \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>)    \
  << (static_require<!str_eq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)     \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, s)>)                                        \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, #s)>)                                       \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, w##s)>)                                     \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                           \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                       \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)           \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)            \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)     \
  << (static_require<!str_eq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)      \
                                                                                                                 \
  << (static_require<!str_eq(n, s, s, s)>)                                                                       \
  << (static_require<!str_eq(n, s, s, #s)>)                                                                      \
  << (static_require<!str_eq(n, s, s, w##s)>)                                                                    \
  << (static_require<!str_eq(n, s, s, string_view{s})>)                                                          \
  << (static_require<!str_eq(n, s, s, wstring_view{w##s})>)                                                      \
  << (static_require<!str_eq(n, s, s, char_range<15, char, false>{s})>)                                          \
  << (static_require<!str_eq(n, s, s, char_range<15, char, true>{s})>)                                           \
  << (static_require<!str_eq(n, s, s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<!str_eq(n, s, s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<!str_eq(n, s, #s, s)>)                                                                      \
  << (static_require<!str_eq(n, s, #s, #s)>)                                                                     \
  << (static_require<!str_eq(n, s, #s, w##s)>)                                                                   \
  << (static_require<!str_eq(n, s, #s, string_view{s})>)                                                         \
  << (static_require<!str_eq(n, s, #s, wstring_view{w##s})>)                                                     \
  << (static_require<!str_eq(n, s, #s, char_range<15, char, false>{s})>)                                         \
  << (static_require<!str_eq(n, s, #s, char_range<15, char, true>{s})>)                                          \
  << (static_require<!str_eq(n, s, #s, char_range<15, wchar_t, false>{w##s})>)                                   \
  << (static_require<!str_eq(n, s, #s, char_range<15, wchar_t, true>{w##s})>)                                    \
  << (static_require<!str_eq(n, s, w##s, s)>)                                                                    \
  << (static_require<!str_eq(n, s, w##s, #s)>)                                                                   \
  << (static_require<!str_eq(n, s, w##s, w##s)>)                                                                 \
  << (static_require<!str_eq(n, s, w##s, string_view{s})>)                                                       \
  << (static_require<!str_eq(n, s, w##s, wstring_view{w##s})>)                                                   \
  << (static_require<!str_eq(n, s, w##s, char_range<15, char, false>{s})>)                                       \
  << (static_require<!str_eq(n, s, w##s, char_range<15, char, true>{s})>)                                        \
  << (static_require<!str_eq(n, s, w##s, char_range<15, wchar_t, false>{w##s})>)                                 \
  << (static_require<!str_eq(n, s, w##s, char_range<15, wchar_t, true>{w##s})>)                                  \
  << (static_require<!str_eq(n, s, string_view{s}, s)>)                                                          \
  << (static_require<!str_eq(n, s, string_view{s}, #s)>)                                                         \
  << (static_require<!str_eq(n, s, string_view{s}, w##s)>)                                                       \
  << (static_require<!str_eq(n, s, string_view{s}, string_view{s})>)                                             \
  << (static_require<!str_eq(n, s, string_view{s}, wstring_view{w##s})>)                                         \
  << (static_require<!str_eq(n, s, string_view{s}, char_range<15, char, false>{s})>)                             \
  << (static_require<!str_eq(n, s, string_view{s}, char_range<15, char, true>{s})>)                              \
  << (static_require<!str_eq(n, s, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                       \
  << (static_require<!str_eq(n, s, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                        \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, s)>)                                                      \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, #s)>)                                                     \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, w##s)>)                                                   \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, string_view{s})>)                                         \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, wstring_view{w##s})>)                                     \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, char_range<15, char, false>{s})>)                         \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, char_range<15, char, true>{s})>)                          \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                   \
  << (static_require<!str_eq(n, s, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                    \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, s)>)                                          \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, #s)>)                                         \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, w##s)>)                                       \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, string_view{s})>)                             \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, wstring_view{w##s})>)                         \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)             \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)              \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)       \
  << (static_require<!str_eq(n, s, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)        \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, s)>)                                           \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, #s)>)                                          \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, w##s)>)                                        \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, string_view{s})>)                              \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, wstring_view{w##s})>)                          \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)              \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)               \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)        \
  << (static_require<!str_eq(n, s, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)         \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, s)>)                                    \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, #s)>)                                   \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, w##s)>)                                 \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                       \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                   \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)       \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)        \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>) \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)  \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, s)>)                                     \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, #s)>)                                    \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, w##s)>)                                  \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                        \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                    \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)        \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)         \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)  \
  << (static_require<!str_eq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)

// clang-format on

TEST(ccutl.str_eq, "lexicographically compares two or more stringlike objects")

REQUIRE_EQ(foo)
REQUIRE_NEQ(foo, bar)
REQUIRE_NEQ(bar, foo)
REQUIRE_NEQ(foo, foobar)
REQUIRE_NEQ(bar, foobar)
REQUIRE_NEQ(foobar, foo)
REQUIRE_NEQ(foobar, bar)

    ;
