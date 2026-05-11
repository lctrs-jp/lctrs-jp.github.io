#include<stdio.h>

int main()
{
  double w,h;

  printf("体重を入れてください：");
  scanf("%lf",&w);
  printf("身長を入れてください：");
  scanf("%lf",&h);

  printf("BMIは%lfです",w/(h*h));

  return 0;
}