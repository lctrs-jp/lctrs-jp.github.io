#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, j;
  int a = 0, b = 0;

  j = strlen(argv[1]);

  for (i = 0; i < j; i++){
    a = *(argv[1] + i);
    a = a + b * 26;
    b = a - 64;
  }
  printf("%d\n", b);

  return 0;
}
