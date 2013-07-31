cmake_minimum_required (VERSION 2.8)
project (TEST)

if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_CONFIGURATION_TYPES Debug Release)
   set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()


execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "GCC Version >=  4.7")
		set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -Wl,-rpath=$ENV{SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=/tools/oss/packages/x86_64-rhel5/gcc/4.7.0/lib64 -Wl,-rpath=/usr/brcm/oss/lib64 -Wl,-rpath=/usr/brcm/oss/lib ")
		set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++0x -D__STDC_UTF_16__")
else()
        message(STATUS "GCC Version < 4.7")
		set(CMAKE_EXE_LINKER_FLAGS "-Wl,-rpath=$ENV{SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=/usr/brcm/oss/lib64 ")
		set(CMAKE_CXX_FLAGS "-Wall -O3")
endif()

set(CMAKE_CXX_LINK_FLAGS "-L$ENV{SYSTEMC_HOME}/lib-linux64")

set(EXECUTABLE_OUTPUT_PATH ..)
set(LIBRARY_OUTPUT_PATH ..)

include_directories (
$ENV{SYSTEMC_HOME}/include
$ENV{SYSTEMC_HOME}/include/sysc/datatypes
)

add_executable(tst main.cpp noise.cpp)
target_link_libraries(tst systemc pthread)





