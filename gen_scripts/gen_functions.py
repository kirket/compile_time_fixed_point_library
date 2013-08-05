@{
import inspect
import fileinput,os,string,re,sys
import time
from math import *
sys.path.append(".")
license_string = """////////////////////////////////////////////////////////////////////////////// 
// Copyright� 2013 by Broadcom Corporation. All Rights reserved.
// Original Author : Tony Kirke, Broadcom Corporation.
// This software is available under both the SystemC Open Source License 
// Version 3.1 and the MIT License
//
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
// MIT License info:
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE 
// USE OR OTHER DEALINGS IN THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////// 
"""

int_types = ['int8_t','int16_t','int32_t','int64_t','uint8_t','uint16_t','uint32_t','uint64_t']
base_types = ['int8_t','int16_t','int32_t','int64_t','uint8_t','uint16_t','uint32_t','uint64_t','double']

assign_form1_types = int_types
div_form_types = base_types

dbg_string = 'std::cout << "At line: " << __LINE__ << " " << __PRETTY_FUNCTION__ << "\\n";'
dbg_string = ' ';

Namespace = 'sc_ft'
UNamespace = Namespace.upper()


GenDate = time.strftime("%Y/%m/%d")
Version = time.strftime("%Y%m%d")

# Most Capitalize strings are Empy Variables
Class = empy.args[0]
UClass = Class.upper()
Header_inc = "SYSTEMC_"+UNamespace+"_"+UClass+"_"+Version+"_CLASS_FUNCTIONS_H_"

add_license_file = open("license.txt").read()

}@
// DO NOT EDIT THIS FILE IT WAS AUTOMATICALLY GENERATED ON @(GenDate)
@(add_license_file)
////////////////////////////////////////////////////////////////////////////// 
#ifndef @(Header_inc)
#define @(Header_inc)
////////////////////////////////////////////////////////////////////////////// 

#include <iostream>

namespace @(Namespace) {


// Put outside of namespace
// IO functions
template <int NINT, int NFRC, sc_q_mode SC_Q_MODE, sc_o_mode SC_O_MODE> std::ostream& operator <<(std::ostream& os, const @(Class)<NINT, NFRC, SC_Q_MODE, SC_O_MODE>& r)
{
  return os << r.to_double(); // << " ";
};
template <int NINT, int NFRC, sc_q_mode SC_Q_MODE, sc_o_mode SC_O_MODE> std::istream& operator >>(std::istream& os, const @(Class)<NINT, NFRC, SC_Q_MODE, SC_O_MODE>& r)
{
  return os >> r;
};


// TEMPLATE functions for +,-,*,/ (divide returns double)

// addition
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+1,Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,QMODE,OMODE>
	operator +(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+1,Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,QMODE,OMODE> tmp(a);
    	tmp += b;	// no saturation needed since enough head space !
	    return(tmp);
}

// subtraction
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+1,Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,QMODE,OMODE>
	operator -(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+1,Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,QMODE,OMODE> tmp(a);
    	tmp -= b;	// no saturation needed since enough head space !
	    return(tmp);
}


// multiplication
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),QMODE,OMODE> 
	operator *(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	
	@(Class)<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),QMODE,OMODE> tmp;
	typedef typename @(Class)<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),QMODE,OMODE>::val_type mult_val_type;
	// Dont need to saturate here!
	tmp.val = (mult_val_type)(a.getVal())*(mult_val_type)(b.getVal());
	return tmp;
}

// division
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),QMODE,OMODE> 
	operator /(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	
	return ((double)a/(double)b);
}


// or
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE>
	operator |(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
    	tmpa.val |= tmpb.val;
	    return(tmpa);
}
// &
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE>
	operator &(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
    	tmpa.val &= tmpb.val;
	    return(tmpa);
}
// ^
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
	@(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE>
	operator ^(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
    	tmpa.val ^= tmpb.val;
	    return(tmpa);
}


// <<
template <int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE>
	operator <<(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const sc_uint<W>& shift) {
		@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE> tmp(a);
    	tmp <<= shift;
	    return(tmp);
}
// <<
template <int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE>
	operator <<(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const sc_int<W>& shift) {
		@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE> tmp(a);
    	tmp <<= shift;
	    return(tmp);
}


// >>
template <int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE>
	operator >>(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const sc_uint<W>& shift) {
		@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE> tmp(a);
    	tmp >>= shift;
	    return(tmp);
}
// >>
template <int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE>
	operator >>(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const sc_int<W>& shift) {
		@(Class)<TOTAL_BITS_+W,INT_BITS_+W,QMODE,OMODE> tmp(a);
    	tmp >>= shift;
	    return(tmp);
}
// >> with int
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>
	operator >>(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const int& shift) {
		@(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE> tmp(a);
    	tmp >>= shift;
	    return(tmp);
}
// << with int
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> 
	@(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>
	operator <<(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const int& shift) {
		@(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE> tmp(a);
    	tmp <<= shift;
	    return(tmp);
}



// Operations to support mixing with ints & doubles, etc

// Comparison operators "==,!=,<,<=,>,>=" between this type and 'double'


// NEW
//template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
//	bool operator ==(const uint_type& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_int() == (int)a);	}

// ^
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator ==(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return (tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator <(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return (tmpa.val < tmpb.val);
}
// re-use previous operators
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator !=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return !(tmpa.val == tmpb.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator >(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return (tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator <=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return !(tmpb.val < tmpa.val);
}
template <int TOTAL_BITS_, int INT_BITS_, int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode QMODE, sc_q_mode QMODE1, sc_o_mode OMODE, sc_o_mode OMODE1> 
bool
	operator >=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const @(Class)<TOTAL_BITS_1,INT_BITS_1,QMODE1,OMODE1>& b) {
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpa(a);
	    @(Class)<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,Template_Max<INT_BITS_,INT_BITS_1>::maxval,QMODE,OMODE> tmpb(b);
		return !(tmpa.val < tmpb.val);
}




// --------------------- BOOLEAN Comparisions "==,<=, <. >=, > , !=" -------------------------------------------
#ifdef ALL
// Compare with doubles
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() == a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() != a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() > a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() >= a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() < a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const double& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() <= a);	}

template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() == a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() != a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() < a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() <= a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() > a);	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const double& a)  {return (b.to_double() >= a);	}

// Compare with ints
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() == double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() != double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() > double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() >= double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() < double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const sc_uint<W>& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() <= double(a));	}

template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() == double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() != double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() < double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() <= double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() > double(a));	}
template<int W, int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const sc_uint<W>& a)  {return (b.to_double() >= double(a));	}

// compare with uint64
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() == double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() != double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() > double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() >= double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() < double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const uint64_t& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() <= double(a));	}

template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() == double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() != double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() < double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() <= double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() > double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const uint64_t& a)  {return (b.to_double() >= double(a));	}

// compare with int64
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() == double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() != double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() > double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() >= double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() < double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const int& a, const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b)  {return (b.to_double() <= double(a));	}

template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator ==(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() == double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator !=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() != double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  <(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() < double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator <=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() <= double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator  >(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() > double(a));	}
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE_, sc_o_mode OMODE_>
	bool operator >=(const @(Class)<TOTAL_BITS_,INT_BITS_,QMODE_,OMODE_> &b, const int& a)  {return (b.to_double() >= double(a));	}

#endif

@{
print "\t// Gen Math Ops"
for t in ['double','int','uint64_t']:
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator +(const "+t+"& a, const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& b) {"
	print "\t\treturn(((double)a+(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator +(const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& b, const "+t+"& a) {"
	print "\t\treturn(((double)a+(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator -(const "+t+"& a, const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& b) {"
	print "\t\treturn(((double)a-(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator -(const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const "+t+"& b) {"
	print "\t\treturn(((double)a-(double)b));}"

	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator *(const "+t+"& a, const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& b) {"
	print "\t\treturn(((double)a*(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator *(const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const "+t+"& b) {"
	print "\t\treturn(((double)a*(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator /(const "+t+"& a, const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& b) {"
	print "\t\treturn(((double)a/(double)b));}"
	print "\ttemplate <int TOTAL_BITS_, int INT_BITS_, sc_q_mode QMODE, sc_o_mode OMODE> double operator /(const "+Class+"<TOTAL_BITS_,INT_BITS_,QMODE,OMODE>& a, const "+t+"& b) {"
	print "\t\treturn(((double)a/(double)b));}"
}@


} // end of namespace @(Namespace)

#endif