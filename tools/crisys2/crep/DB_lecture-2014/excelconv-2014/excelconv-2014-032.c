#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, i;
  int a = 0, b = 0;

  n = strlen(argv[1]);

  for (i = 0; i < n; i++){
    a = *(argv[1] + i);
    a = a + b * 26;

    b = a - 64;
  }

  printf("%d", b);

  return 0;
}
