#include <stdio.h>

int sum1(int n);
int sum2(int n);

int sum1(n)
{
  int i,a=0;
  if(n<=0) return 0;

  else{
   for(i=0;i<=n;i++){
   a=a+i;
   }
  return a;
  }
}

main()
{
  int num;
  printf("Input a natural number: ");
  scanf("%d",&num);

  printf("result by sum1: %d\n",sum1(num));
  printf("result by sum2: %d\n",sum2(num));
  
}

int sum2(n)
{
  if(n<=0) return 0;
  else{
    return(n+sum2(n-1));
  }
}
