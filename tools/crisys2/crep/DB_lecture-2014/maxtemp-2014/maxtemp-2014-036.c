#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, a, t;
  float temp[7], min, max, avg, x, sum;

  for (i = 0; i < 7; i++) {
    printf("%d 日目の最高気温を入力してください; ", i + 1);
    scanf("%f", &temp[i]);
  }

  /* 平均、分散、標準偏差を求める */
  sum = 0;
  for (i = 0; i < 7; i++) {
    sum = sum + temp[i];
  }

  avg = sum / 7;

  x = 0;
  for (i = 0; i < 7; i++) {
    x = x + ( temp[i] - avg ) * ( temp[i] - avg );
  }

  
  printf("平均気温: %f\n", avg);
  printf("分散: %f\n", x/7);
  printf("標準偏差: %f\n", sqrt(x/7));

  /* 最高気温と最低気温を求める */
  min = 200;   /* minとmaxを初期化 */
  max = 0;
  for (i = 1; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);

  /* バブルソートを利用して中央値を求める */
  for (i = 1; i < 7; ++i)
    for (a = 7 - 1; a >= i; --a) {
      if (temp[a - 1] > temp[a]) {
        t = temp[a - 1];
        temp[a - 1] = temp[a];
        temp[a] = t;
	  }
    }

  printf("中央値: %f\n", temp[3]);


  return 0;
}
