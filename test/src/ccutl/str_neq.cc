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
import ccutl.str_neq;
#else
import ccutl;
#endif
#else
#ifdef TESTCCUTL_SINGLE
#include <ccutl/range_of.h>
#include <ccutl/str_neq.h>
#else
#include <ccutl.h>
#endif
#endif

#include <cctest.h>

#include <string_view>

#include "testccutl/char_range.h"

using namespace cctest;

using ccutl::str_neq;
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
#define REQUIRE_EQ(s)                                                                                          \
  << (static_require<!str_neq(s)>)                                                                             \
  << (static_require<!str_neq(s, s)>)                                                                          \
  << (static_require<!str_neq(s, #s)>)                                                                         \
  << (static_require<!str_neq(s, w##s)>)                                                                       \
  << (static_require<!str_neq(s, string_view{s})>)                                                             \
  << (static_require<!str_neq(s, wstring_view{w##s})>)                                                         \
  << (static_require<!str_neq(s, char_range<15, char, false>{s})>)                                             \
  << (static_require<!str_neq(s, char_range<15, char, true>{s})>)                                              \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s})>)                                       \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s})>)                                        \
  << (static_require<!str_neq(#s, s)>)                                                                         \
  << (static_require<!str_neq(#s, #s)>)                                                                        \
  << (static_require<!str_neq(#s, w##s)>)                                                                      \
  << (static_require<!str_neq(#s, string_view{s})>)                                                            \
  << (static_require<!str_neq(#s, wstring_view{w##s})>)                                                        \
  << (static_require<!str_neq(#s, char_range<15, char, false>{s})>)                                            \
  << (static_require<!str_neq(#s, char_range<15, char, true>{s})>)                                             \
  << (static_require<!str_neq(#s, char_range<15, wchar_t, false>{w##s})>)                                      \
  << (static_require<!str_neq(#s, char_range<15, wchar_t, true>{w##s})>)                                       \
  << (static_require<!str_neq(w##s, s)>)                                                                       \
  << (static_require<!str_neq(w##s, #s)>)                                                                      \
  << (static_require<!str_neq(w##s, w##s)>)                                                                    \
  << (static_require<!str_neq(w##s, string_view{s})>)                                                          \
  << (static_require<!str_neq(w##s, wstring_view{w##s})>)                                                      \
  << (static_require<!str_neq(w##s, char_range<15, char, false>{s})>)                                          \
  << (static_require<!str_neq(w##s, char_range<15, char, true>{s})>)                                           \
  << (static_require<!str_neq(w##s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<!str_neq(w##s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<!str_neq(string_view{s}, s)>)                                                             \
  << (static_require<!str_neq(string_view{s}, #s)>)                                                            \
  << (static_require<!str_neq(string_view{s}, w##s)>)                                                          \
  << (static_require<!str_neq(string_view{s}, string_view{s})>)                                                \
  << (static_require<!str_neq(string_view{s}, wstring_view{w##s})>)                                            \
  << (static_require<!str_neq(string_view{s}, char_range<15, char, false>{s})>)                                \
  << (static_require<!str_neq(string_view{s}, char_range<15, char, true>{s})>)                                 \
  << (static_require<!str_neq(string_view{s}, char_range<15, wchar_t, false>{w##s})>)                          \
  << (static_require<!str_neq(string_view{s}, char_range<15, wchar_t, true>{w##s})>)                           \
  << (static_require<!str_neq(wstring_view{w##s}, s)>)                                                         \
  << (static_require<!str_neq(wstring_view{w##s}, #s)>)                                                        \
  << (static_require<!str_neq(wstring_view{w##s}, w##s)>)                                                      \
  << (static_require<!str_neq(wstring_view{w##s}, string_view{s})>)                                            \
  << (static_require<!str_neq(wstring_view{w##s}, wstring_view{w##s})>)                                        \
  << (static_require<!str_neq(wstring_view{w##s}, char_range<15, char, false>{s})>)                            \
  << (static_require<!str_neq(wstring_view{w##s}, char_range<15, char, true>{s})>)                             \
  << (static_require<!str_neq(wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                      \
  << (static_require<!str_neq(wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                       \
  << (static_require<!str_neq(char_range<15, char, false>{s}, s)>)                                             \
  << (static_require<!str_neq(char_range<15, char, false>{s}, #s)>)                                            \
  << (static_require<!str_neq(char_range<15, char, false>{s}, w##s)>)                                          \
  << (static_require<!str_neq(char_range<15, char, false>{s}, string_view{s})>)                                \
  << (static_require<!str_neq(char_range<15, char, false>{s}, wstring_view{w##s})>)                            \
  << (static_require<!str_neq(char_range<15, char, false>{s}, char_range<15, char, false>{s})>)                \
  << (static_require<!str_neq(char_range<15, char, false>{s}, char_range<15, char, true>{s})>)                 \
  << (static_require<!str_neq(char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)          \
  << (static_require<!str_neq(char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)           \
  << (static_require<!str_neq(char_range<15, char, true>{s}, s)>)                                              \
  << (static_require<!str_neq(char_range<15, char, true>{s}, #s)>)                                             \
  << (static_require<!str_neq(char_range<15, char, true>{s}, w##s)>)                                           \
  << (static_require<!str_neq(char_range<15, char, true>{s}, string_view{s})>)                                 \
  << (static_require<!str_neq(char_range<15, char, true>{s}, wstring_view{w##s})>)                             \
  << (static_require<!str_neq(char_range<15, char, true>{s}, char_range<15, char, false>{s})>)                 \
  << (static_require<!str_neq(char_range<15, char, true>{s}, char_range<15, char, true>{s})>)                  \
  << (static_require<!str_neq(char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)           \
  << (static_require<!str_neq(char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)            \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, s)>)                                       \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, #s)>)                                      \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, w##s)>)                                    \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, string_view{s})>)                          \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                      \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)          \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)           \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>)    \
  << (static_require<!str_neq(char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)     \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, s)>)                                        \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, #s)>)                                       \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, w##s)>)                                     \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, string_view{s})>)                           \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                       \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)           \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)            \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)     \
  << (static_require<!str_neq(char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)      \
                                                                                                               \
  << (static_require<!str_neq(s, s, s)>)                                                                       \
  << (static_require<!str_neq(s, s, #s)>)                                                                      \
  << (static_require<!str_neq(s, s, w##s)>)                                                                    \
  << (static_require<!str_neq(s, s, string_view{s})>)                                                          \
  << (static_require<!str_neq(s, s, wstring_view{w##s})>)                                                      \
  << (static_require<!str_neq(s, s, char_range<15, char, false>{s})>)                                          \
  << (static_require<!str_neq(s, s, char_range<15, char, true>{s})>)                                           \
  << (static_require<!str_neq(s, s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<!str_neq(s, s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<!str_neq(s, #s, s)>)                                                                      \
  << (static_require<!str_neq(s, #s, #s)>)                                                                     \
  << (static_require<!str_neq(s, #s, w##s)>)                                                                   \
  << (static_require<!str_neq(s, #s, string_view{s})>)                                                         \
  << (static_require<!str_neq(s, #s, wstring_view{w##s})>)                                                     \
  << (static_require<!str_neq(s, #s, char_range<15, char, false>{s})>)                                         \
  << (static_require<!str_neq(s, #s, char_range<15, char, true>{s})>)                                          \
  << (static_require<!str_neq(s, #s, char_range<15, wchar_t, false>{w##s})>)                                   \
  << (static_require<!str_neq(s, #s, char_range<15, wchar_t, true>{w##s})>)                                    \
  << (static_require<!str_neq(s, w##s, s)>)                                                                    \
  << (static_require<!str_neq(s, w##s, #s)>)                                                                   \
  << (static_require<!str_neq(s, w##s, w##s)>)                                                                 \
  << (static_require<!str_neq(s, w##s, string_view{s})>)                                                       \
  << (static_require<!str_neq(s, w##s, wstring_view{w##s})>)                                                   \
  << (static_require<!str_neq(s, w##s, char_range<15, char, false>{s})>)                                       \
  << (static_require<!str_neq(s, w##s, char_range<15, char, true>{s})>)                                        \
  << (static_require<!str_neq(s, w##s, char_range<15, wchar_t, false>{w##s})>)                                 \
  << (static_require<!str_neq(s, w##s, char_range<15, wchar_t, true>{w##s})>)                                  \
  << (static_require<!str_neq(s, string_view{s}, s)>)                                                          \
  << (static_require<!str_neq(s, string_view{s}, #s)>)                                                         \
  << (static_require<!str_neq(s, string_view{s}, w##s)>)                                                       \
  << (static_require<!str_neq(s, string_view{s}, string_view{s})>)                                             \
  << (static_require<!str_neq(s, string_view{s}, wstring_view{w##s})>)                                         \
  << (static_require<!str_neq(s, string_view{s}, char_range<15, char, false>{s})>)                             \
  << (static_require<!str_neq(s, string_view{s}, char_range<15, char, true>{s})>)                              \
  << (static_require<!str_neq(s, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                       \
  << (static_require<!str_neq(s, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                        \
  << (static_require<!str_neq(s, wstring_view{w##s}, s)>)                                                      \
  << (static_require<!str_neq(s, wstring_view{w##s}, #s)>)                                                     \
  << (static_require<!str_neq(s, wstring_view{w##s}, w##s)>)                                                   \
  << (static_require<!str_neq(s, wstring_view{w##s}, string_view{s})>)                                         \
  << (static_require<!str_neq(s, wstring_view{w##s}, wstring_view{w##s})>)                                     \
  << (static_require<!str_neq(s, wstring_view{w##s}, char_range<15, char, false>{s})>)                         \
  << (static_require<!str_neq(s, wstring_view{w##s}, char_range<15, char, true>{s})>)                          \
  << (static_require<!str_neq(s, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                   \
  << (static_require<!str_neq(s, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                    \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, s)>)                                          \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, #s)>)                                         \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, w##s)>)                                       \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, string_view{s})>)                             \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, wstring_view{w##s})>)                         \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)             \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)              \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)       \
  << (static_require<!str_neq(s, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)        \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, s)>)                                           \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, #s)>)                                          \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, w##s)>)                                        \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, string_view{s})>)                              \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, wstring_view{w##s})>)                          \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)              \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)               \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)        \
  << (static_require<!str_neq(s, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)         \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, s)>)                                    \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, #s)>)                                   \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, w##s)>)                                 \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                       \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                   \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)       \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)        \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>) \
  << (static_require<!str_neq(s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)  \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, s)>)                                     \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, #s)>)                                    \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, w##s)>)                                  \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                        \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                    \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)        \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)         \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)  \
  << (static_require<!str_neq(s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)

#define REQUIRE_NEQ(s, n)                                                                                        \
  << (static_require<str_neq(n, s)>)                                                                             \
  << (static_require<str_neq(n, s, s)>)                                                                          \
  << (static_require<str_neq(n, s, #s)>)                                                                         \
  << (static_require<str_neq(n, s, w##s)>)                                                                       \
  << (static_require<str_neq(n, s, string_view{s})>)                                                             \
  << (static_require<str_neq(n, s, wstring_view{w##s})>)                                                         \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s})>)                                             \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s})>)                                              \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s})>)                                       \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s})>)                                        \
  << (static_require<str_neq(n, #s, s)>)                                                                         \
  << (static_require<str_neq(n, #s, #s)>)                                                                        \
  << (static_require<str_neq(n, #s, w##s)>)                                                                      \
  << (static_require<str_neq(n, #s, string_view{s})>)                                                            \
  << (static_require<str_neq(n, #s, wstring_view{w##s})>)                                                        \
  << (static_require<str_neq(n, #s, char_range<15, char, false>{s})>)                                            \
  << (static_require<str_neq(n, #s, char_range<15, char, true>{s})>)                                             \
  << (static_require<str_neq(n, #s, char_range<15, wchar_t, false>{w##s})>)                                      \
  << (static_require<str_neq(n, #s, char_range<15, wchar_t, true>{w##s})>)                                       \
  << (static_require<str_neq(n, w##s, s)>)                                                                       \
  << (static_require<str_neq(n, w##s, #s)>)                                                                      \
  << (static_require<str_neq(n, w##s, w##s)>)                                                                    \
  << (static_require<str_neq(n, w##s, string_view{s})>)                                                          \
  << (static_require<str_neq(n, w##s, wstring_view{w##s})>)                                                      \
  << (static_require<str_neq(n, w##s, char_range<15, char, false>{s})>)                                          \
  << (static_require<str_neq(n, w##s, char_range<15, char, true>{s})>)                                           \
  << (static_require<str_neq(n, w##s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<str_neq(n, w##s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<str_neq(n, string_view{s}, s)>)                                                             \
  << (static_require<str_neq(n, string_view{s}, #s)>)                                                            \
  << (static_require<str_neq(n, string_view{s}, w##s)>)                                                          \
  << (static_require<str_neq(n, string_view{s}, string_view{s})>)                                                \
  << (static_require<str_neq(n, string_view{s}, wstring_view{w##s})>)                                            \
  << (static_require<str_neq(n, string_view{s}, char_range<15, char, false>{s})>)                                \
  << (static_require<str_neq(n, string_view{s}, char_range<15, char, true>{s})>)                                 \
  << (static_require<str_neq(n, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                          \
  << (static_require<str_neq(n, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                           \
  << (static_require<str_neq(n, wstring_view{w##s}, s)>)                                                         \
  << (static_require<str_neq(n, wstring_view{w##s}, #s)>)                                                        \
  << (static_require<str_neq(n, wstring_view{w##s}, w##s)>)                                                      \
  << (static_require<str_neq(n, wstring_view{w##s}, string_view{s})>)                                            \
  << (static_require<str_neq(n, wstring_view{w##s}, wstring_view{w##s})>)                                        \
  << (static_require<str_neq(n, wstring_view{w##s}, char_range<15, char, false>{s})>)                            \
  << (static_require<str_neq(n, wstring_view{w##s}, char_range<15, char, true>{s})>)                             \
  << (static_require<str_neq(n, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                      \
  << (static_require<str_neq(n, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                       \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, s)>)                                             \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, #s)>)                                            \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, w##s)>)                                          \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, string_view{s})>)                                \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, wstring_view{w##s})>)                            \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)                \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)                 \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)          \
  << (static_require<str_neq(n, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)           \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, s)>)                                              \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, #s)>)                                             \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, w##s)>)                                           \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, string_view{s})>)                                 \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, wstring_view{w##s})>)                             \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)                 \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)                  \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)           \
  << (static_require<str_neq(n, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)            \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, s)>)                                       \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, #s)>)                                      \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, w##s)>)                                    \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                          \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                      \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)          \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)           \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>)    \
  << (static_require<str_neq(n, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)     \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, s)>)                                        \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, #s)>)                                       \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, w##s)>)                                     \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                           \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                       \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)           \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)            \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)     \
  << (static_require<str_neq(n, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)      \
                                                                                                                 \
  << (static_require<str_neq(n, s, s, s)>)                                                                       \
  << (static_require<str_neq(n, s, s, #s)>)                                                                      \
  << (static_require<str_neq(n, s, s, w##s)>)                                                                    \
  << (static_require<str_neq(n, s, s, string_view{s})>)                                                          \
  << (static_require<str_neq(n, s, s, wstring_view{w##s})>)                                                      \
  << (static_require<str_neq(n, s, s, char_range<15, char, false>{s})>)                                          \
  << (static_require<str_neq(n, s, s, char_range<15, char, true>{s})>)                                           \
  << (static_require<str_neq(n, s, s, char_range<15, wchar_t, false>{w##s})>)                                    \
  << (static_require<str_neq(n, s, s, char_range<15, wchar_t, true>{w##s})>)                                     \
  << (static_require<str_neq(n, s, #s, s)>)                                                                      \
  << (static_require<str_neq(n, s, #s, #s)>)                                                                     \
  << (static_require<str_neq(n, s, #s, w##s)>)                                                                   \
  << (static_require<str_neq(n, s, #s, string_view{s})>)                                                         \
  << (static_require<str_neq(n, s, #s, wstring_view{w##s})>)                                                     \
  << (static_require<str_neq(n, s, #s, char_range<15, char, false>{s})>)                                         \
  << (static_require<str_neq(n, s, #s, char_range<15, char, true>{s})>)                                          \
  << (static_require<str_neq(n, s, #s, char_range<15, wchar_t, false>{w##s})>)                                   \
  << (static_require<str_neq(n, s, #s, char_range<15, wchar_t, true>{w##s})>)                                    \
  << (static_require<str_neq(n, s, w##s, s)>)                                                                    \
  << (static_require<str_neq(n, s, w##s, #s)>)                                                                   \
  << (static_require<str_neq(n, s, w##s, w##s)>)                                                                 \
  << (static_require<str_neq(n, s, w##s, string_view{s})>)                                                       \
  << (static_require<str_neq(n, s, w##s, wstring_view{w##s})>)                                                   \
  << (static_require<str_neq(n, s, w##s, char_range<15, char, false>{s})>)                                       \
  << (static_require<str_neq(n, s, w##s, char_range<15, char, true>{s})>)                                        \
  << (static_require<str_neq(n, s, w##s, char_range<15, wchar_t, false>{w##s})>)                                 \
  << (static_require<str_neq(n, s, w##s, char_range<15, wchar_t, true>{w##s})>)                                  \
  << (static_require<str_neq(n, s, string_view{s}, s)>)                                                          \
  << (static_require<str_neq(n, s, string_view{s}, #s)>)                                                         \
  << (static_require<str_neq(n, s, string_view{s}, w##s)>)                                                       \
  << (static_require<str_neq(n, s, string_view{s}, string_view{s})>)                                             \
  << (static_require<str_neq(n, s, string_view{s}, wstring_view{w##s})>)                                         \
  << (static_require<str_neq(n, s, string_view{s}, char_range<15, char, false>{s})>)                             \
  << (static_require<str_neq(n, s, string_view{s}, char_range<15, char, true>{s})>)                              \
  << (static_require<str_neq(n, s, string_view{s}, char_range<15, wchar_t, false>{w##s})>)                       \
  << (static_require<str_neq(n, s, string_view{s}, char_range<15, wchar_t, true>{w##s})>)                        \
  << (static_require<str_neq(n, s, wstring_view{w##s}, s)>)                                                      \
  << (static_require<str_neq(n, s, wstring_view{w##s}, #s)>)                                                     \
  << (static_require<str_neq(n, s, wstring_view{w##s}, w##s)>)                                                   \
  << (static_require<str_neq(n, s, wstring_view{w##s}, string_view{s})>)                                         \
  << (static_require<str_neq(n, s, wstring_view{w##s}, wstring_view{w##s})>)                                     \
  << (static_require<str_neq(n, s, wstring_view{w##s}, char_range<15, char, false>{s})>)                         \
  << (static_require<str_neq(n, s, wstring_view{w##s}, char_range<15, char, true>{s})>)                          \
  << (static_require<str_neq(n, s, wstring_view{w##s}, char_range<15, wchar_t, false>{w##s})>)                   \
  << (static_require<str_neq(n, s, wstring_view{w##s}, char_range<15, wchar_t, true>{w##s})>)                    \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, s)>)                                          \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, #s)>)                                         \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, w##s)>)                                       \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, string_view{s})>)                             \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, wstring_view{w##s})>)                         \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, char_range<15, char, false>{s})>)             \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, char_range<15, char, true>{s})>)              \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, char_range<15, wchar_t, false>{w##s})>)       \
  << (static_require<str_neq(n, s, char_range<15, char, false>{s}, char_range<15, wchar_t, true>{w##s})>)        \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, s)>)                                           \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, #s)>)                                          \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, w##s)>)                                        \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, string_view{s})>)                              \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, wstring_view{w##s})>)                          \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, char_range<15, char, false>{s})>)              \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, char_range<15, char, true>{s})>)               \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, char_range<15, wchar_t, false>{w##s})>)        \
  << (static_require<str_neq(n, s, char_range<15, char, true>{s}, char_range<15, wchar_t, true>{w##s})>)         \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, s)>)                                    \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, #s)>)                                   \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, w##s)>)                                 \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, string_view{s})>)                       \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, wstring_view{w##s})>)                   \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, false>{s})>)       \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, char, true>{s})>)        \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, false>{w##s})>) \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, false>{w##s}, char_range<15, wchar_t, true>{w##s})>)  \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, s)>)                                     \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, #s)>)                                    \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, w##s)>)                                  \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, string_view{s})>)                        \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, wstring_view{w##s})>)                    \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, false>{s})>)        \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, char, true>{s})>)         \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, false>{w##s})>)  \
  << (static_require<str_neq(n, s, char_range<15, wchar_t, true>{w##s}, char_range<15, wchar_t, true>{w##s})>)

// clang-format on

TEST(ccutl.str_neq, "lexicographically compares two or more stringlike objects")

REQUIRE_EQ(foo)
REQUIRE_NEQ(foo, bar)
REQUIRE_NEQ(bar, foo)
REQUIRE_NEQ(foo, foobar)
REQUIRE_NEQ(bar, foobar)
REQUIRE_NEQ(foobar, foo)
REQUIRE_NEQ(foobar, bar)

    ;
