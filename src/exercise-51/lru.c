#include "lru.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

/**
 * 函数：模拟LRU页面置换算法。
 *
 * @param queue_frames 一个字符串，表示页面访问序列。
 *                     字符串中的每个字符是一个数字，表示一个页面号。
 * @param num_frames   页框的数量，表示物理内存中可用的页框数。
 */
void
lru_page_replacement(char *queue_frames, int num_frames) {
  int *frames = (int *)malloc(num_frames * sizeof(int));
  int *indices = (int *)malloc(num_frames * sizeof(int));
  int current_index = 0;
  
  for (int i = 0; i < num_frames; i++) {
      frames[i] = -1;
      indices[i] = -1;
  }

  char *token = strtok(queue_frames, ",");
  while (token != NULL) {
      int page = atoi(token);
      bool found = false;

      for (int i = 0; i < num_frames; i++) {
          if (frames[i] == page) {
              found = true;
              indices[i] = current_index++;
              break;
          }
      }

      if (!found) {
          int min_index = indices[0];
          int replace_pos = 0;
          for (int i = 1; i < num_frames; i++) {
              if (indices[i] < min_index) {
                  min_index = indices[i];
                  replace_pos = i;
              }
          }
          frames[replace_pos] = page;
          indices[replace_pos] = current_index++;
      }

      printf("Access:%d,Frames: [", page);
      for (int i = 0; i < num_frames; i++) {
          if (i > 0) printf(",");
          printf("%d", frames[i]);
      }
      printf("]\n");

      token = strtok(NULL, ",");
  }

  free(frames);
  free(indices);
}
