#include <stdio.h>

int sum2(int); 

int
sum1(int n) 
{
  if(n < 0) { 
    return 0; 
  }

  
  return n * (n + 1) / 2; 
}

int
main(int argc, char *argv[])
{
  int num;

  printf("Input a natural number: ");
  scanf("%d", &num); 

  printf("result by sum1: %d\n",sum1(num));
  printf("result by sum2: %d\n",sum2(num));

  return 0;
}

int
sum2(int n)
{
  if(n < 0 || n == 0) { 
    return 0; 
  }

  return n + sum2(n - 1); 
}
