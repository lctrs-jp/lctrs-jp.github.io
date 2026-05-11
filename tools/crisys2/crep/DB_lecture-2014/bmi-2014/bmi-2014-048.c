#include <stdio.h>

int main(void)
{
  double n, m;

  printf("身長を入力してください cm \n" );
  scanf("%lf", &m);

  printf("体重を入力してください kg \n" );
  scanf("%lf", &n);

  printf("あなたのBMIは・・・\n");
  printf("%lf\n" , n / ( m / 100  *  m / 100 ) );

  return 0;
}
