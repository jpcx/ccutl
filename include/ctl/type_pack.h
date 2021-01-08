//                                             ccutl.type_pack feature guard {{{
#ifndef CCUTL_TYPE_PACK_INCLUDED
#define CCUTL_TYPE_PACK_INCLUDED
//                                             ccutl.type_pack feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.type_pack]: A transformable template type arg container
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

#include <cstdint>
#include <type_traits>
#include <utility>

//                                                        embedded libraries {{{
//                                             #include <pputl/tuple/args.h> {{{

#ifndef PPUTL_TUPLE_ARGS_H_INCLUDED
#define PPUTL_TUPLE_ARGS_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief \link PPUTL_TUPLE_ARGS PPUTL_TUPLE_ARGS\endlink -
#/// returns tuple elements as args
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
#//  Copyright (C) 2020, 2021 Justin Collier <m@jpcx.dev>
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
#/// returns tuple elements as args
#///
#/// @ingroup tuple
#/// @anchor  PPUTL_TUPLE_ARGS
#/// @code
#///   #define TUP (3, 2, 1)
#///   PPUTL_AT(0, PPUTL_TUPLE_ARGS(TUP)) // 3
#/// @endcode
#define PPUTL_TUPLE_ARGS(tup) PPUTL_TUPLE_ARGS_RETURN tup
#
#define PPUTL_TUPLE_ARGS_RETURN(...) __VA_ARGS__
#
#endif

//                                             #include <pputl/tuple/args.h> }}}
//                                                  #include <pputl/nargs.h> {{{

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
#//  Copyright (C) 2020, 2021 Justin Collier <m@jpcx.dev>
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

//                                                  #include <pputl/nargs.h> }}}
//                                                    #include <pputl/cat.h> {{{

#ifndef PPUTL_CAT_H_INCLUDED
#define PPUTL_CAT_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief \link PPUTL_CAT PPUTL_CAT\endlink -
#/// concatenate [0, 256) args
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
#//  Copyright (C) 2020, 2021 Justin Collier <m@jpcx.dev>
#//
#//    This program is free software: you can redistribute it and/or modify
#//    it under the terms of the GNU General Public License as published by
#//    the Free Software Foundation, either version 3 of the License, or
#//    (at your option) any later version.
#//
#//    This program is distributed in the hope that it will be useful,
#//    but WITHOUT ANY WARRANTY; without even the internalied warranty of
#//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#//    GNU General Public License for more details.
#//                                                                           //
#//  You should have received a copy of the GNU General Public License       ///
#//  along with this program.  If not, see <https://www.gnu.org/licenses/>. ////
#///////////////////////////////////////////////////////////////////////////////
#
#
#/// concatenate [0, 256) args
#/// @ingroup pputl
#/// @anchor  PPUTL_CAT
#define PPUTL_CAT(...) PPUTL_DETAIL_CAT_X(__VA_ARGS__)
#
#define PPUTL_DETAIL_CAT_X(...)                                                \
  PPUTL_DETAIL_CAT_CHOOSER(PPUTL_NARGS(__VA_ARGS__))                           \
  (__VA_ARGS__)
#define PPUTL_DETAIL_CAT_CHOOSER(nargs) PPUTL_DETAIL_CAT_CHOOSER_X(nargs)
#define PPUTL_DETAIL_CAT_CHOOSER_X(nargs) PPUTL_DETAIL_CAT_##nargs
#
#// clang-format off
#define PPUTL_DETAIL_CAT_0()
#define PPUTL_DETAIL_CAT_1(a)           a
#define PPUTL_DETAIL_CAT_2(a, b)        a##b
#define PPUTL_DETAIL_CAT_3(a, b, ...)   PPUTL_DETAIL_CAT_2(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_4(a, b, ...)   PPUTL_DETAIL_CAT_3(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_5(a, b, ...)   PPUTL_DETAIL_CAT_4(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_6(a, b, ...)   PPUTL_DETAIL_CAT_5(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_7(a, b, ...)   PPUTL_DETAIL_CAT_6(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_8(a, b, ...)   PPUTL_DETAIL_CAT_7(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_9(a, b, ...)   PPUTL_DETAIL_CAT_8(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_10(a, b, ...)  PPUTL_DETAIL_CAT_9(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_11(a, b, ...)  PPUTL_DETAIL_CAT_10(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_12(a, b, ...)  PPUTL_DETAIL_CAT_11(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_13(a, b, ...)  PPUTL_DETAIL_CAT_12(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_14(a, b, ...)  PPUTL_DETAIL_CAT_13(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_15(a, b, ...)  PPUTL_DETAIL_CAT_14(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_16(a, b, ...)  PPUTL_DETAIL_CAT_15(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_17(a, b, ...)  PPUTL_DETAIL_CAT_16(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_18(a, b, ...)  PPUTL_DETAIL_CAT_17(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_19(a, b, ...)  PPUTL_DETAIL_CAT_18(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_20(a, b, ...)  PPUTL_DETAIL_CAT_19(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_21(a, b, ...)  PPUTL_DETAIL_CAT_20(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_22(a, b, ...)  PPUTL_DETAIL_CAT_21(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_23(a, b, ...)  PPUTL_DETAIL_CAT_22(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_24(a, b, ...)  PPUTL_DETAIL_CAT_23(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_25(a, b, ...)  PPUTL_DETAIL_CAT_24(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_26(a, b, ...)  PPUTL_DETAIL_CAT_25(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_27(a, b, ...)  PPUTL_DETAIL_CAT_26(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_28(a, b, ...)  PPUTL_DETAIL_CAT_27(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_29(a, b, ...)  PPUTL_DETAIL_CAT_28(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_30(a, b, ...)  PPUTL_DETAIL_CAT_29(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_31(a, b, ...)  PPUTL_DETAIL_CAT_30(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_32(a, b, ...)  PPUTL_DETAIL_CAT_31(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_33(a, b, ...)  PPUTL_DETAIL_CAT_32(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_34(a, b, ...)  PPUTL_DETAIL_CAT_33(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_35(a, b, ...)  PPUTL_DETAIL_CAT_34(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_36(a, b, ...)  PPUTL_DETAIL_CAT_35(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_37(a, b, ...)  PPUTL_DETAIL_CAT_36(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_38(a, b, ...)  PPUTL_DETAIL_CAT_37(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_39(a, b, ...)  PPUTL_DETAIL_CAT_38(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_40(a, b, ...)  PPUTL_DETAIL_CAT_39(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_41(a, b, ...)  PPUTL_DETAIL_CAT_40(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_42(a, b, ...)  PPUTL_DETAIL_CAT_41(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_43(a, b, ...)  PPUTL_DETAIL_CAT_42(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_44(a, b, ...)  PPUTL_DETAIL_CAT_43(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_45(a, b, ...)  PPUTL_DETAIL_CAT_44(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_46(a, b, ...)  PPUTL_DETAIL_CAT_45(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_47(a, b, ...)  PPUTL_DETAIL_CAT_46(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_48(a, b, ...)  PPUTL_DETAIL_CAT_47(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_49(a, b, ...)  PPUTL_DETAIL_CAT_48(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_50(a, b, ...)  PPUTL_DETAIL_CAT_49(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_51(a, b, ...)  PPUTL_DETAIL_CAT_50(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_52(a, b, ...)  PPUTL_DETAIL_CAT_51(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_53(a, b, ...)  PPUTL_DETAIL_CAT_52(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_54(a, b, ...)  PPUTL_DETAIL_CAT_53(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_55(a, b, ...)  PPUTL_DETAIL_CAT_54(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_56(a, b, ...)  PPUTL_DETAIL_CAT_55(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_57(a, b, ...)  PPUTL_DETAIL_CAT_56(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_58(a, b, ...)  PPUTL_DETAIL_CAT_57(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_59(a, b, ...)  PPUTL_DETAIL_CAT_58(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_60(a, b, ...)  PPUTL_DETAIL_CAT_59(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_61(a, b, ...)  PPUTL_DETAIL_CAT_60(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_62(a, b, ...)  PPUTL_DETAIL_CAT_61(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_63(a, b, ...)  PPUTL_DETAIL_CAT_62(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_64(a, b, ...)  PPUTL_DETAIL_CAT_63(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_65(a, b, ...)  PPUTL_DETAIL_CAT_64(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_66(a, b, ...)  PPUTL_DETAIL_CAT_65(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_67(a, b, ...)  PPUTL_DETAIL_CAT_66(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_68(a, b, ...)  PPUTL_DETAIL_CAT_67(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_69(a, b, ...)  PPUTL_DETAIL_CAT_68(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_70(a, b, ...)  PPUTL_DETAIL_CAT_69(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_71(a, b, ...)  PPUTL_DETAIL_CAT_70(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_72(a, b, ...)  PPUTL_DETAIL_CAT_71(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_73(a, b, ...)  PPUTL_DETAIL_CAT_72(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_74(a, b, ...)  PPUTL_DETAIL_CAT_73(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_75(a, b, ...)  PPUTL_DETAIL_CAT_74(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_76(a, b, ...)  PPUTL_DETAIL_CAT_75(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_77(a, b, ...)  PPUTL_DETAIL_CAT_76(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_78(a, b, ...)  PPUTL_DETAIL_CAT_77(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_79(a, b, ...)  PPUTL_DETAIL_CAT_78(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_80(a, b, ...)  PPUTL_DETAIL_CAT_79(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_81(a, b, ...)  PPUTL_DETAIL_CAT_80(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_82(a, b, ...)  PPUTL_DETAIL_CAT_81(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_83(a, b, ...)  PPUTL_DETAIL_CAT_82(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_84(a, b, ...)  PPUTL_DETAIL_CAT_83(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_85(a, b, ...)  PPUTL_DETAIL_CAT_84(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_86(a, b, ...)  PPUTL_DETAIL_CAT_85(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_87(a, b, ...)  PPUTL_DETAIL_CAT_86(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_88(a, b, ...)  PPUTL_DETAIL_CAT_87(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_89(a, b, ...)  PPUTL_DETAIL_CAT_88(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_90(a, b, ...)  PPUTL_DETAIL_CAT_89(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_91(a, b, ...)  PPUTL_DETAIL_CAT_90(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_92(a, b, ...)  PPUTL_DETAIL_CAT_91(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_93(a, b, ...)  PPUTL_DETAIL_CAT_92(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_94(a, b, ...)  PPUTL_DETAIL_CAT_93(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_95(a, b, ...)  PPUTL_DETAIL_CAT_94(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_96(a, b, ...)  PPUTL_DETAIL_CAT_95(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_97(a, b, ...)  PPUTL_DETAIL_CAT_96(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_98(a, b, ...)  PPUTL_DETAIL_CAT_97(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_99(a, b, ...)  PPUTL_DETAIL_CAT_98(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_100(a, b, ...) PPUTL_DETAIL_CAT_99(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_101(a, b, ...) PPUTL_DETAIL_CAT_100(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_102(a, b, ...) PPUTL_DETAIL_CAT_101(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_103(a, b, ...) PPUTL_DETAIL_CAT_102(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_104(a, b, ...) PPUTL_DETAIL_CAT_103(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_105(a, b, ...) PPUTL_DETAIL_CAT_104(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_106(a, b, ...) PPUTL_DETAIL_CAT_105(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_107(a, b, ...) PPUTL_DETAIL_CAT_106(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_108(a, b, ...) PPUTL_DETAIL_CAT_107(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_109(a, b, ...) PPUTL_DETAIL_CAT_108(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_110(a, b, ...) PPUTL_DETAIL_CAT_109(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_111(a, b, ...) PPUTL_DETAIL_CAT_110(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_112(a, b, ...) PPUTL_DETAIL_CAT_111(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_113(a, b, ...) PPUTL_DETAIL_CAT_112(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_114(a, b, ...) PPUTL_DETAIL_CAT_113(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_115(a, b, ...) PPUTL_DETAIL_CAT_114(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_116(a, b, ...) PPUTL_DETAIL_CAT_115(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_117(a, b, ...) PPUTL_DETAIL_CAT_116(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_118(a, b, ...) PPUTL_DETAIL_CAT_117(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_119(a, b, ...) PPUTL_DETAIL_CAT_118(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_120(a, b, ...) PPUTL_DETAIL_CAT_119(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_121(a, b, ...) PPUTL_DETAIL_CAT_120(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_122(a, b, ...) PPUTL_DETAIL_CAT_121(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_123(a, b, ...) PPUTL_DETAIL_CAT_122(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_124(a, b, ...) PPUTL_DETAIL_CAT_123(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_125(a, b, ...) PPUTL_DETAIL_CAT_124(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_126(a, b, ...) PPUTL_DETAIL_CAT_125(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_127(a, b, ...) PPUTL_DETAIL_CAT_126(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_128(a, b, ...) PPUTL_DETAIL_CAT_127(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_129(a, b, ...) PPUTL_DETAIL_CAT_128(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_130(a, b, ...) PPUTL_DETAIL_CAT_129(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_131(a, b, ...) PPUTL_DETAIL_CAT_130(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_132(a, b, ...) PPUTL_DETAIL_CAT_131(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_133(a, b, ...) PPUTL_DETAIL_CAT_132(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_134(a, b, ...) PPUTL_DETAIL_CAT_133(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_135(a, b, ...) PPUTL_DETAIL_CAT_134(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_136(a, b, ...) PPUTL_DETAIL_CAT_135(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_137(a, b, ...) PPUTL_DETAIL_CAT_136(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_138(a, b, ...) PPUTL_DETAIL_CAT_137(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_139(a, b, ...) PPUTL_DETAIL_CAT_138(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_140(a, b, ...) PPUTL_DETAIL_CAT_139(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_141(a, b, ...) PPUTL_DETAIL_CAT_140(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_142(a, b, ...) PPUTL_DETAIL_CAT_141(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_143(a, b, ...) PPUTL_DETAIL_CAT_142(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_144(a, b, ...) PPUTL_DETAIL_CAT_143(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_145(a, b, ...) PPUTL_DETAIL_CAT_144(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_146(a, b, ...) PPUTL_DETAIL_CAT_145(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_147(a, b, ...) PPUTL_DETAIL_CAT_146(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_148(a, b, ...) PPUTL_DETAIL_CAT_147(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_149(a, b, ...) PPUTL_DETAIL_CAT_148(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_150(a, b, ...) PPUTL_DETAIL_CAT_149(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_151(a, b, ...) PPUTL_DETAIL_CAT_150(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_152(a, b, ...) PPUTL_DETAIL_CAT_151(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_153(a, b, ...) PPUTL_DETAIL_CAT_152(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_154(a, b, ...) PPUTL_DETAIL_CAT_153(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_155(a, b, ...) PPUTL_DETAIL_CAT_154(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_156(a, b, ...) PPUTL_DETAIL_CAT_155(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_157(a, b, ...) PPUTL_DETAIL_CAT_156(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_158(a, b, ...) PPUTL_DETAIL_CAT_157(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_159(a, b, ...) PPUTL_DETAIL_CAT_158(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_160(a, b, ...) PPUTL_DETAIL_CAT_159(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_161(a, b, ...) PPUTL_DETAIL_CAT_160(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_162(a, b, ...) PPUTL_DETAIL_CAT_161(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_163(a, b, ...) PPUTL_DETAIL_CAT_162(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_164(a, b, ...) PPUTL_DETAIL_CAT_163(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_165(a, b, ...) PPUTL_DETAIL_CAT_164(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_166(a, b, ...) PPUTL_DETAIL_CAT_165(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_167(a, b, ...) PPUTL_DETAIL_CAT_166(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_168(a, b, ...) PPUTL_DETAIL_CAT_167(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_169(a, b, ...) PPUTL_DETAIL_CAT_168(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_170(a, b, ...) PPUTL_DETAIL_CAT_169(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_171(a, b, ...) PPUTL_DETAIL_CAT_170(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_172(a, b, ...) PPUTL_DETAIL_CAT_171(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_173(a, b, ...) PPUTL_DETAIL_CAT_172(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_174(a, b, ...) PPUTL_DETAIL_CAT_173(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_175(a, b, ...) PPUTL_DETAIL_CAT_174(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_176(a, b, ...) PPUTL_DETAIL_CAT_175(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_177(a, b, ...) PPUTL_DETAIL_CAT_176(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_178(a, b, ...) PPUTL_DETAIL_CAT_177(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_179(a, b, ...) PPUTL_DETAIL_CAT_178(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_180(a, b, ...) PPUTL_DETAIL_CAT_179(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_181(a, b, ...) PPUTL_DETAIL_CAT_180(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_182(a, b, ...) PPUTL_DETAIL_CAT_181(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_183(a, b, ...) PPUTL_DETAIL_CAT_182(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_184(a, b, ...) PPUTL_DETAIL_CAT_183(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_185(a, b, ...) PPUTL_DETAIL_CAT_184(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_186(a, b, ...) PPUTL_DETAIL_CAT_185(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_187(a, b, ...) PPUTL_DETAIL_CAT_186(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_188(a, b, ...) PPUTL_DETAIL_CAT_187(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_189(a, b, ...) PPUTL_DETAIL_CAT_188(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_190(a, b, ...) PPUTL_DETAIL_CAT_189(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_191(a, b, ...) PPUTL_DETAIL_CAT_190(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_192(a, b, ...) PPUTL_DETAIL_CAT_191(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_193(a, b, ...) PPUTL_DETAIL_CAT_192(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_194(a, b, ...) PPUTL_DETAIL_CAT_193(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_195(a, b, ...) PPUTL_DETAIL_CAT_194(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_196(a, b, ...) PPUTL_DETAIL_CAT_195(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_197(a, b, ...) PPUTL_DETAIL_CAT_196(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_198(a, b, ...) PPUTL_DETAIL_CAT_197(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_199(a, b, ...) PPUTL_DETAIL_CAT_198(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_200(a, b, ...) PPUTL_DETAIL_CAT_199(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_201(a, b, ...) PPUTL_DETAIL_CAT_200(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_202(a, b, ...) PPUTL_DETAIL_CAT_201(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_203(a, b, ...) PPUTL_DETAIL_CAT_202(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_204(a, b, ...) PPUTL_DETAIL_CAT_203(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_205(a, b, ...) PPUTL_DETAIL_CAT_204(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_206(a, b, ...) PPUTL_DETAIL_CAT_205(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_207(a, b, ...) PPUTL_DETAIL_CAT_206(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_208(a, b, ...) PPUTL_DETAIL_CAT_207(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_209(a, b, ...) PPUTL_DETAIL_CAT_208(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_210(a, b, ...) PPUTL_DETAIL_CAT_209(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_211(a, b, ...) PPUTL_DETAIL_CAT_210(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_212(a, b, ...) PPUTL_DETAIL_CAT_211(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_213(a, b, ...) PPUTL_DETAIL_CAT_212(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_214(a, b, ...) PPUTL_DETAIL_CAT_213(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_215(a, b, ...) PPUTL_DETAIL_CAT_214(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_216(a, b, ...) PPUTL_DETAIL_CAT_215(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_217(a, b, ...) PPUTL_DETAIL_CAT_216(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_218(a, b, ...) PPUTL_DETAIL_CAT_217(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_219(a, b, ...) PPUTL_DETAIL_CAT_218(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_220(a, b, ...) PPUTL_DETAIL_CAT_219(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_221(a, b, ...) PPUTL_DETAIL_CAT_220(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_222(a, b, ...) PPUTL_DETAIL_CAT_221(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_223(a, b, ...) PPUTL_DETAIL_CAT_222(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_224(a, b, ...) PPUTL_DETAIL_CAT_223(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_225(a, b, ...) PPUTL_DETAIL_CAT_224(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_226(a, b, ...) PPUTL_DETAIL_CAT_225(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_227(a, b, ...) PPUTL_DETAIL_CAT_226(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_228(a, b, ...) PPUTL_DETAIL_CAT_227(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_229(a, b, ...) PPUTL_DETAIL_CAT_228(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_230(a, b, ...) PPUTL_DETAIL_CAT_229(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_231(a, b, ...) PPUTL_DETAIL_CAT_230(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_232(a, b, ...) PPUTL_DETAIL_CAT_231(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_233(a, b, ...) PPUTL_DETAIL_CAT_232(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_234(a, b, ...) PPUTL_DETAIL_CAT_233(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_235(a, b, ...) PPUTL_DETAIL_CAT_234(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_236(a, b, ...) PPUTL_DETAIL_CAT_235(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_237(a, b, ...) PPUTL_DETAIL_CAT_236(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_238(a, b, ...) PPUTL_DETAIL_CAT_237(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_239(a, b, ...) PPUTL_DETAIL_CAT_238(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_240(a, b, ...) PPUTL_DETAIL_CAT_239(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_241(a, b, ...) PPUTL_DETAIL_CAT_240(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_242(a, b, ...) PPUTL_DETAIL_CAT_241(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_243(a, b, ...) PPUTL_DETAIL_CAT_242(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_244(a, b, ...) PPUTL_DETAIL_CAT_243(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_245(a, b, ...) PPUTL_DETAIL_CAT_244(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_246(a, b, ...) PPUTL_DETAIL_CAT_245(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_247(a, b, ...) PPUTL_DETAIL_CAT_246(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_248(a, b, ...) PPUTL_DETAIL_CAT_247(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_249(a, b, ...) PPUTL_DETAIL_CAT_248(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_250(a, b, ...) PPUTL_DETAIL_CAT_249(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_251(a, b, ...) PPUTL_DETAIL_CAT_250(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_252(a, b, ...) PPUTL_DETAIL_CAT_251(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_253(a, b, ...) PPUTL_DETAIL_CAT_252(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_254(a, b, ...) PPUTL_DETAIL_CAT_253(a##b, __VA_ARGS__)
#define PPUTL_DETAIL_CAT_255(a, b, ...) PPUTL_DETAIL_CAT_254(a##b, __VA_ARGS__)
#// clang-format on
#
#endif

//                                                    #include <pputl/cat.h> }}}
//                                                        embedded libraries }}}

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

//                                                      ccutl.exists_concept {{{

//                                        ccutl.exists_concept feature guard {{{
#ifndef CCUTL_EXISTS_CONCEPT_INCLUDED
#define CCUTL_EXISTS_CONCEPT_INCLUDED
//                                        ccutl.exists_concept feature guard }}}

/**
 * creates a concept for specialization validity.
 * different template parameter layouts require different SFINAE setups;
 * use this macro to create a concept for a given parameter layout.
 *
 * see ccutl.exists for an example using a (class...) paramter layout.
 *
 * \param name                  - final name of the concept
 * \param template_params_tuple - tupled template parameter types and names
 * \param template_args_tuple   - tupled template argument invocation text
 *
 * \note template parameter names cannot be `Template_`
 *
 * \code
 *   #include <ctl/different.h>
 *   #include <ctl/same.h>
 *   #include <ctl/exists_concept.h>
 *
 *   // create the concept 'exists'
 *   CTL_EXISTS_CONCEPT(exists, (class... Ts), (Ts...));
 *
 *   // may only be specialized with templates that allow an int- type<int>
 *   template <template<class...> class IntableTemplate>
 *   requires exists<IntableTemplate, int>
 *   struct example;
 *
 *   template <ctl::same<int>>
 *   struct good;
 *
 *   template <ctl::different<int>>
 *   struct bad;
 *
 *   constexpr bool ex0 = exists<good, int>; // true
 *   constexpr bool ex1 = exists<bad,  int>; // false
 * \endcode
 *
 * \anchor exists_concept
 * \ingroup ccutl
 */
#define CTL_EXISTS_CONCEPT(name, template_params_tuple, template_args_tuple) \
  template <                                                                 \
      template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_,    \
      PPUTL_TUPLE_ARGS(template_params_tuple)>                               \
  concept name = requires {                                                  \
    typename Template_<PPUTL_TUPLE_ARGS(template_args_tuple)>;               \
  }

//                                        ccutl.exists_concept version guard {{{

#define CCUTL_EXISTS_CONCEPT_VERSION_MAJOR 0
#define CCUTL_EXISTS_CONCEPT_VERSION_MINOR 3
#define CCUTL_EXISTS_CONCEPT_VERSION_PATCH 0

#elif CCUTL_EXISTS_CONCEPT_VERSION_MAJOR != 0
#error   ccutl.exists_concept major version mismatch
#elif CCUTL_EXISTS_CONCEPT_VERSION_MINOR != 3
#error   ccutl.exists_concept minor version mismatch
#elif CCUTL_EXISTS_CONCEPT_VERSION_PATCH != 0
#warning ccutl.exists_concept patch version mismatch
#endif

//                                        ccutl.exists_concept version guard }}}

//                                                      ccutl.exists_concept }}}
//                                                              ccutl.exists {{{

//                                                ccutl.exists feature guard {{{
#ifndef CCUTL_EXISTS_INCLUDED
#define CCUTL_EXISTS_INCLUDED
//                                                ccutl.exists feature guard }}}

// detail {{{
namespace detail {
namespace exists {
/// generated concept implementation for exists
CTL_EXISTS_CONCEPT(impl, (class... Ts), (Ts...));
} // namespace exists
} // namespace detail
// detail }}}

/**
 * defines templates that are specializable by Ts...
 *
 * \note may only be used with template structs, classes, and unions
 *
 * \code
 *   #include "ctl/exists.h"
 *   #include "ctl/same.h"
 *
 *   using std::tuple;
 *   template <ctl::same<int> T>
 *   struct foo {};
 *
 *   auto x0 = ctl::exists<foo, int>;      // true
 *   auto x1 = ctl::exists<foo, int, int>; // false
 *   auto x2 = ctl::exists<foo, long>;     // false
 * \endcode
 *
 * \anchor exists
 * \ingroup ccutl
 */
template <template <class...> class Template, class... Args>
concept exists = detail::exists::impl<Template, Args...>;

//                                                ccutl.exists version guard {{{

#define CCUTL_EXISTS_VERSION_MAJOR 0
#define CCUTL_EXISTS_VERSION_MINOR 3
#define CCUTL_EXISTS_VERSION_PATCH 0

#elif CCUTL_EXISTS_VERSION_MAJOR != 0
#error   ccutl.exists major version mismatch
#elif CCUTL_EXISTS_VERSION_MINOR != 3
#error   ccutl.exists minor version mismatch
#elif CCUTL_EXISTS_VERSION_PATCH != 0
#warning ccutl.exists patch version mismatch
#endif

//                                                ccutl.exists version guard }}}

//                                                              ccutl.exists }}}
//                                                                ccutl.targ {{{

//                                                  ccutl.targ feature guard {{{
#ifndef CCUTL_TARG_INCLUDED
#define CCUTL_TARG_INCLUDED
//                                                  ccutl.targ feature guard }}}

// detail {{{
namespace detail {
namespace targ {
/// primary template for targ_::impl
template <std::size_t, std::size_t, class...>
struct impl;
/// end of iteration; type represents first type
template <std::size_t targ, class First, class... Rest>
struct impl<targ, targ, First, Rest...> {
  using type = First;
};
/// iterates until i reaches target
template <std::size_t targ, std::size_t i, class First, class... Rest>
struct impl<targ, i, First, Rest...> {
  using type = typename impl<targ, i + 1, Rest...>::type;
};
/// helper typedef for impl::type
template <std::size_t targ, class... Pack>
using type = typename impl<targ, 0, Pack...>::type;
/// checks if idx can be used to index Ts...
template <std::size_t idx, class... Ts>
inline constexpr bool
    valid_indexable_pack = sizeof...(Ts) > 0 && idx < sizeof...(Ts);
} // namespace targ
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off

/**
 * represents the type template argument at index idx
 *
 * \code
 *   #include "ctl/targ.h"
 *   using x0 = ctl::targ<0, int, float, double>; // int
 *   using x1 = ctl::targ<1, int, float, double>; // float
 *   using x2 = ctl::targ<2, int, float, double>; // double
 * \endcode
 *
 * \anchor targ
 * \ingroup ccutl
 */
template <std::size_t idx, class... Ts>
requires detail::targ::valid_indexable_pack<idx, Ts...>
using targ = detail::targ::type<idx, Ts...>;

/*                                                        */ // clang-format on

//                                                  ccutl.targ version guard {{{

#define CCUTL_TARG_VERSION_MAJOR 0
#define CCUTL_TARG_VERSION_MINOR 3
#define CCUTL_TARG_VERSION_PATCH 0

#elif CCUTL_TARG_VERSION_MAJOR != 0
#error   ccutl.targ major version mismatch
#elif CCUTL_TARG_VERSION_MINOR != 3
#error   ccutl.targ minor version mismatch
#elif CCUTL_TARG_VERSION_PATCH != 0
#warning ccutl.targ patch version mismatch
#endif

//                                                  ccutl.targ version guard }}}

//                                                                ccutl.targ }}}
//                                                      ccutl.typeof_concept {{{

//                                        ccutl.typeof_concept feature guard {{{
#ifndef CCUTL_TYPEOF_CONCEPT_INCLUDED
#define CCUTL_TYPEOF_CONCEPT_INCLUDED
//                                        ccutl.typeof_concept feature guard }}}

/**
 * creates a template spececialization detection concept.
 * different template parameter layouts require different SFINAE setups;
 * use this macro to create a concept for a given parameter layout.
 *
 * see ccutl.typeof for an example using a (class...) paramter layout.
 *
 * \param name                  - final name of the concept
 * \param template_params_tuple - tupled template parameter types and names
 * \param template_args_tuple   - tupled template argument invocation text
 *
 * \note template parameter names cannot be `Template_` or `T_`
 *
 * \code
 *   #include <vector>
 *   #include <tuple>
 *   #include <array>
 *
 *   #include <ctl/typeof_concept.h>
 *
 *   using std::vector;
 *   using std::array;
 *   using std::tuple;
 *
 *   // template<class T, template<class... Ts> class Template>
 *   // concept type_typeof = {sfinae};
 *   CTL_TYPEOF_CONCEPT(type_typeof, (class... Ts), (Ts...));
 *
 *   constexpr bool ex0 = type_typeof<vector<int>, vector>; // true
 *   constexpr bool ex1 = type_typeof<vector<int>, tuple>;  // false
 *
 *   // template<class T, template<class T, std::size_t sz> class Template>
 *   // concept type_size_typeof = {sfinae};
 *   CTL_TYPEOF_CONCEPT(type_size_typeof, (class T, std::size_t sz), (T, sz));
 *
 *   constexpr bool ex2 = type_size_typeof<array<int, 3>, array>; // true
 *   constexpr bool ex3 = type_size_typeof<tuple<int>, array>;    // false
 * \endcode
 *
 * \anchor typeof_concept
 * \ingroup ccutl
 */
#define CTL_TYPEOF_CONCEPT(name, template_params_tuple, template_args_tuple)   \
  namespace detail {                                                           \
  namespace PPUTL_CAT(name, _concept_) {                                       \
                                                                               \
    template <template <PPUTL_TUPLE_ARGS(template_params_tuple)> class, class> \
    struct test {                                                              \
      static constexpr bool result = false;                                    \
    };                                                                         \
                                                                               \
    template <                                                                 \
        template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_,    \
        PPUTL_TUPLE_ARGS(template_params_tuple)>                               \
    struct test<Template_, Template_<PPUTL_TUPLE_ARGS(template_args_tuple)>> { \
      static constexpr bool result = true;                                     \
    };                                                                         \
                                                                               \
  } /* namespace PPUTL_CAT(name, _concept_) */                                 \
  } /* namespace detail */                                                     \
                                                                               \
  template <                                                                   \
      class T_,                                                                \
      template <PPUTL_TUPLE_ARGS(template_params_tuple)> class Template_>      \
  concept name =                                                               \
      detail::PPUTL_CAT(name, _concept_)::test<Template_, T_>::result

//                                        ccutl.typeof_concept version guard {{{

#define CCUTL_TYPEOF_CONCEPT_VERSION_MAJOR 0
#define CCUTL_TYPEOF_CONCEPT_VERSION_MINOR 3
#define CCUTL_TYPEOF_CONCEPT_VERSION_PATCH 0

#elif CCUTL_TYPEOF_CONCEPT_VERSION_MAJOR != 0
#error   ccutl.typeof_concept major version mismatch
#elif CCUTL_TYPEOF_CONCEPT_VERSION_MINOR != 3
#error   ccutl.typeof_concept minor version mismatch
#elif CCUTL_TYPEOF_CONCEPT_VERSION_PATCH != 0
#warning ccutl.typeof_concept patch version mismatch
#endif

//                                        ccutl.typeof_concept version guard }}}

//                                                      ccutl.typeof_concept }}}
//                                                              ccutl.typeof {{{

//                                                ccutl.typeof feature guard {{{
#ifndef CCUTL_TYPEOF_INCLUDED
#define CCUTL_TYPEOF_INCLUDED
//                                                ccutl.typeof feature guard }}}

// detail {{{
namespace detail {
namespace typeof { // clang-format off
/// generated concept implementation for typeof
CTL_TYPEOF_CONCEPT(impl, (class... Ts), (Ts...)); // clang-format on
} // namespace typeof
} // namespace detail
// detail }}}

/**
 * Detects template specializations for type-parameter templates (<class...>)
 *
 * \code
 *   #include <tuple>
 *   #include "ctl/typeof.h"
 *   using std::tuple;
 *   auto x0 = ctl::typeof<tuple<int, int>, tuple>; // true
 *   auto x1 = ctl::typeof<tuple<int, int>, pair>;  // false
 * \endcode
 *
 * \anchor typeof
 * \ingroup ccutl
 */
template <class T, template <class...> class Template>
concept typeof = detail::typeof ::impl<T, Template>;

//                                                ccutl.typeof version guard {{{

#define CCUTL_TYPEOF_VERSION_MAJOR 0
#define CCUTL_TYPEOF_VERSION_MINOR 3
#define CCUTL_TYPEOF_VERSION_PATCH 0

#elif CCUTL_TYPEOF_VERSION_MAJOR != 0
#error   ccutl.typeof major version mismatch
#elif CCUTL_TYPEOF_VERSION_MINOR != 3
#error   ccutl.typeof minor version mismatch
#elif CCUTL_TYPEOF_VERSION_PATCH != 0
#warning ccutl.typeof patch version mismatch
#endif

//                                                ccutl.typeof version guard }}}

//                                                              ccutl.typeof }}}

// {{{ detail
template <class...>
struct type_pack; // forward declaration for detail functions

namespace detail {
namespace type_pack {
/// pulls template types from specialzied template
template <template <class...> class, class>
struct from;
/// pulls template types from specialzied template
template <template <class...> class Template, class... Rs>
struct from<Template, Template<Rs...>> {
  template <class... Ls>
  using type = ctl::type_pack<Ls..., Rs...>;
};

/*                                                        */ // clang-format off
/// removes the last template type from Ts...
template <class... Ts, std::size_t... seq>
requires (sizeof...(Ts) > 0)
[[nodiscard]] inline constexpr auto
pop_back(std::index_sequence<seq...> &&) noexcept {
  return ctl::type_pack<ctl::targ<seq, Ts...>...>{};
}
/// removes the first template type from Ts...
template <std::size_t n_removed, class... Ts, std::size_t... seq>
requires (sizeof...(Ts) > 0 and n_removed <= sizeof...(Ts))
[[nodiscard]] static constexpr auto
pop_front(std::index_sequence<seq...> &&) noexcept {
  return ctl::type_pack<ctl::targ<seq + n_removed, Ts...>...>{};
}
/// creates a type_pack from a section of Ts...
template <std::size_t begin, class... Ts, std::size_t... seq>
requires (sizeof...(Ts) > 0)
[[nodiscard]] static constexpr auto
slice(std::index_sequence<seq...> &&) noexcept {
  return ctl::type_pack<ctl::targ<seq + begin, Ts...>...>{};
} /*                                                      */ // clang-format on

/// concatenates a nontype pack with Us...
template <class...>
struct concat;
/// concatenates a nontype pack with Us...
template <class... Us>
struct concat<ctl::type_pack<Us...>> {
  template <class... Ts>
  using type = ctl::type_pack<Ts..., Us...>;
};
} // namespace type_pack
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off
/**
 * Provides a template type arg container with transformational utilities
 *
 * \code
 *   #include <tuple>
 *   #include <ctl/type_pack.h>
 *
 *   using std::tuple;
 *
 *   using t0 = ctl::type_pack<>;                  // type_pack<>
 *   using t1 = t0::push_back<int>;                // type_pack<int>
 *   using t2 = t1::push_front<unsigned>;          // type_pack<unsigned, int>
 *   using t3 = t2::concat<type_pack<long, char>>; // type_pack<unsigned, int,
 *                                                              long, char>
 *   using t4 = t3::pop_back<>;                    // type_pack<unsigned, int,
 *                                                              long>
 *   using t5 = t4::pop_front<2>;                  // type_pack<long>
 *   using t6 = t5::to<tuple>;                     // tuple<long>
 *   using t7 = t5::get<0>;                        // long
 *                                                 //
 *   auto sz = t5::size;                           // 1
 * \endcode
 *
 * \anchor type_pack
 * \ingroup ccutl
 */
template <class... Ts>
struct type_pack {
  constexpr type_pack()                         = default;
  constexpr type_pack(const type_pack<Ts...> &) = default;
  constexpr type_pack(type_pack<Ts...> &&)      = default;
  ~type_pack()                                  = default;
  /// Placeholder constructor for deduction-guide construction
  template <template <class...> class Template, class... Us>
  constexpr type_pack(const Template<Us...> &) noexcept {
  }
  /// Placeholder constructor for deduction-guide construction
  template <template <class...> class Template, class... Us>
  constexpr type_pack(Template<Us...> &&) noexcept {
  }

  /// Creates a type_pack from all type template arguments in a type template
  ///
  /// \tparam Template               - Template name
  /// \tparam T [Template<class...>] - Type to grab arguments from
  /// \code
  ///   type_pack<>::from<Template<int, float>>; // -> type_pack<int, float>
  /// \endcode
  template <
      template <class...> class Template, typeof<Template> T>
  using from =
      typename detail::type_pack::from<Template, T>::template type<Ts...>;

  /// Represents a type-specialized template using the types in this pack
  /// \tparam Template - Template to type-specialize
  template <template <class...> class Template>
  requires exists<Template, Ts...>
  using to = Template<Ts...>;

  /// Represents the number of types in the pack
  static constexpr std::size_t size = sizeof...(Ts);

  /// Represents a type from the pack at index idx
  /// \tparam idx - Index to retrieve
  template <std::size_t idx>
  requires (idx < size)
  using get = targ<idx, Ts...>;

  /// Represents a type_pack with T pushed to the back
  /// \tparam T - Type to push back
  template <class T>
  using push_back = type_pack<Ts..., T>;

  /// Represents a type_pack with T pushed to the front
  /// \tparam T - Type to push front
  template <class T>
  using push_front = type_pack<T, Ts...>;

  /// Represents a type_pack with its last n_removed elements removed
  /// \tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires (size >= n_removed)
  using pop_back =
      std::remove_const_t<decltype(detail::type_pack::pop_back<Ts...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// Represents a type_pack with its first n_removed elements removed
  /// \tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires (size >= n_removed)
  using pop_front =
      std::remove_const_t<
          decltype(detail::type_pack::pop_front<n_removed, Ts...>(
              std::make_index_sequence<size - n_removed>()))>;

  /// Represents a type_pack from a slice of this pack [begin, end)
  /// \tparam begin - First element index
  /// \tparam end   - Element index following last element index
  template <std::size_t begin, std::size_t end = size>
  requires ( size >= 0 and begin <= end and end <= size )
  using slice =
      std::remove_const_t<decltype(detail::type_pack::slice<begin, Ts...>(
          std::make_index_sequence<end - begin>()))>;

  /// Represents a type_pack with types from the concatenation of
  ///     another type_pack -- <this..., other...>
  /// \tparam Other - Other type_pack to concatenate
  template <typeof<type_pack> Other>
  using concat =
      typename detail::type_pack::concat<Other>::template type<Ts...>;
}; /*                                                     */ // clang-format on

/// allows for deduction construction from type template objects
template <template <class...> class Template, class... Ts>
type_pack(Template<Ts...>) -> type_pack<Ts...>;

} // namespace CCUTL_NAMESPACE

//                                             ccutl.type_pack version guard {{{

#define CCUTL_TYPE_PACK_VERSION_MAJOR 0
#define CCUTL_TYPE_PACK_VERSION_MINOR 3
#define CCUTL_TYPE_PACK_VERSION_PATCH 0

#elif CCUTL_TYPE_PACK_VERSION_MAJOR != 0
#error   ccutl.type_pack major version mismatch
#elif CCUTL_TYPE_PACK_VERSION_MINOR != 3
#error   ccutl.type_pack minor version mismatch
#elif CCUTL_TYPE_PACK_VERSION_PATCH != 0
#warning ccutl.type_pack patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                             ccutl.type_pack version guard }}}
