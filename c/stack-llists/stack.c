#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* createStack () {

  Stack *s = (Stack *) malloc (sizeof(Stack));
  
  if (s == NULL) {
    printf("createStack: malloc failed!\n");
    return NULL;
  }

  s->top = NULL; //create empty stack

  return s;
}

int isEmptyStack (Stack *s) {

  if (s == NULL || s->top == NULL)
    return 1; //bad input or stack is really empty

  return 0;
}

void pushStack (Stack *s, Node *n) {

  if (s == NULL || n == NULL)
    return; //bad input
  
  if (isEmptyStack(s))
    s->top = n;
  else {
    n->next = s->top;
    s->top  = n;
  }

  return;
}

Node* popStack (Stack *s) {

  Node *top;

  if (s == NULL || isEmptyStack(s))
    return NULL; //bad input or empty stack

  top    = s->top;
  s->top = s->top->next;

  return top;
}

void printStack (const Stack *s) {

  Node *current = NULL;
  
  if (s == NULL)
    return; //bad input;
  
  current = s->top;
  while (current) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");

  return;
}
