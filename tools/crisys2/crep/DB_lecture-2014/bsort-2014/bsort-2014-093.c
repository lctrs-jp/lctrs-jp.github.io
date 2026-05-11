#include <stdio.h>

int main(void){

  int item[100];
  int a, b, t;
  int count;

  printf("数をいくつ入力しますか？");
  scanf("%d",&count);
  printf("%d個入力\n",count);

  for (a = 0; a < count; a++ ){
    scanf("%d", &item[a]);
  }
  for(a = 0; a < count; a++ )
    printf("%d個目の数は%d\n", a + 1, item[a]);

  printf("数を小さい順に並び替える\n");
  for ( a = 1; a < count; ++a )
    for( b = count - 1; b >= a; --b ){
      if (item[b - 1] > item[b] ){
	printf("%d個目の%dより%d個目の%dのほうが小さいため入れ替える  ", b,item[b - 1], b + 1, item[b]);

	t = item[b - 1];
	item[b - 1] = item[b];
	item[b] = t;

	for(t = 0; t < count; t++ )
	  printf("%d  ",item[t]);
	printf("\n");
      }
    }

  for (t = 0; t < count; t++ )
    printf("%d  ", item[t]);
  return 0;
}
