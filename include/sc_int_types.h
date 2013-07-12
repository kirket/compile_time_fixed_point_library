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
	enum sc_o_mode {SC_SAT,SC_SAT_ZERO,SC_SAT_SYM,	SC_WRAP,SC_WRAP_SM};
	enum sc_q_mode {SC_RND,SC_RND_ZERO,SC_RND_MIN_INF,	SC_RND_INF,SC_RND_CONV,	SC_TRN,	SC_TRN_ZERO	};
	enum sc_numrep {SC_NOBASE,SC_DEC,SC_BIN,SC_BIN_US,SC_BIN_SM,SC_OCT,SC_OCT_US,SC_OUT_SM,SC_HEX,SC_HEX_US,SC_HEX_SM,SC_CSD};
}

#include <sc_int.h>
#include <sc_uint.h>
#include <sc_int_functions.h>
#include <sc_uint_functions.h>
#include <sc_int_mixed_functions.h>


#endif
    
