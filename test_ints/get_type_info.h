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
// Macros to avoid code duplication
// For type info please include a declaration of int status in your main program
//
#include <typeinfo>
#include <cxxabi.h>

#define DEMG(x) abi::__cxa_demangle(typeid(x).name(),0,0,&status)
#define TYPE_NAME(x) std::cout << "Type of " << #x << " is  " << abi::__cxa_demangle(typeid(x).name(),0,0,&status) << "\n";
#define TYPE_SHORT(x) std::cout << #x << " type  " << abi::__cxa_demangle(typeid(x).name(),0,0,&status) << " ";

#define TYPE_TEMPLATE_LSHIFT(x,y) std::cout << "Type of \"" << DEMG(x) << x << " << " << y; std::cout << "\" is  " << DEMG(x << int_size<y>()) << "\n";
#define TYPE_TEMPLATE_RSHIFT(x,y) std::cout << "Type of \"" << DEMG(x) << x << " >> " << y; std::cout << "\" is  " << DEMG(x >> int_size<y>()) << "\n";
#define TYPE_NAME_SHIFT(x,y,OP) std::cout << "Type of \"" << DEMG(x) << " "; std::cout << #OP << " (" << DEMG(y) << ") " << y << "\" is  " << DEMG(x OP y) << "\n";
#define TYPE_NAME_FUNC_INTARG1(x,OP,y) std::cout << "Type of " << #OP << "(" << DEMG(x) << "," << y << ") is " << DEMG(OP(x,y)) << "\n";
#define TYPE_NAME_OP(x,y, OP)					  \
	std::cout << "Type of ";					  \
	if (typeid( x OP y ) == typeid (double)) {							\
		if(typeid(x) == typeid(double))  std::cout << "double";	else std::cout << DEMG(x);		 \
		std::cout << #OP ;		 \
		if(typeid(y) == typeid(double))  std::cout << "double";	else std::cout << DEMG(y);		 \
	std::cout << " is double\n";										\
	} else {															\
		if(typeid(x) == typeid(double))  std::cout << "double";	else std::cout << DEMG(x);		 \
		std::cout << " " << #OP << " ";		 \
		if(typeid(y) == typeid(double))  std::cout << "double";	else std::cout << DEMG(y);		 \
		std::cout << " is " << DEMG(x OP y) << "\n"; \
} \



#define TYPE_NAME_FUNC2(x,y, OP)					  \
  if (typeid( OP(x,y) ) == typeid (double))								\
	std::cout << "Type of " << #OP << "(" << DEMG(x) << "," << DEMG(y) << ") is double\n"; \
  else \
	std::cout << "Type of " << #OP << "(" << DEMG(x) << "," << DEMG(y) << ") is  " << DEMG(OP(x,y)) << "\n"; 

#define TYPE_NAME_FUNC(x, OP)					  \
  if (typeid( OP (x) ) == typeid (double))								\
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is double\n"; \
  else if (typeid( OP (x) ) == typeid (int16_t))						\
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is int16_t\n"; \
  else if (typeid( OP (x) ) == typeid (int32_t))						\
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is int32_t\n"; \
  else if (typeid( OP (x) ) == typeid (int64_t))						\
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is int64_t\n"; \
  else \
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is  " << DEMG(OP(x)) << "\n"; 


#define UTYPE_NAME_OP(x,y, OP)		\
	std::cout << "Type of " << DEMG(x) << #OP << DEMG(y) << " is  ***undefined*******\n"; 

#define UTYPE_NAME_FUNC2(x,y, OP)					  \
	std::cout << "Type of " << #OP << "(" << DEMG(x) << "," << DEMG(y) << ") is  ***undefined****\n"; 

#define UTYPE_NAME_FUNC(x, OP)					  \
	std::cout << "Type of " << #OP << "(" << DEMG(x) << ") is  ***undefined******\n"; 


#define MIXED_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, + );						\
  TYPE_NAME_OP( a, b, - );						\
  TYPE_NAME_OP( a, b, * );						\
  TYPE_NAME_OP( a, b, / );						\
  TYPE_NAME_OP( a, b, += );						\
  TYPE_NAME_OP( a, b, -= );						\
  TYPE_NAME_OP( a, b, *= );						\
  TYPE_NAME_OP( a, b, /= );						\


#define DMIXED_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, + );						\
  TYPE_NAME_OP( b, a, + );						\
  TYPE_NAME_OP( a, b, - );						\
  TYPE_NAME_OP( b, a, - );						\
  TYPE_NAME_OP( b, a, * );						\
  TYPE_NAME_OP( a, b, * );						\
  TYPE_NAME_OP( b, a, / );						\
  TYPE_NAME_OP( a, b, / );						\
  TYPE_NAME_OP( a, b, /= );						\
  TYPE_NAME_OP( b, a, /= );						\
  TYPE_NAME_OP( a, b, += );						\
  TYPE_NAME_OP( b, a, += );						\
  TYPE_NAME_OP( a, b, -= );						\
  TYPE_NAME_OP( b, a, -= );						\
  TYPE_NAME_OP( b, a, *= );						\
  TYPE_NAME_OP( a, b, *= );						\

#define DMIXED_LOGIC_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, | );						\
  TYPE_NAME_OP( b, a, | );						\
  TYPE_NAME_OP( a, b, & );						\
  TYPE_NAME_OP( b, a, & );						\
  TYPE_NAME_OP( b, a, ^ );						\
  TYPE_NAME_OP( a, b, ^ );						\
  TYPE_NAME_OP( a, b, |= );						\
  TYPE_NAME_OP( b, a, |= );						\
  TYPE_NAME_OP( a, b, &= );						\
  TYPE_NAME_OP( b, a, &= );						\
  TYPE_NAME_OP( b, a, ^= );						\
  TYPE_NAME_OP( a, b, ^= );						\



#define UNARY_TYPES(a) \
  TYPE_NAME_FUNC( a, - );\
  TYPE_NAME_FUNC( a, +);


#define SHIFT_TYPES(a,b,c)						\
  TYPE_NAME_SHIFT( a, b, >>); \
  TYPE_NAME_SHIFT( a, c, >>); \
  TYPE_NAME_SHIFT( a, b, >>=); \
  TYPE_NAME_SHIFT( a, c, >>=); \
  TYPE_NAME_SHIFT( a, b, <<); \
  TYPE_NAME_SHIFT( a, c, <<); \
  TYPE_NAME_SHIFT( a, b, <<=); \
  TYPE_NAME_SHIFT( a, c, <<=); \



#define COMPARES(a,b,c,TYPE)					\
	assert(TYPE(b) > a); \
	assert(TYPE(b) >= a); \
	assert(TYPE(c) < a); \
	assert(TYPE(c) <= a); \
	assert(TYPE(c) != a); \
	assert(a < (TYPE)b); \
	assert(a <= (TYPE)b); \
	assert(a > (TYPE)c); \
	assert(a >= (TYPE)c); \
	assert(a != (TYPE)c); 
   
#define TO_INT_TYPES(a)						\

// Value stuff
#define VALUE_TEMPLATE_LSHIFT(x,y) std::cout << "Value of \"" << DEMG(x) << x << " << " << y; std::cout << "\" is  " << (x << int_size<y>()) << "\n";
#define VALUE_TEMPLATE_RSHIFT(x,y) std::cout << "Value of \"" << DEMG(x) << x << " >> " << y; std::cout << "\" is  " << (x >> int_size<y>()) << "\n";

#define VALUE_NAME_FUNC_INTARG1(a,F,b) F(a,b)
#define VALUE_NAME_SHIFT(x,y,OP) std::cout << "Value of \"" << DEMG(x) << x << " "; std::cout << #OP << " " << y << "\" is  " << (x OP y) << "\n";
#define VALUE_NAME_FUNC(x, OP)	 std::cout << "Value of " << #OP << "(" << DEMG(x) << x << ") is " << OP(x) << "\n"; 


#define VALUE_NAME_OP(x,y,OP) \
	std::cout << "Value of \"";									\
	if (typeid(x) == typeid (double))	std::cout << " double ";	\
	else { std::cout << DEMG(x); };									\
	std::cout << x << " " << #OP << " ";						\
	if (typeid(y) == typeid (double))	std::cout << " double ";	\
	else { std::cout << DEMG(y); };									\
	std::cout << y << " is " << ( x OP y) << "\n"; \

#define VALUE_NAME_FUNC2(x,y, OP)					  \
	std::cout << "Value of " << #OP << "(" << DEMG(x) << x << "," << DEMG(y) << y << ") is " << OP(x,y) << "\n"; 


#define MIXED_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, + );						\
  VALUE_NAME_OP( a, b, - );						\
  VALUE_NAME_OP( a, b, * );						\
  VALUE_NAME_OP( a, b, / );						\
  VALUE_NAME_OP( a, b, += );						\
  VALUE_NAME_OP( a, b, -= );						\
  VALUE_NAME_OP( a, b, *= );						\
  VALUE_NAME_OP( a, b, /= );						\

#define DMIXED_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, + );						\
  VALUE_NAME_OP( b, a, + );						\
  VALUE_NAME_OP( a, b, - );						\
  VALUE_NAME_OP( b, a, - );						\
  VALUE_NAME_OP( b, a, * );						\
  VALUE_NAME_OP( a, b, * );						\
  VALUE_NAME_OP( a, b, += );						\
  VALUE_NAME_OP( b, a, += );						\
  VALUE_NAME_OP( a, b, -= );						\
  VALUE_NAME_OP( b, a, -= );						\
  VALUE_NAME_OP( b, a, *= );						\
  VALUE_NAME_OP( a, b, *= );						\
  VALUE_NAME_OP( a, b, /= );						\
  VALUE_NAME_OP( b, a, /= );						\

#define DMIXED_LOGIC_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, | );						\
  VALUE_NAME_OP( b, a, | );						\
  VALUE_NAME_OP( a, b, & );						\
  VALUE_NAME_OP( b, a, & );						\
  VALUE_NAME_OP( b, a, ^ );						\
  VALUE_NAME_OP( a, b, ^ );						\
  VALUE_NAME_OP( a, b, |= );						\
  VALUE_NAME_OP( b, a, |= );						\
  VALUE_NAME_OP( a, b, &= );						\
  VALUE_NAME_OP( b, a, &= );						\
  VALUE_NAME_OP( b, a, ^= );						\
  VALUE_NAME_OP( a, b, ^= );						\


#define UNARY_VALUES(a) \
  VALUE_NAME_FUNC( a, - );\
  VALUE_NAME_FUNC( a, +);


#define SHIFT_VALUES(a,b,c)						\
  VALUE_NAME_SHIFT( a, b, >>); \
  VALUE_NAME_SHIFT( a, c, >>); \
  VALUE_NAME_SHIFT( a, b, >>=); \
  VALUE_NAME_SHIFT( a, c, >>=); \
  VALUE_NAME_SHIFT( a, b, <<); \
  VALUE_NAME_SHIFT( a, c, <<); \
  VALUE_NAME_SHIFT( a, b, <<=); \
  VALUE_NAME_SHIFT( a, c, <<=); \



