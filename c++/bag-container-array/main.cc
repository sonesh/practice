#include "Bag.h"

#include <iostream>  //provides cout and cin
#include <cstdlib>   //provides EXIT_SUCCESS

int main (int argc, char *argv[]) {

  Bag bag;

  for (int i = 0; i < Bag::DEFAULT_CAPACITY; i++)
    bag.insert(i);

  std::cout << bag;

  std::cout << bag.erase_one(26) << std::endl << bag;

  std::cout << bag.insert(40) << std::endl << bag;

  std::cout << bag.insert(41) << std::endl << bag;

  for (int i = 0; i < Bag::DEFAULT_CAPACITY; i += 2) {
    std::cout << "removing " << i << std::endl;
    std::cout << bag.erase_one(i) << std::endl << bag;
  }

  for (int i = 0; i < 10; i++) {
    std::cout << "Inserting 3 " << bag.insert(3) << std::endl << bag;
  }

  std::cout << "Removing all 3s " << bag.erase(3) << std::endl << bag;

  return EXIT_SUCCESS;
}
