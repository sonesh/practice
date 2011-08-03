#ifndef BIT_MANIP_UTILS_H_INCLUDED
#define BIT_MANIP_UTILS_H_INCLUDED

#define BIT_LENGTH 32
#define MSB_FILTER  0x80000000

int countOnes (unsigned int n);
int countOnesSparse (unsigned int n);

int getBit (unsigned int n, int index);
int setBit (unsigned int n, int index, int bit);

void printBits (unsigned int n);

#endif

