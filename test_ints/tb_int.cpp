////////////////////////////////////////////////////////////////////////////// 
// Copyright© 2013 by Broadcom Corporation. All Rights reserved.
// Original Author : Tony Kirke, Broadcom Corporation.
// The contents of this file are subject to the restrictions and limitations
// set forth in the SystemC Open Source License Version 3.1 (the "License").
// You may not use this file except in compliance with such restrictions and
// limitations. You may obtain instructions on how to receive a copy of the
// License at http://www.accellera.org/. Software distributed by Contributors
// under the License is distributed exclusively on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied.
// See the License for the specific language governing rights and limitations
// under the License.
////////////////////////////////////////////////////////////////////////////// 
// Basic Test program for sc_int type
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cassert>

#include <sc_ft/sc_int_types.h>
#include "get_type_info.h"

using namespace std;
using namespace sc_ft;

// Quick way to enable/disable asserts
#define ASSERT(t) assert(t)
//#define ASSERT(t) 

int main(int argc, char* argv[]) {

  int status;
  const int INT_BITS = 12;

  srand( time(NULL) );

  sc_int<INT_BITS> x;
  sc_int<INT_BITS> y;
  sc_int<INT_BITS> diff;
  sc_int<INT_BITS> ls;
  sc_int<INT_BITS> rs;

  sc_int<5+6> a,b;
  sc_int<5+4> c;

  sc_int<2> s_shift = 1;
  sc_int<4> s_shift2 = 3;

  x = y = diff = ls = rs = 0;

  std::cout << "************* VALUES ****************\n";

  a = 10;
  b = 3;
  c = 2;

  std::cout << "a = " << a	<< " b = " << b	<< " c = " << c	<< "\n";
  std::cout.precision(16);

  std::cout << "************* Real values ****************\n";

  MIXED_VALUES( a, b, 1);						
  DMIXED_VALUES(a,c,1);
  SHIFT_VALUES(a,s_shift,s_shift2);
  SHIFT_VALUES(a,1,8);

  DMIXED_LOGIC_VALUES(a,c,1);
  std::cout << "\n";


  sc_int<11> sat_a;

  std::cout << "************* Mixing Real values with double ****************\n";
  double d = 1.234;

  DMIXED_VALUES(a,d,1);
  VALUE_NAME_OP( a ,d, / );

  // comparisions with doubles
  std::cout << "Start of ASSERTS \n";

  diff = 4;


  double eq_val = diff;
  sc_int<INT_BITS> x3 = 3;
  sc_int<INT_BITS> y5 = 5;
  sc_int<INT_BITS-1> w3 = 3;
  sc_int<INT_BITS-1> z5 = 5;

  // comparisions with double/int
  COMPARES( diff, 5, 3, double);
  COMPARES( diff, 5, 3, int);
  COMPARES( diff, y5, x3, sc_int<INT_BITS>);
  COMPARES( diff, z5, w3, sc_int<INT_BITS-1>);

  ASSERT( eq_val == diff );
  ASSERT( diff == eq_val);

  /// integer math

  sc_int<INT_BITS> t_one = 1;
  sc_int<INT_BITS> one = 1;
  sc_int<INT_BITS> two = 2;
  sc_int<INT_BITS> minus10 = -10;

  ASSERT( one + two == 3 );
  ASSERT( two + one == 3 );
  ASSERT( two - one == 1 );
  ASSERT( two * one == 2 );
  ASSERT( two / one == 2 );
  
  ASSERT( one + minus10 == -9 );
  ASSERT( minus10 + one == -9 );
  ASSERT( minus10 - one == -11 );
  ASSERT( minus10 * one == -10 );
  ASSERT( minus10 / one == -10 );
  
  ASSERT( two + minus10 == -8 );
  ASSERT( minus10 + two == -8 );
  ASSERT( minus10 - two == -12 );
  ASSERT( minus10 * two == -20 );
  ASSERT( minus10 / two == -5 );

  std::cout << "End of ASSERTS 1\n";

  cout << "t_one = " << t_one;
 
  t_one += double(6.0);
  t_one -= double(6.0);
  
  t_one += 6;
  t_one -= 6; 

  t_one += double(6);
  t_one -= double(6);

  t_one += float(6.0);

  cout << " + 6.0 = " << t_one;

  t_one *= 4;
  t_one /= 4;

  t_one *= double(4);
  t_one /= double(4);

  t_one *= (double)4;
  t_one /= (double)4;
  
  t_one /= 4.0;
  cout << " / 4.0 = " << t_one  << "\n";

  cout << "one = " << one << "\n";
  ASSERT( 3.0 == (one += two) );
  cout << "one = " << one << "\n";
  ASSERT( -2.0 == (one -= 5));
  cout << "one = " << one << "\n";
  ASSERT( 8.0 == (one += 10));
  cout << "one = " << one << "\n";
  ASSERT( 16.0 == (one *= two) );
  ASSERT( 4.0 == (one /= 4) );

  double dhs = 3.0;

  double dresult;

  cout << "inputs = " << dhs << "," << t_one << "\n";

  // Test mixed instantiations

  // "-'" and "+"

  dresult = dhs - t_one; cout << " a - b = " << dresult;
  dresult = t_one - dhs; cout << " b - a = " << dresult;
  dresult = dhs + t_one; cout << " a + b = " << dresult;
  dresult = t_one + dhs; cout << " b + a = " << dresult << "\n";

  // "*"
  cout << " Multiplies ";
  
  dresult = dhs * t_one; cout << " a * b = " << dresult;
  dresult = t_one * dhs; cout << " b * a = " << dresult << "\n";

  // "/"
  cout << " Divides ";
  dresult = dhs / t_one; cout << " a/b = " << dresult;
  dresult = t_one / dhs; cout << " b/a =  " << dresult << "\n";


  
  return(0);
}
