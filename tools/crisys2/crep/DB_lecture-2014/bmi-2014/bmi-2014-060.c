#include<stdio.h>

int main()
{
  int w;               /* w＝体重 */
  float h ;            /* h=身長 */

  printf("体重を入力してください(kg): ");  
  scanf("%d", &w);
  printf("身長を入力してください(m): ");
  scanf("%f", &h);

  printf("あなたのBMIは %f", w/(h*h));
  
  return 0;
  

}

