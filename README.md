```
                    |    |
  __|   __|  |   |  __|  |
 (     (     |   |  |    |
\___| \___| \__,_| \__| _|

   ccutl Core Utilities
          v0.3.0
```

## About

ccutl is a C++ utilities library focused on flexibility and expressibility.

This is a standalone-header-only library; each header may be included independently.

Development will follow these guidelines:

-   Limit API verbosity while maintaining clarity and specificity
-   Enable compile-time abstractions wherever possible
-   Maximally constrain templates to prevent runtime errors

Essentially, ccutl aims to decrease development time without sacrificing runtime performance.

## Requirements

- C++20 _(developed using the GNU ISO C++ library v10.2.0)_

## Setup

Include the `include/` directory or directly copy any of the headers contained within it.

All features are pasted into [`include/ctl/ccutl.h`](https://github.com/jpcx/ccutl/blob/master/include/ctl/ccutl.h)  
Directly copying this file is the easiest way to use the library.

`wget` [`https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/ccutl.h`](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/ccutl.h)

As a CMake interface library (target `ccutl`):

- use `add_subdirectory` or `FetchContent`
- use the CMake install target to install the interface

__note:__  
Preprocessor version checks are provided for each feature.
Multiple versions of ccutl may be used in a single translation unit,
but only if the individual feature dependencies do not overlap.

## Usage

All features are namespaced under `ctl::`; `#define CCUTL_NAMESPACE` to modify.

### Synopsis

Feature | About
--- | ---
[ccutl.arg](https://github.com/jpcx/ccutl/blob/master/include/ctl/arg.h) | [[doc](http://jpcx.github.io/ccutl#arg)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/arg.h)]] returns the passed arg by index, preserving reference qualifier
[ccutl.different](https://github.com/jpcx/ccutl/blob/master/include/ctl/different.h) | [[doc](http://jpcx.github.io/ccutl#different)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/different.h)]] describes a set of types with at least one variation
[ccutl.exists](https://github.com/jpcx/ccutl/blob/master/include/ctl/exists.h) | [[doc](http://jpcx.github.io/ccutl#exists)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/exists.h)]] defines templates that are specializable by Ts...
[ccutl.exists\_concept](https://github.com/jpcx/ccutl/blob/master/include/ctl/exists_concept.h) | [[doc](http://jpcx.github.io/ccutl#exists_concept)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/exists_concept.h)]] creates a concept for specialization validity
[ccutl.found](https://github.com/jpcx/ccutl/blob/master/include/ctl/found.h) | [[doc](http://jpcx.github.io/ccutl#found)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/found.h)]] checks if a value is found within a range
[ccutl.found\_if](https://github.com/jpcx/ccutl/blob/master/include/ctl/found_if.h) | [[doc](http://jpcx.github.io/ccutl#found_if)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/found_if.h)]] checks if a predicate is true for any value in a range
[ccutl.fwd](https://github.com/jpcx/ccutl/blob/master/include/ctl/fwd.h) | [[doc](http://jpcx.github.io/ccutl#fwd)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/fwd.h)]] shorthand for std::forward
[ccutl.highest](https://github.com/jpcx/ccutl/blob/master/include/ctl/highest.h) | [[doc](http://jpcx.github.io/ccutl#highest)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/highest.h)]] expands to the highest value of a given arithmetic type
[ccutl.icmp](https://github.com/jpcx/ccutl/blob/master/include/ctl/icmp.h) | [[doc](http://jpcx.github.io/ccutl#icmp)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/icmp.h)]] performs a three-way comparison of two integrals of any sign
[ccutl.lowest](https://github.com/jpcx/ccutl/blob/master/include/ctl/lowest.h) | [[doc](http://jpcx.github.io/ccutl#lowest)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/lowest.h)]] expands to the lowest value of a given arithmetic type
[ccutl.mv](https://github.com/jpcx/ccutl/blob/master/include/ctl/mv.h) | [[doc](http://jpcx.github.io/ccutl#mv)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/mv.h)]] shorthand for std::move
[ccutl.rmcv](https://github.com/jpcx/ccutl/blob/master/include/ctl/rmcv.h) | [[doc](http://jpcx.github.io/ccutl#rmcv)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/rmcv.h)]] shorthand for std::remove_cv_t
[ccutl.rmcvref](https://github.com/jpcx/ccutl/blob/master/include/ctl/rmcvref.h) | [[doc](http://jpcx.github.io/ccutl#rmcvref)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/rmcvref.h)]] shorthand for std::remove_cvref_t
[ccutl.rmref](https://github.com/jpcx/ccutl/blob/master/include/ctl/rmref.h) | [[doc](http://jpcx.github.io/ccutl#rmref)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/rmref.h)]] shorthand for std::remove_reference_t
[ccutl.same](https://github.com/jpcx/ccutl/blob/master/include/ctl/same.h) | [[doc](http://jpcx.github.io/ccutl#same)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/same.h)]] describes a set of types with no variation
[ccutl.streq](https://github.com/jpcx/ccutl/blob/master/include/ctl/streq.h) | [[doc](http://jpcx.github.io/ccutl#streq)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/streq.h)]] equality comparison of stringlike objects
[ccutl.targ](https://github.com/jpcx/ccutl/blob/master/include/ctl/targ.h) | [[doc](http://jpcx.github.io/ccutl#targ)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/targ.h)]] represents the passed type-template-arg by index
[ccutl.type\_pack](https://github.com/jpcx/ccutl/blob/master/include/ctl/type_pack.h) | [[doc](https://jpcx.github.io/ccutl/structctl_1_1type__pack.html)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/type_pack.h)]] A transformable template type arg container
[ccutl.typeof](https://github.com/jpcx/ccutl/blob/master/include/ctl/typeof.h) | [[doc](http://jpcx.github.io/ccutl#typeof)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/typeof.h)]] defines types that are template<class...> specializations
[ccutl.typeof\_concept](https://github.com/jpcx/ccutl/blob/master/include/ctl/typeof_concept.h) | [[doc](http://jpcx.github.io/ccutl#typeof_concept)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/typeof_concept.h)]] creates a template spec-detection concept
[ccutl.value\_pack](https://github.com/jpcx/ccutl/blob/master/include/ctl/value_pack.h) | [[doc](https://jpcx.github.io/ccutl/structctl_1_1value__pack.html)] [[raw](https://raw.githubusercontent.com/jpcx/ccutl/master/include/ctl/value_pack.h)]] A transformable template nontype arg container

### Examples

```cpp
#include <array>
#include <iostream>
#include <vector>

#include <ctl/typeof.h>
#include <ctl/typeof_concept.h>

// use the provided `typeof` concept that defines `<class...>` specializations
template <ctl::typeof<std::vector> T>
void print_size(T &&r) {
  std::cout << "[std::vector]: size " << v.size() << '\n'; 
}

// creates a concept `typesize_typeof` that defines `<class, size_t>` specializations
CTL_TYPEOF_CONCEPT(typesize_typeof, (class T, size_t N), (T, N));

template <typesize_typeof<std::array> T>
void print_size(T &&v) {
  std::cout << "[std::array]: size " << v.size() << '\n'; 
}

template <typesize_typeof<std::span> T>
void print_size(T &&v) {
  std::cout << "[std::span]: size " << v.size() << '\n'; 
}
```

```cpp
#include <ctl/exists.h>

template <template <class...> class Template>
requires ctl::exists<Template, int>
using specialize_with_int = Template<int>;
```

```cpp
#include <utility>

#include <ctl/type_pack.h>

using intpair = ctl::type_pack<>       // type_pack<>
                   ::push_back<int>    // type_pack<int>
                   ::push_front<int>   // type_pack<int, int>
                   ::push_front<float> // type_pack<float, int, int>
                   ::slice<1>          // type_pack<int, int>
                   ::to<std::pair>;    // std::pair<int, int>
```

## Testing

All API features are tested using [jpcx/cctest](https://github.com/jpcx/cctest) _[embedded]_

Run `make test` to test on your system.

__note:__ Testing is performed on post-buildsystem preprocessed headers

## Contributing

Contribution is welcome! Please make a pull request.
C++ is an extremely versatile language; I'd like to make it even more so!
If you have any suggestions, please let me know at m@jpcx.dev or file a bug report.
Make sure to update the submodules and run `npm i -d` in the `bs` directory in order to begin development.

For general development contributions, read the guide below:

 - Any `.h` files created in the src/ctl directory should work with the existing build system.
 - Place detail files in the `src/ctl/detail` directory.
   - These files are not built as standalone units; they are only included if depended on
 - `#pragma once` must be used for source files due to version guards
 - Each feature must directly or indirectly include `src/ctl/detail/config.h`
 - `src` include directories are `-I.` ,`-Iinclude`, and one for each `libs/` library
   - This is for additional error checking, but the downside is that `make` must be called to see the changes reflected.
 - All headers must have the same license text structure directly underneath the include guard
 - Embedded libraries are allowed; place them in `libs/` and add the appropriate `-I` statement to the Makefile
   - Embedded libraries must be header-only
 - Each file in `src/` must have a complementary test in `test/src/`.

## Documentation

[Project documentation](http://jpcx.github.io/ccutl) is generated by Doxygen and is hosted by GitHub Pages.

## License

```
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
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
