#ifndef BINARY_TREE_NODE_H_INCLUDED
#define BINARY_TREE_NODE_H_INCLUDED

struct binaryTreeNodeTag {
  int data;
  struct binaryTreeNodeTag *left;
  struct binaryTreeNodeTag *right;
};

typedef struct binaryTreeNodeTag BinaryTreeNode;

BinaryTreeNode* createNode (int data);

void setData  (BinaryTreeNode* me, int data);
void setLeft  (BinaryTreeNode* me, BinaryTreeNode* left);
void setRight (BinaryTreeNode* me, BinaryTreeNode *right);

int isLeaf (BinaryTreeNode* me);

#endif
