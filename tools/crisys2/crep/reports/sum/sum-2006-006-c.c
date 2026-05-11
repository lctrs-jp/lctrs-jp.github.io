#include <stdio.h>

int sum1(int n)
{
  int i,k=0;
  
  for(i=1; i<=n; i++){
      k=k+i;
  }
  return(k);
}

main()
{
  int n;
  printf("Input a natural number: ");
  scanf("%d" ,&n);

  printf("result by sum1: %d\n",sum1(n));
  printf("result by sum2: %d\n",sum2(n));
  return 0;
}

int sum2(int n)
{
  if(n<0) return(0);
  else return(n+sum2(n-1));
}
