//                                                  ccutl.rmcv feature guard {{{
#ifndef CCUTL_RMCV_INCLUDED
#define CCUTL_RMCV_INCLUDED
//                                                  ccutl.rmcv feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.rmcv]: shorthand for std::remove_cv_t
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
 * shorthand for std::remove_cv_t
 *
 * \anchor rmcv
 * \ingroup ccutl
 */
template <class T>
using rmcv = std::remove_cv_t<T>;

} // namespace CCUTL_NAMESPACE

//                                                  ccutl.rmcv version guard {{{

#define CCUTL_RMCV_VERSION_MAJOR 0
#define CCUTL_RMCV_VERSION_MINOR 3
#define CCUTL_RMCV_VERSION_PATCH 1

#elif CCUTL_RMCV_VERSION_MAJOR != 0
#error   ccutl.rmcv major version mismatch
#elif CCUTL_RMCV_VERSION_MINOR != 3
#error   ccutl.rmcv minor version mismatch
#elif CCUTL_RMCV_VERSION_PATCH != 1
#warning ccutl.rmcv patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                  ccutl.rmcv version guard }}}
