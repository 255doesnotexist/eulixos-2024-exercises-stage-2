#include "matrix_zero.h"
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
  if (argc < 2 + 3 * 3)
    {
      fprintf (stderr,
               "Usage: %s matrixSize matrixColSize1 matrixColSize2 ... "
               "matrixValues\n",
               argv[0]);
      return 1;
    }

  int matrixSize = atoi (argv[1]);
  int *matrixColSize = (int *)malloc (matrixSize * sizeof (int));

  if (!matrixColSize)
    {
      fprintf (stderr, "Memory allocation failed for matrixColSize\n");
      return 1;
    }

  int argIndex = 2;

  for (int i = 0; i < matrixSize; i++)
    {
      matrixColSize[i] = atoi (argv[argIndex++]);
    }

  int **matrix = (int **)malloc (matrixSize * sizeof (int *));
  if (!matrix)
    {
      fprintf (stderr, "Memory allocation failed for matrix\n");
      free (matrixColSize);
      return 1;
    }

  for (int i = 0; i < matrixSize; i++)
    {
      matrix[i] = (int *)malloc (matrixColSize[i] * sizeof (int));
      if (!matrix[i])
        {
          fprintf (stderr, "Memory allocation failed for matrix[%d]\n", i);
          for (int j = 0; j < i; j++)
            {
              free (matrix[j]);
            }
          free (matrix);
          free (matrixColSize);
          return 1;
        }
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

  // Call function to set zeroes
  setZeroes (matrix, matrixSize, matrixColSize);

  printf ("\nModified matrix:\n");
  printMatrix (matrix, matrixSize, matrixColSize);

  // Free memory
  freeMatrix (matrix, matrixSize);
  free (matrixColSize);

  return 0;
}
