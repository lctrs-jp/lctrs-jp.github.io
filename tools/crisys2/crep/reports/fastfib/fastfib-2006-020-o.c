#include <stdio.h>

int fastfib(int n);

int main(int argc, char *argv[])
{
  int num; 

  do{
    printf("Input a natural number: ");
    scanf("%d", &num); 
    if(num < 0) { 
      printf("Error: a negative number was inputted.\n");
    }
  } while (num < 0); 

  printf("%dth Fibonacci number: %d\n", num, fastfib(num));

  return 0;
}

int fastfib(int n)
{
  int fib = 1; 
  int fib_p = 0; 
  int fib_n; 
  int i; 

  if(n <= 0) { 
    return 0;
  }
  
  for(i = 1; i < n; i++) { 
    fib_n = fib + fib_p; 
    fib_p = fib; 
    fib = fib_n; 
  }

  return fib; 
}



