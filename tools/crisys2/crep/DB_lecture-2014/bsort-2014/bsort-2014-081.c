#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t, i, c;
  int count;

  /*数値を読み込む*/
  printf("数値をいくつ入力しますか？\n");
  scanf("%d", &count );
  printf("数を%d 個入力してください.\n", count);
  for ( i = 0; i < count; i++ )
    scanf("%d", &item[i] );

  /*バブルソートで整列*/
  for( a = 1; a < count; ++a )
    for( b = count - 1; b >= a; --b ){
      if( item[b - 1] > item[b]){
	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;
      }
    
      for( c = 0; c < count; ++c )
	printf(" %d",item[c] );
      printf("\n" );  
 }  
    
      
 return 0;
}
