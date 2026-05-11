#include <stdio.h>

int bmiChecker(double BMI);

int main()
{
  double w=0; //weight
  double h=0; //height
  double bmi; //BMI
  int check; //Grade of BMI

  while(w<=0)
    {
      printf("Please imput your weight(kg).");
      scanf("%lf",&w);
    }
  while(h<=0)
    {
      printf("Please imput your height(m).");
      scanf("%lf",&h);
    }  

  bmi=w/(h*h);
  printf("あなたのBMIは%lfです。",bmi);
  check=bmiChecker(bmi);

  switch(check)
    {
      case 0:
	printf("あなたは（やせ）です。");
        break;
      case 1:
	printf("あなたは（標準）です。");
        break;
      case 2:
	printf("あなたは（肥満）です。");
        break;
      case 3:
	printf("あなたは（高度肥満）です。");
	break;
    }

  return 0;
}

int bmiChecker(double BMI)
{
  int CHECK;

    if(BMI<18.5)
      CHECK=0;
    else if(18.5<=BMI&&BMI<25)
      CHECK=1;
    else if(25<=BMI&&BMI<30)
      CHECK=2;
    else if(30<=BMI)
      CHECK=3;

  return CHECK;
}
