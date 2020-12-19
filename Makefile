.PHONY: cpp_parser
build:
	mkdir -p build && cd build && cmake .. && make
run:
	mkdir -p build && cd build && cmake .. -D TEST_MODE=FALSE && make && ./cpp_parser
run-test:
	mkdir -p build && cd build && cmake .. -D TEST_MODE=TRUE && make && ./cpp_parser


