#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "node.h"

struct listTag {
  Node *head;
};

typedef struct listTag List;

List* createList ();

int isEmpty (const List *list);

void insertAtHead (List *list, Node *h);

int deleteOne (List *list, int data);

int deleteAll (List *list, int data);

void removeDups (List *list);

void makeEmpty (List *list);

int hasCycle (const List *list);

void reverseIteratively (List *list);

void reverseRecursively(List *list);

void reverseRecursivelyInPlace (List *list);

Node* getHead (const List *list);

Node* getLastNode (const List *list);

void printList (const List *list);



#endif
