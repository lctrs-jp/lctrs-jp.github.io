#include <stdio.h>

int fastfib(int n) {
  int i, result, old_result, temp;
  if (!n) return 0;

  result = 1;
  old_result = 0;

  for (i = 2; i <= n; i++) {
    temp = result;
    result = result + old_result;
    old_result = temp;
  }

  return result;
}

int main() {
  int num, fib;

  printf("Input a natural number: ");
  scanf(" %d", &num);
  while(num < 0) {
    printf("Re-input a natural number: ");
    scanf(" %d", &num);
  }

  if ((fib = fastfib(num)) < 0) {
    printf("overflow\n");
  } else {
    printf("%dth Fibonacci number: %d\n", num, fib);
  }

  return 0;
}

