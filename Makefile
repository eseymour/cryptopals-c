.PHONY: all
all: build check

# Using the tup build system
.PHONY: build
build:
	tup

# Currently using simple shell scripts for testing
.PHONY: check
check:
	(cd 01-hex2base64; ./hex2base64_test.sh)
	(cd 02-fixedxor; ./fixedxor_test.sh)
	(cd 03-decodexor; ./decodexor_test.sh)
