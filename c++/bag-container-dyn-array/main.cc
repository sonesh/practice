#include "Bag.h"

#include <iostream>  //provides cout and cin
#include <cstdlib>   //provides EXIT_SUCCESS

int main (int argc, char *argv[]) {

  Bag b1;
  Bag b2;

  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;

  std::cout << "Bag b2's capacity and size are "
            << b2.capacity() << " " 
            << b2.size() << std::endl;
  std::cout << b2;

  for (int i = 0; i < b1.capacity(); i++)
    b1.insert(i);

  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;

  std::cout << "Inserting 2 into b1" << std::endl;
  b1.insert(2);
  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;

  std::cout << "Erasing one 3 from b1" << std::endl;
  b1.eraseOne(3);
  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;

  std::cout << "Erasing all 2's from b1" << std::endl;
  std::cout << "Erased " <<  b1.erase(2) << " items" << std::endl;
  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;  


  std::cout << "Inserting 1000 into b1" << std::endl;
  b1.insert(1000);
  std::cout << "Inserting 2000 into b1" << std::endl;
  b1.insert(2000);

  std::cout << "Bag b1's capacity and size are "
            << b1.capacity() << " " 
            << b1.size() << std::endl;
  std::cout << b1;  


  std::cout << "Bag b2's capacity and size are "
            << b2.capacity() << " " 
            << b2.size() << std::endl;
  //std::cout << b2;  

  std::cout << "Assigning b1 to b2" << std::endl;
  b2 = b1;
  std::cout << "Bag b2's capacity and size are "
            << b2.capacity() << " " 
            << b2.size() << std::endl;
  std::cout << b2;  

  std::cout << "Defining b3 to be equal to b2" << std::endl;
  Bag b3 = b2;
  std::cout << "Bag b3's capacity and size are "
            << b3.capacity() << " " 
            << b3.size() << std::endl;
  std::cout << b3;  

  std::cout << "Adding b2 to b3" << std::endl;
  b3 += b2;
  std::cout << "Bag b3's capacity and size are "
            << b3.capacity() << " " 
            << b3.size() << std::endl;
  std::cout << b3;  

  return EXIT_SUCCESS;
}
