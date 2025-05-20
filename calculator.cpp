#include <iostream>

// Function to add two numbers
double add(double a, double b) {
  return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
  return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
  return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
  if (b == 0) {
    std::cerr << "Error: Division by zero is not allowed." << std::endl;
    return 0; // Or throw an exception
  }
  return a / b;
}

int main() {
  double num1, num2;
  char operation;

  // Prompt user for input
  std::cout << "Enter first number: ";
  if (!(std::cin >> num1)) {
    std::cerr << "Error: Invalid input for first number." << std::endl;
    return 1; // Indicate an error
  }
  std::cout << "Enter an operator (+, -, *, /): ";
  std::cin >> operation;
  // Check if the operator is valid before asking for the second number
  if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
    std::cerr << "Error: Invalid operator." << std::endl;
    return 1; // Indicate an error
  }
  std::cout << "Enter second number: ";
  if (!(std::cin >> num2)) {
    std::cerr << "Error: Invalid input for second number." << std::endl;
    return 1; // Indicate an error
  }

  double result;

  // Perform calculation based on operator
  switch (operation) {
    case '+':
      result = add(num1, num2);
      break;
    case '-':
      result = subtract(num1, num2);
      break;
    case '*':
      result = multiply(num1, num2);
      break;
    case '/':
      // Division by zero is handled in the divide function
      result = divide(num1, num2);
      if (num2 == 0 && result == 0) { // Check if division by zero occurred
          return 1; // Indicate an error because an error message was already printed by divide()
      }
      break;
    // No default case needed here as operator validity is checked before the switch
  }

  // Display the result
  std::cout << "Result: " << result << std::endl;

  return 0;
}
