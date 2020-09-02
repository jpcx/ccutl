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

MAKEFLAGS += --no-print-directory

MODULES = $(shell find include/ccutl -type f -name "*.h")

all: build-headers

include/ccutl:
	mkdir -p $@

include/ccutl/meta: include/ccutl
	mkdir -p $@

include/ccutl/detail_: include/ccutl
	mkdir -p $@

build/modules:
	mkdir -p $@

build/modules_single:
	mkdir -p $@

build/headers:
	mkdir -p $@

build/headers_single:
	mkdir -p $@

build-modules: build/modules
	mkdir -p $</modules
	mkdir -p $</objects
	make -C build_scripts/buildModuleDeps run-modules
	node build_scripts/buildFeatureSummary
	cmake -B$< -GNinja -DCCUTL_MODULES=ON -DTESTCCUTL=ON
	cmake --build $<

build-modules-single: build/modules_single
	mkdir -p $</modules
	mkdir -p $</objects
	make -C build_scripts/buildModuleDeps run-modules-single
	node build_scripts/buildFeatureSummary
	cmake -B$< -GNinja -DCCUTL_MODULES=ON -DTESTCCUTL=ON -DTESTCCUTL_SINGLE=ON
	cmake --build $<

build-headers: build/headers
	node build_scripts/buildFeatureSummary
	cmake -B$< -GNinja -DTESTCCUTL=ON
	cmake --build $<

build-headers-single: build/headers_single
	node build_scripts/buildFeatureSummary
	cmake -B$< -GNinja -DTESTCCUTL=ON -DTESTCCUTL_SINGLE=ON
	cmake --build $<

install: build-headers
	cmake --install build/headers

test-modules: build/modules build-modules
	cmake --build $< --target testccutl
	./$</test/testccutl

test-modules-single: build/modules_single build-modules-single
	cmake --build $< --target testccutl
	./$</test/testccutl

test-headers: build/headers build-headers
	cmake --build $< --target testccutl
	./$</test/testccutl

test-headers-single: build/headers_single build-headers-single
	cmake --build $< --target testccutl
	./$</test/testccutl

test-all: test-modules test-modules-single test-headers test-headers-single

clean:
	${RM} -rf build

.PHONY: all install build-modules build-modules-single build-headers       \
	      build-headers-single test-modules test-modules-single test-headers \
				test-headers-single test-all clean
