#include <stdio.h>

void func1(int a , float b);//ユーザー定義関数

int main()
{
  int a; //体重(kg)を保持する変数
  float b;//身長(m)を保持する変数

 while( a <= 0){
   printf("Input your weight(kg) = ");
   scanf("%d" , &a);//体重を入力
 }

 while( b <= 0){
   printf("Input your height(m) = ");
   scanf("%f" , &b);//身長を入力
 }

 if(( a / (b*b) < 25) && (a / (b*b) >= 18.5 ))//標準を振り分け
   printf("BMI = %f (標準)\n" , a / (b*b) );//標準時のBMIを出力

 else

   if( a / (b*b) >= 30 )//高度肥満を振り分け
     printf("BMI = %f (高度肥満)\n" ,  a / (b*b) );//高度肥満を出力
   else
     func1(a , b);//肥満とやせを振り分け

 return 0;
}

void func1(int a , float b)//ユーザー定義関数の中身
{
   if( a / (b*b) < 18.5 )
     printf("BMI = %f (やせ)\n" , a / (b*b) );
   else
     printf("BMI = %f (肥満)\n" , a / (b*b) );
}
