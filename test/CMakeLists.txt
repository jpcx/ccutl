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

set (CLANG_TEST_WARNINGS
     -Werror
     -Weverything
     -Wno-global-constructors
     -Wno-padded)

add_subdirectory (libs/cctest)

file (GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
      ${PROJECT_SOURCE_DIR}/test/src/**.cc)

# create the test executable
add_executable             (test${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries      (test${PROJECT_NAME} ${PROJECT_NAME} cctest)

target_include_directories (test${PROJECT_NAME} PRIVATE
                            ${PROJECT_SOURCE_DIR}/test/include)

if (CCUTL_MODULES)
  target_compile_definitions (test${PROJECT_NAME} PRIVATE
                              CCUTL_MODULES)
endif ()

if (TESTCCUTL_SINGLE)
  target_compile_definitions (test${PROJECT_NAME} PRIVATE
                              TESTCCUTL_SINGLE)
endif ()

set_target_properties  (test${PROJECT_NAME} PROPERTIES
                        $<$<BOOL:${CCUTL_MODULES}>:CXX_EXTENSIONS OFF>
                        EXCLUDE_FROM_ALL true
                        EXCLUDE_FROM_DEFUALT_BUILD true)
  
target_compile_options (test${PROJECT_NAME} PRIVATE 
                        ${CMAKE_CXX_FLAGS}
                        -std=c++20
                        $<$<BOOL:${CCUTL_MODULES}>:${CLANG_MODULE_FLAGS}>
                        $<$<CXX_COMPILER_ID:Clang>:${CLANG_WARNINGS}>
                        $<$<CXX_COMPILER_ID:Clang>:${CLANG_TEST_WARNINGS}>)
