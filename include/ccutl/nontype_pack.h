#ifndef CCUTL_NONTYPE_PACK_H_INCLUDED
#define CCUTL_NONTYPE_PACK_H_INCLUDED
/////                                                                      c++20
////////////////////////////////////////////////////////////////////////////////
/// @brief \link nontype_pack ccutl.nontype_pack\endlink -
/// Provides a nontype template arg container with transformational utilities
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
export module ccutl.nontype_pack;
import std;
import ccutl.arg_at;
import ccutl.meta.gt;
import ccutl.meta.gteq;
import ccutl.meta.lt;
import ccutl.meta.lteq;
import ccutl.nontype_specialization_of;
import ccutl.type_pack;
export import std;
export import ccutl.arg_at;
export import ccutl.meta.gt;
export import ccutl.meta.gteq;
export import ccutl.meta.lt;
export import ccutl.meta.lteq;
export import ccutl.specialization_of;
export import ccutl.type_pack;
#else
#include "ccutl/arg_at.h"
#include "ccutl/meta/gt.h"
#include "ccutl/meta/lt.h"
#include "ccutl/meta/lteq.h"
#include "ccutl/nontype_specialization_of.h"
#include "ccutl/type_pack.h"
#endif

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)
template <auto...>
struct nontype_pack;        // forward declaration for detail functions
CCUTL_END_EXPORT_NAMESPACE; // ccutl

/*.----------------------------------------------------------------------------,
 /                                   Detail                                  */

namespace ccutl::detail_::nontype_pack_ {
/// @addtogroup detail_
/// \{

/// pulls nontype template values from specialzied template
template <template <auto...> class, class>
struct from;
/// pulls nontype template values from specialzied template
template <template <auto...> class Template, auto... rs>
struct from<Template, Template<rs...>> {
  template <auto... ls>
  using type = nontype_pack<ls..., rs...>;
};

/// checks if a template is specializable with vs...
template <template <auto...> class Template, auto... vs>
concept specializable_with_nontypes = requires() {
  typename Template<vs...>;
};

/*                                                        */ // clang-format off
/// removes the last nontype template value from vs...
template <auto... vs, std::size_t... seq>
requires meta::gt<sizeof...(vs), 0>
[[nodiscard]] inline constexpr auto
pop_back(std::index_sequence<seq...> &&) noexcept {
  return nontype_pack<arg_at<seq>(vs...)...>{};
}
/// removes the first nontype template value from vs...
template <std::size_t n_removed, auto... vs, std::size_t... seq>
requires meta::gteq<sizeof...(vs), n_removed>
[[nodiscard]] static constexpr auto
pop_front(std::index_sequence<seq...> &&) noexcept {
  return nontype_pack<arg_at<seq + n_removed>(vs...)...>{};
}
/// creates a nontype_pack from a section of vs...
template <std::size_t begin, auto... vs, std::size_t... seq>
requires meta::gt<sizeof...(vs), 0>
[[nodiscard]] static constexpr auto
slice(std::index_sequence<seq...> &&) noexcept {
  return nontype_pack<arg_at<seq + begin>(vs...)...>{};
} /*                                                      */ // clang-format on

/// concatenates a nontype pack with rs...
template <class>
struct concat;
/// concatenates a nontype pack with rs...
template <auto... rs>
struct concat<nontype_pack<rs...>> {
  template <auto... ls>
  using type = nontype_pack<ls..., rs...>;
};

/// \}
} // namespace ccutl::detail_::nontype_pack_

CCUTL_BEGIN_EXPORT_NAMESPACE(ccutl)

/*                                                        */ // clang-format off
/// Provides a nontype template arg container with transformational utilities
///
/// @code
///   #include "ccutl/nontype_pack.h"
///   // import ccutl.nontype_pack; //
///
///   using t0 = nontype_pack<>;                    // nontype_pack<>
///   using t1 = t0::push_back<0>;                  // nontype_pack<0>
///   using t2 = t1::push_front<1>;                 // nontype_pack<1, 0>
///   using t3 = t2::concat<nontype_pack<2, 3>>;    // nontype_pack<1, 0, 2, 3>
///   using t4 = t3::pop_back<>;                    // nontype_pack<1, 0, 2>
///   using t5 = t4::pop_front<2>;                  // nontype_pack<2>
///   using t6 = t5::to<example>;                   // example<2>
///   using t7 = t5::at<0>;                         // 2
///                                                 //
///   auto sz = t5::size;                           // 1
/// @endcode
///
/// @ingroup ccutl
/// @anchor  nontype_pack
template <auto... values>
struct nontype_pack {
  constexpr nontype_pack()                                = default;
  constexpr nontype_pack(const nontype_pack<values...> &) = default;
  constexpr nontype_pack(nontype_pack<values...> &&)      = default;
  ~nontype_pack()                                         = default;
  /// @brief Placeholder constructor for deduction-guide construction
  template <template <auto...> class Template, auto... vs>
  constexpr nontype_pack(const Template<vs...> &) noexcept {
  }
  /// @brief Placeholder constructor for deduction-guide construction
  template <template <auto...> class Template, auto... vs>
  constexpr nontype_pack(Template<vs...> &&) noexcept {
  }

  /// @brief Creates a nontype_pack from all nontype template arguments in a
  ///        nontype template
  /// @tparam Template              - Template name
  /// @tparam T [Template<auto...>] - Type to grab arguments from
  /// @details
  ///   nontype_pack<>::from<Tpl, Tpl<1, 2, 'a'>>; // -> nontype_pack<1, 2, 'a'>
  template <
      template <auto...> class Template, nontype_specialization_of<Template> T>
  using from = typename detail_::nontype_pack_::from<Template, T>::template type<values...>;

  /// @brief Creates a nontype template specialization from the held values
  /// @tparam Template - Template to type_specialize
  template <template <auto...> class Template>
  requires detail_::nontype_pack_::specializable_with_nontypes<Template, values...>
  using to = Template<values...>;

  /// @brief Represents the number of types in the pack
  static constexpr std::size_t size = sizeof...(values);

  /// @brief type_pack of the types of each value
  using types = type_pack<decltype(values)...>;

  /// @brief Represents the type of the value at index idx
  /// @tparam idx - Index of the value
  template <std::size_t idx>
  using type_at = typename types::template at<idx>;

  /// @var type_at<idx> at
  /// @brief Represents the value at index idx
  template <std::size_t idx>
  requires meta::lt<idx, sizeof...(values)>
  static constexpr type_at<idx> at = arg_at<idx>(values...);

  /// @brief Represents a nontype_pack with value pushed to the back
  template <auto value>
  using push_back = nontype_pack<values..., value>;

  /// @brief Represents a nontype_pack with value pushed to the front
  template <auto value>
  using push_front = nontype_pack<value, values...>;

  /// @brief Represents a nontype_pack with its last n_removed elements removed
  /// @tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1>
  requires meta::gteq<size, n_removed>
  using pop_back = std::remove_const_t<
      decltype(detail_::nontype_pack_::pop_back<values...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// @brief Represents a nontype_pack with its first n_removed elements
  ///        removed
  /// @tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires meta::gteq<size, n_removed>
  using pop_front = std::remove_const_t<
      decltype(detail_::nontype_pack_::pop_front<n_removed, values...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// @brief Represents a nontype_pack from a slice of this pack [begin, end)
  /// @tparam begin - First element index
  /// @tparam end   - Element index following last element index
  template <std::size_t begin, std::size_t end>
  requires meta::gteq<size, 0>    and
           meta::lteq<begin, end> and
           meta::lteq<end, size>
  using slice = std::remove_const_t<
      decltype(detail_::nontype_pack_::slice<begin, values...>(
          std::make_index_sequence<end - begin>()))>;

  /// @brief Represents a nontype_pack with types from the concatenation of
  ///        another nontype_pack -- <this..., other...>
  /// @tparam Other - Other nontype_pack to concatenate
  template <nontype_specialization_of<nontype_pack> Other>
  using concat = typename detail_::nontype_pack_::concat<Other>::template type<values...>;
}; /*                                                     */ // clang-format on

/// @brief Allows for deduction construction from nontype template objects
template <template <auto...> class Template, auto... values>
nontype_pack(Template<values...>) -> nontype_pack<values...>;

CCUTL_END_EXPORT_NAMESPACE // ccutl

#endif
