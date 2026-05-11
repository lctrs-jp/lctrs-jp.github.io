#include <stdio.h>

void show_to_one(int x);

int main(void)
{
  int src;

  printf("2 以上 3*2^53以下の整数値を入力してください\n");
  scanf("%d", &src);

  show_to_one(src);

  return 0;
}

void show_to_one(int x)
/* ある操作を繰り返して1になる過程を表示する */
{
  int i;

  /* 適切な数字かどうか判定 */
  if (x <= 1){			/* long int型の範囲を超えるため上限なし */
    printf("不適切な数字です\n");
    return ;
  }

  printf("%d\n", x);		/* 過程の表示 */

  while (x != 1){
    if (x % 2 == 0){		/* xが2なら2で割る */
      x = x / 2;
      printf("%d\n", x);	/* 過程の表示 */
    } else if (x % 2 != 0){	/* 条件は必要ないが可読性向上のため書く */
      x = (x * 3) + 1;
      printf("%d\n", x);	/* 過程の表示 */
    }
  }
  return ;
}
