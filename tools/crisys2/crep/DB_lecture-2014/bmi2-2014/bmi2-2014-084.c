#include <stdio.h>

void user();

int main()
{
  float m,h;
  user();
  scanf("%f", &m);
  printf("身長？(m): ");
  scanf("%f", &h);
 
  if( m/(h*h) >= 25 )
    printf("BMI: %f (肥満)", m/(h*h) );

  else if( m/(h*h) < 18.5 )
    printf("BMI: %f (やせ)", m/(h*h) );

  else
    printf("BMI: %f (正常)", m/(h*h) );
  return 0;
}

void user()
{
  printf("体重？(kg): ");
}
