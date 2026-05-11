#include<stdio.h>
float bmi(float x , int y);

int main()
{
  int w;               /* w＝体重 */
  float b,h ;            /* h=身長 */

  printf("体重を入力してください(kg): ");  
  scanf("%d", &w);
  printf("身長を入力してください(m): ");
  scanf("%f", &h);

  b = bmi(h,w);     /*bはbmi*/
  if( b >=30 )
    printf("あなたのBMIは %f (高度肥満)", b);
  
  if( b >=25 && b <30)
    printf("あなたのBMIは %f (肥満)", b);

  if( b >=18.5 && b <25)
    printf("あなたのBMIは %f (標準)", b);
  
  if( b <18.5 )
    printf("あなたのBMIは %f (やせ)", b);

    return 0;
  
}

float bmi(float x, int y)
{
  float z;

  z = y/(x*x);

    return z;

}
