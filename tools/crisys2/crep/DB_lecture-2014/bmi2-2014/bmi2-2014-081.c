
#include <stdio.h>



float BMI(float n,float m);
int main()
{
  float n;/*体重(kg)*/
  float m;/*身長(m)*/
  printf("体重を入力してください（例）61.4kg → 61.4:");
  scanf("%f", &n );
  printf("身長を入力してください（例）181.4cm → 1.814：");
  scanf("%f", &m);
  printf("%f\n", BMI(n,m));
if(BMI(n,m)>=30)
  printf("高度肥満です。医療機関で受診しましょう。");
    else if (BMI(n,m)>=25)
      printf("肥満です。食生活に気をつけましょう。");
	  else if (BMI(n,m)>=18.5)
	    printf("標準です。その体型を維持しましょう。");
	    else
	      printf("痩せです。もっと栄養を摂取しましょう。");

  
  return 0;
}

float BMI(float n,float m)
{
  float bmi;
  bmi=n/(m*m);
  return bmi;
}
