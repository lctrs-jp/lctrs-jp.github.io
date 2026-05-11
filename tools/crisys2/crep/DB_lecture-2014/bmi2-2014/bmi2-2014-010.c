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

  if(bmi >= 30)
{
    printf("あなたは高度肥満に分類されます\n");
}else{
    if(bmi >= 25)
      {
	printf("あなたは肥満に分類されます\n");
      }else{
      if(bmi >= 18.5)
	{
	  printf("あなたのBMIは正常値です\n");
	}else{
	printf("あなたは痩せです\n");
      }}}
  return 0;
}
