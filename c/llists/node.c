#include "node.h"

#include <stdlib.h>

Node* createNode (int data) {
  Node *n = (Node *) malloc (sizeof(Node));
  if (n == NULL)
    return NULL;
  
  n->data = data;
  n->next = NULL;
  
  return n;
}

void setNodeData (Node *me, int data) {
  if (me == NULL)
    return;

  me->data = data;
}

void setNodeNext (Node *me, Node *next) {
  if (me == NULL)
    return;
  
  me->next = next;
}

