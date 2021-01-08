//                                                    ccutl.mv feature guard {{{
#ifndef CCUTL_MV_INCLUDED
#define CCUTL_MV_INCLUDED
//                                                    ccutl.mv feature guard }}}
/*                                                                         C++20
                                               |    |
                             __|   __|  |   |  __|  |
                            (     (     |   |  |    |
                           \___| \___| \__,_| \__| _|

                              ccutl Core Utilities

    [ccutl.mv]: shorthand for std::move
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

#ifndef CCUTL_NAMESPACE
#define CCUTL_NAMESPACE ctl
#endif

namespace CCUTL_NAMESPACE {

//                                                               ccutl.rmref {{{

//                                                 ccutl.rmref feature guard {{{
#ifndef CCUTL_RMREF_INCLUDED
#define CCUTL_RMREF_INCLUDED
//                                                 ccutl.rmref feature guard }}}

/**
 * shorthand for std::remove_reference_t
 *
 * \anchor rmref
 * \ingroup ccutl
 */
template <class T>
using rmref = std::remove_reference_t<T>;

//                                                 ccutl.rmref version guard {{{

#define CCUTL_RMREF_VERSION_MAJOR 0
#define CCUTL_RMREF_VERSION_MINOR 3
#define CCUTL_RMREF_VERSION_PATCH 1

#elif CCUTL_RMREF_VERSION_MAJOR != 0
#error   ccutl.rmref major version mismatch
#elif CCUTL_RMREF_VERSION_MINOR != 3
#error   ccutl.rmref minor version mismatch
#elif CCUTL_RMREF_VERSION_PATCH != 1
#warning ccutl.rmref patch version mismatch
#endif

//                                                 ccutl.rmref version guard }}}

//                                                               ccutl.rmref }}}

/*

note: the following was copied from the C++ standard draft GitHub sources
      https://github.com/cplusplus/draft.git 60a9591

©ISO/IEC

20.2.4  forward/move helpers [forward]

...

  template <class T> constexpr remove_reference_t<T>&& move(T&& t) noexcept;

7   Returns: static_cast<remove_reference_t<T>&&>(t).

*/

/**
 * move an rvalue
 *
 * \anchor mv
 * \ingroup ccutl
 */
template <class T>
constexpr rmref<T>&&
mv(T&& t) noexcept {
  return static_cast<rmref<T>&&>(t);
}

} // namespace CCUTL_NAMESPACE

//                                                    ccutl.mv version guard {{{

#define CCUTL_MV_VERSION_MAJOR 0
#define CCUTL_MV_VERSION_MINOR 3
#define CCUTL_MV_VERSION_PATCH 1

#elif CCUTL_MV_VERSION_MAJOR != 0
#error   ccutl.mv major version mismatch
#elif CCUTL_MV_VERSION_MINOR != 3
#error   ccutl.mv minor version mismatch
#elif CCUTL_MV_VERSION_PATCH != 1
#warning ccutl.mv patch version mismatch
#endif

// vim: fmr={{{,}}} fdm=marker

//                                                    ccutl.mv version guard }}}
