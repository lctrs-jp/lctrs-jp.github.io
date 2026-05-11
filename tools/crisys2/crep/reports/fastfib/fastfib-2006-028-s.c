#include<stdio.h>

int fastfib( int n )
{
  int a=1, b=0, c, i;

  if( n <= 0 ) return 0;
  else if( n < 2 ) return 1;

  for(i=2; i<=n; i++){
    c = a + b;
    b = a;
    a = c;
  }

  return c;
}


main()
{
  int n;
  printf("Input a natural number: ");
  scanf("%d", &n);

  if( n < 0 ){
    printf("Input a positive number.\n");
    exit(1);
  }
  if( fastfib(n) < 0 ){
    printf("Overflow at %dth number.\n", n);
    exit(1); 
  }
  printf("%dth Fibonacci number: %d\n", n, fastfib(n));

}



