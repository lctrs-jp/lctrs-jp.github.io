#include <stdio.h>

int sum1(int n);
int sum2(int n);

int sum1(int n)
{
  if(n<=0) return 0;
  return n*(n+1)/2;
}

int main(int argc,char **argv)
{
  int n=0;

  printf("Input a natural number: ");
  scanf("%d",&n);
 
  printf("result by sum1;  %d\n",sum1(n));
  printf("result by sum2;  %d\n",sum2(n));

  return 0;
}

int sum2(int n)
{
  if(n<=0) return 0;
  return n+sum2(n-1);
}
