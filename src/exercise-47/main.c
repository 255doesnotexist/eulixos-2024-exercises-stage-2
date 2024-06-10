#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，返回目标值在数组中出现的次数
int
count_occurrences (int *arr, int n, int target)
{
  int count = 0;

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (
      // 用于保存目标值出现的次数
      "li t0, 0\n"
      // 用于循环计数(索引)的寄存器
      "li t1, 0\n"

      "loop_start:\n"
      // 如果索引 index >= n，则跳转到 loop_end
      "PLACEHOLDER\n"

      // 保存数组当前元素到t2寄存器
      "PLACEHOLDER\n"

      // 对比数组元素与目标值，如果不相等，跳转到not_equal标签
      "PLACEHOLDER\n"
      "addi t0, t0, 1\n"

      "not_equal:\n"
      "addi t1, t1, 1\n"
      "addi %1, %1, 4\n"
      "j loop_start\n"

      "loop_end:\n"
      "mv %0, t0\n"
      : "=r"(count)
      : "r"(arr), "r"(n), "r"(target)
      : "t0", "t1", "t2");

  // <<<
  return count;
}

int
main (int argc, char *argv[])
{
  if (argc != 4)
    {
      fprintf (stderr, "Usage: %s <n> <arr> <target>\n", argv[0]);
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

  int target = atoi (argv[3]);

  int occurrences = count_occurrences (arr, n, target);
  printf ("Occurrences of target:%d\n", occurrences);

  return 0;
}
