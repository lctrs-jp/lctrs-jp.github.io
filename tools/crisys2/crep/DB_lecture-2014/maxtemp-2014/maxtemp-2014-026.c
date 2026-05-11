#include <stdio.h>
#include <math.h>

int main()
{
  int i;
  double temp[7], min, max, avg, var;
  for (i = 0; i < 7; i++) {
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0.0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %lf\n", avg / 7);

  /* 最高気温と最低気温を求める */
  min = 200.0; /* minとmaxを初期化 */
  max = 0.0;
  for (i = 0; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %lf\n", min);
  printf("最高気温: %lf\n", max);

  /* 標準偏差と分散を求める */
  var = 0;
  for (i = 0; i < 7; i++)
    var = var + (temp[i] - avg / 7) * (temp[i] - avg / 7);
  printf("分散: %lf\n", var / 7);
  printf("標準偏差: %lf\n", sqrt(var / 7) );

  /* 中間値を求める */
  int a,b;
  double t;

  for (a = 1; a < 7; ++a)
    for (b = 6; b >= a; --b) {
      if (temp[b - 1] > temp[b]) {
        t = temp[b - 1];
        temp[b - 1] = temp[b];
        temp[b] = t;
      }
    }

      printf("中間値: %lf\n", temp[3]);
  return 0;
}
