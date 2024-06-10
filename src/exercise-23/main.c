#include "convolution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
parseMatrix (char *str, int *matrix, int rows, int cols)
{
  char *token = strtok (str, ",");
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        {
          matrix[i * cols + j] = atoi (token);
          token = strtok (NULL, ",");
        }
    }
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <input_matrix> <kernel_matrix>\n", argv[0]);
      return 1;
    }

  int inputSize = 5;
  int kernelSize = 3;

  int input[5][5];
  int kernel[3][3];
  int output[3][3];

  parseMatrix (argv[1], (int *)input, inputSize, inputSize);
  parseMatrix (argv[2], (int *)kernel, kernelSize, kernelSize);

  convolution2D (input, kernel, output, inputSize, kernelSize);

  printf ("Result:\n");
  for (int i = 0; i < inputSize - kernelSize + 1; i++)
    {
      for (int j = 0; j < inputSize - kernelSize + 1; j++)
        {
          printf ("%d ", output[i][j]);
        }
      printf ("\n");
    }

  return 0;
}
