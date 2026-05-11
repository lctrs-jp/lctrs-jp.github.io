#include<stdio.h>

int main()
{
  int item[100];
  int a , b, t, n;
  int count;

  /*整数を読み込む*/

  printf("数をいくつ入力しますか？");
  scanf("%d" , &count);
  for (a = 0; a < count; a++)
    scanf("%d" , &item[a]);
  for(n = 0; n < count; n++)
    printf("%d" , item[n]);
    printf("\n");   
    

  
  /*ここでバブルソートを使用して整数を整列させる*/

  for (a = 1; a < count; a++)
    for(b = count - 1; b >= a; b--){
      /*隣接する要素を比較する*/
      if ( item[b - 1] > item[b] ) {
	t = item[b - 1];
        item[b - 1] = item[b];
        item[b] = t;
      /*ソートの途中経過を表示する*/
      for(n = 0; n < count; n++)
	printf("%d" , item[n]);
      printf("\n");   
      }
      
    }

  return 0;
}
 

   
