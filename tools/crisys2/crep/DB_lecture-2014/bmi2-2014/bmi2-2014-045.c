#include<stdio.h>
double bmi(double x, double y);

int main()
{
  double x, y;

 do{
  printf("身長(m):");
  scanf("%lf" ,&x);
   if (x <= 0)
  printf("不正な入力です\n");
   }while (x <= 0);

 do{
  printf("体重(kg):");
  scanf("%lf" , &y);
   if (y <= 0)
  printf("不正な入力です\n");
    }while (y <= 0);

printf("BMI:%lf\n",bmi(x,y) );
if(bmi(x,y)< 18.5)
  printf("やせ気味\n");
 else
   if(bmi(x,y)<25)
     printf("標準です\n");
   else
     if(bmi(x,y)<30)
       printf("肥満です\n");
     else
       printf("高度肥満です\n");

return 0;
}

double bmi(double x,double y)
{
double z;
z = y/(x*x);
return z;
}
