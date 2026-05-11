#include <stdio.h>

int main()
{
  float h, w, b;
    b = w/(h*h);

//情報を入力してもらう
  do
  {printf("身長を入力してください(m)\n");
   scanf("%f", &h );
   printf("体重を入力してください(kg)\n");
   scanf("%f", &w );
  }while( h < 0 || w < 0 );

//BMIの計算結果を表示
  printf("BMI=%1f\n", w/(h*h) );


//計算判定
  if( w/(h*h) < 18.5 )
      printf("あなたはやせています\n");
    else
      {if( w/(h*h) < 25 )
	  printf("あなたは標準です\n");
       else
	 if( w/(h*h) < 30 )
	   printf("あなたは肥満です\n");
	 else
	   printf("あなたは高度肥満です\n");
      }

    return 0;
}
