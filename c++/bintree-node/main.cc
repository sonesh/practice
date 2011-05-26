#include "BinaryTreeNode.h"

#include <iostream>
#include <cstdlib>  //provides EXIT_SUCCESS

int main (int argc, char *argv[]) {
  
  BinaryTreeNode<int> *btNode1 = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *btNode2 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *btNode3 = new BinaryTreeNode<int>(3);
  BinaryTreeNode<int> *btNode4 = new BinaryTreeNode<int>(4);
  BinaryTreeNode<int> *btNode5 = new BinaryTreeNode<int>(5);

  btNode3->setLeft(btNode4);
  btNode2->setRight(btNode3);
  btNode1->setLeft(btNode2);
  btNode1->setRight(btNode5);

  prettyPrint(btNode1, 0);

  return EXIT_SUCCESS;
}
