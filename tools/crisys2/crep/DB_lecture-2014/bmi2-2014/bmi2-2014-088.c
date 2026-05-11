#include <stdio.h>
float twice(float x); // twice のプロトタイプ宣言
int main()
{
  float n;
  float m;

  while( n <= 0 ){
    printf("体重kgを入力してください。\n");
    scanf("%f", &n );
    }

  while( m <= 0 ){
    printf("身長cmを入力してください。\n");
    scanf("%f", &m );
    }

  if ( n / (twice(m) * twice(m)) < 18.5 ){
    printf("BMI = %f / %f * %f = %f 判定　やせ\n ", n, twice(m), twice(m), n / (twice(m) * twice(m))); // nは体重 mは身長
  }else if ( n / (twice(m) * twice(m)) < 25 ){
    printf("BMI = %f / %f * %f = %f 判定　標準\n ", n, twice(m), twice(m), n / (twice(m) * twice(m))); // nは体重 mは身長
  }else if ( n / (twice(m) * twice(m)) < 30 ){
    printf("BMI = %f / %f * %f = %f 判定  肥満\n ", n, twice(m), twice(m), n / (twice(m) * twice(m))); // nは体重 mは身長
  }else{
    printf("BMI = %f / %f * %f = %f 判定　高度肥満\n ", n, twice(m), twice(m), n / (twice(m) * twice(m))); // nは体重 mは身長
  }
  return 0;
}
float twice(float x) // twice の本体
{
  float y;
  y = x / 100;
  return y;
  } 

