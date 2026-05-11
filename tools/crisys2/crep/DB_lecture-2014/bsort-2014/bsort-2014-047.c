#include <stdio.h>

int main()
{
  int item[100];
  int a, b, t;
  int count;

  /* 数値を読み込む*/
  printf("数をいくつ入力しますか？\n");
  scanf("%d", &count);

  while( count > 100 ){
    printf("エラー、数が多すぎます。\n");
    printf("数をいくつ入力しますか？\n");
    scanf("%d", &count);
  };

  printf("数字を入力してください\n");
  for(a = 0; a < count; a++)
    scanf("%d", &item[a] );

  /* ここでバブルソートで整列させる。*/
  printf("数字をソートしていきます。\n"); 
  for( a = 1; a < count; ++a)
    for(b = count - 1; b >= a; --b){
      if( item[b - 1] > item[b] ){
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
      }
      for(t = 0; t < count; t++){
	printf("%d",item[t]);
      }
      printf("\n");
    }

  printf("\n");

  return 0;
}
