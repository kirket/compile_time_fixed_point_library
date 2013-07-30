#define SC_FX_EXCLUDE_OTHER
#define SC_INCLUDE_FX
#include "systemc.h"
#include <cmath>
#include <iostream>

#include <sc_ft/sc_ft.h>

#ifndef SATMODE
#define S_MODE (sc_dt::sc_o_mode)SC_WRAP
#define FT_S_MODE (sc_ft::sc_o_mode)SC_WRAP
#else
#define S_MODE (sc_dt::sc_o_mode)SATMODE
#define FT_S_MODE (sc_ft::sc_o_mode)SATMODE
#endif

#ifndef RNDMODE
#define R_MODE (sc_dt::sc_q_mode)SC_RND
#define FT_R_MODE (sc_ft::sc_q_mode)SC_RND
#else
#define R_MODE (sc_dt::sc_q_mode)RNDMODE
#define FT_R_MODE (sc_ft::sc_q_mode)RNDMODE
#endif

typedef sc_dt::sc_int<4> s_int;
typedef sc_ft::sc_int<4> t_int;
typedef sc_dt::sc_int<4> s_uint;
typedef sc_ft::sc_int<4> t_uint;


typedef sc_dt::sc_fixed<5, 3, R_MODE, S_MODE> s_0;
typedef sc_dt::sc_fixed<5, 3, R_MODE, S_MODE> s_1;
typedef sc_dt::sc_fixed<5, 2, R_MODE, S_MODE> s_2;
typedef sc_dt::sc_ufixed<5, 3, R_MODE, S_MODE> u_1;
typedef sc_dt::sc_ufixed<5, 2, R_MODE, S_MODE> u_2;


typedef sc_ft::sc_fixed<5, 3, FT_R_MODE, FT_S_MODE> t_0;
typedef sc_ft::sc_fixed<5, 3, FT_R_MODE, FT_S_MODE> t_1;
typedef sc_ft::sc_fixed<5, 2, FT_R_MODE, FT_S_MODE> t_2;
typedef sc_ft::sc_ufixed<5, 3, FT_R_MODE, FT_S_MODE> v_1;
typedef sc_ft::sc_ufixed<5, 2, FT_R_MODE, FT_S_MODE> v_2;


struct testData{

	s_0 ref_0, ref_0_inc;
	s_1 ref_s5_3, ref_s5_3_inc;
	s_2 ref_s5_2, ref_s5_2_inc;
	u_1 ref_u5_3, ref_u5_3_inc;
	u_2 ref_u5_2, ref_u5_2_inc;
    
	t_0 new_5_3, new_5_3_inc;
	t_1 new_s5_3, new_s5_3_inc;
	t_2 new_s5_2, new_s5_2_inc;
	v_1 new_u5_3, new_u5_3_inc;
	v_2 new_u5_2, new_u5_2_inc;
  
	s_int ref_int;
	t_int new_int;
	s_uint ref_uint;
	t_uint new_uint;


    inline testData(){
        ref_0 = -4;
        ref_s5_3 = -4;
        ref_s5_2 = -2;
        ref_u5_3 = 0;
        ref_u5_2 = 0;
        new_5_3 = -4;
        new_s5_3 = -4;
        new_s5_2 = -2;
        new_u5_3 = 0;
        new_u5_2 = 0;
        ref_0_inc = 0.25;
        ref_s5_3_inc = 0.25;
        ref_s5_2_inc = 0.125;
        ref_u5_3_inc = 0.25;
        ref_u5_2_inc = 0.125;
        new_5_3_inc = 0.25;
        new_s5_3_inc = 0.25;
        new_s5_2_inc = 0.125;
        new_u5_3_inc = 0.25;
        new_u5_2_inc = 0.125;
        
    }; 
    inline void inc() {
        ref_0 += ref_0_inc;
        new_5_3 += new_5_3_inc;
    }; 
    inline void Reset1() {
        ref_s5_3 = -4;
        ref_s5_2 = -2;
        ref_u5_3 = 0;
        ref_u5_2 = 0;
        new_s5_3 = -4;
        new_s5_2 = -2;
        new_u5_3 = 0;
        new_u5_2 = 0;
    };
    inline void inc2() {
        ref_s5_3 += ref_s5_3_inc;
        ref_s5_2 += ref_s5_2_inc;
        ref_u5_3 += ref_u5_3_inc;
        ref_u5_2 += ref_u5_2_inc;
        new_s5_3 += new_s5_3_inc;
        new_s5_2 += new_s5_2_inc;
        new_u5_3 += new_u5_3_inc;
        new_u5_2 += new_u5_2_inc;
    }; 

	void print() {
		std::cout 
			<< "ref_0 = " << ref_0 << " "
			<< "ref_0_inc = " << ref_0_inc << " "
			<< "ref_s5_3 = " << ref_s5_3 << " "
			<< "ref_s5_2 = " << ref_s5_2 << " "
			<< "ref_u5_3 = " << ref_u5_3 << " "
			<< "ref_u5_2 = " << ref_u5_2 << " "

			<< "new_5_3 = " << new_5_3 << " "
			<< "new_5_3_inc = " << new_5_3_inc << " "
			<< "new_s5_3 = " << new_s5_3 << " "
			<< "new_s5_2 = " << new_s5_2 << " "
			<< "new_u5_3 = " << new_u5_3 << " "
			<< "new_u5_2 = " << new_u5_2 << " "
			<< "\n";
	}
};

