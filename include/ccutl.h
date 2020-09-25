#ifndef CCUTL_H_INCLUDED
#define CCUTL_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link ccutl ccutl\endlink - ccutl Core Utilities
/// @file
/// @defgroup ccutl ccutl
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
export module ccutl;
export import ccutl.arg_at;
export import ccutl.boolean_testable;
export import ccutl.different;
export import ccutl.eq;
export import ccutl.fwd;
export import ccutl.gt;
export import ccutl.gteq;
export import ccutl.highest;
export import ccutl.lowest;
export import ccutl.lt;
export import ccutl.lteq;
export import ccutl.meta;
export import ccutl.meta.eq;
export import ccutl.meta.gt;
export import ccutl.meta.gteq;
export import ccutl.meta.lt;
export import ccutl.meta.lteq;
export import ccutl.meta.neq;
export import ccutl.mv;
export import ccutl.neq;
export import ccutl.nocv;
export import ccutl.nocvref;
export import ccutl.nontype_pack;
export import ccutl.nontype_specialization_of;
export import ccutl.noref;
export import ccutl.range_of;
export import ccutl.same;
export import ccutl.specializable_with;
export import ccutl.specialization_of;
export import ccutl.specializes;
export import ccutl.str_eq;
export import ccutl.str_gt;
export import ccutl.str_gteq;
export import ccutl.str_lt;
export import ccutl.str_lteq;
export import ccutl.str_neq;
export import ccutl.strlen;
export import ccutl.subscriptable_to;
export import ccutl.type_at;
export import ccutl.type_pack;
export import std;
#else
#include "ccutl/arg_at.h"
#include "ccutl/boolean_testable.h"
#include "ccutl/different.h"
#include "ccutl/eq.h"
#include "ccutl/fwd.h"
#include "ccutl/gt.h"
#include "ccutl/gteq.h"
#include "ccutl/highest.h"
#include "ccutl/lowest.h"
#include "ccutl/lt.h"
#include "ccutl/lteq.h"
#include "ccutl/macros/make_specialization_of_concept.h"
#include "ccutl/meta.h"
#include "ccutl/meta/eq.h"
#include "ccutl/meta/gt.h"
#include "ccutl/meta/gteq.h"
#include "ccutl/meta/lt.h"
#include "ccutl/meta/lteq.h"
#include "ccutl/meta/neq.h"
#include "ccutl/mv.h"
#include "ccutl/neq.h"
#include "ccutl/nocv.h"
#include "ccutl/nocvref.h"
#include "ccutl/nontype_pack.h"
#include "ccutl/nontype_specialization_of.h"
#include "ccutl/noref.h"
#include "ccutl/range_of.h"
#include "ccutl/same.h"
#include "ccutl/specializable_with.h"
#include "ccutl/specialization_of.h"
#include "ccutl/specializes.h"
#include "ccutl/str_eq.h"
#include "ccutl/str_gt.h"
#include "ccutl/str_gteq.h"
#include "ccutl/str_lt.h"
#include "ccutl/str_lteq.h"
#include "ccutl/str_neq.h"
#include "ccutl/strlen.h"
#include "ccutl/subscriptable_to.h"
#include "ccutl/type_at.h"
#include "ccutl/type_pack.h"
#endif

// detail group definition

/// contains internal detail functions
///
/// @defgroup detail_
/// @ingroup ccutl

#endif
