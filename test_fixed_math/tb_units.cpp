#define BOOST_TEST_MODULE scfixed
#define BOOST_TEST_DYN_LINK

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

BOOST_AUTO_TEST_CASE(tb_units){
    testData Data; 
    for(int i=0; i<LOOP_ITERS; i++) {
	  Data.inc();
	  Data.Reset1();
        
	  for(int j=0; j<LOOP_ITERS; j++) {
		Data.inc2();
		
		CHECK_DOUBLE((Data.ref_0 & Data.ref_s5_3), (Data.new_5_3 & Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0 & Data.ref_s5_2), (Data.new_5_3 & Data.new_s5_2));
		
		CHECK_DOUBLE((Data.ref_0 | Data.ref_s5_3), (Data.new_5_3 | Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0 | Data.ref_s5_2), (Data.new_5_3 | Data.new_s5_2));
		
		CHECK_DOUBLE((~Data.ref_s5_3), (~Data.new_s5_3));
		CHECK_DOUBLE((~Data.ref_s5_2), (~Data.new_s5_2));
		CHECK_DOUBLE((~Data.ref_u5_3), (~Data.new_u5_3));
		CHECK_DOUBLE((~Data.ref_u5_2), (~Data.new_u5_2));
		
		CHECK_DOUBLE((Data.ref_0 ^ Data.ref_s5_3), (Data.new_5_3 ^ Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0 ^ Data.ref_s5_2), (Data.new_5_3 ^ Data.new_s5_2));

		CHECK_DOUBLE((Data.ref_0*Data.ref_s5_3), (Data.new_5_3*Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0*Data.ref_s5_2), (Data.new_5_3*Data.new_s5_2));
		CHECK_DOUBLE((Data.ref_0*Data.ref_u5_3), (Data.new_5_3*Data.new_u5_3));
		CHECK_DOUBLE((Data.ref_0*Data.ref_u5_2), (Data.new_5_3*Data.new_u5_2));
		
		CHECK_DOUBLE((Data.ref_0+Data.ref_s5_3), (Data.new_5_3+Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0+Data.ref_s5_2), (Data.new_5_3+Data.new_s5_2));
		CHECK_DOUBLE((Data.ref_0+Data.ref_u5_3), (Data.new_5_3+Data.new_u5_3));
		CHECK_DOUBLE((Data.ref_0+Data.ref_u5_2), (Data.new_5_3+Data.new_u5_2));
		
		CHECK_DOUBLE((Data.ref_0-Data.ref_s5_3), (Data.new_5_3-Data.new_s5_3));
		CHECK_DOUBLE((Data.ref_0-Data.ref_s5_2), (Data.new_5_3-Data.new_s5_2));
		CHECK_DOUBLE((Data.ref_0-Data.ref_u5_3), (Data.new_5_3-Data.new_u5_3));
		CHECK_DOUBLE((Data.ref_0-Data.ref_u5_2), (Data.new_5_3-Data.new_u5_2));

		CHECK_DOUBLE((-Data.ref_s5_3), (-Data.new_s5_3));
		CHECK_DOUBLE((-Data.ref_s5_2), (-Data.new_s5_2));
		CHECK_DOUBLE((-Data.ref_u5_3), (-Data.new_u5_3));
		CHECK_DOUBLE((-Data.ref_u5_2), (-Data.new_u5_2));
		
		CHECK_EQ(!Data.ref_s5_3, !Data.new_s5_3);
		CHECK_EQ(!Data.ref_s5_2, !Data.new_s5_2);
		CHECK_EQ(!Data.ref_u5_3, !Data.new_u5_3);
		CHECK_EQ(!Data.ref_u5_2, !Data.new_u5_2);

		
		CHECK_DOUBLE( Data.ref_0 &= Data.ref_s5_3,  Data.new_5_3 &= Data.new_s5_3);
		CHECK_DOUBLE( Data.ref_0 &= Data.ref_s5_2,  Data.new_5_3 &= Data.new_s5_2);
		CHECK_DOUBLE( Data.ref_0 |= Data.ref_s5_3,  Data.new_5_3 |= Data.new_s5_3);
		CHECK_DOUBLE( Data.ref_0 |= Data.ref_s5_2,  Data.new_5_3 |= Data.new_s5_2);
		CHECK_DOUBLE( Data.ref_0 ^= Data.ref_s5_3,  Data.new_5_3 ^= Data.new_s5_3);
		CHECK_DOUBLE( Data.ref_0 ^= Data.ref_s5_2,  Data.new_5_3 ^= Data.new_s5_2);
		
	  }

	  Data.inc();
	  Data.Reset1();
        
	  for(int j=0; j<LOOP_ITERS; j++) {
		s_0 ref_local;
		t_0 new_local;
		ref_local = Data.ref_0;
		new_local = Data.new_5_3;
		
		Data.inc2();
		CHECK_DOUBLE( ref_local *= Data.ref_s5_3,  new_local *= Data.new_s5_3);
		CHECK_DOUBLE( ref_local *= Data.ref_s5_2,  new_local *= Data.new_s5_2);
		CHECK_DOUBLE( ref_local *= Data.ref_u5_3,  new_local *= Data.new_u5_3);
		CHECK_DOUBLE( ref_local *= Data.ref_u5_3,  new_local *= Data.new_u5_3);
		
		ref_local = Data.ref_0;
		new_local = Data.new_5_3;
		
		CHECK_DOUBLE( ref_local += Data.ref_s5_3,  new_local += Data.new_s5_3);
		CHECK_DOUBLE( ref_local += Data.ref_s5_2,  new_local += Data.new_s5_2);
		CHECK_DOUBLE( ref_local += Data.ref_u5_3,  new_local += Data.new_u5_3);
		CHECK_DOUBLE( ref_local += Data.ref_u5_3,  new_local += Data.new_u5_3);
		
		ref_local = Data.ref_0;
		new_local = Data.new_5_3;
		
		CHECK_DOUBLE( ref_local -= Data.ref_s5_3,  new_local -= Data.new_s5_3);
		CHECK_DOUBLE( ref_local -= Data.ref_s5_2,  new_local -= Data.new_s5_2);
		CHECK_DOUBLE( ref_local -= Data.ref_u5_3,  new_local -= Data.new_u5_3);
		CHECK_DOUBLE( ref_local -= Data.ref_u5_3,  new_local -= Data.new_u5_3);
		
	  }

    }  

    for(int i=0; i<LOOP_ITERS; i++) {
	  Data.inc();
	  Data.Reset1();
      
	  for(int j=0; j<LOOP_ITERS; j++) {
		Data.inc2();
		CHECK_EQ( (Data.ref_0 == Data.ref_s5_3), (Data.new_5_3 == Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 == Data.ref_s5_2), (Data.new_5_3 == Data.new_s5_2));
		CHECK_EQ( (Data.ref_0 != Data.ref_s5_3), (Data.new_5_3 != Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 != Data.ref_s5_2), (Data.new_5_3 != Data.new_s5_2));
		CHECK_EQ( (Data.ref_0 > Data.ref_s5_3),  (Data.new_5_3 > Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 > Data.ref_s5_2),  (Data.new_5_3 > Data.new_s5_2));
		CHECK_EQ( (Data.ref_0 >= Data.ref_s5_3), (Data.new_5_3 >= Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 >= Data.ref_s5_2), (Data.new_5_3 >= Data.new_s5_2));
		CHECK_EQ( (Data.ref_0 < Data.ref_s5_3),  (Data.new_5_3 < Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 < Data.ref_s5_2),  (Data.new_5_3 < Data.new_s5_2));
		CHECK_EQ( (Data.ref_0 <= Data.ref_s5_3), (Data.new_5_3 <= Data.new_s5_3));
		CHECK_EQ( (Data.ref_0 <= Data.ref_s5_2), (Data.new_5_3 <= Data.new_s5_2));
		
		CHECK_EQ( (Data.ref_0 == Data.ref_u5_3), (Data.new_5_3 == Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 == Data.ref_u5_2), (Data.new_5_3 == Data.new_u5_2));
		CHECK_EQ( (Data.ref_0 != Data.ref_u5_3), (Data.new_5_3 != Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 != Data.ref_u5_2), (Data.new_5_3 != Data.new_u5_2));
		CHECK_EQ( (Data.ref_0 > Data.ref_u5_3), (Data.new_5_3 > Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 > Data.ref_u5_2), (Data.new_5_3 > Data.new_u5_2));
		CHECK_EQ( (Data.ref_0 < Data.ref_u5_3), (Data.new_5_3 < Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 < Data.ref_u5_2), (Data.new_5_3 < Data.new_u5_2));
		CHECK_EQ( (Data.ref_0 >= Data.ref_u5_3), (Data.new_5_3 >= Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 >= Data.ref_u5_2), (Data.new_5_3 >= Data.new_u5_2));
		CHECK_EQ( (Data.ref_0 <= Data.ref_u5_3), (Data.new_5_3 <= Data.new_u5_3));
		CHECK_EQ( (Data.ref_0 <= Data.ref_u5_2), (Data.new_5_3 <= Data.new_u5_2));
	  }
    }  

    s_1 ref_s5_3;
    s_2 ref_s5_2;
    u_1 ref_u5_3;
    u_2 ref_u5_2;

    t_1 new_s5_3;
    t_2 new_s5_2;
    v_1 new_u5_3;
    v_2 new_u5_2;

    for(int i=0; i<SHIFT_ITERS; i++) {
	  for(int j=0; j<LOOP_ITERS; j++) {
		Data.inc2();
		ref_s5_3 = Data.ref_s5_3;
		ref_s5_2 = Data.ref_s5_2;
		ref_u5_3 = Data.ref_u5_3;
		ref_u5_2 = Data.ref_u5_2;
		
		new_s5_3 = Data.new_s5_3;
		new_s5_2 = Data.new_s5_2;
		new_u5_3 = Data.new_u5_3;
		new_u5_2 = Data.new_u5_2;
        
		CHECK_DOUBLE(ref_s5_3 <<= i, new_s5_3 <<= i);
		CHECK_DOUBLE(ref_s5_2 <<= i, new_s5_2 <<= i);
		CHECK_DOUBLE(ref_u5_3 <<= i, new_u5_3 <<= i);
		CHECK_DOUBLE(ref_u5_2 <<= i, new_u5_2 <<= i);
		
		ref_s5_3 = Data.ref_s5_3;
		ref_s5_2 = Data.ref_s5_2;
		ref_u5_3 = Data.ref_u5_3;
		ref_u5_2 = Data.ref_u5_2;
		
		new_s5_3 = Data.new_s5_3;
		new_s5_2 = Data.new_s5_2;
		new_u5_3 = Data.new_u5_3;
		new_u5_2 = Data.new_u5_2;
        
		CHECK_DOUBLE(ref_s5_3 >>= i, new_s5_3 >>= i);
		CHECK_DOUBLE(ref_s5_2 >>= i, new_s5_2 >>= i);
		CHECK_DOUBLE(ref_u5_3 >>= i, new_u5_3 >>= i);
		CHECK_DOUBLE(ref_u5_2 >>= i, new_u5_2 >>= i);
		
		ref_s5_3 = Data.ref_s5_3;
		ref_s5_2 = Data.ref_s5_2;
		ref_u5_3 = Data.ref_u5_3;
		ref_u5_2 = Data.ref_u5_2;
		
		new_s5_3 = Data.new_s5_3;
		new_s5_2 = Data.new_s5_2;
		new_u5_3 = Data.new_u5_3;
		new_u5_2 = Data.new_u5_2;
        
		ref_s5_3++;
		ref_s5_2++;
		ref_u5_3++;
		ref_u5_2++;
		
		new_s5_3++;
		new_s5_2++;
		new_u5_3++;
		new_u5_2++;
        
		CHECK_DOUBLE(ref_s5_3, new_s5_3);
		CHECK_DOUBLE(ref_s5_2, new_s5_2);
		CHECK_DOUBLE(ref_u5_3, new_u5_3);
		CHECK_DOUBLE(ref_u5_2, new_u5_2);
		
		
		ref_s5_3 = Data.ref_s5_3;
		ref_s5_2 = Data.ref_s5_2;
		ref_u5_3 = Data.ref_u5_3;
		ref_u5_2 = Data.ref_u5_2;
		
		new_s5_3 = Data.new_s5_3;
		new_s5_2 = Data.new_s5_2;
		new_u5_3 = Data.new_u5_3;
		new_u5_2 = Data.new_u5_2;
        
		//std::cout << "ref_u5_3 = " << ref_u5_3  << " vs " << new_u5_3 << "\n";
		
		ref_s5_3--;
		ref_s5_2--;
		ref_u5_3--;
		ref_u5_2--;
		
		new_s5_3--;
		new_s5_2--;
		new_u5_3--;
		new_u5_2--;
		
		//std::cout << "ref_u5_3 = " << ref_u5_3	  << " vs " << new_u5_3 << "\n";
        
		CHECK_DOUBLE(ref_s5_3, new_s5_3);
		CHECK_DOUBLE(ref_s5_2, new_s5_2);
		CHECK_DOUBLE(ref_u5_3, new_u5_3);
		CHECK_DOUBLE(ref_u5_2, new_u5_2);
	  }
    }  
#ifdef DONT_USE_BOOST
	return 0;
#endif
}
