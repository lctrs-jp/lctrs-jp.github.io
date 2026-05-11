#include <stdio.h>

void bmijudge(double bmi);

int main()
{
  //変数の宣言
  double height;
  int weight;

  //入力
  printf("身長は?(mで) ");
  scanf("%lf",&height);
  printf("体重は?(kgで) ");
  scanf("%d",&weight);
  
  bmijudge(weight/height/height);

  return 0;
}

void bmijudge(double bmi)
{
  printf("BMI=%lf\n判定 ",bmi);

  if(bmi<18.5)
  {
    printf("やせ");
  }
  else if(bmi<25)
  {
    printf("標準");
  }
  else if(bmi<30)
  {
    printf("肥満");
  }
  else
  {
    printf("高度肥満");
  }
  printf("\n");
  return;
}
