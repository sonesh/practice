#ifndef BINARY_TREE_NODE_UTILS_H_INCLUDED
#define BINARY_TREE_NODE_UTILS_H_INCLUDED

#include "binarytreenode.h"

void treeClear (BinaryTreeNode** rootPtr);

BinaryTreeNode* treeCopy (const BinaryTreeNode* rootPtr);

int treeSize (const BinaryTreeNode* rootPtr);

int treeNodeHeight (const BinaryTreeNode* nodePtr);

/* should be called with depth = 0 initially */
void prettyPrint (const BinaryTreeNode* rootPtr, int depth);

#endif
