#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, i;
  int count;

  //数値を読み込む
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  for (a = 0; a < count; a++)
    scanf("%d", &item[a]);

  //バブルソートで数値を整列
  for (a = 1; a < count; a++){
    for(b = count - 1; b >= a; b--){
      //隣接する要素を比較
      if (item[b - 1] > item[b]){
	//要素を交換
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
	//交換後の数列を表示
	for(i = 0; i < count; i++){
	printf("%d ", item[i]);
      }
	printf("\n");
      }
    }
  }
  return 0;
}
