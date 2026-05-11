#include <stdio.h>

int main()
{
  float w; /* 体重[㎏]を表す変数*/
  float h; /*身長[ｍ]を表す変数*/
  
  /* BMI指数を計算する*/
  printf("あなたの体重[㎏]を入力してください:");
  scanf("%f", &w);
  printf("あなたの身長[ｍ]を入力してください:");
  scanf("%f", &h);

  if( w/h/h >=30 )
    printf("あなたのBMI指数は%fです(高度肥満)\n", w/h/h);
  else
    if( w/h/h >=25 & w/h/h <30 )
    printf("あなたのBMI指数は%fです(肥満)\n", w/h/h);
    else
      if( w/h/h >=18.5 & w/h/h <25 )
	printf("あなたのBMI指数は%fです(標準)\n", w/h/h);
    else
      if( w/h/h < 18.5 )
	printf("あなたのBMI指数は%fです(やせ)\n", w/h/h);

  return 0;
}
