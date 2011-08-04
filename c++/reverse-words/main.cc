/**
 *  Reverse a string of words entered on stdin
 *
 **/

#include <iostream>  // Provides cout, cin, endl, getline
#include <cstdlib>   // Provides EXIT_SUCCESS & EXIT_FAILURE 

#define MAX_LEN 256

void reverseString (char *start, char *end) {

  if (start == NULL || end == NULL)
    return;

  if (end - start <= 0)
    return;

  char tmp;
  while (start < end) {
    tmp = *start;
    *start = *end;
    *end   = tmp;
    start++;
    end--;
  }
  
  return;
}

void reverseWords (char *inputString) {

  if (inputString == NULL)
    return;

  char *cursor    = NULL;
  char *wordStart = NULL;

  int wordLen     = 0;
  int wordFound   = 0;

  reverseString(inputString, inputString + strlen(inputString) - 1);

  cursor = inputString;
  while (*cursor) {
    if (*cursor == ' ' && wordFound == 0) {              //Ignore initial spaces
    } else if (*cursor == ' ' && wordFound == 1) {       //Found word end
      reverseString(wordStart, wordStart + wordLen - 1);
      wordLen = 0;
      wordFound = 0;
      wordStart = NULL;
    } else if (wordFound == 0) {                         //Found word start
      wordFound = 1;
      wordStart = cursor;
      wordLen++;
    } else {                                             //Continuing on word
      wordLen++;
    }
    cursor++;
  }

  if (wordFound == 1) 
    reverseString(wordStart, wordStart + wordLen - 1);

  return;
}


int main (int argc, char *argv[]) {

  char inputString[MAX_LEN];

  std::cout << "Enter string (max 255 characters):" << std::endl;
  std::cin.getline(inputString, MAX_LEN);
  std::cout << "Length: " << strlen(inputString) << std::endl;
  std::cout << std::endl << std::endl; 
  
  std::cout << "Received string:" << std::endl;
  std::cout << inputString << std::endl;
  std::cout << "Length: " << strlen(inputString) << std::endl;
  std::cout << std::endl << std::endl; 
  
  reverseWords(inputString);

  std::cout << "Reversed words:" << std::endl;
  std::cout << inputString << std::endl;
  std::cout << "Length: " << strlen(inputString) << std::endl;
  std::cout << std::endl << std::endl; 

  return EXIT_SUCCESS;
}
