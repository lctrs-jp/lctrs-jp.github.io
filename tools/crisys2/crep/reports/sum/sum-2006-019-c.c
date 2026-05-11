#include <stdio.h>

int sum2(int n);

int sum1(int n)
{
  int i,k;
  k=0;
    
  for(i=1;i<=n;i++) k=k+i;
  return(k);
}

main()
{
  int num;
  printf("Input a non-negative integer: ");
  scanf("%d",&num);
  
  if(num<0) printf("sum(%d) = 0\n",num);
  else{
    
    printf("sum1(%d) = %d\n",num,sum1(num));
    printf("sum2(%d) = %d\n",num,sum2(num));
  }
  return(0);
}
    
sum2(int n)
{
  if(n==1) return(1);
  else return(n+sum2(n-1));
}
