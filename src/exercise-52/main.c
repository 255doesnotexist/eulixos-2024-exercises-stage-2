#include <stdio.h>
#include <unistd.h>

int
main ()
{
  char hostname[1024];
  if (gethostname(hostname, sizeof(hostname)) == -1) {
      perror("gethostname");
      return 1;
  }

  printf("%s\n", hostname);
}
