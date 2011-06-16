#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct nodeTag {
  int data;
  struct nodeTag *next;
};

typedef struct nodeTag Node;

Node* createNode (int data);

void setNodeData (Node *me, int data);

void setNodeNext (Node *me, Node *next);

#endif
