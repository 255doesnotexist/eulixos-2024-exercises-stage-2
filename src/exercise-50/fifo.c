#include "fifo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 函数：模拟FIFO（先进先出）页面置换算法。
 *
 * @param queue_frames 一个字符串，表示页面访问序列。
 *                     字符串中的每个字符是一个数字，表示一个页面号。
 * @param num_frames   页框的数量，表示物理内存中可用的页框数。
 */
void
fifo_page_replacement (char *queue_frames, int num_frames)
{
  const int MAX_FRAMES = 5000;
  char *token = strtok(queue_frames, ",");
  int page_sequence[MAX_FRAMES];
  int page_count = 0;

  while (token != NULL) {
      page_sequence[page_count++] = atoi(token);
      token = strtok(NULL, ",");
  }

  // 初始化页框数组和指针
  int frames[num_frames];
  for (int i = 0; i < num_frames; i++) {
      frames[i] = -1; // -1 表示空页框
  }
  int front = 0; // 指向最早加载的页框位置

  // 遍历页面访问序列
  for (int i = 0; i < page_count; i++) {
      int page = page_sequence[i];
      int found = 0;

      // 检查页面是否已经在内存中
      for (int j = 0; j < num_frames; j++) {
          if (frames[j] == page) {
              found = 1;
              break;
          }
      }

      // 如果页面不在内存中，执行置换操作
      if (!found) {
          frames[front] = page;
          front = (front + 1) % num_frames;
      }

      // 输出当前内存状态
      printf("Access:%d,Frames: [", page);
      for (int j = 0; j < num_frames; j++) {
          if (j > 0) {
              printf(",");
          }
          if (frames[j] == -1) {
              printf("-1");
          } else {
              printf("%d", frames[j]);
          }
      }
      printf("]\n");
  }
}
