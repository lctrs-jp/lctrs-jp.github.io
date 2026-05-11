#include <stdio.h>
#include <math.h>

int main(void)
{
  int temp[7], i, j, k, min, max, avg, va, med;
  double sd;

  for (i = 0; i < 7; i++) {
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%d" , &temp[i]);
  }
    /*データを大きさでソートする*/
    for (i = 1; i < 7; i++)
      for (j = 7 - 1; j >= i; --j) {
        if (temp[j-1] > temp[j]) {
          k = temp[j - 1];
          temp[j - 1] = temp[j];
          temp[j] = k;
        }
      }


  /*最大値と最小値を求める*/
  min = 200;
  max = 0;
  for (i = 0; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }
  printf("最小最高気温: %d\n", min);
  printf("最大最高気温: %d\n", max);

  /*平均を求める*/
  avg = 0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均最高気温: %d\n", avg / 7);

  /*分散と標準偏差を求める*/
  va = 0;
  for (i = 0; i < 7; i++)
    va = va + (avg / 7 - temp[i]) * (avg / 7 - temp[i]);
  printf("分散: %d\n", va / 7);

  sd = sqrt(va / 7);
  printf("標準偏差: %lf\n", sd);

  /*中央値を求める*/
  printf("中央値: %d\n", temp[3]);

  return 0;
}
