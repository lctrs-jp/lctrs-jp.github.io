#include <stdio.h>

int main()
{
  float m,h;
    printf("体重(kg)を入力してください: ");
    scanf("%f",&m);
    printf("身長(m)を入力してください: ") ;
    scanf("%f",&h);
    printf("BMI: %f",m/(h*h));
    return 0;
}
