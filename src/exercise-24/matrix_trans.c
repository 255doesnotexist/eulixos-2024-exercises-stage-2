#include "matrix_trans.h"
#include <stdio.h>

void
transposeInPlace (int matrix[N][N])
{
  // 在下面实现矩阵原地转置,即空间复杂度为O(1)

  //
}

void
printMatrix (int matrix[N][N])
{
  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        {
          printf ("%d ", matrix[i][j]);
        }
      printf ("\n");
    }
}

void
parseMatrix (const char *input, int matrix[N][N])
{
  int values[N * N];
  int count = 0;
  const char *ptr = input;

  while (*ptr)
    {
      if (*ptr == ',' || *ptr == '\0')
        {
          ptr++;
          continue;
        }
      sscanf (ptr, "%d", &values[count]);
      count++;
      while (*ptr && *ptr != ',')
        {
          ptr++;
        }
    }

  for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        {
          matrix[i][j] = values[i * N + j];
        }
    }
}
