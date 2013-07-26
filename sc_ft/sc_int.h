// DO NOT EDIT THIS FILE IT WAS AUTOMATICALLY GENERATED ON 2013/07/26
////////////////////////////////////////////////////////////////////////////// 
// Copyrightę 2013 by Broadcom Corporation. All Rights reserved.
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

#ifndef SYSTEMC_SC_FT_SC_INT_20130726_CLASSES_H_
#define SYSTEMC_SC_FT_SC_INT_20130726_CLASSES_H_
#include <iostream>
#include <sstream>
#include <cmath> // for floor in sc_fixed
#include <sc_ft/sc_common.h>
#include <sc_ft/sc_int_bitref.h>
#include <sc_ft/sc_uint_bitref.h>
#include <sc_ft/sc_int_subref.h>
#include <sc_ft/sc_uint_subref.h>

namespace sc_ft {

	/// A faster version of the older systemc sc_int
	template <int I_> class sc_int {
	public:
		typedef typename int_type_size<NEXT_INT_SIZE<I_>::val>::int_type val_type;
		typedef int64_t max_val_type;
		val_type val;
#ifndef NO_LHS_RANGE
		sc_int_subref<I_> subref;
		sc_int_bitref<I_> bitref;
#endif
		static const int INTEGER_BITS = I_;



		public:
		/// constructors
		sc_int() : val(0) {	}
		
		/// From exact same type - just copy val
		sc_int(const sc_int& a) : val(a.getVal()) {	}
		sc_int(const double& a) : val((int64_t)a) {	}
		// Constructors (generated)
		sc_int(const int8_t& a) : val((int64_t)a) {	}
		sc_int(const int16_t& a) : val((int64_t)a) {	}
		sc_int(const int32_t& a) : val((int64_t)a) {	}
		sc_int(const int64_t& a) : val((int64_t)a) {	}
		sc_int(const uint8_t& a) : val((int64_t)a) {	}
		sc_int(const uint16_t& a) : val((int64_t)a) {	}
		sc_int(const uint32_t& a) : val((int64_t)a) {	}
		sc_int(const uint64_t& a) : val((int64_t)a) {	}


		/// from another sc_int<>
		template <int I_1> sc_int(const sc_int<I_1>& a) {
			val = a.val;
		}

		// for now
		val_type getVal() const { return(val); }

		/// Conversions
		void from_int(int64_t x) {	val = (max_val_type)x;	}
		double to_double(void) const { return((double)val);}
		int64_t to_int(void) const { return((int64_t)val); }

		// conversion to bool
		bool operator !() const { return(val == 0);}
		
		operator int64_t() const { return((int64_t)val); }
		

		sc_int& operator ++() {
			val++;
			return *this;
		}
		sc_int operator ++(int) { sc_int tmp(*this); ++*this; return(tmp);}
		sc_int& operator --() {
			val--;
			return *this;
		}
		sc_int operator --(int) { sc_int tmp(*this); --*this; return(tmp);}
		
		// assignment operator, just copy the only member variable - no checks!
		// could use copy constructor + swap?
		sc_int& operator =(const sc_int& a) {	
			val= a.getVal();
			return *this;
		}

	    template <int I_1> sc_int(const sc_int_subref<I_1>& a) : val((int64_t)a.val) {	}
	    template <int I_1> sc_int(const sc_int_bitref<I_1>& a) : val((int64_t)a.val) {	}
		template <int I_1> sc_int& 
			operator =(const sc_int_subref<I_1>& a) {	
			val= a.val;
			return *this;
		}
		template <int I_1> sc_int& 
			operator =(const sc_uint_subref<I_1>& a) {	
			val= a.val;
			return *this;
		}
		template <int I_1> sc_int& 
			operator =(const sc_int_bitref<I_1>& a) {	
			val= a.val;
			return *this;
		}
		template <int I_1> sc_int& 
			operator =(const sc_uint_bitref<I_1>& a) {	
			val= a.val;
			return *this;
		}

#ifndef NO_LHS_RANGE
	  // Sub/bitref LHS Stuff
		sc_int_bitref<I_>& operator[](uint64_t i) {
			bool tmp = (val >> i) & 0x1;
			bitref.val = tmp;
			bitref.index = i;
			bitref.val_ptr = this;
			return bitref;
		}
		sc_int_subref<I_>& range(int lhs, int rhs) {
			uint64_t tmp = (val >> rhs) & ((1 << (lhs-rhs+1)) - 1);
			subref.val = tmp;
			subref.lhs = lhs;
			subref.rhs = rhs;
			subref.val_ptr = this;
			return subref;
		}
		sc_int_subref<I_>& range(int lhs, int rhs) const {
			subref.val = val;
			return subref;
		}
#endif

	
		/// assignment operator from another size, use copy constructor, then copy val;
		template <int I_1> sc_int<I_>& operator =(const sc_int<I_1>& a) {
			sc_int<I_> temp(a);
			val = temp.getVal();
			return *this;
		}

		/// sign operator
		sc_int<I_+1> operator -() const {
			sc_int<I_+1> tmp(*this); tmp.val = -tmp.val;	return tmp; 
		} 
		sc_int<I_> operator +() const {
			sc_int<I_> tmp(*this);	return tmp; 
		} 

		/// bit flip
		sc_int operator ~() const { 
			sc_int tmp(*this); tmp.val = ~tmp.val; return(tmp);
		}

		// Assign from different built-in types
		sc_int& operator = (const int8_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const int16_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const int32_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const int64_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const uint8_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const uint16_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const uint32_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const uint64_t& a) {*this = sc_int(a); return *this; }
		sc_int& operator = (const double& a) {*this = sc_int(a); return *this; }

		template <int I_1> sc_int& operator +=(const sc_int<I_1>& a) {
			val += a.val;
			return *this;
		}

		template <int I_1> sc_int& operator -=(const sc_int<I_1>& a) {
			*this += (-a); // re-use +=
			return *this;
		}

		template <int I_1> sc_int& operator *=(const sc_int<I_1>& b) {
			val *= b.val;
			return *this;
		}
		sc_int& operator += (const int8_t& b) {val += b;	return *this;}
		sc_int& operator -= (const int8_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const int8_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const int8_t& b) {val /= b;	return *this;}
		sc_int& operator += (const int16_t& b) {val += b;	return *this;}
		sc_int& operator -= (const int16_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const int16_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const int16_t& b) {val /= b;	return *this;}
		sc_int& operator += (const int32_t& b) {val += b;	return *this;}
		sc_int& operator -= (const int32_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const int32_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const int32_t& b) {val /= b;	return *this;}
		sc_int& operator += (const int64_t& b) {val += b;	return *this;}
		sc_int& operator -= (const int64_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const int64_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const int64_t& b) {val /= b;	return *this;}
		sc_int& operator += (const uint8_t& b) {val += b;	return *this;}
		sc_int& operator -= (const uint8_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const uint8_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const uint8_t& b) {val /= b;	return *this;}
		sc_int& operator += (const uint16_t& b) {val += b;	return *this;}
		sc_int& operator -= (const uint16_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const uint16_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const uint16_t& b) {val /= b;	return *this;}
		sc_int& operator += (const uint32_t& b) {val += b;	return *this;}
		sc_int& operator -= (const uint32_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const uint32_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const uint32_t& b) {val /= b;	return *this;}
		sc_int& operator += (const uint64_t& b) {val += b;	return *this;}
		sc_int& operator -= (const uint64_t& b) {val -= b;	return *this;}
		sc_int& operator *= (const uint64_t& b) {val *= b;	return *this;}
		sc_int& operator /= (const uint64_t& b) {val /= b;	return *this;}
		// "+= and -=" from different built-in types

		sc_int& operator *=(const double& a) {sc_int tmp(a); 
			val *= tmp.getVal();
			return *this; 
		}
		sc_int& operator /=(const double& a) {sc_int tmp(a); 
			val /= tmp.getVal();
			return *this; 
		}
		sc_int& operator +=(const double& a) {sc_int tmp(a); 
			val += tmp.getVal();
			return *this; 
		}
		sc_int& operator -=(const double& a) {sc_int tmp(a); 
			val -= tmp.getVal();
			return *this; 
		}
		sc_int& operator >>=(const int& a) {
			val >>= a;
			return *this; 
		}
		sc_int& operator <<=(const int& a) {
			val <<= a;
			return *this; 
		}

		template <typename T> sc_int& operator &=(const T &l) {
			val &= l;	return *this;	
		}
		template <typename T> sc_int& operator |=(const T &l) {
			val |= l;	return *this; 
		}
		template <typename T> sc_int& operator ^=(const T &l) {
			val ^= l;	return *this;	
		}

	// Gen String Conversions
	/// Warning Not Complete
	std::string to_dec() const {
		std::stringstream ss;
		ss << std::dec << to_int();
		return(ss.str());
	}
	/// Warning Not Complete
	std::string to_oct() const {
		std::stringstream ss;
		ss << std::oct << to_int();
		return(ss.str());
	}
	/// Warning Not Complete
	std::string to_hex() const {
		std::stringstream ss;
		ss << std::hex << to_int();
		return(ss.str());
	}
	/// 
	std::string to_bin() const {
		std::stringstream ss;
		for (int i=I_-1;i>-1;i--) {
			bool b = (val >> i) & 0x1;
			if (b) ss << "1";
			else ss << "0";
		}
		return(ss.str());
	}

     /// Warning Not Complete
	 std::string to_string(sc_numrep numrep, bool with_prefix, sc_fmt FMT=SC_F) const {
	    std::string s;
	    switch(numrep) {
			case SC_DEC: s = to_dec(); break;
			case SC_OCT: s = to_oct(); break;
			case SC_HEX: s = to_hex(); break;
		    default: s = to_bin(); break;
	     }
     	 return(s);
     }

	
		/// Warning Not Complete
		void print( std::ostream& os = ::std::cout ) const { 
			os << to_int(); 
		}
		/// Warning Not Complete
		void scan( std::istream& is) { ;}
		
	}; // end of class 
	
	
} // end of namespace sc_ft

#endif
    

	

    
