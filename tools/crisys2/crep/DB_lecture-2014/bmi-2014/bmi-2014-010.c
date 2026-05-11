#include <stdio.h>

int main()
{
  float w, h, bmi ;

  printf("あなたの体重を入力してください[kg]\n"); //体重の入力
  scanf("%f", &w);

  printf("あなたの身長を入力してください[m]\n"); //身長の入力
  scanf("%f", &h);

  bmi=w/(h*h);
  printf("あなたのBMIは %f です\n", bmi); //bmiの算出

  return 0;
}
