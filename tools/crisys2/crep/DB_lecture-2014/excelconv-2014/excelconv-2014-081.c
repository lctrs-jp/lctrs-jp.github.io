#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int n, a;
  
  for(n = 0; n < strlen(argv[1]); n++)
    a = a*26 + argv[1][n] - 64;
 
  printf("%d\n", a);
}
