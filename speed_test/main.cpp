// For testing speed of various data types using FIR template class
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "fir.h"
#include <sys/time.h>

#define SC_INCLUDE_FX
#define SC_EXCLUDE_FIXED_OTHER
#include "systemc.h"

//#define NO_LHS_RANGE

#include <sc_ft/sc_fixed.h>

using namespace std;

double get_time()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double d = t.tv_sec + (double) t.tv_usec/1000000;
    return d;
}


int sc_main(int argc, char* argv[]) {
  const long LOOPS = ((long)1 << 20);
  const int FIR_SIZE = 64;
  const int MODSIZE = 64;
  const int INT_BITS =  8;
  const int FRAC_BITS = 6;
  const double NOISE_GAIN = 0.010;
  int i;

  typedef sc_ft::sc_fixed<INT_BITS+FRAC_BITS, INT_BITS> sc_new;
  typedef sc_dt::sc_fixed<INT_BITS+FRAC_BITS, INT_BITS> sc_ref;

  fir<double>   REF_FIR(FIR_SIZE);
  fir<sc_ref>   SC_FIR(FIR_SIZE);
  fir<sc_new>   MSC_FIR(FIR_SIZE);

  double phase = 3.14*1.0/9.0;
  //  noise AWGN;

  double ref;
  sc_ref sc;
  sc_new msc;

  // Set coefficients
  double c;
  for (i=0;i<FIR_SIZE;i++) {
	c  = 1.0/FIR_SIZE;
	sc = c;
	msc = c;
	REF_FIR.settap(i,c);
	SC_FIR.settap(i,sc);
	MSC_FIR.settap(i,msc);
  }


  double expj,tmp;
  double arg = 0;

  sc_new msc_i[MODSIZE];
  double ref_i[MODSIZE];
  sc_ref sc_i[MODSIZE];

  for (i=0;i<MODSIZE;i++) {
	tmp    = 0; //AWGN.gauss();
	expj   = cos(arg);
	arg += phase;
	ref_i[i]    = expj+NOISE_GAIN*tmp;
	msc_i[i]    = ref_i[i];
	sc_i[i]     = ref_i[i];
#ifdef TEST
	std::cout << "ref_i..." << i << " "
			  << ref_i[i] << " "
			  << msc_i[i] << " "
			  << sc_i[i] << "\n";
#endif
  }

  double ref_time=1;

  std::cout << "Starting Loops with Loops = " << LOOPS << "\n";

  for (int sel=0;sel<3;sel++) {
	double time_start = get_time();
	int index=0;
	for (long loops=0;loops<LOOPS;loops++) {
	  index = (index+1)%MODSIZE;
	  switch (sel) {
	  case 0: ref = REF_FIR.update(ref_i[index]); break;
	  case 1: sc = SC_FIR.update(sc_i[index]);break;
	  case 2: msc = MSC_FIR.update(msc_i[index]); break;
	  }

	}
  
	double time_end = get_time();

#ifdef TEST
	switch (sel) {
	case 0: std::cout << ref << "\n"; break;
	case 1: std::cout << sc  << "\n"; break;
	case 2: std::cout << msc << "\n"; break;
	}
#endif

	switch (sel) {
	case 0: std::cout << "double   "; break;
	case 1: std::cout << "sc_dt    "; break; 
	case 2: std::cout << "sc_ft    "; break; 
	}

	std::cout << " Time elapsed = " << time_end - time_start << " ";

	if (sel==0) ref_time = (time_end-time_start);

	std::cout << " Factor = " << (time_end - time_start)/ref_time << "\n";
	
  }
  return 0;
}

