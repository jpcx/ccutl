//                                               ccutl.rmcvref feature guard {{{
#ifndef CCUTL_RMCVREF_INCLUDED
#define CCUTL_RMCVREF_INCLUDED
//                                               ccutl.rmcvref feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.rmcvref]: shorthand for std::remove_cvref_t
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

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

/**
 * shorthand for std::remove_cvref_t
 *
 * \anchor rmcvref
 * \ingroup ccutl
 */
template <class T>
using rmcvref = std::remove_cvref_t<T>;

} // namespace CCUTL_NAMESPACE

//                                               ccutl.rmcvref version guard {{{

#define CCUTL_RMCVREF_VERSION_MAJOR 0
#define CCUTL_RMCVREF_VERSION_MINOR 3
#define CCUTL_RMCVREF_VERSION_PATCH 2

#elif CCUTL_RMCVREF_VERSION_MAJOR != 0
#error   ccutl.rmcvref major version mismatch
#elif CCUTL_RMCVREF_VERSION_MINOR != 3
#error   ccutl.rmcvref minor version mismatch
#elif CCUTL_RMCVREF_VERSION_PATCH != 2
#warning ccutl.rmcvref patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                               ccutl.rmcvref version guard }}}
