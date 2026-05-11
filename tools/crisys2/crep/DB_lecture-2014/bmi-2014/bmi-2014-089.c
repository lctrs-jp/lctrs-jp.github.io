#include <stdio.h>
/* 作成：****　作成日：１０／１６*/
int main()
{
  int  Wt; /*体重を示す変数*/
  float Ht , Bm; /*Htは身長、BmはBMIを示す関数*/
  printf("体重は何㎏？\n");
  scanf("%d" , &Wt );
  printf("身長は何m？\n");
  scanf("%f" , &Ht );
  Bm = Wt/Ht/Ht;
  printf("あなたのBMIは%fでした\n" , Bm );
  return 0;
}
  
