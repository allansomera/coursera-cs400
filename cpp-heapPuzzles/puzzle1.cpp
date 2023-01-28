#include <iostream>

using std::cout;
using std::endl;

int main() {
  int  i =  2,  j =  4,  k =  8;
  int *p = &i, *q = &j, *r = &k;

  k = i; // k => 2
  cout << i << j << k << *p << *q << *r << endl;
  // i => 2 
  // j => 4 
  // k => 2 
  // *p => 2
  // *q => 4
  // *r => 2
  // ans 242242

  p = q; // p is now pointing to where q is pointing, so p => 4
  cout << i << j << k << *p << *q << *r << endl;
  // i => 2 
  // j => 4 
  // k => 2 
  // *p => 4
  // *q => 4
  // *r => 2
  // ans 242442
  

  *q = *r; // derefernce *q is now has the value of dereferenced 
  // r (*r => 2), so *q => 2
  cout << i << j << k << *p << *q << *r << endl;
  // i => 2 
  // j => 2 
  // k => 2 
  // *p => 2
  // *q => 2
  // *r => 2
  // ans 242422

  return 0;
}
