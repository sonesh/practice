#include "node.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  int i = 0;
  Stack *myStack = createStack();
  Node *n = NULL;

  if (myStack == NULL) {
    printf("main: Cannot create stack. Exiting!\n");
    return 0;
  }

  for (i = 0; i < 10; i++) {
    n = createNode(i);
    pushStack(myStack, n);
  }

  printStack(myStack);

  for (i = 0; i < 11; i++) {
    n = popStack(myStack);
    if (n == NULL) {
      printf("main: popped NULL!\n");
      printStack(myStack);
      break;
    }
    printf("main: popped %d\n", n->data);
    free(n);
    n = NULL;
    printStack(myStack);
  }

  return 0;
}
