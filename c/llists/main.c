#include "node.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main (int argc, char *argv[]) {

  int i;
  int result;

  List *list = (List *) malloc (sizeof(List));
  if (list == NULL) {
    printf("main: malloc failed while creating list");
    return 0;
  }
    
  assert(isEmpty(list) == 1);
  printList(list);

  for (i = 0; i < 10; i++) {
    insertAtHead(list, createNode(i));
  }

  printList(list);

  printf("Deleting -1\n");
  result = deleteOne(list, -1);
  printf("result=%d\n", result);
  printList(list);

  printf("Deleting one 3\n");
  result = deleteOne(list, 3);
  printf("result=%d\n", result);
  printList(list);

  printf("Deleting all 4's\n");
  result = deleteAll(list, 4);
  printf("result=%d\n", result);
  printList(list);

  printf("Inserting 5\n");
  insertAtHead(list, createNode(5));
  printList(list);

  printf("Deleting all 5's\n");
  result = deleteAll(list, 5);
  printf("result=%d\n", result);
  printList(list);

  printf("Reversing iteratively\n");
  reverseIteratively(list);
  printList(list);

  printf("Reversing recursively\n");
  reverseRecursively(list);
  printList(list);

  printf("Reversing recursively in-place\n");
  reverseRecursivelyInPlace(list);
  printList(list);

  printf("Inserting 0\n");
  insertAtHead(list, createNode(0));
  printList(list);

  printf("Inserting 2\n");
  insertAtHead(list, createNode(2));
  printList(list);

  printf("Inserting 1\n");
  insertAtHead(list, createNode(1));
  printList(list);

  printf("Inserting 6\n");
  insertAtHead(list, createNode(6));
  printList(list);
    
  printf("Inserting 0\n");
  insertAtHead(list, createNode(0));
  printList(list);

  printf("Removing duplicates\n");
  removeDups(list);
  printList(list);

  return 0;
}
