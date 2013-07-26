
Compile Time Fixed Point library for SystemC
================================

A C++ library of (largely) SystemC compatible compile time fixed point data types for fast simulation and synthesis

The objective of this library is to provide classes for the following types

- sc_fixed
- sc_ufixed
- sc_int
- sc_uint

that are

- a) much faster for simulation than the current equivalent SystemC types
- b) potentially synthesisable using current high-level synthesis tools
- c) have more intuitive return types for various math operations such as addition,subtraction, multiplication, etc

Initial support will only be for

- Saturation modes : SC\_WRAP, SC_SAT
and
- Rounding modes : SC\_RND, SC_TRN

These types will exist in the namespace *sc_ft* and will be able to co-exist with current SystemC types as long as header files do not contain lines such as *"using namespace sc_dt;"*

This code compiles with both GCC 4.2.1 and 4.7.0 (using C++011)


To see the fixed-point type semantics for the integer types, please look at file test_ints/Type_Info.txt


This is an example of the output of the test run in the speed_test directory.

This is with GCC 4.2.1
 

             SystemC 2.3.0-ASI --- Jul 11 2013 17:10:30
        Copyright (c) 1996-2012 by all Contributors,
        ALL RIGHTS RESERVED

Starting Loops with Loops = 1048576
double    Time elapsed = 0.057703  Factor = 1
sc_dt     Time elapsed = 19.2423  Factor = 333.47
sc_ft     Time elapsed = 0.0629501  Factor = 1.09093


This is with GCC 4.7.0 (C++11)

             SystemC 2.3.0-ASI --- Jul 11 2013 17:10:30
        Copyright (c) 1996-2012 by all Contributors,
        ALL RIGHTS RESERVED

Starting Loops with Loops = 1048576
double    Time elapsed = 0.0416451  Factor = 1
sc_dt     Time elapsed = 18.8252  Factor = 452.039
sc_ft     Time elapsed = 0.061903  Factor = 1.48644

