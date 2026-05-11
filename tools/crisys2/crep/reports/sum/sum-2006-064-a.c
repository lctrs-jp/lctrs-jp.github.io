#include <stdio.h>

int sum2(int);

int sum1(int n)
{
  int i, x=0;
  if(n<=0) return 0;
  else{ 
    for (i=0;i<=n;i++)
      {
	x=x+i;
      }
    return x;
  }
}

main()
{
  int num;
  printf("Input a natural number>");
  scanf("%d",&num);

  printf("result by sum1:%d\n",sum1(num));
  printf("result by sum2:%d\n",sum2(num));

  return 0;
}

int sum2(int n)
{
  if(n<=0) return 0;
  else return sum2(n-1)+n;
}
