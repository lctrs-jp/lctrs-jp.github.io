#include <stdio.h>

/*2014年計算機プログラミング基礎及び演習のBMIプログラム*/
float BMI();/*プロトタイプ宣言*/

int main()  
 
{
  BMI(); /*BMI関数の呼び出し*/
}

float BMI() /*BMI関数の定義*/


{ 
  float height , weight; /*身長と体重の変数*/

  printf( "BMIの計算を行います\n"
          "身長を入力(m)");
  scanf("%f" , &height);

  printf("体重を入力(kg)");
  scanf("%f" , &weight);

  if(weight / (height * height) >= 25 && weight / (height * height) < 30 )
    printf("BMIは%.2fで肥満です\n", weight / (height * height)); /* BMIを出力*/
  if(weight / ( height * height ) >=30)
    printf("BMIは%.2fで高度肥満です\n", weight / (height * height)); /* BMIを出力*/
  if(weight / (height * height) >=  18.5 &&  weight/(height * height) < 25)
     printf("BMIは%.2fで標準です\n", weight / (height * height)); /* BMIを出力*/
  if(weight / (height * height) > 0 && weight / (height * height) <  18.5 )
    printf("BMIは%.2fでやせです\n", weight / (height * height)); /* BMIを出力*/
  

 return 0;
}  
