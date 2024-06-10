#include "matrix_zero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
setZeroes (int **matrix, int matrixSize, int *matrixColSize)
{
  int m = matrixSize;
  int n = *matrixColSize;
  int *row = (int *)malloc (m * sizeof (int));
  int *col = (int *)malloc (n * sizeof (int));
  memset (row, 0, m * sizeof (int));
  memset (col, 0, n * sizeof (int));

  // 在下面实现将矩阵中为0的元素所在的行和列都置为0

  free (row);
  free (col);
}

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

void
freeMatrix (int **matrix, int matrixSize)
{
  for (int i = 0; i < matrixSize; i++)
    {
      free (matrix[i]);
    }
  free (matrix);
}
