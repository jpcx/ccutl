#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.exists]: defines templates that are specializable by Ts...
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
    along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "ctl/exists_concept.h"

namespace CCUTL_NAMESPACE {

// detail {{{
namespace detail {
namespace exists {
/// generated concept implementation for exists
CTL_EXISTS_CONCEPT(impl, (class... Ts), (Ts...));
} // namespace exists
} // namespace detail
// detail }}}

/**
 * defines templates that are specializable by Ts...
 *
 * \note may only be used with template structs, classes, and unions
 *
 * \code
 *   #include "ctl/exists.h"
 *   #include "ctl/same.h"
 *
 *   using std::tuple;
 *   template <ctl::same<int> T>
 *   struct foo {};
 *
 *   auto x0 = ctl::exists<foo, int>;      // true
 *   auto x1 = ctl::exists<foo, int, int>; // false
 *   auto x2 = ctl::exists<foo, long>;     // false
 * \endcode
 *
 * \anchor exists
 * \ingroup ccutl
 */
template <template <class...> class Template, class... Args>
concept exists = detail::exists::impl<Template, Args...>;

} // namespace CCUTL_NAMESPACE

// vim: fmr={{{,}}} fdm=marker
