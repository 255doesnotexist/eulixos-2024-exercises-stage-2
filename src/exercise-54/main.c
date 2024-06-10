#include "RR.h"
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int time_slice = 4;
  int n = 4;

  Process processes[] = { { 1, 0, 10, 10, 0, 0, 0 },
                          { 2, 1, 6, 6, 0, 0, 0 },
                          { 3, 2, 8, 8, 0, 0, 0 },
                          { 4, 3, 4, 4, 0, 0, 0 } };

  calculateTimes (processes, n, time_slice);

  for (int i = 0; i < n; i++)
    {
      printf ("P%d:%d,%d,%d\n", processes[i].pid, processes[i].completion_time,
              processes[i].turnaround_time, processes[i].waiting_time);
    }

  return EXIT_SUCCESS;
}
