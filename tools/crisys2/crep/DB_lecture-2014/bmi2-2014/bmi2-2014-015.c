#include <stdio.h>

int main (void)
{
  double  n , w ;

  printf("身長を入力してください: ");
  scanf("%lf",  &n );
  printf("体重を入力してください: ");
  scanf("%lf",  &w );

  if( w/(n*n)>=30) 
     printf("BMIは %f（高度肥満です。このままだと早死にします）", w / n / n );

  if(25< w/(n*n) < 30)
    printf("BMIは %f（肥満です。早く痩せましょう）", w / n / n );

  if(18.5<  w/(n*n) < 25)
    printf("BMIは %f（標準です。素晴らしい！）", w / n / n );

  if(w/(n*n) < 18.5)
    printf("BMIは %f (やせています。もっと食べましょう) ", w / n / n );

  return 0;
}
