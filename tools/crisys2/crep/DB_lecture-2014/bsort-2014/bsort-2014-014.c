#include <stdio.h>

int main()
{
  int item[100];
  int a, b, t, j;
  int count;

  //数値を読み込む
  printf("数をいくつ入力しますか？:");
  scanf("%d", &count);
  printf("数を %d つ入力してください:\n", count);
  for(a = 0; a < count; a++)
    scanf("%d", &item[a]);

  for(a = 0; a < count; a++)
  printf("%d", item[a]);
  printf("\n");

  //バブルソート
  for(a = 1; a < count; a++) {
    for(b = count - 1; b >= a; b--) {
      if(item[b - 1] > item[b]) {
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
	for(j = 0; j < count; j++)
	  printf("%d", item[j]);
	printf("\n");
      }
    }
  }

  //整列後のリストを表示
  for(t = 0; t < count; t++)
  printf("%d", item[t]);

  return 0;
}
