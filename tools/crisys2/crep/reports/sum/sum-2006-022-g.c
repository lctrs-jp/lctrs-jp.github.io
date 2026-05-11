#include <stdio.h>

int sum2(int n);

int sum1(int n)
{
  if ( n<=0 ) {
    return 0;
  } else {
    return (n*(n+1)/2);
  }
}

int main()
{
  int n;

  printf("Input a natural number: ");
  scanf("%d", &n);

  if ( sum1(n) == 0 || sum2(n) == 0) {
    printf("Input a non-negative number.\n");
  } else {
    printf("result by Sum1: %d\n",sum1( n ));
    printf("result by Sum2: %d\n",sum2( n ));
    if ( sum1(n) <= 0 || sum2(n) <= 0) {
      printf("ERROR: overflow\n");
    }
  }
}

int sum2(int n)
{
  if ( n<=0 ) {
    return 0;
  } else {
    return (sum2( n-1 )+n);
  }
}
