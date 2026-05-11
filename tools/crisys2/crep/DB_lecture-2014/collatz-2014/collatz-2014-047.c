#include <stdio.h>

int main(void)
{
  int x = 0;

  printf("2以上の整数を入力してください: ");
  scanf("%d", &x);

  /* 必ず2以上の数値入力を要求 */
  while ( x < 2 ) {
    printf("2以上の整数を入力してください: ");
    scanf("%d", &x);   
  }

  printf("%d ", x);

  /* 結果が1になるまで繰り返す */
  while ( x != 1 ) {
    /* 偶数の場合の対応 */ 
    if ( x % 2 == 0) {
      x = x / 2;
      printf("-> %d " ,x); 
    }	 
    /* 奇数の場合の対応 */ 
    else if ( x % 2 == 1 ) {
      x = x * 3 + 1;
      printf("-> %d " ,x);
    }
  }    

  printf("\n");
  return 0;
}

