#include "convolution.h"

void
convolution2D (int input[5][5], int kernel[3][3], int output[3][3],
               int inputSize, int kernelSize)
{
  int i, j, m, n;
  int kernelRadius = kernelSize / 2;

  for (i = 0; i < inputSize - kernelSize + 1; i++)
    {
      for (j = 0; j < inputSize - kernelSize + 1; j++)
        {
          output[i][j] = 0;
        }
    }

  // 在下面通过多重循环实现卷积运算
}
