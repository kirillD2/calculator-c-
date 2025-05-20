# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Default target: build the calculator executable
all: calculator

# Target to compile calculator.cpp
calculator: calculator.cpp
	$(CXX) $(CXXFLAGS) calculator.cpp -o calculator

# Target to compile test_calculator.cpp and link with Google Test
test_calculator: test_calculator.cpp calculator.cpp
	$(CXX) $(CXXFLAGS) test_calculator.cpp -o test_calculator $(GTEST_LIBS)

# Target to run the tests
run_tests: test_calculator
	./test_calculator

# Target to clean up build artifacts
clean:
	rm -f calculator test_calculator *.o
