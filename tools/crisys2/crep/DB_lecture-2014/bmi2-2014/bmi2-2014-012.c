#include<stdio.h>
int main()
{
  float w;
  float h;

  while(w <= 0 ){
    printf("Input your weight: ");
    scanf("%f",&w );
  }
  while(1){
	printf("Input your height: " );    
    scanf("%f",&h );
	if( h > 0 ) break;
  }
  if( w/h/h >= 30)
    printf("BMI = %f(高度肥満)\n",w/h/h);
 
 else
   if ( w/h/h >= 25)
     printf("BMI = %f(肥満)\n",w/h/h);
   else
     if (w/h/h >= 18.5)
       printf("BMI = %f(標準)\n",w/h/h);
     else
       printf("BMI = %f(痩せ)\n",w/h/h);

  return 0;
}
