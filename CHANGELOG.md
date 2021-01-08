# Changelog

## [Upcoming](https://github.com/jpcx/ccutl/compare/0.3.2...devel)

## [0.3.2](https://github.com/jpcx/ccutl/releases/tag/0.3.2) \[[diff](https://github.com/jpcx/ccutl/compare/0.3.1...0.3.2)\]

### Fixed

- Added `ccutl.streq` to `ccutl.h`
- Fixed changelog 'upcoming' link

## [0.3.1](https://github.com/jpcx/ccutl/releases/tag/0.3.1) \[[diff](https://github.com/jpcx/ccutl/compare/0.3.0...0.3.1)\]

### Added

- Added migration notice to README
- Fixed docs for `ccutl.highest` and `ccutl.lowest`

## [0.3.0](https://github.com/jpcx/ccutl/releases/tag/0.3.0) \[[diff](https://github.com/jpcx/ccutl/compare/0.2.1...0.3.0)\]

### Changed

- Rewrote build system and project structure. All include/ files are now standalone headers
- Changed default namespace from `ccutl::` to `ctl::`
- renamed:
  - `ccutl.no[cv, ref, cvref]` -> `ccutl.rm[cv, ref, cvref]`
  - `ccutl.arg_at` -> `ccutl.arg`
  - `ccutl.type_at` -> `ccutl.targ`
  - `ccutl.specializable_with` -> `ccutl.exists`
  - `ccutl.specialization_of` -> `ccutl.typeof`
  - `ccutl.macros.make_specialization_of_concept` -> `ccutl.typeof_concept`
  - `ccutl.nontype_pack` -> `ccutl.value_pack`
  - `ccutl.type_pack::at<n>` -> `ccutl.type_pack::get<n>`
  - `ccutl.value_pack::at<n>` -> `ccutl.value_pack::get<n>`
  - `ccutl.value_pack::type_at<n>` -> `ccutl.value_pack::get_type<n>`
- ccutl comparison functions (`eq, neq, lt, lteq, gteq`):
  - removed non-integral three-way-comparable comparisons
  - combined as `ccutl.icmp`

### Removed

- Removed C++20 module support
- Removed `ccutl.boolean_testable`
- Removed `ccutl.meta`
- Removed `ccutl.macros`
- Removed `ccutl.nontype_specialization_of`
- Removed `ccutl.str_[eq, neq, lt, lteq, gt, gteq]` (use `std::string_view` instead)
- Removed `ccutl.strlen` (use `std::string_view` instead)
- Removed `ccutl.range_of`
- Removed `ccutl.subscriptable_to`

### Added

- `ccutl.exists_concept`: creates `ccutl.exists` concepts
- `ccutl.found`: uses `std::ranges::find` to check for the existence of an element
- `ccutl.found_if`: uses `std::ranges::find_if` to check for the truth of a predicate
- `ccutl.streq`: equality comparison of stringlike objects
- `ccutl.icmp`: three-way comparison of integrals of any signedness

## [0.2.1](https://github.com/jpcx/ccutl/releases/tag/0.2.1) \[[diff](https://github.com/jpcx/ccutl/compare/0.2.0...0.2.1)\]

### Fixed

- Fixed README links

## [0.2.0](https://github.com/jpcx/ccutl/releases/tag/0.2.0) \[[diff](https://github.com/jpcx/ccutl/compare/0.1.2...0.2.0)\]

### Added

- ccutl.str\_lt
- ccutl.str\_gt
- ccutl.str\_lteq
- ccutl.str\_gteq
- ccutl.str\_neq

### Changed

- RENAMED ccutl.streq --> ccutl.str\_eq
- RENAMED ccutl.indexed\_type --> ccutl.type\_at
- RENAMED ccutl.indexed\_arg --> ccutl.arg\_at
- ccutl.str\_eq and ccutl.strlen: forwarding references --> const references
- switched to ccutl.arg\_at for ccutl.str\_eq arg selection

### Fixed

- ccutl.str\_eq:
  - no longer uses null terminators to determine range end
  - works with extent ranges
  - correctly ceases range execution on either null terminator or range end
- ccutl string functions now work properly with wchar\_t ranges

## [0.1.2](https://github.com/jpcx/ccutl/releases/tag/0.1.2) \[[diff](https://github.com/jpcx/ccutl/compare/0.1.1...0.1.2)\]

### Changed

- Fixed subscriptable-to file brief
- updated CMake project information
- moved manual dependencies to buildModuleDeps

## [0.1.1](https://github.com/jpcx/ccutl/releases/tag/0.1.1) \[[diff](https://github.com/jpcx/ccutl/compare/0.1.0...0.1.1)\]

### Changed

- Separated dev build scripts from main build recipe
- Fixed README typo
- Fixed module depenencies for detail headers
- Updated cctest dev dependency

## [0.1.0](https://github.com/jpcx/ccutl/releases/tag/0.1.0)

### Added

- Basic features, documentation, and tests
