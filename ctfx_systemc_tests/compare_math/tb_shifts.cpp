#define BOOST_TEST_MODULE scfixed
#define BOOST_TEST_DYN_LINK

//#define DONT_USE_BOOST
#ifndef DONT_USE_BOOST
#include <boost/test/included/unit_test.hpp>
#else
#define BOOST_CHECK_EQUAL(a,b) ((a) == (b));
#define BOOST_AUTO_TEST_CASE(x) int sc_main(int argc, char* argv[]) 
#endif
//
#define CHECK_EQ(a,b) BOOST_CHECK_EQUAL(a,b)

#ifdef CHECK_TYPES
#define LOOP_ITERS 1
#define SHIFT_ITERS 1
#define CHECK_DOUBLE(a,b) TYPE_NAME(a); TYPE_NAME(b);
#elif CHECK_VALUES
#define LOOP_ITERS 32
#define SHIFT_ITERS 5
#define CHECK_DOUBLE(a,b) TYPE_SHORT(b); std::cout << (b).to_double() << "\n";
#else
#define LOOP_ITERS 32
#define SHIFT_ITERS 5
#define CHECK_DOUBLE(a,b) BOOST_CHECK_EQUAL((a).to_double(), (b).to_double());
#endif

#include "testData.h"
#include "get_type_info.h"
int status;

#ifndef DONT_USE_BOOST
// Keep SystemC compile happy!
int sc_main(int argc, char* argv[]) { return 0;}
#endif

using namespace std;

BOOST_AUTO_TEST_CASE(lr_shifts){

  testData Data; 

  for(int i=0; i<LOOP_ITERS; i++) {
	Data.inc();
	Data.inc2();
	for(int j=0; j<SHIFT_ITERS; j++) {
#ifdef CHECK_VALUES
	  std::cout << "ref_s5_3 = " << Data.ref_s5_3 << " "
				<< "new_s5_3 = " << Data.new_s5_3 << " " << j << " ";
#endif
	  // with ints
	  Data.ref_int = j;
	  Data.new_int = j;
	  CHECK_DOUBLE((Data.ref_s5_3<<Data.ref_int), (Data.new_s5_3<<Data.new_int));
	  CHECK_DOUBLE((Data.ref_s5_3>>Data.ref_int), (Data.new_s5_3>>Data.new_int));
	  //
	  // Don't expect to match!!!
#ifdef CHECK_VALUES
	  std::cout << "ref_u5_3 = " << Data.ref_u5_3 << " "
				<< "new_u5_3 = " << Data.new_u5_3 << " " << j << "  ";
#endif

	  CHECK_DOUBLE((Data.ref_u5_3<<Data.ref_int), (Data.new_u5_3<<Data.new_int));
	  CHECK_DOUBLE((Data.ref_u5_2>>Data.ref_int), (Data.new_u5_2>>Data.new_int));
	}

	// with other s/u fixed
	// Don't expect to match!!!
#ifdef CHECK_VALUES
	  std::cout << "ref_s5_3 = " << Data.ref_s5_3 << " "
				<< "new_s5_3 = " << Data.new_s5_3 << " ";
	  std::cout << "ref_u5_3 = " << Data.ref_u5_3 << " "
				<< "new_u5_3 = " << Data.new_u5_3 << " ";
#endif

	CHECK_DOUBLE((Data.ref_s5_3<<Data.ref_u5_2), (Data.new_s5_3<<Data.new_u5_2));
	CHECK_DOUBLE((Data.ref_u5_3<<Data.ref_u5_2), (Data.new_u5_3<<Data.new_u5_2));
	CHECK_DOUBLE((Data.ref_s5_3<<Data.ref_s5_2), (Data.new_s5_3<<Data.new_s5_2));
	CHECK_DOUBLE((Data.ref_u5_3<<Data.ref_s5_2), (Data.new_u5_3<<Data.new_s5_2));

	CHECK_DOUBLE((Data.ref_s5_3>>Data.ref_u5_2), (Data.new_s5_3>>Data.new_u5_2));
	CHECK_DOUBLE((Data.ref_u5_3>>Data.ref_u5_2), (Data.new_u5_3>>Data.new_u5_2));
	CHECK_DOUBLE((Data.ref_s5_3>>Data.ref_s5_2), (Data.new_s5_3>>Data.new_s5_2));
	CHECK_DOUBLE((Data.ref_u5_3>>Data.ref_s5_2), (Data.new_u5_3>>Data.new_s5_2));
  }
#ifdef DONT_USE_BOOST
  return 0;
#endif

}

