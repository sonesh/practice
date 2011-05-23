#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

struct nodeTag {
  int data;
  struct nodeTag *next;
};

typedef struct nodeTag Node;

Node* createNode (int data);

void setNext (Node *me, Node *next);

void setData (Node *me, int data);

#endif
