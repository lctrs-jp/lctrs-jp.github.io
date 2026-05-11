#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, i;
  int count;

  /* 数値を読み込む */
  printf("数をいくつに入力しますか?\n ");
  scanf("%d", &count);
  printf("数を%d個入力してください。\n", count);
  for (a = 0; a< count; a++)
    scanf("%d", &item[a]);

  /* ここでバブルソートを使用して数値を整列させる */
  for (a = 1; a < count; ++a)
    for (b = count - 1; b >= a; --b) {
      /* 隣接する要素を比較する */
      if (item[b - 1] > item[b]) {
	/* 要素を交換する */
	i = item[b - 1];
	item[b - 1] = item[b];
	item[b] = i;
	/* 整列後のリストを表示する */
	for (i = 0; i < count; i++)
	  printf("%d\t ", item[i]);
	if (i == count)
	  printf("\n");
      }
    }

  return 0;
}
