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

# adds targets for module precompilation and object compilation
# any additional modules passed will become dependencies of module `name`
# module names are formatted with dots: e.g. `ccutl.noref`
#
# DEPENDS:      uses ${CLANG_WARNINGS} variable for warnings
#               uses ${CLANG_MODULE_FLAGS} variable for module-specific flags
function (add_module name)
  # create relative path of module based on name
  string (REPLACE "." "/" SLASHED_NAME ${name})

  # create file location variables
  set (SRCNAME ${SLASHED_NAME}.h)
  set (PRENAME ${name}.pcm)
  set (OBJNAME ${name}.o)
  set (SRC ${PROJECT_SOURCE_DIR}/include/${SRCNAME})
  set (PRE ${PROJECT_BINARY_DIR}/modules/${PRENAME})
  set (OBJ ${PROJECT_BINARY_DIR}/objects/${OBJNAME})

  # create module precompile command
  set (PRECOMPILE_MODULE
    ${CMAKE_CXX_COMPILER}
    ${CLANG_MODULE_FLAGS}
    -Xclang -emit-module-interface
    -I${PROJECT_SOURCE_DIR}/include
    -I${PROJECT_SOURCE_DIR}/libs/pputl/include
    -DCCUTL_MODULES
    -c
    ${CLANG_WARNINGS}
    -x 'c++'
    ${SRC}
    -o ${PRE})

  set (COMPILE_OBJECT
    ${CMAKE_CXX_COMPILER}
    -std=c++20
    -c
    ${CLANG_WARNINGS}
    ${PRE}
    -o ${OBJ})

  if (${ARGC} GREATER 1)
    if (${ARGV1} STREQUAL "ALL")
      # target is included in default target
      if (${ARGC} GREATER 2)
        # target has internal module dependencies
        list (APPEND ARGS ${ARGV})
        list (SUBLIST ARGS 2 ${ARGC}-2 DEPENDENCIES)

        set  (OBJ_DEPENDENCIES ${DEPENDENCIES})
        list (TRANSFORM OBJ_DEPENDENCIES APPEND .o)
        list (TRANSFORM OBJ_DEPENDENCIES PREPEND ${PROJECT_BINARY_DIR}/objects/)

        add_custom_command (OUTPUT ${PRE}
          COMMAND ${PRECOMPILE_MODULE}
          DEPENDS ${SRC} ${OBJ_DEPENDENCIES}
          COMMENT "precompiling module ${name}...")
        add_custom_target (${PRENAME} ALL DEPENDS ${PRE})
      endif ()
    else ()
      # target is standard target and has internal module dependencies
      list (APPEND ARGS ${ARGV})
      list (SUBLIST ARGS 1 ${ARGC}-1 DEPENDENCIES)

      set  (OBJ_DEPENDENCIES ${DEPENDENCIES})
      list (TRANSFORM OBJ_DEPENDENCIES APPEND .o)
      list (TRANSFORM OBJ_DEPENDENCIES PREPEND ${PROJECT_BINARY_DIR}/objects/)

      add_custom_command (OUTPUT ${PRE}
        COMMAND ${PRECOMPILE_MODULE}
        DEPENDS ${SRC} ${OBJ_DEPENDENCIES}
        COMMENT "precompiling module ${name}...")
      add_custom_target (${PRENAME} DEPENDS ${PRE})
    endif ()
  else ()
    # target is standard target with no internal module dependencies
    add_custom_command (OUTPUT ${PRE}
      COMMAND ${PRECOMPILE_MODULE}
      DEPENDS ${SRC}
      COMMENT "precompiling module ${name}...")
    add_custom_target (${PRENAME} DEPENDS ${PRE})
  endif ()

  add_custom_command (OUTPUT ${OBJ}
    COMMAND ${COMPILE_OBJECT}
    DEPENDS ${PRE}
    COMMENT "compiling object    ${name}...")
  add_custom_target (${OBJNAME} ALL DEPENDS ${OBJ})
 
endfunction ()
