#include <stdio.h>

int main(void)
{
  int n, i = n % 2;

  printf("2以上の整数を入力してください : ");
  scanf("%d", &n);

  while (n != 1) {
    if (i == 0) {
      n = n /2;
      printf(" -> %d", n);
      i = n % 2;
    }
    else {
      n = (3 * n) + 1;
      printf(" -> %d", n);
      i = n % 2;
    }
      }

  return ;
} 
    
