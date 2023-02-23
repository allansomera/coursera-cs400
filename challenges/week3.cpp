#include <iostream>
/*
 *  Class Pair has already been declared
 * as shown in the following comments:
 */

class Pair {
public:
  int *pa,*pb;
  Pair(int, int);
  Pair(const Pair &);
 ~Pair();
  void print();
};

// Implement its member functions below.

Pair::Pair(int a, int b):pa(new int(a)),pb(new int(b)){ }

// Pair::Pair(int a, int b){
//     int *aa = new int(0);
//     int *bb = new int(0);
//     *aa = a;
//     *bb = b;
//     pa = new int;
//     pb = new int;
//     *pa = a;
//     *pb = b;
//     print();
// }

Pair::Pair(const Pair &p):pa(new int(*p.pa)), pb(new int(*p.pb)){}

// Pair::Pair(const Pair &p){
//     int * aa = new int(0);
//     int * bb = new int(0);
//     *aa = *(p.pa);
//     *bb = *(p.pb);
//     pa = new int;
//     pb = new int;
//     *pa = *(p.pa);
//     *pb = *(p.pb);
//     print();
// }

// Pair& Pair::operator=(const Pair& p){
//     pa = p.pa;
//     pb = p.pb;
//     return *this;
// }

Pair::~Pair(){
    delete pa;
    delete pb;
}

void Pair::print(){
    std::cout << "pa: " << *pa << std::endl;
    std::cout << "pb: " << *pb << std::endl;
}
 
 /* Here is a main() function you can use
  * to check your implementation of the
  * class Pair member functions.
  */
  
int main() {
  Pair p(15,16);
  Pair q(p);
  Pair *hp = new Pair(23,42);
  
  std::cout << "If this message is printed,"
    << " at least the program hasn't crashed yet!\n"
    << "But you may want to print other diagnostic messages too." << std::endl;
  p.print();
  q.print();
  std::cout << *(hp->pa) << std::endl;
  std::cout << *(hp->pb) << std::endl;
  delete hp;
  // std::cout << "hp->pa is: " << *(hp->pa) << std::endl;
  // std::cout << "hp->pb is: " << *(hp->pb) << std::endl;

  return 0;
}
