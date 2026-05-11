//BMI計算プログラム
//2014/10/16 ****

#include <stdio.h>

int main()
{
   float m;  /*体重の変数*/
   float h;  /*身長の変数*/
   
   printf("-----------------------------------\n\n\n");
   printf("BMIを計算します\n\n");
  
   printf("体重(kg)を入力してください\n");
   scanf("%f" , &m );
  
   printf("身長(m)を入力してください\n");
   scanf("%f" , &h );

   //BMI=体重 / (身長^2)
   printf("\nあなたのBMIは %f です\n\n\n" , m / ( h * h ) );
   printf("-----------------------------------\n");

   return 0;

}
