#include <stdio.h>

float BMI(float h,float w);

int main()
{

  float weight=0,height=0,bmi;
  printf("\nBMIを算出します\n");
  do{
  printf("\nあなたの身長（㎝）を入力してください。\n");
  scanf("%f",&height);		/* 身長を入力してもらう */
  if (height <=0)
    printf("正の数値を入力してください。\n");

  }while(height<=0);

  do {
  printf("あなたの体重（㎏）を入力してください。\n");
  scanf("%f",&weight);		/* 体重を入力してもらう */
  if (height <=0)
    printf("正の数値を入力してください。\n");

  }while(weight <=0);
  //BMI = 10000 * weight / ( height * height );	/* BMIを計算する */

 printf("\nあなたのデータ\n"); /* 身長、体重、BMIを表示する */
 printf("身長\t%f(cm)\n",height);
 printf("体重\t%f(kg)\n",weight);
 printf("BMI\t%f\n",BMI(height,weight));
 bmi = BMI(height,weight);
 


 printf("\nありがとうございました。\n\n");

 return 0;
}

float BMI(float h,float w)
{
  return 10000 * w  / ( h * h ) ;
}
