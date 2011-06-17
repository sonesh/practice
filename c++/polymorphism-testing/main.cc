#include <iostream>
#include <cstdlib>

class Animal {
  
public:
  virtual void makeNoise () {
    std::cout << "I'm an Animal!" << std::endl;
  }

};


class Dog : public Animal {

public:
  void makeNoise () {
    std::cout << "I'm a Dog!" << std::endl;
  }

};


class Cat : public Animal {

public:
  void makeNoise () {
    std::cout << "I'm a Cat!" << std::endl;
  }

};


int main (int argc, char *argv[]) {

  Animal *a = new Dog();
  Animal *b = new Cat();
  Animal *c = new Animal();

  a->makeNoise();
  b->makeNoise();
  c->makeNoise();

  return EXIT_SUCCESS;

}
