#include <stdio.h>
#include <stdlib.h>

void
allocate_memory (size_t size_in_mb)
{
  size_t size_in_bytes = size_in_mb * 1024 * 1024;
  char *buffer = malloc (size_in_bytes);
  if (buffer == NULL)
    {
      perror ("malloc failed");
      exit (EXIT_FAILURE);
    }
  for (size_t i = 0; i < size_in_bytes; ++i)
    {
      buffer[i] = 'a'; // 模拟内存使用
    }
  printf ("Allocated %zu MB of memory\n", size_in_mb);
  free (buffer);
}

int
main ()
{
  // 尝试分配 120 MB 的内存
  allocate_memory (120);

  return 0;
}
