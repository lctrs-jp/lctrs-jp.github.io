#include <stdio.h>
float bmi(int w , float h);

int main()
{
  int w; /*体重(kg)を保持する変数*/
  float h; /*身長(m)を保持する変数*/
  
  printf("Input your weight: ");/*体重を入力*/
  scanf("%d", &w );
  printf("Input your height: ");/*身長を入力*/
  scanf("%f", &h );
  /*以下、場合分けしてBMIを出力*/
  if( bmi(w,h) >= 30 ){
    printf("BMI = %f(高度肥満)\n", bmi(w,h));
  }else{
    if( bmi(w,h) < 30 && bmi(w,h) >= 25 ){;
    printf( "BMI = %f(肥満)\n", bmi(w,h));
    }else{
      if( bmi(w,h) < 25 && bmi(w,h) >= 18.5 ){
	printf( "BMI = %f(標準)\n", bmi(w,h));
      }else{
	printf( "BMI = %f(やせ)\n", bmi(w,h));
      }
    }
  }
  return 0;
}

float bmi(int w, float h)/*BMIを算出する関数*/
{
  float p;
  p = w / ( h * h );
  return p;
}
