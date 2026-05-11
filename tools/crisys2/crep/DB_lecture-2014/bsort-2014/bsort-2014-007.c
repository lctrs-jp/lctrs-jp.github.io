#include <stdio.h>
int main(void)
{
  int item[100];
  int a, b, c, t;
  int count;

  //数値を読み込む
  printf("数をいくつ入力しますか?\n");
  scanf("%d", &count);
  printf("数を%d個入力してください\n", count);
  for(a = 0; a < count; a++)
    scanf("%d", &item[a]);   

  //入力された数をソート
  for(a = 1; a < count; ++a)
    for(b = count -1; b >= a; --b){
      if(item[b - 1] > item[b]){
	t = item[b - 1];
	item[b - 1] =item[b];
	item[b] = t;
	//ソートの途中経過
	for(c = 0; c < count; c++) 
	  printf("%d ", item[c]);
      }
      printf("\n");
    }
  return 0;
}


      
