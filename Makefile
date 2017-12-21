# Using tup as the build system
.PHONY: all
all:
	tup

# Currently using simple shell scripts for testing
.PHONY: check
check:
	(cd 01-hex2base64; ./hex2base64_test.sh)
	(cd 02-fixedxor; ./fixedxor_test.sh)
	(cd 03-decodexor; ./decodexor_test.sh)

.PHONY: lint
lint:
	cppcheck -q --enable=all --suppress=missingIncludeSystem --inconclusive -Ilib .

.PHONY: docs
docs:
	rm -rf doc
	doxygen Doxyfile
