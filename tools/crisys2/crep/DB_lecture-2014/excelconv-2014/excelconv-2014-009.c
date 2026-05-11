#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
  int n=0, l, i;

  for (l=0;*(argv[1]+l);l++) ;

  for (i=0;*(argv[1]+i);i++) 
    n=n+pow(26, l-i-1)*(*(argv[1]+i)-64);

  printf("%d\n", n);

  return 0;
}
