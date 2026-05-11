#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, j;
  int count;

  /* 数値を読み込む */
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  for (a = 0; a < count; a++)
    scanf("%d", &item[a]);
  for (j = 0; j < count - 1; j++)
    printf("%d ", item[j]);
  printf("%d\n", item[count - 1]);
  j = 0;
  /* ここでバブルソートを使用して数値を整列させる */
  for (a = 1; a < count; ++a)
    for (b = count - 1; b >= a; --b){
      /* 隣接する要素を比較する */
      if (item[b - 1] > item[b]) {
	/* 要素を交換する */
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
      }
      /* 途中経過（最終結果を含む）を表示する */
      for(j = 0; j < count - 1; j++)
	printf("%d ", item[j]);
      printf("%d\n", item[count - 1]);
      j = 0;
    }
  return 0;
}
