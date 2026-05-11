#include <stdio.h>
  int main()

  {
    double h;
    double w;
    double b;
  printf("身長を入力してください");
  scanf("%lf", &h);
  
    printf("体重を入力してください");
    scanf("%lf", &w);
    
    b=w/(h*h);
    printf("BMIは" );
    printf("%lf",b);
    return 0;
}

