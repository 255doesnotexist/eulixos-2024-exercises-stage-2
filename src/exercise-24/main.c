#include <stdio.h>
#include <stdlib.h>

#include "matrix_trans.h"

int
main (int argc, char *argv[])
{
  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s <matrix>\n", argv[0]);
      return 1;
    }

  int matrix[N][N];
  parseMatrix (argv[1], matrix);

  transposeInPlace (matrix);

  printf ("Transposed Matrix:\n");
  printMatrix (matrix);

  return 0;
}
