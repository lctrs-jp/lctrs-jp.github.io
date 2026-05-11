#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, j;
  double temp[7], max, min, sum;
  double avg, var, k;

  for (i = 0; i < 7 ; i++) {
    printf("%d日目の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  //最大値と最小値を求める
  min = 100;
  max = 0;
  for ( i = 0; i < 7; i++) {
    if( max < temp[i])
      max = temp[i];
    if( min > temp[i])
      min = temp[i];
  }

  printf("最大値: %lf\n", max);
  printf("最小値: %lf\n", min);

  //平均値を求める
  sum = 0; //sumを初期化
  for ( i = 0; i < 7; i++)
    sum = sum + temp[i];
  printf("平均値: %lf\n", sum / 7);

  //分散と標準偏差を求める
  avg = sum / 7;
  var = 0;
  for ( i =0; i < 7; i++)
    var = var + pow(temp[i] - avg, 2);
  printf("分散: %lf\n", var / (7 - 1));
  printf("標準偏差: %lf\n", sqrt(var / (7 - 1)));

  //バブルソートを行う
  for (j = 1; j < 7; j++)
    for ( i = 7 - 1; i >= j; i--) {
      if (temp[i - 1] > temp[i] ) {
        k = temp[i - 1];
        temp[i - 1] = temp[i];
        temp[i] = k;
      }
    }

  //中央値を求める
  printf("中央値: %lf\n", (temp[2] + temp[3]) / 2);

  return 0;
}
