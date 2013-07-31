#include <typeinfo>
#include <cxxabi.h>

#define DEMG(x) abi::__cxa_demangle(typeid(x).name(),0,0,&status)
#define TYPE_NAME(x) std::cout << "Type of " << #x << " is  " << abi::__cxa_demangle(typeid(x).name(),0,0,&status) << "\n";
#define TYPE_SHORT(x) std::cout << #x << " type  " << abi::__cxa_demangle(typeid(x).name(),0,0,&status) << " ";

#define TYPE_TEMPLATE_LSHIFT(x,y) std::cout << "Type of \"" << DEMG(x) << x << " << " << y; std::cout << "\" is  " << DEMG(x << int_size<y>()) << "\n";
#define TYPE_TEMPLATE_RSHIFT(x,y) std::cout << "Type of \"" << DEMG(x) << x << " >> " << y; std::cout << "\" is  " << DEMG(x >> int_size<y>()) << "\n";
#define TYPE_NAME_SHIFT(x,y,OP) std::cout << "Type of \"" << DEMG(x) << " "; std::cout << #OP << " " << y << "\" is  " << DEMG(x OP y) << "\n";
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

#define THIS_MIXED_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, += );						\
  TYPE_NAME_OP( a, b, -= );						\
  TYPE_NAME_OP( a, b, *= );						\


#define DMIXED_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, + );						\
  TYPE_NAME_OP( b, a, + );						\
  TYPE_NAME_OP( a, b, - );						\
  TYPE_NAME_OP( b, a, - );						\
  TYPE_NAME_OP( b, a, * );						\
  TYPE_NAME_OP( a, b, * );						\

#define DMIXED_THIS_TYPES(a,b,c)						\
  TYPE_NAME_OP( a, b, += );						\
  TYPE_NAME_OP( b, a, += );						\
  TYPE_NAME_OP( a, b, -= );						\
  TYPE_NAME_OP( b, a, -= );						\
  TYPE_NAME_OP( b, a, *= );						\
  TYPE_NAME_OP( a, b, *= );						\


#define FUNC_TYPES(a,b,c)						\
  TYPE_NAME_FUNC( a, - );						\
  TYPE_NAME_SHIFT( a, b, >>); \
  TYPE_NAME_SHIFT( a, c, >>); \
  TYPE_NAME_SHIFT( a, b, <<); \
  TYPE_NAME_SHIFT( a, c, <<); \


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

#define THIS_MIXED_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, += );						\
  VALUE_NAME_OP( a, b, -= );						\
  VALUE_NAME_OP( a, b, *= );						\


#define DMIXED_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, + );						\
  VALUE_NAME_OP( b, a, + );						\
  VALUE_NAME_OP( a, b, - );						\
  VALUE_NAME_OP( b, a, - );						\
  VALUE_NAME_OP( b, a, * );						\
  VALUE_NAME_OP( a, b, * );						\

#define DMIXED_THIS_VALUES(a,b,c)						\
  VALUE_NAME_OP( a, b, += );						\
  VALUE_NAME_OP( b, a, += );						\
  VALUE_NAME_OP( a, b, -= );						\
  VALUE_NAME_OP( b, a, -= );						\
  VALUE_NAME_OP( b, a, *= );						\
  VALUE_NAME_OP( a, b, *= );						\


#define FUNC_VALUES(a,b,c)						\
  VALUE_NAME_FUNC( a, - );						\
  VALUE_NAME_SHIFT( a, b, >>); \
  VALUE_NAME_SHIFT( a, c, >>); \
  VALUE_NAME_SHIFT( a, b, <<); \
  VALUE_NAME_SHIFT( a, c, <<); 

#define FUNC2_VALUES(a,b,c) \
  VALUE_NAME_SHIFT( a, b, >>=); \
  VALUE_NAME_SHIFT( a, c, >>=); \
  VALUE_NAME_SHIFT( a, b, <<=); \
  VALUE_NAME_SHIFT( a, c, <<=); \

#define FUNC2_TYPES(a,b,c) \
  TYPE_NAME_SHIFT( a, b, >>=); \
  TYPE_NAME_SHIFT( a, c, >>=); \
  TYPE_NAME_SHIFT( a, b, <<=); \
  TYPE_NAME_SHIFT( a, c, <<=); \

