#ifndef PPUTL_NARGS_H_INCLUDED
#define PPUTL_NARGS_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief \link PPUTL_NARGS PPUTL_NARGS\endlink -
#/// Returns the number of args passed [0, 256)
#/// @file
#//                          __    ___
#//                         /\ \__/\_ \
#//   _____   _____   __  __\ \ ,_\//\ \
#//  /\ '__`\/\ '__`\/\ \/\ \\ \ \/ \ \ \
#//  \ \ \_\ \ \ \_\ \ \ \_\ \\ \ \_ \_\ \_
#//   \ \ ,__/\ \ ,__/\ \____/ \ \__\/\____\
#//    \ \ \   \ \ \   \/___/   \/__/\/____/
#//     \/_/    \/_/
#//
#//  pputl Preprocessor Utilities
#//  Copyright (C) 2020 Justin Collier <m@jpcx.dev>
#//
#//	   This program is free software: you can redistribute it and/or modify
#//	   it under the terms of the GNU General Public License as published by
#//	   the Free Software Foundation, either version 3 of the License, or
#//	   (at your option) any later version.
#//
#//	   This program is distributed in the hope that it will be useful,
#//	   but WITHOUT ANY WARRANTY; without even the internalied warranty of
#//	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#//	   GNU General Public License for more details.
#//                                                                           //
#//  You should have received a copy of the GNU General Public License       ///
#//  along with this program.  If not, see <https://www.gnu.org/licenses/>. ////
#///////////////////////////////////////////////////////////////////////////////
#
#/// Returns the number of args passed [0, 256)
#/// @ingroup pputl
#/// @anchor  PPUTL_NARGS
#define PPUTL_NARGS(...) PPUTL_DETAIL_NARGS_X(__VA_ARGS__)
#
#define PPUTL_DETAIL_NARGS_X(...)                                              \
  PPUTL_DETAIL_NARGS_CHOOSER(                                                  \
      __VA_ARGS__ __VA_OPT__(, ) PPUTL_DETAIL_NARGS_E_TOOMANYARGS,             \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, PPUTL_DETAIL_NARGS_E_TOOMANYARGS,      \
      PPUTL_DETAIL_NARGS_E_TOOMANYARGS, 255, 254, 253, 252, 251, 250, 249,     \
      248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235,    \
      234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221,    \
      220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207,    \
      206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193,    \
      192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179,    \
      178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165,    \
      164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151,    \
      150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137,    \
      136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123,    \
      122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109,    \
      108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, \
      92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75,  \
      74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57,  \
      56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39,  \
      38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21,  \
      20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,   \
      0)
#
#define PPUTL_DETAIL_NARGS_CHOOSER(                                            \
    e255, e254, e253, e252, e251, e250, e249, e248, e247, e246, e245, e244,    \
    e243, e242, e241, e240, e239, e238, e237, e236, e235, e234, e233, e232,    \
    e231, e230, e229, e228, e227, e226, e225, e224, e223, e222, e221, e220,    \
    e219, e218, e217, e216, e215, e214, e213, e212, e211, e210, e209, e208,    \
    e207, e206, e205, e204, e203, e202, e201, e200, e199, e198, e197, e196,    \
    e195, e194, e193, e192, e191, e190, e189, e188, e187, e186, e185, e184,    \
    e183, e182, e181, e180, e179, e178, e177, e176, e175, e174, e173, e172,    \
    e171, e170, e169, e168, e167, e166, e165, e164, e163, e162, e161, e160,    \
    e159, e158, e157, e156, e155, e154, e153, e152, e151, e150, e149, e148,    \
    e147, e146, e145, e144, e143, e142, e141, e140, e139, e138, e137, e136,    \
    e135, e134, e133, e132, e131, e130, e129, e128, e127, e126, e125, e124,    \
    e123, e122, e121, e120, e119, e118, e117, e116, e115, e114, e113, e112,    \
    e111, e110, e109, e108, e107, e106, e105, e104, e103, e102, e101, e100,    \
    e99, e98, e97, e96, e95, e94, e93, e92, e91, e90, e89, e88, e87, e86, e85, \
    e84, e83, e82, e81, e80, e79, e78, e77, e76, e75, e74, e73, e72, e71, e70, \
    e69, e68, e67, e66, e65, e64, e63, e62, e61, e60, e59, e58, e57, e56, e55, \
    e54, e53, e52, e51, e50, e49, e48, e47, e46, e45, e44, e43, e42, e41, e40, \
    e39, e38, e37, e36, e35, e34, e33, e32, e31, e30, e29, e28, e27, e26, e25, \
    e24, e23, e22, e21, e20, e19, e18, e17, e16, e15, e14, e13, e12, e11, e10, \
    e9, e8, e7, e6, e5, e4, e3, e2, e1, _0, _1, _2, _3, _4, _5, _6, _7, _8,    \
    _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23,  \
    _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, \
    _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, \
    _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, \
    _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, _81, _82, _83, \
    _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, \
    _99, _100, _101, _102, _103, _104, _105, _106, _107, _108, _109, _110,     \
    _111, _112, _113, _114, _115, _116, _117, _118, _119, _120, _121, _122,    \
    _123, _124, _125, _126, _127, _128, _129, _130, _131, _132, _133, _134,    \
    _135, _136, _137, _138, _139, _140, _141, _142, _143, _144, _145, _146,    \
    _147, _148, _149, _150, _151, _152, _153, _154, _155, _156, _157, _158,    \
    _159, _160, _161, _162, _163, _164, _165, _166, _167, _168, _169, _170,    \
    _171, _172, _173, _174, _175, _176, _177, _178, _179, _180, _181, _182,    \
    _183, _184, _185, _186, _187, _188, _189, _190, _191, _192, _193, _194,    \
    _195, _196, _197, _198, _199, _200, _201, _202, _203, _204, _205, _206,    \
    _207, _208, _209, _210, _211, _212, _213, _214, _215, _216, _217, _218,    \
    _219, _220, _221, _222, _223, _224, _225, _226, _227, _228, _229, _230,    \
    _231, _232, _233, _234, _235, _236, _237, _238, _239, _240, _241, _242,    \
    _243, _244, _245, _246, _247, _248, _249, _250, _251, _252, _253, _254,    \
    _255, size, ...)                                                           \
  size
#
#define PPUTL_DETAIL_NARGS_E_TOOMANYARGS                                       \
  ([] {                                                                        \
    static_assert(false, "PPUTL_NARGS: too many args [0, 256)");               \
    return 0;                                                                  \
  })()
#
#endif