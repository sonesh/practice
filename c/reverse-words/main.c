#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void reverseString (char *start, char *end) {

  if (end - start < 0)
    return;

  char tmp;

  if (start == NULL || end == NULL)
    return;

  while (start < end) {
    tmp    = start[0];
    *start = *end;
    *end   = tmp;
    start++;
    end--;
  }

  return;
}


int main (int argc, char *argv[]) {

  char buffer[MAX_LEN];
  char *str    = NULL;
  char *word   = NULL;
  char *cursor = NULL;
  int len = 0;
  int wordFound = 0;

  printf("Enter string of words:\n");
  str = fgets(buffer, MAX_LEN+1, stdin);
  if (str == NULL) {
    printf("Error reading string from stdin. Quitting...\n");
    return EXIT_SUCCESS;
  }

  //strip the new line
  len = strlen(str);
  if (str[len-1] == '\n')
    str[len-1] = '\0';

  reverseString (str, str + strlen(str) - 1);

  printf("Reversed string:\n%s\n", str);

  cursor = str;
  word   = str;
  len    = 0;
  wordFound = 0;

  for (cursor = str; *cursor != '\0'; cursor++) {
    if (*cursor == ' ' && wordFound == 0) {
      //Do nothing
    } else if (*cursor == ' ' && wordFound == 1) {
      reverseString (word, word + len -1);
      len = 0;
      wordFound = 0;
    } else if (wordFound == 0) {
      word = cursor;
      wordFound = 1;
      len = 1;
    } else {
      len++;
    }
  }

  //broke out of foor loop after seeing null char
  if (wordFound == 1)
    reverseString(word, cursor - 1);

  printf("Reverse words:\n%s\n", str);

  return EXIT_SUCCESS;
}
