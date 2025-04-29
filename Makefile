all: src

.PHONY: src
src:
	make -C src
	@echo "Build complete."

.PHONY: test
test:
	make -f MakefileCppUTest.mk

.PHONY: coverage
coverage: clean
	mkdir -p test/coverage
	make -f MakefileCppUTest.mk CPPUTEST_USE_GCOV=Y gcov
	lcov -c -d test/build/src -o test/coverage/coverage.info
	genhtml test/coverage/coverage.info --output-directory test/coverage/coverageTest.html

clean:
	make -f MakefileCppUTest.mk clean
	make -C src clean
	rm -rf test/coverage