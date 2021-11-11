#include "../include/recursiveFunctions.hpp"

// Basics
int recursiveFunctions::zero(int x) {
  return 0;
}

int recursiveFunctions::succesor(int x) {
  return x + 1;
}

int recursiveFunctions::proyection(std::vector<int> set, int index) {
  return set[index-1];
}

// Sum
/*
 * sum(x, y) = (x+y)
 * sum(x, 0) = x = g(x) = P1,1(x)
 * sum(x, s(y)) = (x+y) + 1 = h(x, y, sum(x,y)) = S o P3,3(x,y, sum(x, y))
*/
int recursiveFunctions::sum(int x, int y) {
  if (y == 0) {
    std::vector<int> h = {x};
    return recursiveFunctions::proyection(h, 1);
  }
  y--;
  std::vector<int> h = {x, y, recursiveFunctions::sum(x, y)};
  return recursiveFunctions::succesor(recursiveFunctions::proyection(h, 3));
}

// Product
/*
 * prod(x, y) = (x*y)
 * prod(x, 0) = z(x)
 * prod(x, s(y)) = h(x, y, prod(x,y)) = sum o (P3,1 x P3,3)(x, y, prod(x,y))
*/
int recursiveFunctions::prod(int x, int y) {
  if (y == 0) {
    return recursiveFunctions::zero(x);
  }
  y--;
  std::vector<int> h = {x, y, recursiveFunctions::prod(x, y)};
  return recursiveFunctions::sum(recursiveFunctions::proyection(h, 1), recursiveFunctions::proyection(h, 3));
}

// Power
/*
 * pow(x, y) = (x^y)
 * pow(x, 0) = s(z(x))
 * pow(x, s(y)) = h(x, y, pow(x, y)) = prod o (P3,1 x P3,3)(x, y, prod(x, y))
*/
int recursiveFunctions::power(int x, int y) {
  if (y == 0) {
    return recursiveFunctions::succesor(recursiveFunctions::zero(x));
  }
  y--;
  std::vector<int> h = {x, y, power(x, y)};
  return recursiveFunctions::prod(recursiveFunctions::proyection(h, 1), recursiveFunctions::proyection(h, 3));
}
