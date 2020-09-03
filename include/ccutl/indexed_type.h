#ifndef CCUTL_INDEXED_TYPE_H_INCLUDED
#define CCUTL_INDEXED_TYPE_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link indexed_type ccutl.indexed_type\endlink -
/// represents the type template argument at index idx
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
#include <cstdint>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.indexed_type;
import std;
export import std;
#endif

namespace ccutl::detail_::indexed_type_ {

/// @addtogroup detail_
/// \{

/// primary template for indexed_type_::impl
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

/// \}

} // namespace ccutl::detail_::indexed_type_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/*                                                        */ // clang-format off

/// represents the type template argument at index idx
///
/// @code
///   #include "ccutl/indexed_type.h"
///   // import ccutl.indexed_type; //
///   using x0 = ccutl::indexed_type<0, int, float, double>; // int
///   using x1 = ccutl::indexed_type<1, int, float, double>; // float
///   using x2 = ccutl::indexed_type<2, int, float, double>; // double
/// @endcode
///
/// @ingroup ccutl
/// @anchor  indexed_type
template <std::size_t idx, class... Ts>
requires detail_::indexed_type_::valid_indexable_pack<idx, Ts...>
using indexed_type = detail_::indexed_type_::type<idx, Ts...>;

/*                                                        */ // clang-format on

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
