#include <stdio.h>

int main(void)
{
  int item[100];
  int a,b,c,t;
  int count;
  
  /*数値を読み取る*/
  printf("数をいくつ入力しますか？　");
  scanf("%d\n", &count);
  for(a =0; a < count; a++)
    scanf("%d", &item[a]);

  /*ここでバブルソートを利用して数値を整列させる*/
  for(a = 1; a < count; ++a)
    for(b = count - 1; b >= a; --b){
      /*隣接する要素を比較する*/
      if(item[b-1] > item[b]){
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
	for(c =0; c < count; ++c)
	  printf("%d ",item[c]);  
	printf("\n");
    }
    }
/*を表示する*/
    for(t = 0; t < count; t++)
  printf("%d",item[t]);

return 0;
}
