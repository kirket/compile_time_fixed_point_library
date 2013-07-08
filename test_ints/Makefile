build = build

tb: $(build)/Makefile
	$(MAKE) -C $(build)

$(build)/Makefile: CMakeLists.txt
	mkdir -p $(build) && cd $(build) && cmake ..

clean:
	$(MAKE) -C $(build) clean
	rm -rf $(build)

test: tb
	@tb_int_types >Type_results.txt
	@diff Type_results.txt Type_Info.txt || echo "Results Differ!"
