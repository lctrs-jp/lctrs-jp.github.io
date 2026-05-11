#include <stdio.h>
int sum1(int n);
int sum2(int n);

main()
{
  int a;
  printf("Input an integer\n");
  scanf("%d",&a);

  printf("result by sum1 %d \n",sum1(a));
  printf("result by sum2 %d \n",sum2(a));
}

sum1(n)
{
  int i;
  int s = 0;
  if(n<0) s = 0;
  else{
    for(i=0;i<=n;i++){ 
      s = s + i;
    }
  }
  return s;
}

sum2(n)
{
  if(n<=0) return 0;
  else return ( n + sum2(n-1)); 
 
}
