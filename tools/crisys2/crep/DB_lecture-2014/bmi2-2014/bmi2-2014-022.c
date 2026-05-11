#include <stdio.h>

int fanc1(double h);
int func2(double w);
  int main()
{
  double b,h,w;
  func1();
  func2();

  b = h / ( w * w );
　
 if (b<18.5)
    printf("あなたのBMIは%lf(やせ)",b);

 if ( 18.5<=b&&b<25)
    printf("あなたのBMIは%lf(標準)",b);
 if (25<=b&&b<30) 
    printf("あなたのBMIは%lf(肥満)",b);
 if (30<=b)
    printf("あなたのBMIは%lf(高度肥満)",b);

   return 0;
}

int fanc1(double h)
{
  printf("身長を入力してください[m]");
  scanf("%lf",&h );
  return h;
}

int func2(double w)
{ 
  printf("体重を入力してください[kg]");
  scanf("%lf",&w);
  return w;
}
