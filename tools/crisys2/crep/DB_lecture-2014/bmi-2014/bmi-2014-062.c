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
    printf("bmi=%f\n",n/(m*m) ) ;
    return 0;
}
