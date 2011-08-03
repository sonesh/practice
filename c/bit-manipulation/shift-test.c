#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

  int n, d;

  printf("Enter number and shift distance:\n");
  scanf("%d %d", &n, &d);

  printf("Number to shift: %d\n", n);
  printf("Right shift distance: %d\n", d);

  printf("After shifting: %d\n", n << d);

  return EXIT_SUCCESS;
}
