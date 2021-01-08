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

# make the include dir by default
all: include

PREFIX ?= /usr/local

CXX       = clang++
CXXFLAGS += -std=c++20                 \
						-g                         \
						-I.                        \
						-Iinclude                  \
						-Itest/libs                \
						-Ilibs/pputl/include       \
						-Weverything               \
						-Wno-padded                \
						-Wno-c++98-compat          \
						-Wno-c++98-compat-pedantic \
						-Wno-global-constructors   \
						-Wno-exit-time-destructors \
						-Wno-documentation-unknown-command

# all of the input headers in the source directory
SRC_HEADERS  = $(shell find src/ -type f -name '*.h')
# all of the tests. each input header must have an associated test source
TEST_SOURCES = $(patsubst src/%.h, test/src/%.cc, ${SRC_HEADERS}) test/src/main.cc
# all of the test objects
TEST_OBJECTS = $(patsubst test/%.cc, test/.o/%.o, ${TEST_SOURCES})

# rule to make the include directory and everything within it
include: bs/build.ts ${SRC_HEADERS} libs/pputl/include
	bs/node_modules/.bin/ts-node -s $<

# test sources depend on the include dir to be generated
${TEST_SOURCES}: include

# cache directories for test objects
test/.o/src/ctl/detail:
	mkdir -p $@

# make sure the object dirs exist
${TEST_OBJECTS}: test/.o/src/ctl/detail

# create all of the test objects
test/.o/%.o: test/%.cc
	${CXX} ${CXXFLAGS} -c $< -o $@

# create the test executable using all of the test objects 
test/test: ${TEST_OBJECTS}
	${CXX} ${CXXFLAGS} $^ -o $@

# `make test` functionality
test: test/test
	@./$<

# install include/ctl to ${DESTDIR}${PREFIX}/include/
install: ${DESTDIR}${PREFIX}/include include
	install -d 644 $</ctl
	install -m 644 include/ctl/* -t $</ctl

# removes ${DESTDIR}${PREFIX}/include/ctl
uninstall: ${DESTDIR}${PREFIX}/include/ctl
	${RM} -r $<

# clean up testing
clean-test:
	${RM} test/test
	${RM} -r test/.o

# clean up everything. THIS DELETES THE INCLUDE DIR!
clean: libs/pputl/include # adding this dependency to prevent accidental clean
	${RM} -r include
	${MAKE} clean-test


.PHONY: all test install uninstall clean-test clean
