#include <stdio.h>

int main()
{
  float h; /* 身長 */
  float w; /* 体重 */
  float BMI;
  printf("あなたの身長は(m)？");
  scanf("%f", &h);
  printf("あなたの体重は(kg)？");
  scanf("%f", &w);
  BMI = w / (h * h);
  printf("BMI = %f\n", BMI);
  return 0;
}