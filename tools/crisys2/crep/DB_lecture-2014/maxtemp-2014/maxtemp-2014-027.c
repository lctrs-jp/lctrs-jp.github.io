#include <stdio.h>
#include <math.h>


int main(void)
{
  double temp[7],  min, max, sum, avg, sumv, v, s, m,t;
  int num = 7;
  int i,a,b,j,k;

  
  for (i = 0; i < num; i++) {
    printf("%d 日目の最高気温を入力してください: ", i+1);
    scanf("%lf", &temp[i]);
  }


  /* 最大値と最小値を求める */
  min = 200.0;  /* minとmaxを初期化 */
  max = 0.0;
  for (i = 0; i < num; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最小値: %lf\n", min);
  printf("最大値: %lf\n", max);


  /* 平均を求める */
  sum = 0.0;
  for (i = 0; i < num; i++)
  sum = sum + temp[i];
  avg = sum / num;

  printf("平均: %lf\n", avg);


  /* 分散を求める */
  sumv = 0.0;
  for (i = 0; i < num; i++)
  sumv = sumv + (temp[i] - avg) * (temp[i] - avg);
  v = sumv / num;

  printf("分散: %lf\n", v);


  /* 標準偏差を求める */
  s = sqrt(v);

  printf("標準偏差; %lf\n", s);


  /* 中央値を求める */
  /* バブルソート */
  for (a = 1; a < num; ++a)
    for (b = num - 1; b >=a; --b) {
      if (temp[b - 1] > temp[b]) {
        t = temp[b - 1];
        temp[b - 1] = temp[b];
        temp[b] = t;
      }
  }

  if (num % 2 == 1) {
    j = (num - 1) / 2;
    m = temp[j];
    printf("中央値: %lf\n", m);
  }

  else {
    j = (num - 2) / 2;
    k = num / 2;
    m = (temp[j] + temp[k]) / 2;
    printf("中央値: %lf\n", m);
  }

  return 0;
}
  


  


