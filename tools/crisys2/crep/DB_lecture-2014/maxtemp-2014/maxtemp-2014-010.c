#include <stdio.h>
#include <math.h>

int main(void)
{
  double t[7], min, max, avg, var, a, b;
  int days, i, j;

  for (i = 0; i < 7; i++) {
    printf("10月 %d 日の最高気温を入力してください", i + 1);
    scanf("%lf", &t[i]);
  }

  /*平均気温*/
  avg = 0;
  for ( i = 0; i < 7; i++)
    avg = avg + t[i];
  printf("平均気温 %lf\n", avg / 7 );
 
  /*最低気温 最高気温*/
  min = 200;
  max = 0;
  for ( i = 0; i < 7; i++) {
    if (min > t[i])
      min = t[i];
    if (max < t[i])
      max = t[i];
  }

  printf("最低気温 %lf\n", min);
  printf("最高気温 %lf\n", max);

  /*標準偏差 分散*/
  var = 0;
  avg = avg / 7;
  for ( i = 0; i < 7; i++ ){
    var = var + ( t[i] - avg ) * ( t[i] - avg );
  }
  var = var / 7;
  b = sqrt(var);
 
  printf("分散 %lf\n", var );

  printf("標準偏差 %lf\n", b );

  /*中央値*/
  a = 0;
  for( i = 0 ; i < 7 ; i++ ){
    for( j = 7 ; j >= i ; --j ){
      if(t[j-1] > t[j]){
	a = t[j-1];
        t[j-1] = t[j];
	t[j] = a;
      }
    }
  }

  printf("中央値 %lf\n", t[4] );
  
  return 0;
}
