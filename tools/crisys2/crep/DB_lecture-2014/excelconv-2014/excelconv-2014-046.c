#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc,char *argv[])
{
  int i,n;
  n = 0;
  *(argv[1]+strlen(argv[1])) = '\0';
  for(i=0;*(argv[1]+i);i++)
    n = n + pow(26,strlen(argv[1])-i-1)*((*(argv[1]+i))-64);
  printf("%s = %d\n",argv[1],n);

  return 0;

  }
