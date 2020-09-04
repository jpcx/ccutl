# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# 
#                       |    |
#     __|   __|  |   |  __|  |
#    (     (     |   |  |    |
#   \___| \___| \__,_| \__| _|
# 
#   ccutl Core Utilities
#   Copyright (C) 2020 Justin Collier <m@jpcx.dev>
# 
#     This program is free software: you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation, either version 3 of the License, or
#     (at your option) any later version.
# 
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the internalied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# - - - - - - - - - - - - - - - - - project - - - - - - - - - - - - - - - - -  #

cmake_minimum_required (VERSION 3.0)
project (ccutl
         VERSION 0.1.2
         DESCRIPTION "A General Utilities Library for C++20"
         HOMEPAGE_URL "https://github.com/jpcx/ccutl"
         LANGUAGES CXX)

configure_file (
  ${PROJECT_SOURCE_DIR}/cmake/config.h.in
  ${PROJECT_SOURCE_DIR}/include/ccutl/detail_/config.h @ONLY)

configure_file (
  ${PROJECT_SOURCE_DIR}/cmake/README.md.in
  ${PROJECT_SOURCE_DIR}/README.md @ONLY)

configure_file (
  ${PROJECT_SOURCE_DIR}/cmake/CHANGELOG.md.in
  ${PROJECT_SOURCE_DIR}/CHANGELOG.md @ONLY)

configure_file (
  ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake.in
  ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake @ONLY)

# - - - - - - - - - - - - - - - - - variables - - - - - - - - - - - - - - - -  #

set (CLANG_WARNINGS
     -Wno-c++98-compat
     -Wno-gnu-zero-variadic-macro-arguments
     -Wno-c++98-compat
     -Wno-c++98-compat-pedantic
     -Wno-documentation
     -Wno-documentation-unknown-command)

set (CLANG_MODULE_FLAGS
     -std=c++20
     -stdlib=libstdc++
     -fmodules
     -fmodule-map-file=${PROJECT_SOURCE_DIR}/src/std.modulemap
     -fprebuilt-module-path=${PROJECT_BINARY_DIR}/modules)

set (INCLUDE_DEST "include/${PROJECT_NAME}-${PROJECT_VERSION}")
set (LIB_DEST "lib/cmake/${PROJECT_NAME}-${PROJECT_VERSION}")

# - - - - - - - - - - - - - - - - - - setup - - - - - - - - - - - - - - - - -  #

if (CCUTL_MODULES)
  file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/modules)
  file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/objects)
endif ()

if (CCUTL_MODULES)
  if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message (FATAL_ERROR "modules may only be built with Clang (for now)")
  endif ()
  include (cmake/project_module_structure.cmake)
endif ()

# - - - - - - - - - - - - - - - - - interface - - - - - - - - - - - - - - - -  #

# create the main library
add_library                (${PROJECT_NAME} INTERFACE)
target_include_directories (${PROJECT_NAME} INTERFACE
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${INCLUDE_DEST}>
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/libs/pputl/include>
                            $<INSTALL_INTERFACE:${INCLUDE_DEST}>)

if (CCUTL_MODULES)
  add_dependencies    (${PROJECT_NAME} ${PROJECT_NAME}.o)
  target_link_options (${PROJECT_NAME} INTERFACE
                       ${MODULE_OBJECTS} -stdlib=libstdc++)
endif ()

target_compile_options (${PROJECT_NAME} INTERFACE
                        ${BASE_FLAGS}
                        ${CMAKE_CXX_FLAGS}
                        $<$<BOOL:${CCUTL_MODULES}>:${CLANG_MODULE_FLAGS}>
                        ${CLANG_WARNINGS})

# - - - - - - - - - - - - - - - - - install - - - - - - - - - - - - - - - - -  #

install (TARGETS ${PROJECT_NAME}
         EXPORT ${PROJECT_NAME}
         DESTINATION ${INCLUDE_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake
         DESTINATION ${LIB_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake
         DESTINATION ${LIB_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/add_module.cmake
         DESTINATION ${LIB_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/project_module_structure.cmake
         DESTINATION ${LIB_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}.h
         DESTINATION ${INCLUDE_DEST})

install (DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
         DESTINATION ${INCLUDE_DEST})

install (DIRECTORY ${PROJECT_SOURCE_DIR}/libs/pputl/include/pputl
         DESTINATION ${INCLUDE_DEST})

install (EXPORT ${PROJECT_NAME}
         DESTINATION ${LIB_DEST})

# - - - - - - - - - - - - - - - - - - test - - - - - - - - - - - - - - - - - - #

add_subdirectory (test)
