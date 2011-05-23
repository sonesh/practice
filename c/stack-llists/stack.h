#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "node.h"

struct stackTag {
  Node *top;
};

typedef struct stackTag Stack;

Stack* createStack ();

int isEmptyStack (Stack *s);

void pushStack (Stack *s, Node *n);

Node* popStack (Stack *s);

void printStack (const Stack *s);

#endif
