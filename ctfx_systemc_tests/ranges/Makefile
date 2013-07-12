build = build

tb: $(build)/Makefile
	$(MAKE) -C $(build)

$(build)/Makefile: CMakeLists.txt
	mkdir -p $(build) && cd $(build) && cmake ..

clean:
	$(MAKE) -C $(build) clean
	rm -rf $(build)

tst: tb
	@tst >RESULTS.txt 2>stderr.log
	@diff ./golden/test.log RESULTS.txt || echo "Results Differ!"
