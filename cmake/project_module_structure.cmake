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

include (cmake/add_module.cmake)

# The following section is generated using codegen/buildModuleDeps.            #
# The script generates a dependency chain for each module and writes it here.  #
# add_module communicates these dependcies to CMake and creates their targets. #

# begin project modules
add_module (ccutl.specialization_of)
add_module (ccutl.specializable_with)
add_module (ccutl.reduce)
add_module (ccutl.range_of)
add_module (ccutl.noref)
add_module (ccutl.nontype_specialization_of)
add_module (ccutl.nocvref)
add_module (ccutl.subscriptable_to
            ccutl.nocvref)
add_module (ccutl.nocv)
add_module (ccutl.mv
            ccutl.noref)
add_module (ccutl.meta.neq
            ccutl.neq)
add_module (ccutl.lowest
            ccutl.specializes)
add_module (ccutl.indexed_type)
add_module (ccutl.same
            ccutl.indexed_type)
add_module (ccutl.specializes
            ccutl.same)
add_module (ccutl.highest
            ccutl.specializes)
add_module (ccutl.lt
            ccutl.highest)
add_module (ccutl.meta.lt
            ccutl.lt)
add_module (ccutl.fwd
            ccutl.noref)
add_module (ccutl.strlen
            ccutl.fwd)
add_module (ccutl.streq
            ccutl.fwd)
add_module (ccutl.indexed_arg
            ccutl.fwd)
add_module (ccutl.nontype_pack
            ccutl.indexed_arg
            ccutl.nontype_specialization_of
            ccutl.type_pack)
add_module (ccutl.eq
            ccutl.highest
            ccutl.fwd)
add_module (ccutl.neq
            ccutl.eq)
add_module (ccutl.meta.eq
            ccutl.eq)
add_module (ccutl.lteq
            ccutl.eq
            ccutl.lt)
add_module (ccutl.meta.lteq
            ccutl.lteq)
add_module (ccutl.gt
            ccutl.eq
            ccutl.lt)
add_module (ccutl.meta.gt
            ccutl.gt)
add_module (ccutl.gteq
            ccutl.gt)
add_module (ccutl.meta.gteq
            ccutl.gteq)
add_module (ccutl.type_pack
            ccutl.meta.gt
            ccutl.meta.gteq
            ccutl.meta.lt
            ccutl.meta.lteq
            ccutl.specializable_with
            ccutl.specialization_of)
add_module (ccutl.meta
            ccutl.meta.eq
            ccutl.meta.gt
            ccutl.meta.gteq
            ccutl.meta.lt
            ccutl.meta.lteq
            ccutl.meta.neq)
add_module (ccutl.different
            ccutl.same)
add_module (ccutl.boolean_testable
            ccutl.fwd)
add_module (ccutl
            ccutl.nocv
            ccutl.mv
            ccutl.boolean_testable
            ccutl.meta
            ccutl.nontype_pack
            ccutl.subscriptable_to
            ccutl.range_of
            ccutl.streq
            ccutl.different
            ccutl.lowest
            ccutl.reduce
            ccutl.strlen)
# end project modules

# manual dependencies for non-module detail headers
add_dependencies (ccutl.streq.o  ccutl.subscriptable_to.o)
add_dependencies (ccutl.strlen.o ccutl.subscriptable_to.o)
add_dependencies (ccutl.eq.o     ccutl.noref.o)
add_dependencies (ccutl.gt.o     ccutl.noref.o)
add_dependencies (ccutl.gteq.o   ccutl.noref.o)
add_dependencies (ccutl.lt.o     ccutl.noref.o)
add_dependencies (ccutl.lteq.o   ccutl.noref.o)
add_dependencies (ccutl.neq.o    ccutl.noref.o)
