#include <stdio.h>

/*2014年計算機プログラミング基礎及び演習のBMIプログラム*/

int main()

{ 
  float height , weight; /*身長と体重の変数*/

  printf( "BMIの計算を行います\n"
          "身長を入力(m)");
  scanf("%f" , &height);

  printf("体重を入力(kg)");
  scanf("%f" , &weight);

  printf("BMIは%.2fです\n" , weight / ( height * height)); /*BMIの計算*/

 return 0;
}  
