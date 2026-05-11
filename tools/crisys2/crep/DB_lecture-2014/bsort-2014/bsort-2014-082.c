#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, x;
  int count;

  /* 数値を読み込む */
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  for (a = 0; a <count; a++)
    scanf("%d", &item[a]);

  /* ここで」バブルソートを使用して数値を整列させる */
  for (a = 1; a < count; ++a)
    for (b = count - 1; b >= a; --b) {
      /* 隣接する要素を比較する */
      if (item[b - 1] > item[b]) {
	/* 要素を交換する */
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
      }
	for (t = 0; t < count; t++) 
	  printf("途中経過: %d \n", item[t]);
    }
  /* 整列後のリストを表示する */
  printf("最終結果: ");
  for (t = 0; t < count; t++)
    printf("%d", item[t]);

  return 0;
}
