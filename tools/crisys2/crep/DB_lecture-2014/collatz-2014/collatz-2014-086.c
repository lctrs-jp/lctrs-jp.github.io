#include <stdio.h> /* 問題4 */

int main()
{
  int num;


  printf("2以上の数を入力してください\n");
  scanf("%d", &num );

  /* 数が1になるまで計算させる */
  while( num != 1){
{  
    if( num % 2 == 0 )/* 偶数の場合 */
    num = num / 2;
    else              /* 奇数の場合 */
      num = num * 3 + 1;
}
    {

if( num != 1 )
  printf("%d->" , num ); /* 1以外の時の表示 */
 else
   printf("%d\n" , num ); /* 1の時の表示 */
    }}


    return 0;
}

