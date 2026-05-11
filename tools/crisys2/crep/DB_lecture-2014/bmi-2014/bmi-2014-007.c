//身長（cm）、体重（kg）を入力しBMIを表示するプログラム

#include <stdio.h>

int main()
{
  int height;
  int weight;
  float bmi;

  printf("身長（cm）、体重（kg）を半角数字の整数で入力してください。\n");
  printf("身長 =");		//身長入力
  scanf("%d", &height);
  printf("体重 =");		//体重入力
  scanf("%d", &weight);
  bmi = weight / ((height/100.0) * (height/100.0));
  printf("BMI  = %.2f\n", bmi);	//小数点以下２桁までBMI表示
  return 0;
}
