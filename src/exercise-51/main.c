#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lru.h"

#ifndef _GNU_SOURCE
char *
strdup (const char *s)
{
  size_t len = strlen (s) + 1;
  char *dup = malloc (len);
  if (dup)
    {
      strcpy (dup, s);
    }
  return dup;
}
#endif
int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <queue_frames> <num>\n", argv[0]);
      return EXIT_FAILURE;
    }

  int num = atoi (argv[2]);
  char *queue_frames = strdup (argv[1]);

  if (!queue_frames)
    {
      fprintf (stderr, "Failed to load frames queue from input\n");
      return EXIT_FAILURE;
    }

  lru_page_replacement (queue_frames, num);

  return EXIT_SUCCESS;
}
