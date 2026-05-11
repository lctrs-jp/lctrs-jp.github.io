#include <stdio.h>

int fastfib(int n);

int main(void)
{
    int fib, num;

    printf("Input a natural number: ");
    do{
      scanf("%d", &num);
      if(num <= 0)printf("Input a positive number: ");
    }while(num  <= 0);

    fib = fastfib(num);
    if(fib > 0){
      printf("%dth Fibonacci number: %d\n", num, fib);
    }else{
      printf("Overflow.\n");
    }
    return 0;
}

int fastfib(int n)
{
  int i, f, fib1 = 1, fib2 = 1;

  if(n == 1 || n == 2){
    return 1;
  }else{
    for(i = 2; i < n; i++){
      f = fib1 + fib2;
      fib2 = fib1;
      fib1 = f;
    }
    return f;
  }
}
