cmake_minimum_required (VERSION 2.8)
project (TEST)

if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()

#SET(Boost_DEBUG 1)
# this is setup for Test framework to work , not sure of correct Min Version but 1.33 doesn't work
SET(BOOST_MIN_VERSION "1.47.0")
# Unconventional Setup!!!!
SET(BOOST_INCLUDEDIR /usr/brcm/oss/include/boost-1_47)

find_package(Boost ${BOOST_MIN_VERSION})
if (NOT Boost_FOUND)
      message("Building without Boost Unit Test Framework\n")
	  SET(BOOST_SETUP "-DDONT_USE_BOOST")
else()
      message("Found Boost version = ${Boost_VERSION}")
	  SET(BOOST_SETUP " ")
endif (NOT Boost_FOUND)



execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "GCC Version >=  4.7")
		set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -Wl,-rpath=$ENV{SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=/tools/oss/packages/x86_64-rhel5/gcc/4.7.0/lib64 -Wl,-rpath=/usr/brcm/oss/lib64 -Wl,-rpath=/usr/brcm/oss/lib ")
		set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++0x -D__STDC_UTF_16__ ${BOOST_SETUP} ")
else()
        message(STATUS "GCC Version < 4.7")
		set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath=$ENV{SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=/usr/brcm/oss/lib64 ")
		set(CMAKE_CXX_FLAGS "-Wall -O3 ${BOOST_SETUP}")
endif()

set(CMAKE_CXX_LINK_FLAGS "-L$ENV{SYSTEMC_HOME}/lib-linux64 -L/usr/brcm/oss/lib64")

set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)

include_directories (
../..
$ENV{SYSTEMC_HOME}/include
${Boost_INCLUDE_DIRS}
)
set(RND_TYPES "SC_TRN" "SC_RND")
set(SAT_TYPES "SC_SAT" "SC_WRAP" "SC_SAT_SYM")

foreach (r ${RND_TYPES})
	foreach (f ${SAT_TYPES})
		add_executable(tb_${r}_${f} tb_units.cpp)
		set_target_properties(tb_${r}_${f} PROPERTIES COMPILE_FLAGS "-DSATMODE=${f} -DRNDMODE=${r}")
        target_link_libraries(tb_${r}_${f} systemc pthread)


		add_executable(tb_shifts_${r}_${f} tb_shifts.cpp )
		set_target_properties(tb_shifts_${r}_${f} PROPERTIES COMPILE_FLAGS "-DSATMODE=${f} -DRNDMODE=${r}")
        target_link_libraries(tb_shifts_${r}_${f} systemc pthread)

	endforeach(f)
endforeach(r)

add_executable(tb_types tb_units.cpp )
set_target_properties(tb_types PROPERTIES COMPILE_FLAGS "-DCHECK_TYPES")
target_link_libraries(tb_types systemc pthread)

add_executable(tb_val tb_units.cpp )
set_target_properties(tb_val PROPERTIES COMPILE_FLAGS "-DCHECK_VALUES")
target_link_libraries(tb_val systemc pthread)


add_executable(tb_shifts_types tb_shifts.cpp )
set_target_properties(tb_shifts_types PROPERTIES COMPILE_FLAGS "-DCHECK_TYPES")
target_link_libraries(tb_shifts_types systemc pthread)

add_executable(tb_shifts_val tb_shifts.cpp )
set_target_properties(tb_shifts_val PROPERTIES COMPILE_FLAGS "-DCHECK_VALUES")
target_link_libraries(tb_shifts_val systemc pthread)






