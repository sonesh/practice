#include "list.h"

#include <stdlib.h>
#include <stdio.h>

List* createList () {

  List *list = (List *) malloc (sizeof(List));
  if (list == NULL)
    return NULL;

  list->head = NULL;
  return list;
}

int isEmpty (const List *list) {
  if (list->head == NULL)
    return 1;
  else
    return 0;
}

void insertAtHead (List *list, Node *n) {

  if (list == NULL || n == NULL)
    return;

  if (list->head != NULL)
    n->next = list->head;

  list->head = n;
}

int deleteOne (List *list, int data) {

  Node *current  = NULL;
  Node *previous = NULL;

  if (list == NULL || list->head == NULL)
    return 0;

  current = list->head;
  if (current->data == data) {
    list->head = current->next;
    free(current);
    current = NULL;
    return 1;
  }

  previous = current;
  current  = current->next;

  while (current) {
    if (current->data == data) {
      previous->next = current->next;
      free(current);
      current = NULL;
      return 1;
    }
    previous = current;
    current = current->next;
  }

  return 0;
}

int deleteAll (List *list, int data) {

  int deleteCount = 0;

  Node *previous = NULL;
  Node *current  = NULL;

  if (list == NULL || list->head == NULL)
    return deleteCount;

  current = list->head;

  while (current) {

    if (current->data == data) {
      if (current == list->head) {
        list->head = current->next;
        free(current);
        current = list->head;
      } else {
        previous->next = current->next;
        free(current);
        current = previous->next;
      }
      deleteCount++;
    }

    previous = current;
    current = current->next;
  }

  return deleteCount;
}

void removeDups (List *list) {

  Node *unique   = NULL;
  Node *previous = NULL;
  Node *current  = NULL;

  if (list == NULL || list->head == NULL)
    return;

  previous = list->head;
  current = list->head->next;

  while (current) {

    unique = list->head;

    while (unique != current) {
      if (unique->data == current->data) {
        previous->next = current->next;
        free(current);
        current = previous->next;
        break;
      }
      unique = unique->next;
    }

    if (unique == current) {
      previous = current;
      current  = current->next;
    }

  }

}

void makeEmpty (List *list) {
  
  Node *toDelete = NULL;

  if (list == NULL || list->head == NULL)
    return;

  while (list->head) {
    toDelete = list->head;
    list->head = toDelete->next;
    free(toDelete);
    toDelete = NULL;
  }
}

int hasCycle (const List *list) {
  
  Node *slowPtr = NULL;
  Node *fastPtr = NULL;

  if (list == NULL)
    return 0;

  slowPtr = list->head;
  fastPtr = list->head;

  while ((fastPtr != NULL) && (fastPtr->next != NULL)) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if (slowPtr == fastPtr)
      return 1;
  }

  return 0;
}

void reverseIteratively (List *list) {

  Node *previous = NULL;
  Node *current  = NULL;
  Node *next     = NULL;

  if (list == NULL || list->head == NULL)
    return;

  current = list->head;
  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current  = next;
  }

  list->head = previous;
}

Node* reverseRecursivelyHelper (Node *current) {
  Node *newHead = NULL;

  if (current == NULL)
    return NULL;

  if (current->next == NULL)
    return current;

  newHead = reverseRecursivelyHelper (current->next);
  current->next->next = current;
  current->next = NULL;
  
  return newHead;
}

void reverseRecursively (List *list) {

  if (list == NULL || list->head == NULL)
    return;
  
  list->head = reverseRecursivelyHelper (list->head);
}

void reverseRecursivelyInPlaceHelper (Node **current) {

  Node *newHead = NULL;

  if (current == NULL || *current == NULL)
    return;
  
  if ( (*current)->next == NULL )
    return;

  if ( (*current)->next->next == NULL ) {
    newHead          = (*current)->next;
    newHead->next    = (*current);
    (*current)->next = NULL;
    (*current)       = newHead;
  }
}

void reverseRecursivelyInPlace (List *list) {
  
  if (list == NULL || list->head == NULL)
    return;

  reverseRecursivelyInPlaceHelper( &(list->head) );
}

Node *getHead (const List *list) {
  
  if (list == NULL || list->head == NULL)
    return NULL;

  return list->head;
}

Node* getLastNode (const List *list) {
  
  Node *current = NULL;

  if (list == NULL || list->head == NULL)
    return NULL;

  current = list->head;
  while (current->next != NULL)
    current = current->next;

  return current;
}

void printList (const List *list) {

  const Node *current = NULL;

  if (list == NULL)
    return;

  if (hasCycle(list)) {
    printf("List has cycle. Unable to print\n");
    return;
  }

  current = list->head;

  while (current) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");

}
