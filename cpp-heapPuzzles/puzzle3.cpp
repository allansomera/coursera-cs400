/**
 * C++ puzzle program.  Try to figure out the result before running!
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>

using std::cout;
using std::endl;

int main() {
  int *p, *q; //allocate stack memory for *p, *q
  p = new int; // allocate heap memory for p to point at
  q = p; // point q to the same place p is pointing at
  *q = 8; // dereference q and store the value of 8, in turn p will also be pointing to a value 8
  cout << *p << endl; // *p will print out 8

  q = new int; // make q point to a new heap memory location
  *q = 9; //dereference q and store the value of 9 to the new location it is pointing at, p is still 8
  cout << *p << endl; // 8
  cout << *q << endl; // 9

  return 0;
}
