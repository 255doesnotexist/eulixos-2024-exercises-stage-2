#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RISC-V 汇编内联汇编函数，用于计算斐波那契数列的第 n 个数
int
fibonacci (int n)
{
  int result; // 用于保存计算结果

  // >>> 替换 PLACEHOLDER 为合适的指令完成注释的功能
  __asm__ volatile (

      // 初始化斐波那契数列的前两个数为 0 和 1
      "li t0, 0\n\t"
      "li t1, 1\n\t"

      // 如果 n 为 0，则返回 return_zero标签
      "PLACEHOLDER\n\t"
      // 如果 n 为 1，则返回 return_one标签
      "PLACEHOLDER\n\t"

      "loop:\n\t"
      "addi %1, %1, -1\n\t"
      "add t2, t0, t1\n\t"

      // 更新 t0 为 t1
      "PLACEHOLDER\n\t"
      // 更新 t1 为 t2
      "mv t1, t2\n\t"

      // 如果 n 不为 0，则继续循环
      "bne %1, x0, loop\n\t"
      // 循环结束，最终结果存储在 %0 中
      "PLACEHOLDER\n\t"
      "j end\n\t"

      // n 为 0 时的返回值
      "return_zero:\n\t"
      "li %0, 0\n\t"
      "j end\n\t"

      // n 为 1 时的返回值
      "return_one:\n\t"
      "li %0, 1\n\t"
      "j end\n\t"

      "end:\n\t"
      : "=r"(result)
      : "r"(n)
      : "t0", "t1", "t2");

  // <<<
  return result;
}

int
main (int argc, char *argv[])
{

  if (argc != 2)
    {
      printf ("Usage: %s <integer>\n", argv[0]);
      return 1;
    }

  int n = atoi (argv[1]);
  printf ("Fibonacci number at position %d is %d\n", n, fibonacci (n));

  return 0;
}
