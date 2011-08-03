#include "bit-manip-utils.h"

#include <stdio.h>
#include <stdlib.h>

/* Takes O(lg n) time */
int countOnes (unsigned int n) {

  int count = 0;

  while (n) {
    if (n & 1)
      count++;
    n = n >> 1;
  }

  return count;
}

/* Takes O(x) time where x is the actual number of ones */
int countOnesSparse (unsigned int n) {

  int count = 0;
  
  while (n) {
    count++;
    n = n & (n-1);
  }

  return count;
}

/* Undefined behaviour if index < 0 || index > 31 */
int getBit (unsigned int n, int index) {
  return (n & (1 << index));
}

/* Sets a particular bit to 0 or 1, and returns the new int that results */
int setBit (unsigned int n, int index, int bit) {
  unsigned int mask = 0;
  if (bit)
    return (n | (1 << index));
  else {
    mask = ~(1 << index);
    return n & mask;
  }
}

/* Print the bit representation of the int */
void printBits (unsigned int n) {
  int i = 0;

  for (i = 0; i < BIT_LENGTH; i++) {
    printf("%d", (n & MSB_FILTER) ? 1 : 0);
    n = n << 1;
  }

  printf("\n");
}

