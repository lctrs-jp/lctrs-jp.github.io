#include<stdio.h>
#include<math.h>

int fastfib(int n);

main(){
  int n;

  printf("Input a natural number: ");
  scanf("%d", &n);

  printf("%dth Fibonacci number: %d\n", n, fastfib(n));
}

int fastfib(int n){
  int fib;
  if(n < 0){
    printf("Input a non-negative integer.\n");
    return 0;
  }

  fib = ((pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2, n))/sqrt(5));
  if(fib<0) printf("overflow.\n");
  return fib;
}
