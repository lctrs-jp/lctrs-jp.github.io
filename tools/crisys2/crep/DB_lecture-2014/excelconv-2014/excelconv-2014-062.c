#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, p, r;
  r = argv[1][0] - 64;
  for(i = 1; argv[1][i] != '\0' ; i++){
    p = argv[1][i] - 64;
    r = r * 26 + p;
  }  
  
  printf("%d\n",r );

  return 0;
}
