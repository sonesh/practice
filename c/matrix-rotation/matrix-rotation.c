/**
 * Rotate an NxN matrix by 90 degrees
 *
 **/

#include <stdlib.h>
#include <stdio.h>

void printMatrix (int **array, int nrows, int ncols) {
  
  int i, j;
  
  for (i = 0; i < nrows; i++) {
    for (j = 0; j < ncols; j++)
      printf("%6d", array[i][j]);
    printf("\n");
  }    
}

int** generateMatrix (int nrows, int ncols) {

  int i, j;
  int **array;
  int count = 1;

  // Allocate rows
  array = (int **) malloc (nrows * sizeof(int *));
  if (array == NULL)
    return NULL;

  // Allocate columns
  for (i = 0; i < nrows; i++) {
    array[i] = (int *) malloc (ncols * sizeof(int));
    if (array[i] == NULL)
      return NULL;
  }
  
  for (i = 0; i < nrows; i++)
    for (j = 0; j < ncols; j++)
      array[i][j] = count++;

  return array;
}


/**
 * Insight:
 *  M[i_new, j_new] = M[i_orig, j_orig]
 *  i_new = j_orig
 *  j_new = N-1-i_orig
 *  Putting everything in terms of the new coordinates we get:
 *  M[i_new, j_new] = M[N-1-j_new][i_new]
 */
void rotateMatrixBy90 (int **array, int nrows, int ncols) {

  int n = nrows;
  int ring, itemColIndex;
  int tmp;

  int ringLimit = n/2;

  if (array == NULL)
    return;

  for (ring = 0; ring < ringLimit; ring++) {
    for (itemColIndex = ring; itemColIndex < n-1-ring; itemColIndex++) {
      tmp = array[ring][itemColIndex];
      array[ring][itemColIndex] = array[n-1-itemColIndex][ring];
      array[n-1-itemColIndex][ring] = array[n-1-ring][n-1-itemColIndex];
      array[n-1-ring][n-1-itemColIndex] = array[itemColIndex][n-1-ring];
      array[itemColIndex][n-1-ring] = tmp;
    }
  }
  
  return;
}

int main (int argc, char *argv[]) {
  
  int n;
  int **array;

  printf("Enter dimesnion of square matrix:\n");
  scanf("%d", &n);
  
  if ( (array = generateMatrix(n, n)) == NULL ) {
    printf("Unable to generate matrix\n");
    return EXIT_FAILURE;
  }

  printf("Original:\n");
  printMatrix(array, n, n);

  rotateMatrixBy90 (array, n, n);

  printf("\n\n");
  printf("Rotated by 90:\n");
  printMatrix(array, n, n);

  return EXIT_SUCCESS;
}
