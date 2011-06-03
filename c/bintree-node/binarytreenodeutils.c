#include "binarytreenodeutils.h"

#include <stdlib.h>
#include <stdio.h>

void treeClear (BinaryTreeNode** rootPtr) {

  if (rootPtr == NULL || *rootPtr == NULL)
    return; 

  printf("going left %p %p\n", (*rootPtr)->left, &((*rootPtr)->left));
  treeClear(  &((*rootPtr)->left)  );
  printf("going right %p %p\n", (*rootPtr)->right, &((*rootPtr)->right));
  treeClear(  &((*rootPtr)->right) );
  printf("me(%d) before free %p\n", (*rootPtr)->data, *rootPtr);
  free(*rootPtr);
  printf("me after free %p\n", *rootPtr);
  *rootPtr = NULL;
}

int treeSize (const BinaryTreeNode* rootPtr) {

  if (rootPtr == NULL)
    return 0;
  else 
    return 1 + treeSize(rootPtr->left) + treeSize(rootPtr->right);
}

/* In reverse/backward in-order */
void prettyPrint (const BinaryTreeNode* rootPtr, int depth) {
  if (rootPtr == NULL)
    return;
  
  prettyPrint(rootPtr->right, depth + 1);
  printf("%*s%d\n", 4*depth, "", rootPtr->data);
  prettyPrint(rootPtr->left, depth + 1);
}
