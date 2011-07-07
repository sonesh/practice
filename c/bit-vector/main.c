#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_BYTES 1<<20
#define NUM_SHIFT 3
#define MASK      0x7

int test (char *bitVector, int i) {
  return ( bitVector[i >> NUM_SHIFT] & (1 << (MASK & i)) );
}

void clear (char *bitVector, int i) {
  bitVector[i >> NUM_SHIFT] &= ~(1 << (MASK & i));
}

void set (char *bitVector, int i) {
  bitVector[i >> NUM_SHIFT] |= (1 << (MASK & i));
}

int main (int argc, char *argv[]) {

  int bitNum = 0;
  int count  = 0;
  int lastBitNum = (NUM_BYTES << 3) - 1;
  char bitVector[NUM_BYTES] = {0};

  for (bitNum = 0; bitNum <= lastBitNum ; bitNum++) {
    if (test(bitVector, bitNum) != 0)  {
      printf("Bit set already!\n");
      return EXIT_FAILURE;
    }
  }

  for (bitNum = 0; bitNum <= lastBitNum; bitNum += 2)
    set(bitVector, bitNum);

  for (bitNum = 0; bitNum <= lastBitNum; bitNum++)
    if (test(bitVector, bitNum))
      count++;
  
  printf("count=%d\n", count);

  return EXIT_SUCCESS;
}
