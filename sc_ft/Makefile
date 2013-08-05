all: sc_int.h sc_uint.h sc_int_functions.h sc_uint_functions.h sc_int_mixed_functions.h \
sc_fixed.h sc_ufixed.h sc_ufixed_functions.h \
sc_fixed_functions.h sc_fixed_roundsat.h \
sc_mixed_functions.h 

doc: all
	@doxygen >dox.log

sc_int.h: ../gen_scripts/gen_int.py license.txt
	em.py ../gen_scripts/gen_int.py sc_int sc_uint signed >sc_int.h

sc_bigint.h: ../gen_scripts/gen_int.py license.txt
	em.py ../gen_scripts/gen_int.py sc_bigint sc_biguint signed >sc_bigint.h

sc_biguint.h: ../gen_scripts/gen_int.py license.txt
	em.py ../gen_scripts/gen_int.py sc_biguint sc_bigint unsigned >sc_biguint.h

sc_bigint_functions.h: ../gen_scripts/gen_int_functions.py  license.txt
	em.py ../gen_scripts/gen_int_functions.py sc_bigint >sc_bigint_functions.h


sc_uint.h: ../gen_scripts/gen_int.py license.txt
	em.py ../gen_scripts/gen_int.py sc_uint sc_int unsigned >sc_uint.h

sc_int_functions.h: ../gen_scripts/gen_int_functions.py  license.txt
	em.py ../gen_scripts/gen_int_functions.py sc_int >sc_int_functions.h

sc_uint_functions.h: ../gen_scripts/gen_int_functions.py  license.txt
	em.py ../gen_scripts/gen_int_functions.py sc_uint >sc_uint_functions.h

sc_int_mixed_functions.h: ../gen_scripts/gen_int_mixed_functions.py  license.txt
	em.py ../gen_scripts/gen_int_mixed_functions.py sc_int sc_uint >sc_int_mixed_functions.h

sc_fixed.h: ../gen_scripts/gen_class.py license.txt
	em.py ../gen_scripts/gen_class.py sc_fixed sc_ufixed signed >sc_fixed.h

sc_ufixed.h: ../gen_scripts/gen_class.py license.txt
	em.py ../gen_scripts/gen_class.py sc_ufixed sc_fixed unsigned >sc_ufixed.h

sc_ufixed_functions.h: ../gen_scripts/gen_functions.py license.txt
	em.py ../gen_scripts/gen_functions.py sc_ufixed >sc_ufixed_functions.h

sc_fixed_functions.h: ../gen_scripts/gen_functions.py  license.txt
	em.py ../gen_scripts/gen_functions.py sc_fixed >sc_fixed_functions.h

sc_fixed_roundsat.h: ../gen_scripts/gen_roundsat.py  license.txt
	em.py ../gen_scripts/gen_roundsat.py sc_fixed sc_ufixed >sc_fixed_roundsat.h

sc_mixed_functions.h: ../gen_scripts/gen_mixed.py license.txt
	em.py ../gen_scripts/gen_mixed.py sc_fixed sc_ufixed sc_int sc_uint >sc_mixed_functions.h

