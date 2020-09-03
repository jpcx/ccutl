#ifndef CCUTL_MV_H_INCLUDED
#define CCUTL_MV_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link mv ccutl.mv\endlink -
/// move an rvalue
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
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.mv;
import ccutl.noref;
export import ccutl.noref;
#else
#include "ccutl/noref.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/*

note: the following was copied from the C++ standard draft GitHub sources
      https://github.com/cplusplus/draft.git 60a9591

©ISO/IEC

20.2.4  forward/move helpers [forward]

...

  template <class T> constexpr remove_reference_t<T>&& move(T&& t) noexcept;

7   Returns: static_cast<remove_reference_t<T>&&>(t).

*/

/// move an rvalue
///
/// @ingroup ccutl
/// @anchor  mv
template <class T>
constexpr noref<T> &&
mv(T &&t) noexcept {
  return static_cast<noref<T> &&>(t);
}

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
