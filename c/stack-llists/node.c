#include "node.h"

#include <stdio.h>
#include <stdlib.h>

Node* createNode (int data) {

  Node *n = (Node *) malloc (sizeof(Node));
  
  if (n == NULL) {
    printf("createNode: malloc failed!\n");
    return NULL;
  }

  n->data = data;
  n->next = NULL;

  return n;
}

void setNext (Node *me, Node *next) {

  if (me == NULL)
    return; //bad input

  me->next = next;
  return;
}

void setData (Node *me, int data) {

  if (me == NULL)
    return; //bad input

  me->data = data;
  return;
}
