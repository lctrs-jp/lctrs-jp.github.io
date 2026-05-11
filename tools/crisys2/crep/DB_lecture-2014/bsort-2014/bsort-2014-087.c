#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, s;
  int count;

  /* 数値を読み込む*/
  printf("数値をいくつ入力しますか");
  scanf("%d", &count);
  for (a = 0; a< count; a++)
    scanf("%d", &item[a]);
  /*　ここでバブルソートを使用して数値を整列させる　*/
  for (a = 1; a < count; ++a)
    for (b = count - 1; b >= a; --b) {
	/*　隣接する要素を比較　*/
	if (item[b - 1] > item[b]){
	  /*要素を交換*/
          t = item[b - 1];
          item[b - 1] = item[b];
          item[b] = t;
	}
        for (s = 0; s < count; s++)
	     printf("%d", item[s]);   
    printf("\n");
    }
	   /*整列後のリストを表示*/
	   for (t = 0; t < count; t++)
	     printf("%d", item[t]);
	   printf("\n");
 return 0;
}
