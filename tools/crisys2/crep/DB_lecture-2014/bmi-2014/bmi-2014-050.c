#include <stdio.h>

int main()
{
  float a, b, c;

  a = 1.80;
  b = 60;
  c = b / (a * a);
  
    printf("身長を入力してください:");
    scanf("%f",&a);
    printf("体重を入力してください:");
    scanf("%f",&b);
    printf("あなたのｂｍiは:%f",c);
    return 0;
}     
