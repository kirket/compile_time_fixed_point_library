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
#ifndef BRCM_SCU_BITREF_CLASSES_H_
#define BRCM_SCU_BITREF_CLASSES_H_

namespace sc_ft {

	// forward decl
#ifndef DOXYGEN_SHOULD_SKIP_THIS
	template <int W> class sc_int;
	template <int W> class sc_uint;
#endif
	
	/// For getting bit-set of bits from a sc_int or sc_uint
	template <int I_> class sc_uint_bitref {
	public:
		bool val;
		int index;
		sc_uint<I_> *val_ptr;
		// tbd
		template <int W> sc_uint_bitref& operator = (const sc_uint<W>& a) {val = a.to_int();  return *this;}
		template <int W> sc_uint_bitref& operator = (const sc_int<W>& a) {val = a.to_int();  return *this;}

		sc_uint_bitref& operator = (const sc_uint_bitref& a) {
			if (a.val) *val_ptr |= (a.val << index);
			else	   *val_ptr &= ~(a.val << index);
			return *this;
		}
		sc_uint_bitref& operator = (const int& a) {
			if (a) *val_ptr |= (a << index);
			else   *val_ptr &= ~(a << index);
			return *this;
		}
		operator bool() const { return(val); }
		operator int8_t() const { return((int8_t)val); }
		operator int16_t() const { return((int16_t)val); }
		operator int32_t() const { return((int32_t)val); }
		operator int64_t() const { return((int64_t)val); }
		operator uint8_t() const { return((uint8_t)val); }
		operator uint16_t() const { return((uint16_t)val); }
		operator uint32_t() const { return((uint32_t)val); }
		operator uint64_t() const { return((uint64_t)val); }
		template <int W> bool operator ==(const sc_uint<W>& a) {return (val == a.to_int());	}
		bool operator ==(const int& a) {return (val == a);	}
	};

} // end of namespace sc_ft

#endif
    

	
