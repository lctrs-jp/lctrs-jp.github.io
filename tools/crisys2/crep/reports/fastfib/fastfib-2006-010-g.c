#include <stdio.h>

int fastfib(int n);

main()
{
  int n;
  printf("Input a natural number: ");
  scanf("%d", &n);
  if(fastfib(n) == 0){
    printf("Input a natural number ( Fib(%d) = 0 )\n", n);
  }else{  
    printf("%dth Fibonacci number: %d\n", n, fastfib(n));
  }
}

int fastfib(int n)
{
  int i, fib, p = 1, q = 0;
  if(n < 1){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    for(i = 2; i <= n; i++){
      fib = p + q;
      q = p;
      p = fib;
      
    }
    return fib;
  }
}
