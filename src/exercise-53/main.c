#include "v2p.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s <virtual_address>\n", argv[0]);
      return EXIT_FAILURE;
    }

  char *str_address = strdup (argv[1]);

  if (!str_address)
    {
      fprintf (stderr, "Failed to load frames queue from input\n");
      return EXIT_FAILURE;
    }

  char *ptr;
  uint32_t virtual_address = strtoul (str_address, &ptr, 16);
  uint32_t physical_address = translate_address (virtual_address);
  printf ("Physical_Address：0x%x\n", physical_address);

  return EXIT_SUCCESS;
}
