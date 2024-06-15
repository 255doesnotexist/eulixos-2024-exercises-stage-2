#include "RR.h"
#include <stdio.h>
#include <stdlib.h>

int
getNextProcess(int* queue, int* front, int* rear) {
  if (*front == *rear) {
      return -1;
  }
  
  int pid = queue[*front];
  (*front)++;
  
  return pid;
}

/**
 * 函数: calculateTimes
 * 功能: 根据时间片轮转调度算法计算每个进程的完成时间、周转时间和等待时间
 *
 * 参数:
 *  - processes: 指向包含多个进程信息的数组
 *  - n: 进程数量
 *  - time_slice: 时间片长度
 *
 * 描述:
 *  计算进程的完成时间，周转时间和等待时间并存在结构体中即可
 */
void
calculateTimes (Process *processes, int n, int time_slice)
{
  int current_time = 0;
  int total_processes = n;
  int completed_processes = 0;
  int queue[100], front = 0, rear = 0;
  int i, next_process;

  // 将所有到达时间为 0 的进程加入队列
  for (i = 0; i < n; i++) {
    if (processes[i].arrival_time == 0) {
      queue[rear++] = i;
    }
  }
  
  while (completed_processes < total_processes) {
    next_process = getNextProcess(queue, &front, &rear);
    
    if (next_process == -1) {
      // 没有进程在就绪队列中，时间前进
      current_time++;
      for (i = 0; i < n; i++) {
        if (processes[i].arrival_time == current_time) {
          queue[rear++] = i;
        }
      }
      continue;
    }
    
    // 执行进程
    int time_to_run = (processes[next_process].remaining_time > time_slice) ? time_slice : processes[next_process].remaining_time;
    processes[next_process].remaining_time -= time_to_run;
    current_time += time_to_run;
    
    // 检查是否有新进程到达
    for (i = 0; i < n; i++) {
      if (processes[i].arrival_time > current_time - time_to_run && processes[i].arrival_time <= current_time) {
        queue[rear++] = i;
      }
    }
    
    // 检查进程是否完成
    if (processes[next_process].remaining_time == 0) {
      processes[next_process].completion_time = current_time;
      processes[next_process].turnaround_time = processes[next_process].completion_time - processes[next_process].arrival_time;
      processes[next_process].waiting_time = processes[next_process].turnaround_time - processes[next_process].burst_time;
      completed_processes++;
    } else {
      // 如果进程未完成，将其重新加入队列
      queue[rear++] = next_process;
    }
  }
}
