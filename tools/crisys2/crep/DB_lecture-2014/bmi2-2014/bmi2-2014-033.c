#include  <stdio.h>
float bmi(float x,float y);
float main()
{
 float  m,h,b;
    printf("体重(kg)を入力して下さい");    
    scanf("%f",&m);  
    printf("身長(m)を入力してください");
    scanf("%f",&h);
    b=bmi(m,h);

    if(b<18.5)
      {
  printf("BMI=%f\b",b);
  printf("  やせ");
      }
    else if(18.5<=b ,b<25)
      {
printf("BMI=%f\b",b);
	printf("  標準");
      }
    else if(25<=b,b<30)
      {
      printf("BMI=%f\b",b);
      printf("  肥満");
      }
    else if(30<=b){
	  printf("BMI=%f\b",b);
	  printf("  高度肥満");}
 	   return 0;

}

float bmi(float x,float y)
{
  float z;
  z=x/y/y;
  return z;
}
