#include <stdio.h>

int bmis(int k, float bmi );


int main()
{
  float w , h , bmi;
  int k,s;
  w = 0;
  h = 0;
  s = 0;

  while( w <= 0 ){
  printf("あなたの体重を入力してください。\n");
  scanf("%f", &w );             /* 体重を代入 */
  s = s + 1;
  if ( s > 20 ) break;
  } 
  s = 0;
  while( h <= 0){
  printf("あなたの身長を入力してください。\n");
  scanf("%f", &h );             /* 身長を代入 */ 
  s = s + 1;
  if ( s > 20 ) break;
  }
  
  bmi = w * 10000 / ( h * h );  /* BMIを計算 */
  printf("あなたのBMIは %f です。\n", bmi );

  switch( bmis( k,bmi) ){
  case 1:
    printf("あなたは、”やせ”  です。\n");
    break;
  case 2:
    printf("あなたは、”標準”  です。\n");
    break;
  case 3:
    printf("あなたは、”肥満”  です。\n");
    break;
  case 4:
    printf("あなたは、”高度肥満”  です。\n");
    break;
  }

  return 0;
}
    
int bmis(int k, float bmi )
{
  k = 1;
  if ( bmi >= 18.5 )
    k = 2;
  if ( bmi >= 25 )
    k = 3;
  if ( bmi >= 30 )
    k = 4;

  return k;
}
