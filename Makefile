CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion -Wall -Wextra
SOURCES=Complex.cpp ComplexArray.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp Complex.hpp ComplexArray.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Complex.o: Complex.cpp Complex.hpp

ComplexArray.o: ComplexArray.cpp ComplexArray.hpp Complex.hpp

main.o: main.cpp Complex.hpp ComplexArray.hpp

clean:
	rm -f *.o demo test

.PHONY: all test clean