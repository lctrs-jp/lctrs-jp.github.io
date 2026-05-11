#include <stdio.h>
#include <math.h>
#include <string.h>

double main(int argc, char *argv[])
{
  int i = 0,n = 0;
  int k;  

  i = strlen(argv[1]); /* 文字数をカウント */
  

  for(k = 0; k < i; k++)
    {
      n =  n + pow(26, i - k - 1) * (*(argv[1] + k) - 64);
      /* k番目の文字を整数に変換し、26の(j-k-1)乗をかける */        
    }
   
  printf("%d\n", n);

  return n;
}
  
