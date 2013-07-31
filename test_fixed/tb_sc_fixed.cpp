#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <sstream>

#include <sc_ft/sc_fixed.h>
#include "get_type_info.h"

using namespace std;

using namespace sc_ft;

// Quick way to enable/disable asserts
//#define ASSERT(t) assert(t)
#define ASSERT(t) 

int main(int argc, char* argv[]) {

  int status;
  const int FRAC_BITS = 15;
  const int INT_BITS = 12;
  const int TOTAL_BITS = INT_BITS+FRAC_BITS;

  int num=10;
  double rinp;
  bool test_assigns = false;

  if (argc > 1) {
	test_assigns = atoi(argv[1]);
  }

  srand( time(NULL) );

  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> x;
  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> y;
  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> diff;
  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> ls;
  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> rs;


  sc_fixed<5+6,6> a,b;
  sc_fixed<5+4,5> c;

  /*

  sc_fixed<11,6,SC_TRN,SC_SAT> from_a;
  sc_fixed<11,6,SC_TRN,SC_SAT> to_a;

  from_a = 1.0;
  std::cout << "from_a = " << from_a << " ";
  to_a.to_range(from_a.range(8,2),10,0); // 6 bits
  std::cout << " to_a = " << to_a << "\n";
  exit(1);
  */

  //  c = 15.625;
  //  a = -2.03125;

  //  VALUE_NAME_OP( c, a, -= );
  //  exit(1);


  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> inc;
  inc.setVal(1);

  
  cout << "incremental value = " << inc << "\n";

  x = y = diff = ls = rs = 0;

  for (int j=0;j<num;j++) {
	// Create uniform random nunber
	rinp = (double)rand()/(RAND_MAX) - 0.5;
	y = x;
	x = rinp;

	diff = x - y;
	ls = diff << 2;
	rs = ls;
	rs >>= 2;
  }

  /// integer math

  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> t_one = 1.0;
  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> one = 1.0;

  std::cout << "************* VALUES ****************\n";

  //
  double d;

  double da,db,dc;

  a = da = 10.25;
  b = db = 1.125;
  c = dc = 2.0625;
  d = dc;

  std::cout << "a = " << a
			<< " b = " << b
			<< " c = " << c
			<< "\n";


  std::cout.precision(16);
  //  std::cout << to_int<int16_t>(a) << "\n";

  std::cout << "************* Real values ****************\n";

  MIXED_VALUES( a, b, 1);						
  THIS_MIXED_VALUES( a, b, 1);						

  DMIXED_VALUES(a,c,1);
  DMIXED_THIS_VALUES( a, c, 1);						

  FUNC_VALUES(a,1,8);

  sc_fixed<11,6,SC_TRN,SC_SAT> sat_a;



  sat_a = 1.1123;
  b = sat_a; // save
  VALUE_NAME_SHIFT( sat_a, 1, >>=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 8, >>=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 1, <<=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 8, <<=); 

  sat_a = -1.1123;
  b = sat_a; // save
  VALUE_NAME_SHIFT( sat_a, 1, >>=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 8, >>=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 1, <<=); 
  sat_a = b; // reset
  VALUE_NAME_SHIFT( sat_a, 8, <<=); 

  VALUE_NAME_OP(a,b, /);
  VALUE_NAME_OP(a,c, /);

  std::cout << "************* Mixing Real values with double ****************\n";

  DMIXED_VALUES(a,d,1);
  VALUE_NAME_OP( a ,d, / );

  
  if (test_assigns) {
	std::cout << "************* sc_fixed assignments showing quantization and saturation ***\n";
	sc_fixed<4,2,SC_TRN,SC_SAT> small;
	sc_fixed<6,3,SC_TRN,SC_SAT> val;
	sc_fixed<6,2,SC_TRN,SC_SAT> bigf;
	sc_fixed<6,4,SC_TRN,SC_SAT> bigi;
	
	double dval;
	for (int i=-32;i<32;i++) {
	  dval = (double)i/8.0;
	  val   = dval;
	  // now assign to other sizes
	  small = val;
	  bigf  = val;
	  bigi = val;
	  std::cout << setw(6) 
				<< "<6,3> " 
				<< setw(6) 
				<< val << " => "
				<< setw(6) 
				<< "<4,2> "
				<< setw(6) 
				<< small << " "
				<< setw(6) 
				<< "<6,2> "
				<< setw(6) 
				<< bigf << " "
				<< setw(6) 			  
				<< "<6,4> "
				<< setw(6) 
				<< bigi
				<< "\n";
	}
  }

  a = 1.0;
  //  VALUE_TEMPLATE_RSHIFT( a, 1);
  //  VALUE_TEMPLATE_LSHIFT( a, 1);

  return(0);
}

