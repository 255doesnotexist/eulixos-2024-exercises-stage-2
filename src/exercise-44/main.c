#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，用于计算整数数组的和
int
calculate_sum (int *arr, int n)
{
  int result = 0; // 用于保存计算结果

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 用于循环计数(索引)的寄存器
      "li t0, 0\n"
      // result值初始化为 0
      "li t1, 0\n"

      "loop:\n\t"
      // 如果索引是否大于等于n，跳转end标签
      "bge t0, %2, end\n\t"

      // 从数组中加载元素值保存到t2寄存器
      "lw t2, 0(%1)\n\t"

      // 计算 result += arr[i],result值保存在t1寄存器
      "add t1, t1, t2\n\t"
      // 数组索引自增，指向下一个元素
      "addi %1, %1, 4\n\t" 

      "addi t0, t0, 1\n\t"
      "j loop\n"

      "end:\n\t"
      "mv %0, t1\n"

      : "=r"(result)
      : "r"(arr), "r"(n)
      : "t0", "t1", "t2");

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

  printf ("Sum of array elements is %d\n", calculate_sum (arr, n));
  return 0;
}
