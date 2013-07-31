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

int main(int argc, char* argv[]) {

  const int FRAC_BITS = 6;
  const int TOTAL_BITS = FRAC_BITS+6;

  double d;

  sc_fixed<TOTAL_BITS,FRAC_BITS,SC_RND,SC_SAT> a,b;
  sc_fixed<TOTAL_BITS-1,FRAC_BITS-1,SC_RND,SC_SAT> c;


  int status;

  std::cout << "************* Real types ****************\n";

  MIXED_TYPES(a,b,1);
  THIS_MIXED_TYPES( a, b, 1);						
  DMIXED_TYPES(a,c,1);
  DMIXED_THIS_TYPES(a,c,1);

  FUNC_TYPES(a,1,8);
  TYPE_NAME_OP( a ,b, / );
  TYPE_NAME_OP( a ,c, / );

  a = 1.0;
  //  TYPE_TEMPLATE_RSHIFT( a, 1);
  //  TYPE_TEMPLATE_LSHIFT( a, 1);

  ///////////////////// Now mix with double!!!!!
  std::cout << "************* Mixing Real types with double ****************\n";

  DMIXED_TYPES(a,d,1);
  TYPE_NAME_OP( a ,d, / );

  //  show_type(a >> int_size<5>());

  return(0);
}
