build = build

tb: $(build)/Makefile
	$(MAKE) -C $(build)

$(build)/Makefile: CMakeLists.txt
	mkdir -p $(build) && cd $(build) && cmake ..

update_ignore:
	file -F" " -i * | grep exec | awk '{print $$1}' | xargs -0 >.gitignore

clean:
	$(MAKE) -C $(build) clean
	rm -rf $(build)

run: tb
	tb_SC_TRN_SC_SAT
	tb_SC_RND_SC_SAT
#	tb_SC_TRN_SC_WRAP
#	tb_SC_RND_SC_WRAP

