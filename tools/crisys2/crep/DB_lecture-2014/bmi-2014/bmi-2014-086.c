#include <stdio.h>

int main()
{
  double l, w, BMI;

  printf("How tall are you?(cm):");
  scanf("%lf", &l);
  printf("How much do you weigh?(kg):");
  scanf("%lf", &w);

  printf("Your BMI is : %4.2lf\n", BMI = w * 10000  / ( l * l ));

  return 0;
}
