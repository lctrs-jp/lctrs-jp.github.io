#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int i, n = 0, len;
  int str[5];

  len = strlen(argv[1]);

  for(i = 0; i < len; i++) {
    str[i] = argv[1][i] - 64;
    n = n + (pow(26,len - i - 1) * str[i]);
  }
  
  printf("%d\n",n);
  
  return 0;
}
