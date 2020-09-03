# ccutl 0.1.0  | [_Files_](http://jpcx.github.io/ccutl/files.html) | [_API_](http://jpcx.github.io/ccutl/group__ccutl.html) | [_CHANGELOG_](https://github.com/jpcx/ccutl/blob/0.1.0/CHANGELOG.md)

```
                    |    |
  __|   __|  |   |  __|  |
 (     (     |   |  |    |
\___| \___| \__,_| \__| _|

   ccutl Core Utilities
```

## About

ccutl is a C++ utilities library focused on clarity and ease of use.  
This is a place for general utilites that are often re-implemented in different projects.

Development will follow these guidelines:

-   Limit API verbosity
-   Minimize runtime costs
    -   Use compile-time abstractions
-   Prevent runtime errors
    -   Maximally constrain templates
    -   Encourage constexpr components
-   Increase user development speed
    -   Focus on feature generalization

In essence, this library aims to increase the expressibility of C++ and  
decrease general development time without sacrificing runtime performance.

Generally, this library will contain the following types of utilites:

- shortcuts to existing functionality (e.g. [ccutl::mv](http://jpcx.github.io/ccutl/group__ccutl.html#mv), [ccutl::fwd](http://jpcx.github.io/ccutl/group__ccutl.html#fwd_lvalues), [ccutl::noref](http://jpcx.github.io/ccutl/group__ccutl.html#noref))
- more flexible versions of existing functionality (e.g. [ccutl::same](http://jpcx.github.io/ccutl/group__ccutl.html#same))
- more approachable metaprogramming techniques (e.g. [ccutl::type\_pack](http://jpcx.github.io/ccutl/structccutl_1_1type__pack.html), [ccutl::indexed\_type](http://jpcx.github.io/ccutl/group__ccutl.html#indexed_type))
- less verbose methods for common operations (e.g. [ccutl::streq](http://jpcx.github.io/ccutl/group__ccutl.html#streq), [ccutl::highest](http://jpcx.github.io/ccutl/group__ccutl.html#highest), [ccutl::lowest](http://jpcx.github.io/ccutl/group__ccutl.html#lowest))
- preprocessor tools to circumvent language limitations (e.g. [CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT](http://jpcx.github.io/ccutl/group__ccutl.html#CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT))
- type-general operations (e.g. [ccutl::eq](http://jpcx.github.io/ccutl/group__ccutl.html#eq), [ccult::strlen](http://jpcx.github.io/ccutl/group__ccutl.html#strlen))
- code generation scripts (future releases)

## Requirements

- C++20
- CMake >=3.17
- GNU ISO C++ Library >=10.0.0

__Optional:__

- clang ^10.0.0 with -fmodules support
- GNU Make ^4.0.0
- Ninja ^1.0.0

__Development:__

- TypeScript ^3.9.0
- Node.JS    ^12.0.0

## C++20 Modules

This project can be built as C++20 modules!  
__due to limited module support available today, modules are disabled by default-__ [__see below__](#setup_as_modules)

Several notes must be made:

- ccutl modules must be built with Clang. I wasn't able to successfully build them with GCC devel/c++-modules
- the library uses many C++20 features that are currently unavailable in `libc++`, so GNU `libstdc++` is required
- Clang does not have an `std` module for `libstdc++`, and header units were not working
- an `std` modules is created internally (system header inclusion in the global module fragment caused many errors)
- this `std` module includes ALL C++ API headers and is re-exported from each module that imports it
- conflicts will arise if `ccutl` is imported with another module that exports `std` or any C++ header units.

The project will be updated as soon as:

- Clang provides an `std` module for `libstdc++`
- `libc++` is updated with the necessary `ranges`, `compare`, and `concepts` support
- GCC modules are updated and can be used to build this project

As it is, the project should work with clang 10.0.0 and `libstdc++` 10.0.0.

System headers must be included after the `import ccutl;` statement.

## Setup

ccutl is a header-only CMake interface library with `find_package` compatibility.  

### As Headers

#### Standard -I

```shell
git clone -b 0.1.0 https://github.com/jpcx/ccutl.git
```
```makefile
CXXFLAGS += -I[ccutl download dir]/include
```

#### CMake Install

```shell
git clone -b 0.1.0 https://github.com/jpcx/ccutl.git
cd ccutl

make # mkdir build
     # cmake -Bbuild

# installs header to      ${DESTDIR}${PREFIX}/include/ccutl-0.1.0
# installs cmake files to ${DESTDIR}${PREFIX}/lib/cmake/ccutl-0.1.0
sudo make install # cmake --install build
```
```cmake
find_package(ccutl 0.1 REQUIRED)
target_link_libraries([your target] ccutl)
```

#### CMake FetchContent

```cmake
include(FetchContent)
FetchContent_Declare(ccutl
                     GIT_REPOSITORY https://github.com/jpcx/ccutl.git
                     GIT_TAG "0.1.0")
FetchContent_MakeAvailable(ccutl)
target_link_libraries([your target] ccutl)
```

#### CMake add_subdirectory

```shell
git clone -b 0.1.0 https://github.com/jpcx/ccutl.git # or git submodule add
```
```cmake
add_subdirectory([ccutl download dir])
target_link_libraries([your target] ccutl)
```

### As Modules <a id="setup_as_modules" />

ccutl modules cannot be installed to the system at this time.  
They may be consumed directly as a subfolder as follows:

```shell
git clone -b 0.1.0 https://github.com/jpcx/ccutl.git
```
```cmake
set(CCUTL_MODULES ON)
add_subdirectory([ccutl download dir])
target_link_libraries([your target] ccutl)
set_target_properties([your target] PROPERTIES
                      CXX_EXTENSIONS OFF)
```

## Usage

**Headers Example**

```cpp
#include <ccutl.h>
// #include <ccutl/type_pack.h>

using x0     = ccutl::type_pack<>;
using x1     = x0::push_back<int>;
using inttup = x1::to<std::tuple>;
```

**Modules Example**

```cpp
import ccutl;
// import ccutl.eq;

constexpr bool x0 = ccutl::eq(1, 1u);
```

## Testing

All API features are tested using [jpcx/cctest](https://github.com/jpcx/cctest) [embedded]

Testing Headers:
```shell
make test-headers # mkdir -p build/headers                         &&
                  # cmake -Bbuild/headers                          &&
                  # cmake --build build/headers --target testccutl &&
                  # ./build/headers/test/testccutl
```

Testing Modules:
```shell
# modules can only be tested with Clang (for now)
make test-modules # mkdir -p build/modules                         &&
                  # cmake -Bbuild/modules -DCCUTL_MODULES=ON       &&
                  # cmake --build build/modules --target testccutl &&
                  # ./build/modules/test/testccutl
```

Additionally, there are two recipes for testing using single feature import/include:  
`make test-modules-single` and `make test-headers-single`

Testing Everything:
```shell
make test-all # performs four separate tests
```

## Contributing

Contribution is welcome! Please make a pull request.

C++ is an extremely versatile language, I'd like to make it even more so!

## Documentation

[Project documentation](http://jpcx.github.io/ccutl) is generated by Doxygen and is hosted by GitHub Pages.

## Synopsis

Module | Brief
--- | ---
ccutl | ccutl Core Utilities
ccutl.boolean_testable | describes a bool-convertible B that is capable of usual logic operations
ccutl.different | describes a set of types with at least one variation
ccutl.eq | equality comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.fwd | perfect reference forwarder
ccutl.gt | greater-than comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.gteq | greater-than-or-equal-to comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.highest | represents the highest number possible for a given arithmetic type
ccutl.indexed_arg | returns the argument at index idx
ccutl.indexed_type | represents the type template argument at index idx
ccutl.lowest | represents the lowest number possible for a given arithmetic type
ccutl.lt | less-than comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.lteq | less-than-or-equal-to comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta | module file for contains metaprogramming-specific variants of ccutl features
ccutl.meta.eq | template equality comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta.gt | template greater-than comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta.gteq | template greater-than-or-equal-to comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta.lt | template less-than comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta.lteq | template less-than-or-equal-to comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.meta.neq | template non-equality comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.mv | move an rvalue
ccutl.neq | non-equality comparison of two strongly-ordered three-way comparables or differently-signed integrals
ccutl.nocv | removes the topmost cv qualifiers on a type
ccutl.nocvref | removes the topmost cv and reference qualifiers on a type
ccutl.nontype_pack | Provides a nontype template arg container with transformational utilities
ccutl.nontype_specialization_of | detects template specializations for nontype-parameter templates (<auto...>)
ccutl.noref | removes the topmost reference qualifiers on a type
ccutl.range_of | describes a range-type T that contains Contained
ccutl.same | describes a set of types with no variation
ccutl.specializable_with | describes a template that is specializable with given type template args
ccutl.specialization_of | detects template specializations for type-parameter templates (<class...>)
ccutl.specializes | requires that a type may be used to specialize a given template
ccutl.streq | true if all provided char ranges or null-terminated strings are equal
ccutl.strlen | returns the length of any char range or null-terminated string
ccutl.subscriptable_to | describes a T whose subscript operator returns a type decay-same as SubType
ccutl.type_pack | Provides a type template arg container with transformational utilities

Macro | Location | Brief
--- | --- | ---
CCUTL_MAKE_SPECIALIZATION_OF_CONCEPT | `ccutl/macros/make_specialization_of_concept.h` | Creates a concept that can detect template specializations.