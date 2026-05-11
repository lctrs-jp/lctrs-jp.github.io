#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, i, j;
  int count;

  /* 数値を読み込む */
  printf("数をいくつ入力しますか？: ");
  scanf("%d", &count);
  for (a = 0; a < count; a++)
    scanf("%d", &item[a]);
  printf("\n");
  for (j = 0; j < count; j++) {
    printf("%d ", item[j]);
  }

  /* ここでバブルソートを使用して数値を整列させる */
  for (a = 1; a < count; ++a)
    for (b = count -1; b >= a; --b){
      /* 隣接する要素を比較する */
      if(item[b - 1] > item[b]){
	/* 要素を交換する */
	printf("\n");
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
        for ( i = 0; i < count; i++) {
          printf("%d ", item[i]);
        }
      }
    }
  printf("\n");

  /* 整列後のリストを表示する */
  for (t = 0; t < count; t++)
    printf("%d ", item[t]);

  return 0;
}
