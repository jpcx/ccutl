#ifndef CCUTL_DETAIL_EXPORT_CONFIG_H_INCLUDED
#define CCUTL_DETAIL_EXPORT_CONFIG_H_INCLUDED
#/////                                                                     c++20
#///////////////////////////////////////////////////////////////////////////////
#/// @brief namespace definition macros, version macros, and C++ version check
#/// @file
#//                      |    |
#//    __|   __|  |   |  __|  |
#//   (     (     |   |  |    |
#//  \___| \___| \__,_| \__| _|
#//
#//  ccutl Core Utilities
#//  Copyright (C) 2020 Justin Collier <m@jpcx.dev>
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
#if (!defined(__cplusplus) || __cplusplus <= 201703L)
#error: ccutl requires at least C++20
#endif
#
#define CCUTL_VERSION_MAJOR 0
#define CCUTL_VERSION_MINOR 1
#define CCUTL_VERSION_PATCH 0
#
#ifdef CCUTL_MODULES
#define CCUTL_BEGIN_EXPORT_NAMESPACE(fullname) export namespace fullname {
#define CCUTL_END_EXPORT_NAMESPACE             }
#else
#define CCUTL_BEGIN_EXPORT_NAMESPACE(fullname) namespace fullname {
#define CCUTL_END_EXPORT_NAMESPACE             }
#endif
#
#endif
