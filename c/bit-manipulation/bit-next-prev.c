/** 
 * Given a positive 2's complement integer, print the next largest 
 * and next smallest integer with the same number of 1 bits.
 *
 * Insights:
 *  1. Given an int, for every bit we turn off, we have to turn on another bit
 *  2. If we turn on a bit at position i, the value of the integer increases by 2^i
 *  3. If we turn off a bit at position j, the value of the integer decrases by 2^j
 *  4. If we turn on and off at i & j, the value of integer increases by (2^i - 2^j)
 **/

#include "bit-manip-utils.h"

#include <stdio.h>
#include <stdlib.h>

int getNextLargest (unsigned int n) {
 
  if (n <= 0) {
    printf("Please only provide positive integers.\n");
    return -1;
  }

  int bitPosition = 0;
  int onesCount   = 0;

  /* Find the first one */
  while (!getBit(n, bitPosition))
    bitPosition++;

  /* Find the next zero and count all the ones to it, including this one*/
  while (getBit(n, bitPosition)) {
    bitPosition++;
    onesCount++;
  }

  /* Turn on the this zero */
  n = setBit(n, bitPosition, 1);

  /* Turn off the one to the left*/
  bitPosition--;
  n = setBit(n, bitPosition, 0);
  onesCount--;

  /* Shift all the other lower ones as right as possible*/
  int i;
  for (i = bitPosition - 1; i >= onesCount; i--)       // First set zeroes
    n = setBit(n, i, 0);
  for (i = onesCount - 1; i >= 0; i--)                 // Then set ones   
    n = setBit(n, i, 1);

  return n;
}

int getNextSmallest (unsigned int n) {

  if (n <= 0) {
    printf("Please only provide positive integers.\n");
    return -1;
  }

  int bitPosition = 0;
  int zeroesCount   = 0;

  /* Find the first zero */
  while (getBit(n, bitPosition)) {
    bitPosition++;
  }

  /* Find the next one and count all the zeroes to it, including this zero*/
  while (!getBit(n, bitPosition)) {
    bitPosition++;
    zeroesCount++;
  }

  /* Turn off this one */
  n = setBit(n, bitPosition, 0);

  /* Turn on the zero to the left */
  bitPosition--;
  n = setBit(n, bitPosition, 1);
  zeroesCount--;

  /* Shift all zeroes as right as possible */
  int i;
  for (i = bitPosition-1; i >= zeroesCount; i--)  // First set ones
    n = setBit(n, i, 1);
  for (i = zeroesCount - 1; i >= 0; i--)          // Then set zeroes
    n = setBit(n, i, 0);

  return n;
}

int main (int argc, char *argv[]) {

  int n, nl;

  printf("Enter int:\n");
  scanf("%d", &n);

  printf("\n\n");

  printf("Number: %d\n", n);
  printf("Binary: ");
  printBits(n);
  printf("# Ones: %d\n", countOnes(n));

  printf("\n\n");
  

  nl = getNextLargest(n);
  if (nl <= 0)
    return EXIT_SUCCESS;
  printf("Next Largest: %d\n", nl);
  printf("Binary: ");
  printBits(nl);
  printf("# Ones: %d\n", countOnes(nl));

  printf("\n\n");
  
  nl = getNextSmallest(n);
  if (nl <= 0)
    return EXIT_SUCCESS;
  printf("Next Smallest: %d\n", nl);
  printf("Binary: ");
  printBits(nl);
  printf("# Ones: %d\n", countOnes(nl));

  return EXIT_SUCCESS;
}
