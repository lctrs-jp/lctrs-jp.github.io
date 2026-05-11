#include <stdio.h>

int main()

{
  double a,b;

  printf("貴様の身長を教えてもらおうか");
  scanf("%lf",&a);
  printf("あなたの体重を教えてくださるかしら");
  scanf("%lf",&b);
  printf("BMI = %lf" , b / (a * a));
  return 0;
}
