#include<stdio.h>

int sum1(int n);
int sum2(int n);

main()                                        
{
  int n;

  printf("Input a natural number: ");
  scanf("%d", &n);

  printf("sum1  %d : sum2  %d \n", sum1(n), sum2(n));
  
}

int sum1(int n)                     
{
  if(n <= 0)
  {  return(0); }

  int result1 = 0;
  for( ; n >= 0; n--)
  {  result1 = result1 + n; }

  return(result1);
}
  
int sum2(int n)                             
{
  if(n < 0)
  {  return(0); }

  else if(n == 0)
  {  return(0);  }

  return(sum2(n-1) + n);
}
