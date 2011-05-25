#include <iostream>

//WILL NOT COMPILE!
int main (int argc, char *argv[]) {

  int nci = 100;                //non-const int
  const int ci = 500;           //const int
  const int cii = 700;

  int *pnci = &nci;             //ptr to non-const integer
  const int *pci = &ci;         //ptr to const integer

  int const *cpnci = &nci;      //const ptr to non-const integer
  const int* const cpci = &ci;  //const ptr to const integer

  std::cout << "nci = " << nci << " ci = " << ci << std::endl;
  std::cout << "pnci = " << pnci << " pci = " << pci << std::endl;
  std::cout << "cpnci = " << cpnci << " cpci = " << cpci << std::endl;  

  *pnci += *pnci;  //Legal as pnci is ptr to a non-const int
  std::cout << "nci = " << *pnci << " or " << nci << std::endl;

  pci = &nci; //Legal: but cannot change value of nci via pci

  *pci = 40; //Illegal: cannot change value of obj that ptr to const points to

  pnci = pci; //Illegal: cannot set ptr to non-const with value of ptr to const

  pnci = &ci; //Illegal: cannot set ptr to non-const with address of const object

  return 0;
}
