#include <stdio.h>

int fastfib( int n )
{
  int i;
  int j = 1;
  int z = 0, tmp = 0;

  for( i = 0 ; i < n ; i++ ){
    tmp = j;
    j += z;
    z = tmp;
  }
  return z;
}

main()
{
  int n;

  printf("n = ");
  scanf("%d", &n );

  printf("fastfib( %d ) = %d\n", n, fastfib( n ) );
}
