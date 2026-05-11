//bmi.cを改良して肥満度も表示するようにしたプログラム

#include <stdio.h>

int check(float bmi);

int main()
{
  float height, weight;
  float bmi;

  printf("身長(cm)、体重(kg)を半角数字で入力してください。\n");

  while(1){
    printf("身長 =");	scanf("%f", &height);
    printf("体重 =");	scanf("%f", &weight);

//負の数が入力されたら再入力させる
    if (height < 0 || weight < 0){
      printf("正の整数で入力してください。\n");
      continue;
    }

    break;
  }

  bmi = weight / ((height / 100) * (height / 100));
  printf("BMI = %.2f", bmi);
  switch (check(bmi)){
  case 1:
    printf("（やせ）");
    break;
  case 2:
    printf("（普通）");
    break;
  case 3:
    printf("（肥満）");
    break;
  case 4:
    printf("（高度肥満）");
    break;
  }
  printf("\n");

  return 0;
}

//BMI値から肥満指数を返す関数
int check(float bmi)
{
  int bmi_index;

  if (bmi < 18.5){
    bmi_index = 1;
  }else if (18.5 <= bmi && bmi < 25){
    bmi_index = 2;
  }else if (25 <= bmi && bmi < 30){
    bmi_index = 3;
  }else{
    bmi_index = 4;
  }

  return bmi_index;
}
