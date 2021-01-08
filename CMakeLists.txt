#                                                                        C++20 #
#                                              |    |                          #
#                            __|   __|  |   |  __|  |                          #
#                           (     (     |   |  |    |                          #
#                          \___| \___| \__,_| \__| _|                          #
#                                                                              #
#                             ccutl Core Utilities                             #
#                                                                              #
#   [ccutl]: a C++ utilities library focused on flexibility and expressibility #
#   Copyright (C) 2020, 2021 Justin Collier                                    #
#                                                                              #
#     This program is free software: you can redistribute it and/or modify     #
#     it under the terms of the GNU General Public License as published by     #
#     the Free Software Foundation, either version 3 of the License, or        #
#     (at your option) any later version.                                      #
#                                                                              #
#     This program is distributed in the hope that it will be useful,          #
#     but WITHOUT ANY WARRANTY; without even the internalied warranty of       #
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
#     GNU General Public License for more details.                             #
#                                                                              #
#   You should have received a copy of the GNU General Public License          #
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.     #

# - - - - - - - - - - - - - - - - - project - - - - - - - - - - - - - - - - -  #

cmake_minimum_required (VERSION 3.0)
project (ccutl
         VERSION 0.3.1
         DESCRIPTION "a C++ utilities library focused on flexibility and expressibility"
         HOMEPAGE_URL "https://github.com/jpcx/ccutl"
         LANGUAGES CXX)

configure_file (
  ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake.in
  ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake @ONLY)

set (NAMESPACE ctl)

# - - - - - - - - - - - - - - - - - variables - - - - - - - - - - - - - - - -  #

set (CLANG_WARNINGS
  -Wno-padded
  -Wno-c++98-compat
  -Wno-c++98-compat-pedantic
  -Wno-global-constructors
  -Wno-exit-time-destructors
  -Wno-documentation-unknown-command)

set (INCLUDE_DEST "include/${PROJECT_NAME}-${PROJECT_VERSION}")
set (LIB_DEST "lib/cmake/${PROJECT_NAME}-${PROJECT_VERSION}")

# - - - - - - - - - - - - - - - - - interface - - - - - - - - - - - - - - - -  #

# create the main library
add_library                (${PROJECT_NAME} INTERFACE)
target_include_directories (${PROJECT_NAME} INTERFACE
                            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${INCLUDE_DEST}>)

target_compile_options (${PROJECT_NAME} INTERFACE
                        ${CLANG_WARNINGS})

# - - - - - - - - - - - - - - - - - install - - - - - - - - - - - - - - - - -  #

install (TARGETS ${PROJECT_NAME}
         EXPORT ${PROJECT_NAME}
         DESTINATION ${INCLUDE_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake
         DESTINATION ${LIB_DEST})

install (FILES ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config-version.cmake
         DESTINATION ${LIB_DEST})

install (DIRECTORY ${PROJECT_SOURCE_DIR}/include/${NAMESPACE}
         DESTINATION ${INCLUDE_DEST})

install (EXPORT ${PROJECT_NAME}
         DESTINATION ${LIB_DEST})
