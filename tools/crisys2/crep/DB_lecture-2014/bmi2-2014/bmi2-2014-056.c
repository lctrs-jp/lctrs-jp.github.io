#include <stdio.h>

int bmi()/*bmiの計算*/
{
  double w,h,bmi;/* w 体重 h 身長 bmi そのまんま */
  printf("体重を入力して下さい(kg)");
    scanf("%lf", &w );
  printf("身長をお教え下さい(m)");
    scanf("%lf", &h );
  
    return w/(h*h);}/*bmiの計算*/
int main()/*分類*/
{
  double a;

  a = bmi();
  printf("%lf\n", a);
 if(a <18.5 )    
	  printf ("やせ\n");
   else  if(a < 25 )  
        printf("標準\n");
   else  if(a < 30)  
        printf("肥満\n") ; 
    else  
        printf("高度肥満\n");
          
  return 0;
}

  
