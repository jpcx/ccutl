#ifndef CCUTL_TYPE_PACK_H_INCLUDED
#define CCUTL_TYPE_PACK_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link type_pack ccutl.type_pack\endlink -
/// Provides a type template arg container with transformational utilities
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
#include <type_traits>
#include <utility>
#endif

#include "ccutl/detail_/config.h"

#ifdef CCUTL_MODULES
export module ccutl.type_pack;

import std;
import ccutl.type_at;
import ccutl.meta.gt;
import ccutl.meta.gteq;
import ccutl.meta.lt;
import ccutl.meta.lteq;
import ccutl.specializable_with;
import ccutl.specialization_of;
export import std;
export import ccutl.type_at;
export import ccutl.meta.gt;
export import ccutl.meta.gteq;
export import ccutl.meta.lt;
export import ccutl.meta.lteq;
export import ccutl.specializable_with;
export import ccutl.specialization_of;
#else
#include "ccutl/meta/gt.h"
#include "ccutl/meta/gteq.h"
#include "ccutl/meta/lt.h"
#include "ccutl/meta/lteq.h"
#include "ccutl/specializable_with.h"
#include "ccutl/specialization_of.h"
#include "ccutl/type_at.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)
template <class...>
struct type_pack;           // forward declaration for detail functions
CCUTL_END_EXPORT_NAMESPACE; // ccutl

/*.----------------------------------------------------------------------------,
 /                                   Detail */

namespace ccutl::detail_::type_pack_ {
/// @addtogroup detail_
/// \{

/// pulls template types from specialzied template
template <template <class...> class, class>
struct from;
/// pulls template types from specialzied template
template <template <class...> class Template, class... Rs>
struct from<Template, Template<Rs...>> {
  template <class... Ls>
  using type = type_pack<Ls..., Rs...>;
};

/*                                                        */ // clang-format off
/// removes the last template type from Ts...
template <class... Ts, std::size_t... seq>
requires meta::gt<sizeof...(Ts), 0>
[[nodiscard]] inline constexpr auto
pop_back(std::index_sequence<seq...> &&) noexcept {
  return type_pack<type_at<seq, Ts...>...>{};
}
/// removes the first template type from Ts...
template <std::size_t n_removed, class... Ts, std::size_t... seq>
requires meta::gt<sizeof...(Ts), 0> and meta::lteq<n_removed, sizeof...(Ts)>
[[nodiscard]] static constexpr auto
pop_front(std::index_sequence<seq...> &&) noexcept {
  return type_pack<type_at<seq + n_removed, Ts...>...>{};
}
/// creates a type_pack from a section of Ts...
template <std::size_t begin, class... Ts, std::size_t... seq>
requires meta::gt<sizeof...(Ts), 0>
[[nodiscard]] static constexpr auto
slice(std::index_sequence<seq...> &&) noexcept {
  return type_pack<type_at<seq + begin, Ts...>...>{};
} /*                                                      */ // clang-format on

/// concatenates a nontype pack with Us...
template <class...>
struct concat;
/// concatenates a nontype pack with Us...
template <class... Us>
struct concat<type_pack<Us...>> {
  template <class... Ts>
  using type = type_pack<Ts..., Us...>;
};

/// \}
} // namespace ccutl::detail_::type_pack_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/*                                                        */ // clang-format off
/// Provides a type template arg container with transformational utilities
///
/// @code
///   #include <tuple>
///   // import std; //
///   #include <ccutl/type_pack.h>
///   // import ccutl.type_pack; //
///
///   using std::tuple;
///
///   using t0 = type_pack<>;                       // type_pack<>
///   using t1 = t0::push_back<int>;                // type_pack<int>
///   using t2 = t1::push_front<unsigned>;          // type_pack<unsigned, int>
///   using t3 = t2::concat<type_pack<long, char>>; // type_pack<unsigned, int,
///                                                              long, char>
///   using t4 = t3::pop_back<>;                    // type_pack<unsigned, int,
///                                                              long>
///   using t5 = t4::pop_front<2>;                  // type_pack<long>
///   using t6 = t5::to<tuple>;                     // tuple<long>
///   using t7 = t5::at<0>;                         // long
///                                                 //
///   auto sz = t5::size;                           // 1
/// @endcode
///
/// @ingroup ccutl
/// @anchor  type_pack
template <class... Ts>
struct type_pack {
  constexpr type_pack()                         = default;
  constexpr type_pack(const type_pack<Ts...> &) = default;
  constexpr type_pack(type_pack<Ts...> &&)      = default;
  ~type_pack()                                  = default;
  /// @brief Placeholder constructor for deduction-guide construction
  template <template <class...> class Template, class... Us>
  constexpr type_pack(const Template<Us...> &) noexcept {
  }
  /// @brief Placeholder constructor for deduction-guide construction
  template <template <class...> class Template, class... Us>
  constexpr type_pack(Template<Us...> &&) noexcept {
  }

  /// @brief Creates a type_pack from all type template arguments in a
  ///        type template
  /// @tparam Template               - Template name
  /// @tparam T [Template<class...>] - Type to grab arguments from
  /// @code
  ///   type_pack<>::from<Template<int, float>>; // -> type_pack<int, float>
  /// @endcode
  template <
      template <class...> class Template, specialization_of<Template> T>
  using from =
      typename detail_::type_pack_::from<Template, T>::template type<Ts...>;

  /// @brief Represents a type-specialized template using the types in this pack
  /// @tparam Template - Template to type-specialize
  template <template <class...> class Template>
  requires specializable_with<Template, Ts...>
  using to = Template<Ts...>;

  /// @brief Represents the number of types in the pack
  static constexpr std::size_t size = sizeof...(Ts);

  /// @brief Represents a type from the pack at index idx
  /// @tparam idx - Index to retrieve
  template <std::size_t idx>
  requires meta::lt<idx, size>
  using at = type_at<idx, Ts...>;

  /// @brief Represents a type_pack with T pushed to the back
  /// @tparam T - Type to push back
  template <class T>
  using push_back = type_pack<Ts..., T>;

  /// @brief Represents a type_pack with T pushed to the front
  /// @tparam T - Type to push front
  template <class T>
  using push_front = type_pack<T, Ts...>;

  /// @brief Represents a type_pack with its last n_removed elements removed
  /// @tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires meta::gteq<size, n_removed>
  using pop_back =
      std::remove_const_t<decltype(detail_::type_pack_::pop_back<Ts...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// @brief Represents a type_pack with its first n_removed elements removed
  /// @tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires meta::gteq<size, n_removed>
  using pop_front =
      std::remove_const_t<
          decltype(detail_::type_pack_::pop_front<n_removed, Ts...>(
              std::make_index_sequence<size - n_removed>()))>;

  /// @brief Represents a type_pack from a slice of this pack [begin, end)
  /// @tparam begin - First element index
  /// @tparam end   - Element index following last element index
  template <std::size_t begin, std::size_t end>
  requires meta::gteq<size, 0>    and
           meta::lteq<begin, end> and
           meta::lteq<end, size>
  using slice =
      std::remove_const_t<decltype(detail_::type_pack_::slice<begin, Ts...>(
          std::make_index_sequence<end - begin>()))>;

  /// @brief Represents a type_pack with types from the concatenation of
  ///        another type_pack -- <this..., other...>
  /// @tparam Other - Other type_pack to concatenate
  template <specialization_of<type_pack> Other>
  using concat =
      typename detail_::type_pack_::concat<Other>::template type<Ts...>;
}; /*                                                     */ // clang-format on

/// @brief Allows for deduction construction from type template objects
template <template <class...> class Template, class... Ts>
type_pack(Template<Ts...>) -> type_pack<Ts...>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
