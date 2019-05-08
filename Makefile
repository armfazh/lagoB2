HEADERS= api.h \
		 blake2b-load-avx2.h \
		 blake2b-load-avx2-simple.h \
		 blake2b-round.h \
		 blake2-config.h \
		 blake2.h \
		 blake2-kat.h
OBJ=blake2b.cc
TEST=test.cc
BENCH=bench.cc

all: bench test

test: $(HEADERS) $(OBJ) $(TEST)
	clang++ -o $@ $(OBJ) $(TEST) -O3 -std=c++11 -isystem benchmark/include -Lbuild/src -lpthread -lgtest_main -march=native  /usr/local/lib/libgtest.a
bench: $(HEADERS) $(OBJ) $(BENCH)
	clang++ -o $@ $(OBJ) $(BENCH) -O3 -std=c++11 -isystem benchmark/include -Lbuild/src -lpthread  -march=native  /usr/local/lib/libbenchmark.a
clean:
	rm -rf bench test
