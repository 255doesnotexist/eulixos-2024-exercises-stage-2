#include "matrix_mul.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
parseMatrix (char *str, int **matrix, int rows, int cols)
{
  char *token = strtok (str, ",");
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          matrix[i][j] = atoi (token);
          token = strtok (NULL, ",");
        }
    }
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <matrix_A> <matrix_B>\n", argv[0]);
      return 1;
    }

  int ASize = 3, BSize = 3;
  int AColSize[] = { 3, 3, 3 };
  int BColSize[] = { 3, 3, 3 };

  int **A = (int **)malloc (ASize * sizeof (int *));
  int **B = (int **)malloc (BSize * sizeof (int *));
  for (int i = 0; i < ASize; i++)
    {
      A[i] = (int *)malloc (3 * sizeof (int));
      B[i] = (int *)malloc (3 * sizeof (int));
    }

  parseMatrix (argv[1], A, ASize, 3);
  parseMatrix (argv[2], B, BSize, 3);

  int returnSize;
  int *returnColumnSizes;

  int **result = multiply (A, ASize, AColSize, B, BSize, BColSize, &returnSize,
                           &returnColumnSizes);

  printf ("Result:\n");
  printMatrix (result, returnSize, returnColumnSizes[0]);

  for (int i = 0; i < ASize; i++)
    {
      free (A[i]);
      free (B[i]);
      free (result[i]);
    }
  free (A);
  free (B);
  free (result);
  free (returnColumnSizes);

  return 0;
}
