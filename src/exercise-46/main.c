#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，用于检查数组是否按非降序排列
int
is_sorted (int *arr, int n)
{
  int result = 1; // 默认为已排序

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 用于循环计数的寄存器
      "li t0, 1\n\t"
      "addi t1, %1, 4\n\t"

      "loop:\n\t"
      // 保存数组当前元素到t2寄存器
      "lw t2, 0(%1)\n\t"
      // 保存数组下一个元素到t3寄存器
      "lw t3, 0(t1)\n\t"
      // 如果当前元素大于下一个元素，数组不是按非降序排列
      "bge t3, t2, sorted\n\t"
      "li %0, 0\n\t"
      "j end\n\t"

      "sorted:\n\t"
      // 指针移动到数组下一个元素
      "addi %1, %1, 4\n\t"
      // 指针移动到数组下下一个元素
      "addi t1, t1, 4\n\t"

      "addi t0, t0, 1\n\t"
      // 如果计数器小于数组长度，则继续循环
      "blt t0, %2, loop\n\t"

      "end:\n\t"
      : "=r"(result)
      : "r"(arr), "r"(n)
      : "t0", "t1", "t2", "t3");

  // <<<
  return result;
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

  if (is_sorted (arr, n))
    printf ("Array is sorted.\n");
  else
    printf ("Array is not sorted.\n");
  return 0;
}
