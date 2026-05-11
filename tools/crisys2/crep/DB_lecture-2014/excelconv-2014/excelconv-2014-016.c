#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[ ])
{
  int a, b;
  int n = 0, i = 0;

  a = strlen(argv[1]);

  for (b = 0; b < a; b++){
    n = *(argv[1] + b);
    n = n + i * 26;
    
    i = n - 64;
  }

  printf("%d", i);
  return 0;
}
    

