#include "binarytreenode.h"

#include <stdlib.h>
#include <stdio.h>

BinaryTreeNode* createNode (int data) {

  BinaryTreeNode *newNode = (BinaryTreeNode *) malloc (sizeof(BinaryTreeNode));
  if (newNode == NULL) {
    printf("createNode: malloc failed\n");
    return NULL;
  }

  newNode->data  = data;
  newNode->left  = NULL;
  newNode->right = NULL;

  return newNode;
}

void setData (BinaryTreeNode* me, int data) {
  if (me != NULL)
    me->data = data;
}

void setLeft (BinaryTreeNode* me, BinaryTreeNode* left) {
  if (me != NULL)
    me->left = left;
}

void setRight (BinaryTreeNode* me, BinaryTreeNode* right) {
  if (me != NULL)
    me->right = right;
}

int isLeaf (BinaryTreeNode* me) {
  if (me != NULL)
    return ( (me->left == NULL) && (me->right == NULL) );
  else 
    return 0;
}
