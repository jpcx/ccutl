#ifndef CCUTL_BOOLEAN_TESTABLE_H_INCLUDED
#define CCUTL_BOOLEAN_TESTABLE_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link boolean_testable ccutl.boolean_testable\endlink -
/// describes a bool-convertible B that is capable of usual logic operations
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
module;
#else
#include <concepts>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.boolean_testable;
import std;
import ccutl.fwd;
export import std;
export import ccutl.fwd;
#else
#include "ccutl/fwd.h"
#endif

namespace ccutl::detail_::boolean_testable_ {
/// requires that a type is convertible to bool
///
/// @ingroup detail_
template <class B>
concept impl = std::convertible_to<B, bool>;
} // namespace ccutl::detail_::boolean_testable_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)
/// describes a bool-convertible B that is capable of usual logic operations
///
/// @note ex: `bool`, `std::true_type`, `std::bitset<N>::reference`, `int*`
/// @see https://en.cppreference.com/w/cpp/concepts/boolean-testable
///
/// @tparam B - expression result type
///
/// @code
///   #include "ccutl/boolean_testable.h"
///   // import ccutl.boolean_testable; //
///   auto x0 = ccutl::boolean_testable<bool>;           // true
///   auto x1 = ccutl::boolean_testable<std::true_type>; // true
/// @endcode
///
/// @ingroup ccutl
/// @anchor  boolean_testable
template <class B>
concept boolean_testable =
    detail_::boolean_testable_::impl<B> &&requires(B &&b) {
  { fwd<B>(b) }
  ->detail_::boolean_testable_::impl;
};
CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
