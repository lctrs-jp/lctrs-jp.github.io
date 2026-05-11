#include <stdio.h>

int main()
{
  float weight; // 自分の体重
  float height; // 自分の身長
  float bmi;
  
//身長と体重を得る
  printf(" 体重を入力してください: ");
    scanf("%f", &weight);
    printf(" 身長を入力してください: ");
    scanf("%f", &height);
    //BMIを得る
    bmi = weight /(height * height);  
printf("BMIは %f", bmi);

  return 0;
}
