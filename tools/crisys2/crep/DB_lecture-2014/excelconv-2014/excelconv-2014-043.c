#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, j, count;
  

 
  count = strlen(argv[1]);

  i = 0;
  for(j = 0; j < count; j++)
    i = i*26 + (argv[1][j] - 65 + 1);

  printf("%d\n", i);
  
  return 0;

}
