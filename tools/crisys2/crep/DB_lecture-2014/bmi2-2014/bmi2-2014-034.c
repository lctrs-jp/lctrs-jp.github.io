#include <stdio.h>

int main()
{
  int w; 
  double h , b;


  printf("体重を入力（kg）" );
  scanf("%d", &w );

  printf("身長を入力（m）" );
  scanf("%lf", &h ); /*入力を求める*/

  b=(w/(h*h) );/*BMIを求める関数*/

  printf("体重（kg）%d\n " ,w );
  printf("身長（m）%lf\n" ,h );
  printf("BMI=%lf\n" , b );

  if(w/(h*h)<18.5)
    printf("あなたはやせです\n");
   else if(w/(h*h)<25)
     printf("あなたは標準です\n");
    else if(w/(h*h)<30)
      printf("あなたは肥満です\n");
        else 
	  printf("あなたは高度肥満です\n");
  /*グループ分け*/


  return 0;
}
