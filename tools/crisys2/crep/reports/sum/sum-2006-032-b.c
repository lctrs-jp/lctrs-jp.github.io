#include <stdio.h>

int sum1(int n) {
  int i, x=0;

  if(n<0) return 0;
  else {
    for(i=1; i<=n; i++) {
      x = x + i;
    }
    return x;
  }
}

int sum2(int n);

main()
{
  int i;

  printf("Input a natural number: ");
  scanf("%d", &i);

  printf("result by sum1: %d\n", sum1(i));
  printf("result by sum2: %d\n", sum2(i));
}

int sum2(int n)
{
  if(n<0) return 0;
  else return (n + sum2(n-1));
}
      
