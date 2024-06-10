#ifndef _RR_H__
#define _RR_H__
typedef struct
{
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
} Process;

void calculateTimes (Process *processes, int n, int time_slice);
#endif
