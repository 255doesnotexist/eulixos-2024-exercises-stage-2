#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，用于查找整数数组的最大值
int
find_max (int *arr, int n)
{
  int max; // 用于保存最大值

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 用于循环计数的寄存器
      "li t0, 0\n"
      // 将 max 初始化为数组的第一个元素值, 保存到 t1 寄存器
      "lw t1, 0(%1)\n\t"

      "loop:\n\t"
      // 当前元素值保存在t2寄存器
      "lw t2, 0(%1)\n\t"

      // 如果 max >= 当前元素值，则跳转到next标签
      "blt t1, t2, update_max\n\t"
      "j next\n\t"

      "update_max:\n\t"
      // 如果 max < 当前元素值，则更新 max 为当前元素值
      "mv t1, t2\n\t"

      "next:\n\t"
      "addi %1, %1, 4\n\t"
      "addi t0, t0, 1\n\t"
      // 如果计数器小于数组长度，则继续循环
      "blt t0, %2, loop\n\t"

      "end:\n\t"
      "mv %0, t1\n"
      : "=r"(max)
      : "r"(arr), "r"(n)
      : "t0", "t1", "t2");

  // <<<
  return max;
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <n> <arr>\n", argv[0]);
      return 1;
    }

  int n = atoi (argv[1]);
  int arr[n];

  // 解析逗号分隔的数组字符串
  char *arr_str = argv[2];
  char *token = strtok (arr_str, ",");
  int i = 0;
  while (token != NULL)
    {
      if (i >= n)
        {
          fprintf (stderr, "Error: Expected %d array elements but got more.\n",
                   n);
          return 1;
        }
      arr[i++] = atoi (token);
      token = strtok (NULL, ",");
    }
  if (i != n)
    {
      fprintf (stderr, "Error: Expected %d array elements but got %d.\n", n,
               i);
      return 1;
    }

  printf ("Maximum element in array is %d\n", find_max (arr, n));
  return 0;
}
