all: docs

docs: gen/fixes.js gen/Doxyfile
	doxygen gen/Doxyfile
	node $<

clean:
	rm -rf latex
	rm -rf gen*.html
	rm -rf build_scripts
	find .               \
		! -path './.git*'  \
		! -path './gen*'   \
		! -name 'LICENSE'  \
		! -name 'Makefile' \
		! -path '*master*' \
		! -path '.'        \
		-delete

.PHONY: all docs clean
