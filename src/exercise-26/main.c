#include "matrix_kmin.h"
#include <stdio.h>
#include <stdlib.h>

void
printMatrix (int **matrix, int matrixSize, int *matrixColSize)
{
  for (int i = 0; i < matrixSize; i++)
    {
      for (int j = 0; j < matrixColSize[i]; j++)
        {
          printf ("%d ", matrix[i][j]);
        }
      printf ("\n");
    }
}

int
main (int argc, char *argv[])
{
  if (argc < 4)
    {
      fprintf (stderr,
               "Usage: %s matrixSize k colSize1 colSize2 ... matrixValues\n",
               argv[0]);
      return 1;
    }

  int matrixSize = atoi (argv[1]);
  int k = atoi (argv[2]);

  int *matrixColSize = (int *)malloc (matrixSize * sizeof (int));
  int **matrix = (int **)malloc (matrixSize * sizeof (int *));

  int argIndex = 3;
  for (int i = 0; i < matrixSize; i++)
    {
      matrixColSize[i] = atoi (argv[argIndex++]);
      matrix[i] = (int *)malloc (matrixColSize[i] * sizeof (int));
    }

  for (int i = 0; i < matrixSize; i++)
    {
      for (int j = 0; j < matrixColSize[i]; j++)
        {
          matrix[i][j] = atoi (argv[argIndex++]);
        }
    }

  printf ("Original matrix:\n");
  printMatrix (matrix, matrixSize, matrixColSize);

  printf ("The %dth smallest element in the matrix is: %d\n", k,
          kthSmallest (matrix, matrixSize, matrixColSize, k));

  for (int i = 0; i < matrixSize; i++)
    {
      free (matrix[i]);
    }
  free (matrix);
  free (matrixColSize);

  return 0;
}
