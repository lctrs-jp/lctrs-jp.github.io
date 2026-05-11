#include <stdio.h>

int sum1(int n) {
  int i, sum = 0;

  if (n < 0)
    return 0;

  for (i = 0; i <= n; i++)
    sum += i;

  return sum;
}


int sum2(int n) {
  if (n <= 0)
    return 0;			
  else
    return n + sum2(n - 1);	
}

int main() {
  int val = 0;

  printf("Input a natural number: ");
  scanf("%d", &val);

  printf("result by sum1: %d\n", sum1(val));
  printf("result by sum2: %d\n", sum2(val));

  return 0;
}

