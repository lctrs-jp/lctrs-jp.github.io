#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, u;
  int count;

  //数値を読み込む
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  printf("数を %d 個入力してください\n", count);
  for (a = 0; a  < count; a++) 
    scanf("%d\n", &item[a]);

  //過程を表示しつつ数値を整列させる
  for(a = 1; a < count; a++)
    for (b = count - 1; b >= a; b--) {
      //隣接する要素を比較する
      if (item[b -1] > item[b]) {
	//要素を交換する
	t = item[b -1];
	item[b - 1] = item[b];
	item[b] = t;
	//交換後のリストを表示する
	for (u = 0; u < count; u++) 
	  printf("%d ", item[u]);
	printf("\n");
      }
    }
  return 0;
}
