#pragma once
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>.    */

#include <type_traits>
#include <utility>

#include "ctl/exists.h"
#include "ctl/targ.h"
#include "ctl/typeof.h"

namespace CCUTL_NAMESPACE {

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

// vim: fmr={{{,}}} fdm=marker
