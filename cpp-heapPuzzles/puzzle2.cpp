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
  int *x = new int;
  int &y = *x; // alias the dereferenced memory of x
  int &c = y; //reference y, notice you dont need to dereference y, so what ever
              //happens to y, will happen to c
  y = 100;

  cout << &x << endl;
  cout << x << endl; //contents of x is the address of the allocated heap memory, small numbered address
  cout << *x << endl; // 100, because we added that value when setting y = 100

  cout << &y << endl;
  cout << "y is: " << y << endl;

  cout << &c << endl;
  cout << "c is: " << c << endl;
  // cout << *y << endl; <= cant dereference a non pointer, compiler will complain

  return 0;
}
