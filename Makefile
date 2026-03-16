CXX=clang++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
SOURCES=Complex.cpp ComplexArray.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))
TIDY_FLAGS=-checks='*,-fuchsia-*,-llvm-header-guard,-misc-include-cleaner'
MIN_STUDENT_TESTS=20

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

student_test: StudentTest.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o student_test_runner
	@COUNT=$$(./student_test_runner --count 2>&1 | sed -n 's/.*test cases: *\([0-9]*\).*/\1/p'); \
	if [ "$$COUNT" -lt $(MIN_STUDENT_TESTS) ]; then \
		echo "Error: StudentTest.cpp must contain at least $(MIN_STUDENT_TESTS) test cases (found $$COUNT)"; \
		exit 1; \
	else \
		echo "StudentTest.cpp has $$COUNT test cases (minimum $(MIN_STUDENT_TESTS) required) - OK"; \
	fi
	./student_test_runner

StudentTest.o: StudentTest.cpp Complex.hpp ComplexArray.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile StudentTest.cpp -o StudentTest.o

tidy:
	clang-tidy $(TIDY_FLAGS) $(SOURCES) main.cpp test.cpp -- $(CXXFLAGS)

clean:
	rm -f *.o demo test student_test_runner

.PHONY: all test clean tidy student_test