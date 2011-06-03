#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 256

/**
   Given array a[] with range [startIndex, endIndex], return the index of
   location of integer target; if not present, return -1
 */
int binarySearchIterative (int a[], int startIndex, int endIndex, int target) {

  int midIndex = 0;

  /* null array */
  if (a == NULL) {
    printf("binarySearchIterative: Null Array!\n");
    return -1;      
  }

  /* malformed range */
  if (startIndex > endIndex) {
    printf("binarySearchIterative: Malformed Range!\n");
    return -1;       
  }

  while (startIndex <= endIndex) {

    /* array is not sorted */
    if (a[startIndex] > a[endIndex]) {
      printf("binarySearchIterative: Array not sorted!\n");
      return -1;
    }
    
    /* target not in range */
    if (target < a[startIndex] || target > a[endIndex]) {
      printf("binarySearchIterative: Target not in range!\n");
      return -1;
    }
    
    midIndex = (startIndex + (endIndex - startIndex)/2); /* avoid overflow */
    
    if (target < a[midIndex])
      endIndex = midIndex - 1;
    else if (target > a[midIndex])
      startIndex = midIndex + 1;
    else {
      printf("binarySearchIterative: Found target!\n");
      return midIndex;
    }
  }
  
  printf("binarySearchIterative: Target not in range!\n");
  return -1;
}

int main (int argc, char *argv[]) {

  int a[13] = {-3, 2, 2, 4, 5, 5, 7, 23, 42, 68, 90, 90, 102};
  char num[MAXLEN];
  int target = 0;
  int index = 0;
  int i = 0;
  char test[] = "Hello";
  
  /* read integer from stdin */
  printf("Enter target\n");
  if (fgets(num, MAXLEN, stdin) == NULL)
    return EXIT_FAILURE;

  printf("Array: \n");
  for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    printf("%d ", a[i]);
  printf("\n");

  /* get rid of newline */
  num[strlen(num)-1] = '\0';

  printf("%s\n", num);

  /* replace atoi with something else as 0 input cannot be determined */
  target = atoi(num);
  printf("Target: %d\n", target);

  index = binarySearchIterative (a, 0, (sizeof(a)/sizeof(a[0]) - 1), target);

  printf("Index: %d\n", index);

  return EXIT_SUCCESS;
}
