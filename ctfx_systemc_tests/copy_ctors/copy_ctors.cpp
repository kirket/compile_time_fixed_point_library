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

  copy_ctors.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

// test of sc_[u]fix constructors with fixed-point type argument

#include <sc_ft.h>

using namespace sc_ft;
using namespace std;

#define WRITE(a) \
    cout << a.type_params() << endl

int main( int, char*[] ) {
    sc_fixed<1,2,SC_RND,SC_SAT> fxd;
    sc_fixed<3,4,SC_RND_ZERO,SC_SAT_ZERO> fxdf;
    sc_ufixed<5,6,SC_RND_MIN_INF,SC_SAT_SYM> ufxd;
    sc_ufixed<7,8,SC_RND_INF,SC_WRAP> ufxdf;

    sc_fixed<9,10,SC_RND_CONV,SC_SAT> fx;
    sc_fixed<11,12,SC_TRN,SC_SAT_ZERO> fxf;
    sc_ufixed<13,14,SC_TRN_ZERO,SC_SAT_SYM> ufx;
    sc_ufixed<15,16,SC_RND,SC_WRAP> ufxf;

    WRITE(  fxd );
    WRITE(  fxdf );
    WRITE( ufxd );
    WRITE( ufxdf );

    WRITE(  fx );
    WRITE(  fxf );
    WRITE( ufx );
    WRITE( ufxf );

    // sc_fix
    sc_fixed<1,2,SC_RND,SC_SAT> fx01(  fxd );
    sc_fixed<1,2,SC_RND,SC_SAT> fx02(  fxdf );
    sc_fixed<1,2,SC_RND,SC_SAT> fx03( ufxd );
    sc_fixed<1,2,SC_RND,SC_SAT> fx04( ufxdf );
    sc_fixed<1,2,SC_RND,SC_SAT> fx05(  fx );
    sc_fixed<1,2,SC_RND,SC_SAT> fx06(  fxf );
    sc_fixed<1,2,SC_RND,SC_SAT> fx07( ufx );
    sc_fixed<1,2,SC_RND,SC_SAT> fx08( ufxf );

    cout << endl;
    WRITE( fx01 );
    WRITE( fx02 );
    WRITE( fx03 );
    WRITE( fx04 );
    WRITE( fx05 );
    WRITE( fx06 );
    WRITE( fx07 );
    WRITE( fx08 );


    // sc_ufix
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx01(  fxd );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx02(  fxdf );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx03( ufxd );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx04( ufxdf );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx05(  fx );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx06(  fxf );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx07( ufx );
    sc_ufixed<1,2,SC_RND,SC_SAT> ufx08( ufxf );

    cout << endl;
    WRITE( ufx01 );
    WRITE( ufx02 );
    WRITE( ufx03 );
    WRITE( ufx04 );
    WRITE( ufx05 );
    WRITE( ufx06 );
    WRITE( ufx07 );
    WRITE( ufx08 );

    return 0;
}
