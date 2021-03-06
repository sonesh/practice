#include "binarytreenode.h"
#include "binarytreenodeutils.h"

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

  BinaryTreeNode *btNode1 = createNode(1);
  BinaryTreeNode *btNode2 = createNode(2);
  BinaryTreeNode *btNode3 = createNode(3);
  BinaryTreeNode *btNode4 = createNode(4);
  BinaryTreeNode *btNode5 = createNode(5);

  setLeft(btNode3, btNode4);
  setRight(btNode2, btNode3);
  setLeft(btNode1, btNode2);
  setRight(btNode1, btNode5);

  printf("Tree Size: %d\n", treeSize(btNode1));

  printf("btNode1=%p, left=%p, right=%p, &btNode1 = %p\n", 
         btNode1, btNode1->left, btNode1->right, &btNode1);
  printf("btNode2=%p, left=%p, right=%p, &btNode2 = %p\n", 
         btNode2, btNode2->left, btNode2->right, &btNode2);
  printf("btNode3=%p, left=%p, right=%p, &btNode3 = %p\n", 
         btNode3, btNode3->left, btNode3->right, &btNode3);
  printf("btNode4=%p, left=%p, right=%p, &btNode4 = %p\n", 
         btNode4, btNode4->left, btNode4->right, &btNode4);
  printf("btNode5=%p, left=%p, right=%p, &btNode5 = %p\n", 
         btNode5, btNode5->left, btNode5->right, &btNode5);

  printf("\n\n");

  prettyPrint(btNode1, 0);

  printf("\ntreeSize = %d\n\n", treeSize(btNode1));

  printf("btNode1 height: %d\n", treeNodeHeight(btNode1));
  printf("btNode2 height: %d\n", treeNodeHeight(btNode2));
  printf("btNode3 height: %d\n", treeNodeHeight(btNode3));
  printf("btNode4 height: %d\n", treeNodeHeight(btNode4));
  printf("btNode5 height: %d\n", treeNodeHeight(btNode5));

  printf("\n\n");

  treeClear (&btNode1);
  
  /* dereferencing btNode[1-5] should core dump or be garbage */

  printf("btNode1=%p, &btNode=%p\n", btNode1, &btNode1);
  return EXIT_SUCCESS;
}
