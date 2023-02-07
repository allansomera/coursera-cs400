/**
 * C++ program copying a Cube class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "../Cube.h"
using uiuc::Cube;

Cube foo() {
  Cube c;
  return c; // when it returns, it needs to call the copy constructor to send
  // it back to main
}

int main() {
  Cube c2 = foo();
  return 0;
}
