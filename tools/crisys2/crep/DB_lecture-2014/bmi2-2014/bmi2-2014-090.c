#include <stdio.h>

int main()
{
  float h, w, BMI;
  printf("your height?");
  scanf("%f",&h);
  printf("your weight?");
  scanf("%f",&w);
  BMI = w /(h * h);
  
  if(BMI<18.5)
    {
      printf("BMI=%f\b",BMI);
      printf("skinny");
    }
  else if(18.5<=BMI ,BMI<25)
    {
    printf("BMI=%f\b",BMI);
      printf("ordinary");
    }
  else if(25<=BMI,BMI<30)
    {
      printf("BMI=%f\b",BMI);
      printf("obese");
    }
  else if(30<=BMI)
    {
      printf("BMI=%f\b",BMI);
      printf("high obese");
    }
  return 0;
}
