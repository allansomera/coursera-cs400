/**
 * C++ program allocating and free'ing heap memory.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Cube.h"
#include <iostream>
using uiuc::Cube;


int main() {
  int x = 11;
  int *p = new int;
  p = &x;
  Cube *c = new Cube;
  int *q = p;
  std::cout << "updated p is: " << *p << std::endl;
  std::cout << "q is: " << q << std::endl;
  *q = 10;
  std::cout << "update *q = 10 => " << *q << std::endl;
  std::cout << "updated p is: " << *p << std::endl;
  std::cout << "x is: " << x << std::endl;
  std::cout << "changing q to nullptr" << std::endl;
  // q = nullptr; 
  delete q;
  std::cout << "x is: " << x << std::endl;
  std::cout << "delte q is: " << q << std::endl;
  std::cout << "p is: " << *p << std::endl;
  std::cout << "addressof p is: " << p << std::endl;

  std::cout << "updating *p = 42 " << std::endl;
  *p = 42;
  (*c).setLength(4);

  std::cout << "p is: " << *p << std::endl;
  std::cout << "x is: " << x << std::endl;

  delete c;  c = nullptr;
  p = nullptr;
  delete p;

  return 0;
}
