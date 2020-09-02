#ifndef CCUTL_META_H_INCLUDED
#define CCUTL_META_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief module file for \link meta ccutl.meta\endlink
///        contains metaprogramming-specific variants of ccutl features
/// @file
/// @defgroup meta meta
/// @ingroup ccutl
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
module;
#include "ccutl/detail_/config.h"
export module ccutl.meta;
export import std;
export import ccutl.meta.eq;
export import ccutl.meta.gt;
export import ccutl.meta.gteq;
export import ccutl.meta.lt;
export import ccutl.meta.lteq;
export import ccutl.meta.neq;
#else
#include "ccutl/detail_/config.h"
#include "ccutl/meta/eq.h"
#include "ccutl/meta/gt.h"
#include "ccutl/meta/gteq.h"
#include "ccutl/meta/lt.h"
#include "ccutl/meta/lteq.h"
#include "ccutl/meta/neq.h"
#endif

#endif
