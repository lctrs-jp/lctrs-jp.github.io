#include <stdio.h>

double cast();

int main()
{
  double BMI;
  BMI = cast();

  if(BMI < 18.50)
    printf("Your BMI is : %4.2lf(thin)\n", BMI);
  else
    if((BMI >= 18.50) && (BMI < 25.00))
      printf("Your BMI is : %4.2lf(Ordinary)\n", BMI);
    else
      if((BMI >= 25.00) && ((BMI < 30.00))
        printf("Your BMI is : %4.2lf(fat)\n", BMI);
      else
        printf("Your BMI is : %4.2lf(very fat)\n", BMI);

  return 0;
}

double cast()
{
  double l,w;

  printf("How tall are you?(cm):");
  scanf("%lf", &l);
  printf("How much do you weigh?(kg):");
  scanf("%lf", &w);

  return (( w * 10000 ) / ( l * l ));
}
