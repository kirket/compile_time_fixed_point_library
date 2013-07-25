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
#ifndef BRCM_SCU_SUBREF_CLASSES_H_
#define BRCM_SCU_SUBREF_CLASSES_H_

namespace sc_ft {

	// forward decl
#ifndef DOXYGEN_SHOULD_SKIP_THIS
	template <int W> class sc_int;
	template <int W> class sc_uint;
#endif

	/// For getting sub-set of bits from a sc_int or sc_uint
	template <int I_> class sc_uint_subref {
	public:
		uint64_t val;
		int lhs;
		int rhs;
		sc_uint<I_> *val_ptr;
		sc_uint_subref& operator = (const sc_uint_subref& a) {
			val = (a.val << rhs);
			*val_ptr = val; 
			return *this;
		}
		template <int W> sc_uint_subref& operator = (const sc_uint<W>& a) {
			uint64_t prev_val = val_ptr->val;
			uint64_t mask = ((1 << ((lhs - rhs) + 1)) - 1) << rhs;
			prev_val &= ~mask;
			val = ((a.val << rhs) & mask) | prev_val;
			*val_ptr = val; 
			return *this;
		}
		template <int W> sc_uint_subref& operator = (const sc_int<W>& a) {
			uint64_t prev_val = val_ptr->val;
			uint64_t mask = ((1 << ((lhs - rhs) + 1)) - 1) << rhs;
			prev_val &= ~mask;
			val = ((a.val << rhs) & mask) | prev_val;
			*val_ptr = val; 
			return *this;
		}
		sc_uint_subref& operator = (const int& a) {
			uint64_t prev_val = val_ptr->val;
			uint64_t mask = ((1 << ((lhs - rhs) + 1)) - 1) << rhs;
			prev_val &= ~mask;
			val = ((a << rhs) & mask) | prev_val;
			*val_ptr = val; 
			return *this;
		}
		operator int8_t() const { return((int8_t)val); }
		operator int16_t() const { return((int16_t)val); }
		operator int32_t() const { return((int32_t)val); }
		operator int64_t() const { return((int64_t)val); }
		operator uint8_t() const { return((uint8_t)val); }
		operator uint16_t() const { return((uint16_t)val); }
		operator uint32_t() const { return((uint32_t)val); }
		operator uint64_t() const { return((uint64_t)val); }
		template <int W> bool operator ==(const sc_uint<W>& a) {
			return (val == a.to_int());
		}
	};

} // end of namespace sc_ft

#endif
    

	
