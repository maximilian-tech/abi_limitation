all: abi_limitation

abi_limitation: abi_limitation.cpp
	clang++ -march=native -mtune=native -O3 $< -std=c++14 -lbenchmark -lpthread -o $@
