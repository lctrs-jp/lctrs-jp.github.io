#include <stdio.h>

int main()
{
  double h,w;

  while(w<=0||h<=0){
    printf("体重");
    scanf("%lf", &w );
    printf("身長");
    scanf("%lf", &h );
  }

    if(25<=w/(h*h)&&w/(h*h)<30)
      printf("BMI=%lf (肥満)\n",w/(h*h));
    else if(w/(h*h)<18.5)
      printf("BMI=%lf (やせ)\n",w/(h*h));
    else if(18.5<=w/(h*h)&&w/(h*h)<25)
      printf("BMI=%lf (標準)\n",w/(h*h));
    else if(w/(h*h)>=30)
      printf("BMI=%lf (高度肥満)\n",w/(h*h));
    return 0;
}
