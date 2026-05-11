#include <stdio.h>

int sum2(int m, int n);

int main()
{
  int m, n;

  printf("Input an integer: ");
  scanf("%d", &m );
  printf("Input an integer: ");
  scanf("%d", &n );

  if( m == n )
    printf("Error: those are the same.\n");
  else{
    printf("Summation: ");
    if( m < n )
      printf("%d\n", sum2(m,n) );
    else
      printf("%d\n", sum2(n,m) );
  }

  return 0;
}

int sum2(int m, int n)
{
  int i, total = 0;

  i = m;
  while( i <= n ){
    total = total + i;
    i++;
  }

  return total;
}
