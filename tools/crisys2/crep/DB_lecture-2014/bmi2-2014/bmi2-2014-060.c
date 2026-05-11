#include <stdio.h>

void result();

int main()
{
  float w, h;
  char x; 
  result();


      //体重
  printf("体重(kg)を入力してください。\n");
  scanf("%f", &w );//体重入力
  scanf("%c", &x );//バグ対策

  if( w <= 0 )//エラーメッセージ
    {
    while( w <= 0 )
      {  
      printf("不正な値です。入力しなおしてください。\n");
      scanf("%f", &w );//体重入力
      scanf("%c", &x );//バグ対策
      }
    }

  h = 0;
      //身長
  printf("身長(m)を入力してください。\n");
  scanf("%f", &h );//身長入力
  scanf("%c", &x );//バグ対策

  if( h <= 0 )//エラーメッセージ
    {
    while( h <= 0 )
      {  
      printf("不正な値です。入力しなおしてください。\n");
      scanf("%f", &h );//身長入力
      scanf("%c", &x );//バグ対策
      }
    }


  float b;
  b = w / ( h * h );
  printf("体重 %fkg 身長 %fm \n", w, h );
  printf("あなたのBMIは %f です。\n", b );

  if( b < 25 )
    {
      if( b < 18 )
	printf("やせ気味です。\n");
      else
	printf("標準です。\n");
    }  

  else
    {
      if( b < 30 )
	printf("肥満です。\n");
      else
	printf("高度肥満です。\n");
    }  




  return 0;
}





void result()
{
  printf("あなたのBMIを計算します。\n");
  return;
}
