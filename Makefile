all: src

.PHONY: src
src:
	make -C src
	@echo "Build complete."

.PHONY: test
test:
	make -f MakefileCppUTest.mk

clean:
	make -f MakefileCppUTest.mk clean
	make -C src clean