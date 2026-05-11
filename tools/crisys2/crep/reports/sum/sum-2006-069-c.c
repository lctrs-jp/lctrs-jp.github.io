#include <stdio.h>

int sum1( int n ) 
{
  int a=0, i;
  
  for(i=1;i<=n;i++){
  a=a+i;
  }
  return a;
}

int sum2( int n ); 

main()
{
  int num;

  printf("Input a natural number: ");
  scanf("%d", &num);

  printf("result by sum1: %d \n", sum1(num));
  printf("result by sum2: %d", sum2(num));
}

int sum2( int n ) 
{
  if(n==0) return 0;
  else if(n<0) return 0; 
  else return (n + sum2(n-1)); 
}
