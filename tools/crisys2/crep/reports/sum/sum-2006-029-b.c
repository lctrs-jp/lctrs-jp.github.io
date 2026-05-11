#include<stdio.h>

int sum1(int);
int sum2(int);

int main()
{
  int n;

  printf("Input a natural number: ");
  scanf("%d",&n);

  printf(" result yb sum1: %d\n result by sum2: %d\n", sum1(n) ,sum2(n) );

  return 0;
}

int sum1(int n)  
{
  int i,gokei1=0;
 
  if(n<0) {return 0;}

  else
 {
    for(i=0;i<=n;i++)
    
    gokei1=gokei1+i;

    return gokei1;
 }
}

int sum2(int n)  
{
  if(n<0)  {return 0;}           
 
  else if(n==0) {return 0;}

  else  { return sum2(n-1)+n;}
}
