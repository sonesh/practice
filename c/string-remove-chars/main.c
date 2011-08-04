/**
 *  Remove specified characters from a string. 
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Provides strchr

#define MAX_NUM_CHAR 256
#define MAX_LEN_STR  256

char charHashTable[MAX_NUM_CHAR];

void removeChars (char *inputString, char *removeString) {

  char *cursor = removeString;
  char *writeSrc = inputString;
  char *readSrc  = inputString;

  if (inputString == NULL || removeString == NULL)
    return;

  //Initialize removeString hash table
  while (*cursor) {
    if (!charHashTable[*cursor])
      charHashTable[*cursor] = 1;
    cursor++;
  }

  while (*readSrc) {
    if (!charHashTable[*readSrc]) {
      *writeSrc = *readSrc;
      *writeSrc++;
    }
    readSrc++;
  }

  *writeSrc = '\0';

  return;
}


int main (int argc, char *argv[]) {

  char inputString[MAX_LEN_STR + 1];
  char removeString[MAX_LEN_STR + 1];
  char *newLine;

  int i = 0;
  for (i = 0; i < MAX_NUM_CHAR; i++) {
    charHashTable[i] = 0;
  }

  //Read inputString
  printf("Enter inputString:\n");
  if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
    //remove newline
    if ((newLine = strchr(inputString, '\n')) != NULL)         
      *newLine = '\0';
  } else {
    printf("Error reading inputString. Exiting\n");
    return EXIT_FAILURE;
  }

  //Read removeString
  printf("Enter removeString:\n");
  if (fgets(removeString, sizeof(removeString), stdin) != NULL) {
    //remove newline
    if ((newLine = strchr(removeString, '\n')) != NULL)         
      *newLine = '\0';
  } else {
    printf("Error reading removeString. Exiting\n");
    return EXIT_FAILURE;
  }  

  printf("Original string:\n");
  printf("%s\n", inputString);

  printf("\n");
  printf("Removal chars:\n");
  printf("%s\n", removeString);

  removeChars(inputString, removeString);

  printf("\n");
  printf("Edited string:\n");
  printf("%s\n", inputString);

  return EXIT_SUCCESS;
}
