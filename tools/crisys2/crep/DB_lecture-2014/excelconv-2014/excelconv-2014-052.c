#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, sum;
  sum = 0;

  for(i = 0; *(argv[1] + i) ; i++)
    sum = sum + pow( 26, strlen(argv[1]) - i - 1) * ( *(argv[1] + i) - 64 );

  printf("%d\n",sum);

  return 0;
}
