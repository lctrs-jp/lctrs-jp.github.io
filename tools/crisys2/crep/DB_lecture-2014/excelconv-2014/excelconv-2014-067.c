#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{ 
  int i, t,l;

  t = argv[1][0] - 64;
    l = strlen(argv[1]);

    for(i = 1; i < l; i++)
      t = t*26 + (argv[1][i] - 64);
  
    printf("%d\n", t);
  return 0;
}
