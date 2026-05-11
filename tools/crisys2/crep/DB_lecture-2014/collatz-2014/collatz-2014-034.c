#include <stdio.h>
#include <string.h>
int main(void)
{
  int n, k;
  printf("2以上の整数を入力してください： ");
  scanf("%d", &n);
  printf("%d", n);
  while(n != 1){ /* nが1となるまで計算する */
  k = n % 2;
  if (k == 0){
    n = n / 2;
    printf("-> %d ", n); /* 偶数のときに2で割る */
  }
  else{
    n = n * 3 + 1;
    printf("-> %d ", n); /* 奇数のときに3をかけて1を足す */
  }
  }
  printf("よって計算終了", n); /* n = 1 のときに表示 */
   return 0;
}

