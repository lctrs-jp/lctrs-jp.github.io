#include <stdio.h>
#include <math.h>

int main()
{
  float temp[7], min, max, avg, m, S, s, t;
  int days, i, j;

  days = 7;

  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n", avg / days);
  /* 最大値と最小値を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  printf("最小値: %f\n", min);
  printf("最大値: %f\n", max);

  /*  分散を求める　*/

  m = avg / days;
  S = 0;
  for (i = 0; i < days; i++)
    S = S + (temp[i] - m) * (temp[i] - m);
      printf("分散: %f\n", S / days);

  /* 標準偏差を求める */

      s = S / days;
    printf("標準偏差: %f\n", sqrt(s));
    f[j - 1] > temp[j]) {
  t = temp[j - 1];
  temp[j - 1] = temp[j];
  temp[j] = t;
}
}

printf("中間値: %f\n", temp[3]);

return 0;
}

  /* 中央値を求める */

    for (i = 1; i < days; ++i)
      for (j = days - 1; j >= i; --j)  {
        if (temp[j - 1] > temp[j]) {
          t = temp[j - 1];
          temp[j - 1] = temp[j];
          temp[j] = t;
        }
      }

    printf("中間値: %f\n", temp[3]);

 return 0;
}
