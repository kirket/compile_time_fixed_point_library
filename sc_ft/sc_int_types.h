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
#ifndef SYSTEMC_SC_FT_MODES_H_
#define SYSTEMC_SC_FT_MODES_H_

namespace sc_ft {
	// These wont clash with current SystemC sc_dt enums since in this namespace - Order IS important!
	enum sc_o_mode {SC_SAT,SC_SAT_ZERO,SC_SAT_SYM,	SC_WRAP,SC_WRAP_SYM};
	enum sc_q_mode {SC_RND,SC_RND_ZERO,SC_RND_MIN_INF,	SC_RND_INF,SC_RND_CONV,	SC_TRN,	SC_TRN_ZERO	};
	enum sc_numrep {SC_NOBASE,SC_DEC,SC_BIN,SC_BIN_US,SC_BIN_SM,SC_OCT,SC_OCT_US,SC_OUT_SM,SC_HEX,SC_HEX_US,SC_HEX_SM,SC_CSD};
	enum sc_fmt {SC_F,SC_E};
}

#include <sc_ft/sc_int.h>
#include <sc_ft/sc_uint.h>
#include <sc_ft/sc_int_functions.h>
#include <sc_ft/sc_uint_functions.h>
#include <sc_ft/sc_int_mixed_functions.h>

namespace sc_ft {
	inline std::string o_mode_string(sc_o_mode O) {
		switch(O) {
		case SC_SAT: return("SC_SAT"); break;
		case SC_SAT_ZERO: return("SC_SAT_ZERO"); break;
		case SC_SAT_SYM: return("SC_SAT_SYM"); break;
		case SC_WRAP: return("SC_WRAP"); break;
		case SC_WRAP_SYM: return("SC_WRAP_SYM"); break;
		}
		return("ERROR");
	}
	inline std::string q_mode_string(sc_q_mode Q) {
		switch(Q) {
		case SC_RND: return("SC_RND"); break;
		case SC_RND_ZERO: return("SC_RND_ZERO"); break;
		case SC_RND_MIN_INF: return("SC_RND_MIN_INF"); break;
		case SC_RND_INF: return("SC_RND_INF"); break;
		case SC_RND_CONV: return("SC_RND_CONV"); break;
		case SC_TRN: return("SC_TRN"); break;
		case SC_TRN_ZERO: return("SC_TRN_ZERO"); break;
		}
		return("ERROR");
	}
}

	
#endif
    
