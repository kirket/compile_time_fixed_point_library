/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2005 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.4 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  range_fx.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// This may look like C code, but it is really -*- C++ -*-
// 
// range_fx.cxx -- 
// Copyright Synopsys 1998
// Author          : Ric Hilderink
// Created On      : Mon Jan 11 13:03:27 1999
// Status          : none
// 


#include <limits.h>
#include <iostream>

// Include sc_ft namespace
#include <sc_ft.h>

using namespace std;
using sc_ft::SC_BIN;
using sc_ft::SC_E;
using sc_ft::SC_F;

#define T_FX_FIXED  sc_ft::sc_fixed<22,11>
#define T_FX_UFIXED sc_ft::sc_ufixed<22,11>

#define RANGE_TO_MIN(FX_TTT) \
{									      \
  FX_TTT x(1); \
  FX_TTT d(1); \
									      \
  int i;								      \
  for (i = 0; i < 300; ++i)						      \
    {									      \
      d = d / 2;							      \
      x += d;								      \
      out << i << " " << d.to_double() << " " << x.to_double() << " " << x.to_string(SC_BIN, SC_E) << "\n"; \
    }									      \
}									      


#define RANGE_MIN_MAX(FX_TTT) \
{									      \
  FX_TTT x(1); \
  FX_TTT d(4); \
  FX_TTT e(0.125);                                                           \
  int i;								      \
  for (i = 0; i < 300; ++i)						      \
    {									      \
      d = d * 2;							      \
      e = e / 2;                                                              \
      x += d + e;							      \
      out << i << " " << d.to_double() << " " << x.to_double() << " " << x.to_string(SC_BIN, SC_E) << "\n"; \
    }									      \
  for (i = 0; i < 300; ++i)						      \
    {									      \
      x -= (d + e);							      \
      out << i << " " << d.to_double() << " " << x.to_double() << " " << x.to_string(SC_BIN, SC_E) << "\n"; \
      d = d / 2;							      \
      e = e * 2;                                                              \
    }									      \
}

#define RANGE_TO_MAX(FX_TTT) \
{									      \
  FX_TTT x(1); \
  FX_TTT d(1); \
  int i;								      \
  for (i = 0; i < 300; ++i)						      \
    {									      \
      d = d * 2;							      \
      x += d;								      \
      out << i << " " << d.to_double() << " " << x.to_double() << " " << x.to_string(SC_BIN, SC_E) << "\n"; \
    }									      \
  for (i = 0; i < 300; ++i)						      \
    {									      \
      x -= d;								      \
      out << i << " " << d.to_double() << " " << x.to_double() << " " << x.to_string(SC_BIN, SC_E) << "\n"; \
      d = d / 2;							      \
    }									      \
}


static void range_to_min(ostream& out)
{
  //  RANGE_TO_MIN(T_FX_FLOAT);
  //  RANGE_TO_MIN(T_FX_UFIX);
  //  RANGE_TO_MIN(T_FX_FIX);
  RANGE_TO_MIN(T_FX_FIXED);
  RANGE_TO_MIN(T_FX_UFIXED);
}

static void range_to_max(ostream& out)
{
  //  RANGE_TO_MAX(T_FX_FLOAT);
  //  RANGE_TO_MAX(T_FX_UFIX);
  //  RANGE_TO_MAX(T_FX_FIX);
  RANGE_TO_MAX(T_FX_FIXED);
  RANGE_TO_MAX(T_FX_UFIXED);
}

static void range_min_max(ostream& out)
{
  //  RANGE_MIN_MAX(T_FX_FLOAT);
  //  RANGE_MIN_MAX(T_FX_UFIX);
  //  RANGE_MIN_MAX(T_FX_FIX);
  RANGE_MIN_MAX(T_FX_FIXED);
  RANGE_MIN_MAX(T_FX_UFIXED);
}


void range_fx(ostream& out)
{
  //  sc_fxtype_params fooCast(222, 111, SC_RND, SC_SAT);
  out << "************** range_FX_TTT\n";
  range_to_min(out);
  //  range_to_max(out);
  //  range_min_max(out);
}

