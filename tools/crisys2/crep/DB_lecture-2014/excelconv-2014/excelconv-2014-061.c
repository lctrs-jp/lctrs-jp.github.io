#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

  int s, t, u;
  t = (argv[1][0] - 64);
  u = strlen(argv[1]);
  for(s = 1; s < u; s++)
    t = t * 26 + (argv[1][s] - 64);
  printf("%d\n", t);
    return 0;
}
