#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.value_pack]: A transformable template nontype arg container
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include <type_traits>
#include <utility>

#include "src/ctl/detail/config.h"

#include "ctl/arg.h"
#include "ctl/exists_concept.h"
#include "ctl/type_pack.h"
#include "ctl/typeof_concept.h"

namespace CCUTL_NAMESPACE {

// {{{ detail
template <auto...>
struct value_pack; // forward declaration for detail functions

namespace detail {
namespace value_pack {
/// pulls nontype template values from specialzied template
template <template <auto...> class, class>
struct from;
/// pulls nontype template values from specialzied template
template <template <auto...> class Template, auto... rs>
struct from<Template, Template<rs...>> {
  template <auto... ls>
  using type = ctl::value_pack<ls..., rs...>;
};

/// checks if a template is specializable with vs...
template <template <auto...> class Template, auto... vs>
concept specializable_with_nontypes = requires() {
  typename Template<vs...>;
};

/*                                                        */ // clang-format off
/// removes the last nontype template value from vs...
template <auto... vs, std::size_t... seq>
requires (sizeof...(vs) > 0)
[[nodiscard]] inline constexpr auto
pop_back(std::index_sequence<seq...> &&) noexcept {
  return ctl::value_pack<ctl::arg<seq>(vs...)...>{};
}
/// removes the first nontype template value from vs...
template <std::size_t n_removed, auto... vs, std::size_t... seq>
requires (sizeof...(vs) >= n_removed)
[[nodiscard]] static constexpr auto
pop_front(std::index_sequence<seq...> &&) noexcept {
  return ctl::value_pack<ctl::arg<seq + n_removed>(vs...)...>{};
}
/// creates a value_pack from a section of vs...
template <std::size_t begin, auto... vs, std::size_t... seq>
requires (sizeof...(vs) > 0)
[[nodiscard]] static constexpr auto
slice(std::index_sequence<seq...> &&) noexcept {
  return ctl::value_pack<ctl::arg<seq + begin>(vs...)...>{};
} /*                                                      */ // clang-format on

/// concatenates a nontype pack with rs...
template <class>
struct concat;
/// concatenates a nontype pack with rs...
template <auto... rs>
struct concat<ctl::value_pack<rs...>> {
  template <auto... ls>
  using type = ctl::value_pack<ls..., rs...>;
};

CTL_TYPEOF_CONCEPT(typeof_vtpl, (auto... Vs), (Vs...));
CTL_EXISTS_CONCEPT(vspec_exists, (auto... Vs), (Vs...));
} // namespace value_pack
} // namespace detail
// detail }}}

/*                                                        */ // clang-format off
/**
 * Provides a nontype template arg container with transformational utilities
 *
 * \code
 *   #include "ctl/value_pack.h"
 *
 *   using t0 = ctl::value_pack<>;                 // value_pack<>
 *   using t1 = t0::push_back<0>;                  // value_pack<0>
 *   using t2 = t1::push_front<1>;                 // value_pack<1, 0>
 *   using t3 = t2::concat<value_pack<2, 3>>;      // value_pack<1, 0, 2, 3>
 *   using t4 = t3::pop_back<>;                    // value_pack<1, 0, 2>
 *   using t5 = t4::pop_front<2>;                  // value_pack<2>
 *   using t6 = t5::to<example>;                   // example<2>
 *   using t7 = t5::get<0>;                        // 2
 *                                                 //
 *   auto sz = t5::size;                           // 1
 * \endcode
 *
 * \anchor value_pack
 * \ingroup ccutl
 */
template <auto... values>
struct value_pack {
  constexpr value_pack()                                = default;
  constexpr value_pack(const value_pack<values...> &) = default;
  constexpr value_pack(value_pack<values...> &&)      = default;
  ~value_pack()                                         = default;
  /// Placeholder constructor for deduction-guide construction
  template <template <auto...> class Template, auto... vs>
  constexpr value_pack(const Template<vs...> &) noexcept {
  }
  /// Placeholder constructor for deduction-guide construction
  template <template <auto...> class Template, auto... vs>
  constexpr value_pack(Template<vs...> &&) noexcept {
  }

  /// Creates a value_pack from all template arguments in a nontype template
  /// \tparam Template              - Template name
  /// \tparam T [Template<auto...>] - Type to grab arguments from
  /// \details
  ///   value_pack<>::from<Tpl, Tpl<1, 2, 'a'>>; // -> value_pack<1, 2, 'a'>
  template <
      template <auto...> class Template,
      detail::value_pack::typeof_vtpl<Template> T>
  using from = typename detail::value_pack::from<Template, T>::template type<values...>;

  /// Creates a nontype template specialization from the held values
  /// \tparam Template - Template to type_specialize
  template <template <auto...> class Template>
  requires detail::value_pack::specializable_with_nontypes<Template, values...>
  using to = Template<values...>;

  /// Represents the number of types in the pack
  static constexpr std::size_t size = sizeof...(values);

  /// type_pack of the types of each value
  using types = type_pack<decltype(values)...>;

  /// Represents the type of the value at index idx
  /// \tparam idx - Index of the value
  template <std::size_t idx>
  using get_type = typename types::template get<idx>;

  /// \var get_type<idx> get
  /// Represents the value at index idx
  template <std::size_t idx>
  requires (idx < sizeof...(values))
  static constexpr get_type<idx> get = arg<idx>(values...);

  /// Represents a value_pack with value pushed to the back
  template <auto value>
  using push_back = value_pack<values..., value>;

  /// Represents a value_pack with value pushed to the front
  template <auto value>
  using push_front = value_pack<value, values...>;

  /// Represents a value_pack with its last n_removed elements removed
  /// \tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1>
  requires (size >= n_removed)
  using pop_back = std::remove_const_t<
      decltype(detail::value_pack::pop_back<values...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// Represents a value_pack with its first n_removed elements
  ///     removed
  /// \tparam n_removed [ =1 ] - Number of elements to remove
  template <std::size_t n_removed = 1ul>
  requires (size >= n_removed)
  using pop_front = std::remove_const_t<
      decltype(detail::value_pack::pop_front<n_removed, values...>(
          std::make_index_sequence<size - n_removed>()))>;

  /// Represents a value_pack from a slice of this pack [begin, end)
  /// \tparam begin - First element index
  /// \tparam end   - Element index following last element index
  template <std::size_t begin, std::size_t end = size>
  requires ( size >= 0 and begin <= end and end <= size )
  using slice = std::remove_const_t<
      decltype(detail::value_pack::slice<begin, values...>(
          std::make_index_sequence<end - begin>()))>;

  /// Represents a value_pack with types from the concatenation of
  ///     another value_pack -- <this..., other...>
  /// \tparam Other - Other value_pack to concatenate
  template <detail::value_pack::typeof_vtpl<value_pack> Other>
  using concat = typename detail::value_pack::concat<Other>::template type<values...>;
}; /*                                                     */ // clang-format on

/// Allows for deduction construction from nontype template objects
template <template <auto...> class Template, auto... values>
value_pack(Template<values...>) -> value_pack<values...>;

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
