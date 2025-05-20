#include "gtest/gtest.h"
#include "calculator.cpp" // Include the calculator code to be tested

// Test fixture for Calculator tests
class CalculatorTest : public ::testing::Test {
protected:
    // You can define helper functions or variables here if needed
};

// Test case for the add function
TEST_F(CalculatorTest, Add) {
    ASSERT_EQ(add(2, 2), 4);
    ASSERT_EQ(add(-1, 1), 0);
    ASSERT_EQ(add(0, 0), 0);
    ASSERT_EQ(add(1.5, 2.5), 4.0);
}

// Test case for the subtract function
TEST_F(CalculatorTest, Subtract) {
    ASSERT_EQ(subtract(2, 2), 0);
    ASSERT_EQ(subtract(5, 2), 3);
    ASSERT_EQ(subtract(-1, 1), -2);
    ASSERT_EQ(subtract(2.5, 1.5), 1.0);
}

// Test case for the multiply function
TEST_F(CalculatorTest, Multiply) {
    ASSERT_EQ(multiply(2, 3), 6);
    ASSERT_EQ(multiply(-2, 5), -10);
    ASSERT_EQ(multiply(5, 0), 0);
    ASSERT_EQ(multiply(1.5, 2.0), 3.0);
}

// Test case for the divide function
TEST_F(CalculatorTest, Divide) {
    ASSERT_EQ(divide(6, 2), 3);
    ASSERT_EQ(divide(5, 2), 2.5);
    ASSERT_EQ(divide(0, 5), 0);
}

// Test case for division by zero
TEST_F(CalculatorTest, DivideByZero) {
    // Expect death is not the ideal way to test this,
    // as the function currently prints to cerr and returns 0.
    // A more robust solution would be to throw an exception.
    // For now, we test the current behavior.
    ASSERT_EQ(divide(5, 0), 0); 
    // We can also check if an error message is printed to cerr,
    // but that's more complex to set up with Google Test's default assertions.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
