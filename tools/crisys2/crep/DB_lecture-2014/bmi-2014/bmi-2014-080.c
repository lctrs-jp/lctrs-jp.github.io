
#include <stdio.h>
float BMI(int n,float m);
int main()
{
  int n;
  float m;
  scanf("%d %f", &n ,&m );
  printf("%f\n", BMI(n,m));
  
  return 0;
}

float BMI(int n,float m)
{
  float bmi;
  bmi=n/(m*m);
  return bmi;
}
