#include <stdio.h>
float func1(float x);

int main(void)
{
  float w,h,bmi;//w=体重,h=身長
  printf("体重を入力してください(kg):");
  scanf("%f", &w);
  printf("身長を入力してください(m):");
  scanf("%f", &h);

  bmi=w/(h*h);

  printf("あなたのBMIは%fです\n", bmi);
  func1(bmi);

  return 0;
}

float func1(float x)
{
  if (x < 18.5)
    printf("あなたは痩せています\n");
  else
    if((x >= 18.5) && (x < 25))
      printf("あなたは標準です\n");
    else
      if((x >= 25) && (x < 30))
	printf("あなたは肥満です\n");
      else
	if(x >= 30)
	  printf("あなたは高度肥満です\n");

  return 0;
}
