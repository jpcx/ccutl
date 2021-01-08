#pragma once
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.rmref]: shorthand for std::remove_reference_t
    Copyright (C) 2020-2021 Justin Collier

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

#include "src/ctl/detail/config.h"

namespace CCUTL_NAMESPACE {

/**
 * shorthand for std::remove_reference_t
 *
 * \anchor rmref
 * \ingroup ccutl
 */
template <class T>
using rmref = std::remove_reference_t<T>;

} // namespace CCUTL_NAMESPACE
