#include <stdio.h>

int sum1(int n)
{
  int i,s;
  s=0;
  if(n<=0) s==0;
   else for(i=1;i<=n;i++)
     {s=s+i;}
  return s;
}

int main()
{
 int num;
 printf("Input a natural number: ");
  scanf("%d\n",&num);
  printf("result by sum1: %d\n",sum1(num));
  printf("result by sum2: %d\n",sum2(num));
}
  
int sum2(int n)
{
  if(n<=0){return(0);}
  else {return(n+sum2(n-1));}
}
