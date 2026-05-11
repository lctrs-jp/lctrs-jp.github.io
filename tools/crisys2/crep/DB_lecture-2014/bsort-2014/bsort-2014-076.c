#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, k;
  int count; 

  /* 数値を読み込む  */
  printf("数をいくつ入力しますか？ ");
  scanf("%d", &count);
  for (a = 0; a < count; a++)
    scanf("%d", &item[a]);
  /* ここでバブルソートを使用して数値を数列させる */
 for (a = 1; a < count; ++a)
     for (b = count - 1; b >= a; --b)
     
{
       /* 隣接する要素を比較する*/ 
       if (item[b - 1] > item[b]) {
	 /* 要素を交換する */
	  t = item[b - 1];
	   item[b - 1] = item[b];
	   item[b] = t;
    
       }

       for (k = 0; k < count; k++)
	 printf("%d ", item[k]); 
       printf("\n");} 
   return 0;
}
