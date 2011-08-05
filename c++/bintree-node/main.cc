#include "BinaryTreeNode.h"

#include <iostream>
#include <cstdlib>  //provides EXIT_SUCCESS

int main (int argc, char *argv[]) {

  int a[] = {9, 5, 2, 7, 19, 10, 4, 42, 1, 6, 34};

  BinaryTreeNode<int> *root = NULL;

  for (std::size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    insertNode(&root, a[i]);

  prettyPrint(root, 0);
  
  return EXIT_SUCCESS;
}
