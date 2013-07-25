cmake_minimum_required (VERSION 2.8)
project (TEST_INTS)

if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()


execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "GCC Version >=  4.7 => using c++0x compile switch")
		set(CMAKE_CXX_FLAGS "-Werror -std=c++0x -D__STDC_UTF_16__")
		set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ ")
else()
        message(STATUS "GCC Version < 4.7")
		set(CMAKE_CXX_FLAGS "-Werror")
endif()

set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)

include_directories (
..
../sc_ft
)

add_executable(tb_int tb_int.cpp)
add_executable(tb_int_types tb_int_types.cpp)

