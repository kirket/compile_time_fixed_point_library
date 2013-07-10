////////////////////////////////////////////////////////////////////////////// 
// Copyright© 2013 by Broadcom Corporation. All Rights reserved.
// Origina Author : Tony Kirke, Broadcom Corporation.
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

#ifndef SYSTEMC_SCFIXED_INT_CLASSES_H_
#define SYSTEMC_SCFIXED_INT_CLASSES_H_

#if __cplusplus < 201103L
#include <inttypes.h>
#else
#include <cinttypes>
#endif

/// SystemC namespace for compile-time fixed point types: sc_fixed,sc_ufixed,sc_int,sc_uint
namespace sc_ft {

	/// Template functions to use in Compile-time Template Parameters : Absolute Value
	template <int A_> struct Abs_Func { enum { val = (A_ < 0) ? -A_ : A_ };	};
	/// Max compile time calculation
	template <int A_, int B_> struct Template_Max { enum { maxval = (A_ > B_) ? A_ : B_ };	};
	/// Max Total Bits for sc_fixed based on Max of two different sc_fixed 
	template <int T_, int I_, int T1_, int I1_>
        struct Template_Max_Total_Bits { 
			enum { maxval = Template_Max<T_-I_,T1_-I1_>::maxval + Template_Max<I_,I1_>::maxval };
		};
	
#if __cplusplus < 201103L
	/// Compile-time assert class to use for when more than 64 bits used!
	template<bool test> struct CompileAssert {typedef bool compile_ok;};
	/// Failure case doesn't have typedef
	template<> struct CompileAssert<false>  {}; // fail on false.
#endif


	/// Use Template parameter to select int type, default is error, should go to one of the specializations below
	template <int S_> struct int_type_size { 
		/// will generate compiler error
#if __cplusplus < 201103L
		typedef typename CompileAssert<(S_<65)>::compile_ok int_type;
		typedef typename CompileAssert<(S_<65)>::compile_ok uint_type;
#else
		static_assert(S_ < 65, " bitwidth is too large > 64" );
		// these are for completeness
		typedef uint64_t uint_type;
		typedef  int64_t  int_type;
#endif
	};
	/// Specialization for 8 bits
	template<> struct int_type_size<8>  { typedef int8_t int_type;  typedef uint8_t uint_type; };
	/// Specialization for 16 bits
	template<> struct int_type_size<16> { typedef int16_t int_type; typedef uint16_t uint_type; };
	/// Specialization for 32 bits
	template<> struct int_type_size<32> { typedef int32_t int_type; typedef uint32_t uint_type; };
	/// Specialization for 64 bits
	template<> struct int_type_size<64> { typedef int64_t int_type; typedef uint64_t uint_type; };
	// Not-supported currently
#if __cplusplus >= 201103L
	template<> struct int_type_size<128> { typedef long long int_type; };
#endif

	/// For mapping to minimum integer type size
	template<int N_VAL> struct NEXT_INT_SIZE {
		enum {val = N_VAL <= 8 ? 8: N_VAL <= 16 ? 16 : N_VAL <= 32 ? 32 : N_VAL <= 64 ? 64 : N_VAL <= 128 ? 128 : 256 };
	};

	// Forward int/uint types based on bit-width
	template <int S_> struct int_size_needed {
		typedef typename int_type_size<NEXT_INT_SIZE<S_>::val>::uint_type uint_type;
		typedef typename int_type_size<NEXT_INT_SIZE<S_>::val>::int_type int_type;
		int_type val;
		bool operator[](int i) { return((val & (1 << i)) ? 1 : 0);}
	};

	/// Possible ranges for bit-widths
	typedef int64_t max_int_type;
	typedef uint64_t max_uint_type;

}
	
#endif
