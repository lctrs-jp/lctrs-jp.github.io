#include <stdio.h>

int main()
{
  int n; 
  float m; 
  float bmi;

    printf("体重\n");
    scanf("%d", &n);
    printf("身長\n");
    scanf("%f", &m);
    if(n/(m*m)<18.5){
      printf("bmi=%f\n",n/(m*m) ) ;
      printf("やせ型です");
      }
    if(n/(m*m)>=18.5&n/(m*m)<25){
      printf("bmi=%f\n",n/(m*m));
      printf("標準です");
    }
    if(n/(m*m)>=25&n/(m*m)<30){
      printf("bmi=%f\n",n/(m*m));
      printf("肥満です");
    }
    else{
      printf("bmi=%f\n",n/(m*m));
      printf("高度肥満です");
    }
   return 0;
}
