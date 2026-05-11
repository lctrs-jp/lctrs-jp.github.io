#include <stdio.h>

int main(void)
{
  int i, n;
  /* 整数を入力させる */
  printf("2以上の整数を入力して下さい：");
  scanf("%d", &n);
  
  printf("%d", n);
  while(n != 1) {
    /* 偶数の場合2で割る */
    if (n % 2 == 0)
      n = n / 2;
    
    /* 奇数の場合3を掛けて1を足す */
    else 
      n = 3 * n + 1;
    
    printf("-> %d", n);
  }
  printf("\n");
  
  return 0;
}
