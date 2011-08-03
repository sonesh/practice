/**
 *  Given two 32-bit numbers N and M, and two bit positions i and j, 
 *  write a method to set all bits between i and j in N to equal M
 *  (i.e. M becomes a substring of N located between positions j and i)
 **/

#include <stdio.h>
#include <stdlib.h>  //Provides EXIT_SUCCESS

#define BIT_LENGTH 32
#define MAX_INT 2147483647
#define MIN_INT -2147483648

/* Convert signed int d to it's binary string representation */
void convertToBinary (char *a, int d) {
  int mask = 0x80000000;
  int i;

  for (i = 0; i < 32; i++) {
    
    if ( (d << i) & mask )
      a[i] = '1';
    else
      a[i] = '0';
  }

  a[32] = '\0';
}

/* Get the minimum number of bits needed to represent signed int m */
int getBitWidth (int m) {
  unsigned int n = (unsigned int) m; //make sure we do logical shifts
  int bitWidth = 0;
  
  while (n) {
    bitWidth++;
    n >>= 1;
  }
  
  return bitWidth;
}

/**
 *
 * Error checking, ignoring for now
 * Checks to perform:
 * 1. Make sure ln and lm are within signed 32 bit range
 * 2. Make sure j and i are valid bit positions (each between 0 and 31, incl)
 * 3. Make sure j is greater or equal to i
 * 4. Make sure bits needed for m are fewer than j-i+1 bits
 * 
 **/
int passChecks(long ln, long lm, int i, int j) {

  if (ln < MIN_INT || ln > MAX_INT) {
    printf ("Number n not within 32-bit range.\n");
    return 0;
  } else if (lm < MIN_INT || lm > MAX_INT) {
    printf ("Number m not within 32-bit range.\n");
    return 0;
  } else if (i < 0 || i > 31) {
    printf("Number i is not a valid bit position.\n");
    return 0;
  } else if (j < 0 || j > 31) {
    printf("Number j is not a valid bit position.\n");
    return 0;    
  } else if (i > j) {
    printf("Bit position i (LSB of substring) is greater than j (MSB of substring).\n");
    return 0;
  } else if (getBitWidth((int)lm) > (j-i+1)) {
    printf("Bitwidth %d of m is greater than %d, so m will not be transfered entirely.\n", getBitWidth((int)lm), j-i+1);
    return 0;
  }else
    return 1;
}

int main (int argc, char *argv[]) {

  long ln,lm;
  int n, m, i, j;
  int mask = 0xFFFFFFFF;  
  int left, right, result;
  char binary[BIT_LENGTH+1]; //extra space at end for null character

  printf("Enter n, m, i, j integer values:\n");
  if (scanf("%ld %ld %d %d", &ln, &lm, &i, &j) != 4) {
    printf("Not all values entered. Please try again.\n");
    return EXIT_SUCCESS;
  }

  if (!passChecks(ln, lm, i, j)) {
    printf("Error in input value. Pleae try again.\n");
    return EXIT_SUCCESS;
  }

  n = (int) ln;
  m = (int) lm;


  //all ones, followed by all zeroes starting at position j
  if (j == 31)
    left = 0;
  else 
    left = mask - ((1 << (j+1)) - 1);

  //all zeroes until position i, followed by all ones
  right = (1 << i) - 1;

  //all bits between positions j and i (inclusive) are cleared
  mask = left | right;

  //clear all bits between positions j and i, then shift in m there
  result = (n & mask) | (m << i);
 
  convertToBinary(binary, n);
  printf("Number:    %s\n", binary);

  convertToBinary(binary, m);
  printf("Substring: %s\n", binary);

  convertToBinary(binary, mask);
  printf("Mask:      %s\n", binary);

  convertToBinary(binary, result);
  printf("Result:    %s\n", binary);
  
  return EXIT_SUCCESS;

}
