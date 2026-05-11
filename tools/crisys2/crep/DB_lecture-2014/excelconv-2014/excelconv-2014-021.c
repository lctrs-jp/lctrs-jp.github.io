#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
  int i = 0;
  char *p;
  p = argv[1];

  while(*p) {
    i = i * 26 + *p - 64;
    p++;
  }

  printf("%d\n", i);

  return 0;
}

