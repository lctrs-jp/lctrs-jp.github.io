#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, k;
  int count;

  //数値を読み込む
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  for (a = 0; a < count; a++)
    scanf("%d", &item[a]);

  printf("ソート経過:");

  //ここでバブルソートを利用して数値を整列させる
  for (a = 1; a < count; ++a)
    for (b = count - 1; b >= a; --b) {     
      if (item[b-1] > item[b]) {
	//要素を交換する
	t = item[b-1];
	item[b-1] = item [b];
	item[b] = t;
      }
      printf("\n");
      for (t = 0; t < count; t++){
	printf("%d ",item[t]);
      }
    }
  printf("\n");

  //整列後のリストを表示する
  printf("ソート結果:\n");
  for(t = 0; t < count; t++){
    printf("%d ", item[t]);
  }
  printf("\n");

  return 0;
}
