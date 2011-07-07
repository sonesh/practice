#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256

void reverseString (char *str) {

  int startIndex = 0;
  int endIndex   = strlen(str) - 1;

  char tmp;

  while (startIndex < endIndex) {
    tmp             = str[startIndex];
    str[startIndex] = str[endIndex];
    str[endIndex]   = tmp;
    startIndex++;
    endIndex--;
  }
    
}

int main (int argc, char *argv[]) {
  
  char buffer[MAX_STR_LEN+1];

  char *str;
  int index = 0;

  printf("Enter string to reverse:\n");
  str = fgets(buffer, MAX_STR_LEN+1, stdin);
  if (str == NULL) {
    printf("Error reading string from stdin. Quitting...\n");
    return 0;
  }
  
  /* strip last new line, if read in from std input */
  index = strlen(buffer) - 1; 
  if (buffer[index] == '\n')   
    buffer[index] = '\0';

  reverseString(buffer);

  printf("Reversed string:\n%s\n", buffer);

  return 0;
}
