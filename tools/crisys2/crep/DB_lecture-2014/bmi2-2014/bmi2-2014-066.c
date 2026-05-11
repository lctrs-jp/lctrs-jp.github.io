//BMI計算・判定プログラム
//20141016 

#include <stdio.h>

//関数bmiのプロトタイプ宣言
float bmi(float m , float h); 

int main()
{
   float m;  /*体重の変数*/
   float h;  /*身長の変数*/

   printf("-----------------------------------\n\n\n");
   printf("BMIを計算します\n\n");

   //体重の入力
   printf("体重(kg)を入力してください\n");
   scanf("%f" , &m ); 

   //負の値を拒否する
   for(; m < 0 ;){
     printf("体重(kg)を正の値で入力してください\n");
     scanf("%f" , &m );
   }
  
   //身長の入力
   printf("身長(m)を入力してください\n");
   scanf("%f" , &h ); 

   //BMI別の判定を出力
   if( bmi(m , h) < 18.5){
     printf("\nあなたのBMIは %f (やせ)です\n\n", bmi(m , h) );
     printf("-----------------------------------\n\n\n");
    }

   else if( bmi(m , h) >= 18.5 && bmi(m , h) < 25){
     printf("\nあなたのBMIは %f (標準)です\n\n", bmi(m , h) );
     printf("-----------------------------------\n\n\n");
    }

   else if( bmi(m , h) >= 25 && bmi(m , h) < 30){
     printf("\nあなたのBMIは %f (肥満)です\n\n", bmi(m , h) );
     printf("-----------------------------------\n\n\n");
    }
                                              
   else{
     printf("\nあなたのBMIは %f (高度肥満)です\n\n" , bmi(m , h) );
     printf("-----------------------------------\n\n\n");
    }  

  return 0;

}


//bmi関数の本体
float bmi(float m , float h) 
{
  return m / (h * h);
} 
