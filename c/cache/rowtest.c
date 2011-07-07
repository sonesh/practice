#include <stdio.h>

#define NROWS 1024
#define NCOLS 1024

int array[NROWS][NCOLS];

int main (int argc, char *argv[]) {

  int sum = 0;
  int i = 0, j = 0;

  for (i = 0; i < NROWS; i++)
    for (j = 0; j < NCOLS; j++)
      array[i][j] = i;

  for (i = 0; i < NROWS; i++)
    for (j = 0; j < NCOLS; j++)
      sum += array[i][j];

  printf("sum=%d\n", sum);

}
