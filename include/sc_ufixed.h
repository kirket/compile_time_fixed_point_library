// DO NOT EDIT THIS FILE IT WAS AUTOMATICALLY GENERATED 2013/07/12
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
#ifndef SYSTEMC_SC_FT_SC_UFIXED_20130712_CLASSES_H_
#define SYSTEMC_SC_FT_SC_UFIXED_20130712_CLASSES_H_


#include <sc_int_types.h>
#include <sc_fixed_roundsat.h>
namespace sc_ft {

/// A faster, lightweight and potentially synthesizable Fixed-point class based on sc_fixed/sc_ufixed
template <int TOTAL_BITS_, int INT_BITS_, sc_q_mode SC_Q_MODE_= SC_TRN, sc_o_mode SC_O_MODE_ = SC_WRAP>
class sc_ufixed {

  //BOOST_STATIC_ASSERT(TOTAL_BITS_ < 65);

// private:
 public:
	typedef sc_uint<TOTAL_BITS_> val_type;
	typedef uint64_t max_val_type;
  /// for sc_int this is defined and is a sub-reference, just pass it on
  typedef sc_int_subref<TOTAL_BITS_> subref_type; 
  /// for sc_int this is defined and is a bit-reference, just pass it on
  typedef sc_int_bitref<TOTAL_BITS_> bitref_type; 
  val_type val;

 public:
	// constructors
	sc_ufixed() : val(0) {	}
    sc_ufixed(double a) { from_double(a);}
	// built-in types

	template <int W> sc_ufixed(const sc_int<W>& a)  {	from_int(a.to_int());	}
	template <int W> sc_ufixed(const sc_uint<W>& a) {	from_int(a.to_int());	}

	
	// Gen Constructors
	sc_ufixed(int8_t a) { from_int(a);}
	sc_ufixed(int16_t a) { from_int(a);}
	sc_ufixed(int32_t a) { from_int(a);}
	sc_ufixed(int64_t a) { from_int(a);}
	sc_ufixed(uint8_t a) { from_int(a);}
	sc_ufixed(uint16_t a) { from_int(a);}
	sc_ufixed(uint32_t a) { from_int(a);}
	sc_ufixed(uint64_t a) { from_int(a);}

	// From exact same type - just copy val
	sc_ufixed(const sc_ufixed& a) : val(a.getVal()) {	}
	// from another sc_ufixed<>
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1> 
		sc_ufixed(const sc_ufixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
		// Combine separate round and saturates
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(
			sc_shift_class_function<TOTAL_BITS_-INT_BITS_,SC_Q_MODE_>::shift_function(a));
	}
	// from sc_fixed<>
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1> 
		sc_ufixed(const sc_fixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
		// Combine separate round and saturates
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(
			sc_shift_class_function<TOTAL_BITS_-INT_BITS_,SC_Q_MODE_>::shift_function(a));
	}

	// This is not yet functional (FIXME)
	bitref_type& operator[](uint64_t i) {
		return val[i];
	}
	
	// for now
	val_type getVal() const { return(val); }

	// Conversions
	void from_double(double x) {
	if (x<0) val = 0; else 
	  val = (val_type)floor(x * ((max_val_type)1 << (TOTAL_BITS_-INT_BITS_)) + 0.5*(SC_Q_MODE_==SC_RND));
	}

	// Conversions
	template <typename T_> void from_int(T_ x) {
	if (x<0) val = 0; else 
	  val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(
			((max_val_type)x << (TOTAL_BITS_-INT_BITS_)));
	}

	double to_double(void) const {
		double y = ((double)val)/((uint64_t)1 << (TOTAL_BITS_-INT_BITS_));
		return(y);
	}
	int64_t to_int(void) const {
	    return (int64_t)sc_round_class_function<SC_Q_MODE_>::round(val,TOTAL_BITS_-INT_BITS_);
	}

	// Allow conversion to double for simulation purposes, this should not be in Synth Version
	operator double() const { return(to_double()); }
	// Conversion to int type for comparing to ints
	operator val_type() const { return( val >> (TOTAL_BITS_-INT_BITS_)); }

	// conversion to bool
	//////operator bool() const { return(val != 0); }
	bool operator !() const { return(val == 0);}

	sc_ufixed& operator ++() {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(1<<(TOTAL_BITS_-INT_BITS_)));
        return *this;
	}
	sc_ufixed operator ++(int) { sc_ufixed tmp(*this); ++*this; return(tmp);}
	sc_ufixed& operator --() {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(1<<(TOTAL_BITS_-INT_BITS_)));
        return *this;
	}
	sc_ufixed operator --(int) { sc_ufixed tmp(*this); --*this; return(tmp);}

	// assignment operator, just copy the only member variable - no checks!
	// could use copy constructor + swap?
	sc_ufixed& operator =(const sc_ufixed& a) {	
		val= a.getVal();
        return *this;
    }

	// for sc_int val_type val.range is sc_int_subref type
	subref_type& range(const int lhs, const int rhs) {
		return val.range(lhs,rhs);
	}

	// assignment operator from another size, use copy constructor, then copy val;
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed<TOTAL_BITS_,INT_BITS_,SC_Q_MODE_,SC_O_MODE_>& operator =(const sc_ufixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
	    sc_ufixed<TOTAL_BITS_,INT_BITS_,SC_Q_MODE_,SC_O_MODE_> temp(a);
		val = temp.getVal();
		return *this;
	}

	// 
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed<TOTAL_BITS_,INT_BITS_,SC_Q_MODE_,SC_O_MODE_>& operator =(const sc_fixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
	    sc_ufixed<TOTAL_BITS_,INT_BITS_,SC_Q_MODE_,SC_O_MODE_> temp(a);
		val = temp.getVal();
		return *this;
	}

	// sign operator - return sc_fixed
    sc_fixed<TOTAL_BITS_+1,INT_BITS_+1> operator -() const {
	     sc_fixed<TOTAL_BITS_+1,INT_BITS_+1> tmp;
		 tmp.val = val;
		 tmp.multm1();
		 return tmp;
	 } 
	// bit flip
	sc_ufixed operator ~() const {sc_ufixed tmp(*this); tmp.flip(); return(tmp);    }
	// Assign from different built-in types
	// Gen Assigns
	sc_ufixed& operator =(const int8_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const int16_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const int32_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const int64_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const uint8_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const uint16_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const uint32_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const uint64_t& a) {*this = sc_ufixed(a); return *this; }
	sc_ufixed& operator =(const double& a) {*this = sc_ufixed(a); return *this; }


	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator +=(const sc_ufixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
		sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		         Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,SC_Q_MODE_1,SC_O_MODE_1> tmp(*this); // just extra headroom above and below
		sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
            	 Template_Max<INT_BITS_,INT_BITS_1>::maxval+1,SC_Q_MODE_1,SC_O_MODE_1> tmpa(a); // just extra headroom above and below
				tmpa.val += tmp.val; // no saturation or rounding yet;
				*this = tmpa; // now saturate + round
				return *this;
	}
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator +=(const sc_fixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1,SC_O_MODE_1>& a) {
		 
		sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+2,
		         Template_Max<INT_BITS_,INT_BITS_1>::maxval+2,SC_Q_MODE_1,SC_O_MODE_1> tmp(*this); // just extra headroom above and below
		sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval+2,
		         Template_Max<INT_BITS_,INT_BITS_1>::maxval+2,SC_Q_MODE_1,SC_O_MODE_1> tmpa(a); // just extra headroom above and below
				tmpa.val += tmp.val; // no saturation or rounding yet;
				*this = tmpa; // now saturate + round
				return *this;
	}

	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator -=(const sc_ufixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1, SC_O_MODE_1>& a) {
		 
	    *this += (-a); // re-use +=
		return *this;
	}
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator -=(const sc_fixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1, SC_O_MODE_1>& a) {
		 
	    *this += (-a); // re-use +=
		return *this;
	}

	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1> sc_ufixed&
		operator *=(const sc_ufixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1, SC_O_MODE_1>& b) {
		 
		// first full precision
		sc_ufixed<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),SC_Q_MODE_,SC_O_MODE_> tmp = *this * b;
		// now assign from larger type
		*this = tmp;
		return *this;
	}
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1> sc_ufixed&
		operator *=(const sc_fixed<TOTAL_BITS_1,INT_BITS_1,SC_Q_MODE_1, SC_O_MODE_1>& b) {
		 
		// first full precision
		sc_ufixed<(TOTAL_BITS_+TOTAL_BITS_1),(INT_BITS_+INT_BITS_1),SC_Q_MODE_,SC_O_MODE_> tmp = *this * b;
		// now assign from larger type
		*this = tmp;
		return *this;
	}
    // Dont define this
	template <int TOTAL_BITS_1, int INT_BITS_1> sc_ufixed&
		operator /=(const sc_ufixed<TOTAL_BITS_1,INT_BITS_1>& b) {
		from_double(to_double()/b.to_double);
		return *this;
	}
    //

	// "+= and -=" from different built-in types

	// Gen Assigns 2
	sc_ufixed& operator +=(const double& a) {sc_ufixed tmp(a); 
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+tmp.getVal());
		return *this; 
	}
	sc_ufixed& operator -=(const double& a) {sc_ufixed tmp(a); 
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-tmp.getVal());
		return *this; 
	}

	// Gen Assigns 3
	sc_ufixed& operator +=(const int8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const int8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const int16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const int16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const int32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const int32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const int64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const int64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const uint8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const uint8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const uint16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const uint16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const uint32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const uint32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator +=(const uint64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val+(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}
	sc_ufixed& operator -=(const uint64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(val-(a<<(TOTAL_BITS_-INT_BITS_)));
		return *this; 
	}

	// "/="  and "*="
	// Gen Multiply/Divide 
	sc_ufixed& operator *=(const int8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const int8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const int16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const int16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const int32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const int32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const int64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const int64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const uint8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const uint8_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const uint16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const uint16_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const uint32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const uint32_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const uint64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const uint64_t& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}
	sc_ufixed& operator *=(const double& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val*a + 0.5)));
		return *this;
	}
	sc_ufixed& operator /=(const double& a) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate(int64_t(floor(val/a + 0.5)));
		return *this;
	}


	template <int W> sc_ufixed& operator <<=(sc_int<W> shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift.to_int());
		return *this;
	}
	template <int W> sc_ufixed& operator <<=(sc_uint<W> shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift.to_int());
		return *this;
	}

	template <int W> sc_ufixed& operator >>=(sc_int<W> shift) {
		val >>= shift.to_int();
		return *this;
	}
	template <int W> sc_ufixed& operator >>=(sc_uint<W> shift) {
		val >>= shift.to_int();
		return *this;
	}
	
	
	// Gen Right Shift/Equals 
	sc_ufixed& operator >>=(const int8_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const int16_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const int32_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const int64_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const uint8_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const uint16_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const uint32_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}
	sc_ufixed& operator >>=(const uint64_t& shift) {
		val = sc_round_class_function<SC_Q_MODE_>::round(val,shift);
		return *this;
	}


	// Gen Left Shift/Equals 
	sc_ufixed& operator <<=(int8_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(int16_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(int32_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(int64_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(uint8_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(uint16_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(uint32_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
	sc_ufixed& operator <<=(uint64_t shift) {
		val = sc_saturate_class_function<TOTAL_BITS_,SC_O_MODE_>::usaturate((max_val_type)val << shift);
		return *this;
	}
/*
    // needs work on resultant bit-sizes
    template <int B_>
	    sc_ufixed<TOTAL_BITS_+B_,INT_BITS_+B_,SC_Q_MODE_,SC_O_MODE_>
		operator <<(const int_size<B_>& x) {
	       sc_ufixed<TOTAL_BITS_+Template_Max<B_-TOTAL_BITS_+INT_BITS_,0>::maxval,INT_BITS_+B_,SC_Q_MODE_,SC_O_MODE_> y(*this);
     	   y <<= B_;
		   return y;
	    }
    // needs work on resultant bit-sizes
    template <int B_>
	    sc_ufixed<Template_Max<TOTAL_BITS_-B_,0>::maxval,Template_Max<INT_BITS_-B_,0>::maxval,SC_Q_MODE_,SC_O_MODE_> 
        operator >>(const int_size<B_>& x) {
           sc_ufixed<Template_Max<TOTAL_BITS_-B_,0>::maxval,Template_Max<INT_BITS_-B_,0>::maxval,SC_Q_MODE_,SC_O_MODE_> y(*this);
	       y >>= B_;
		   return y;
	    }
*/

	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator &=(const sc_ufixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1, SC_O_MODE_1>& a) {
 	    sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		         Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmp(*this);
		sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
      		     Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmpa(a);
		tmp.val &= tmpa.val;
		*this = tmp;
		return *this;
	}
	//
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator ^=(const sc_ufixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1, SC_O_MODE_1>& a) {
	sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmp(*this);
	sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmpa(a);

		tmp.val = tmp.val ^ tmpa.val;
		if ((TOTAL_BITS_1-INT_BITS_1) > (TOTAL_BITS_-INT_BITS_)) {
		tmp.val >>= Abs_Func<(TOTAL_BITS_1-INT_BITS_1) - (TOTAL_BITS_-INT_BITS_)>::val;
		}
	//if (INT_BITS_1 > INT_BITS_) std::cout << " FIXME masking needed ";
		val = tmp.val;
		return *this;
	}
	//
	template <int TOTAL_BITS_1, int INT_BITS_1, sc_q_mode SC_Q_MODE_1, sc_o_mode SC_O_MODE_1>
	sc_ufixed& operator |=(const sc_ufixed<TOTAL_BITS_1, INT_BITS_1, SC_Q_MODE_1, SC_O_MODE_1>& a) {
	sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmp(*this);
	sc_ufixed<Template_Max_Total_Bits<TOTAL_BITS_,INT_BITS_,TOTAL_BITS_1,INT_BITS_1>::maxval,
		Template_Max<INT_BITS_,INT_BITS_1>::maxval,SC_Q_MODE_,SC_O_MODE_> tmpa(a);

		tmp.val = tmp.val | tmpa.val;
		if ((TOTAL_BITS_1-INT_BITS_1) > (TOTAL_BITS_-INT_BITS_)) {
     		tmp.val >>= Abs_Func<(TOTAL_BITS_1-INT_BITS_1) - (TOTAL_BITS_-INT_BITS_)>::val;
		}
		if (INT_BITS_1 > INT_BITS_) {
			std::cout << " FIXME masking needed ";
		}
		val = tmp.val;
		return *this;
	}
	
	
	// boolean operators for same type
	bool operator ==(const sc_ufixed& a) const { return ((val == a.getVal())); }
	bool operator !=(const sc_ufixed& a) const { return ((val != a.getVal())); }
	bool operator  <(const sc_ufixed& a) const { return ((val  < a.getVal())); }
	bool operator  >(const sc_ufixed& a) const { return ((val  > a.getVal())); }
	bool operator <=(const sc_ufixed& a) const { return ((val <= a.getVal())); }
	bool operator >=(const sc_ufixed& a) const { return ((val >= a.getVal())); }

	

	// Misc member functions
	val_type getInt() const { return(val >> (TOTAL_BITS_-INT_BITS_)); }
	val_type getFrac() const { return(val - (getInt() << (TOTAL_BITS_-INT_BITS_))); }
    void init_max() {val = ((val_type)1<<(TOTAL_BITS_-1)) - 1;		}
    void init_min() {val = -((val_type)1<<(TOTAL_BITS_-1));    	}

	// Legitimately directly set integer part
	void setVal(int a) { val = val_type(a);	}

    void multm1() { val = -val; }
	void flip() {
	val = (~val) & ((1 << TOTAL_BITS_) -1);
    }

	bool is_neg() const { return(false); }
    /// Check for zero
	bool is_zero() const { return(val == 0); }

    /// Return total word length
	int wl() const { return(TOTAL_BITS_); }
    /// Return integer word length
	int iwl() const { return(INT_BITS_); }
    /// Return Quantization mode
	sc_q_mode q_mode() const { return(SC_Q_MODE_); }
    /// Return Overflow mode
	sc_o_mode o_mode() const { return(SC_O_MODE_); }

	// Gen String Conversions
	/// Warning Not Complete
	std::string to_dec() const {
		max_val_type v = val;
		std::stringstream ss;
		ss << std::dec << v;
		return(ss.str());
	}
	/// Warning Not Complete
	std::string to_oct() const {
		max_val_type v = val;
		std::stringstream ss;
		ss << std::oct << v;
		return(ss.str());
	}
	/// Warning Not Complete
	std::string to_hex() const {
		max_val_type v = val;
		std::stringstream ss;
		ss << std::hex << v;
		return(ss.str());
	}
	/// 
	std::string to_bin() const {
		std::stringstream ss;
		for (int i=TOTAL_BITS_-1;i>-1;i--) {
			bool b = (val >> i) & 0x1;
			if (b) ss << "1";
			else ss << "0";
		}
		return(ss.str());
	}

     /// Warning Not Complete
	 std::string to_string(sc_numrep numrep, bool with_prefix) const {
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
	void print( std::ostream& os = ::std::cout ) const { os << to_double(); }
	/// Warning Not Complete
	void scan( std::istream& is) { ;}

	
}; // end of class 

} // end of namespace sc_ft

#include <sc_ufixed_functions.h>
#include <sc_mixed_functions.h>

#endif
    
