#include <iostream>
#include "../include/recursiveFunctions.hpp"

int main() {
  int numberOfOperations;
  std::cout << "How many operations will you perform? ";
  std::cin >> numberOfOperations;
  for (int i = 0; i < numberOfOperations; i++) {
    int base;
    std::cout << "Introduce the base: ";
    std::cin >> base;
    int exponent;
    std::cout << "Introduce the exponent: ";
    std::cin >> exponent;
    std::cout << "The result is: " << recursiveFunctions::power(base, exponent) << '\n';
  }
}
