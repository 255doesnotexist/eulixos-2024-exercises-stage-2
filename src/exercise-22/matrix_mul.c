#include "matrix_mul.h"
#include <stdio.h>
#include <stdlib.h>

int **
multiply (int **A, int ASize, int *AColSize, int **B, int BSize, int *BColSize,
          int *returnSize, int **returnColumnSizes)
{
  (void)BSize; // Suppress unused parameter warning

  int **result = (int **)malloc (ASize * sizeof (int *));
  *returnColumnSizes = (int *)malloc (ASize * sizeof (int));

  for (int i = 0; i < ASize; i++)
    {
      (*returnColumnSizes)[i] = BColSize[0];
      result[i] = (int *)calloc ((*returnColumnSizes)[i], sizeof (int));
    }

  // 下面通过多重循环实现两个矩阵相乘

  *returnSize = ASize;
  return result;
}

void
printMatrix (int **matrix, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          printf ("%d ", matrix[i][j]);
        }
      printf ("\n");
    }
}
