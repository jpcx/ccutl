all: docs

docs: gen/fixes.js gen/Doxyfile
	doxygen gen/Doxyfile
	node $<

clean:
	rm -rf latex
	rm -rf gen*.html
	rm -rf build_scripts
	rm -f md_master_ccutl_README.html
	rm -f tabs.css
	find .               \
		! -path './.git*'  \
		! -path './gen*'   \
		! -name 'LICENSE'  \
		! -name 'Makefile' \
		! -path '*master*' \
		! -path '*libs*' \
		! -path '*bs*' \
		! -path '.'        \
		-delete

.PHONY: all docs clean
