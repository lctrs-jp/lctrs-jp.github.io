#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, days;
  float temp[7], max, min, avg, hyoujun, bunsan, tyuukan;

  printf("一週間の最高気温について調べます\n");
  days = 7;

  for (i = 0; i < days; i++){
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  }

/* 最高気温と最低気温を求める */
 max = 0; /* maxとminを初期化 */
 min = 100;
 for (i = 0; i < days; i++){
   if (max < temp[i])
     max = temp[i];
   if (min > temp[i])
     min = temp[i];
 }

 printf("最高気温: %f\n", max);
 printf("最低気温: %f\n", min);

 /* 平均気温を求める */
 avg = 0;
 for (i = 0; i < days; i++){
   avg = avg + temp[i];
 }
 printf("平均気温: %f\n", avg / days);

 /* 分散を求める */
 bunsan = 0;
 for (i = 0; i < days; i++){
   bunsan = bunsan + (temp[i] - avg / days) * (temp[i] - avg / days);
 }
 printf("分散: %f\n", bunsan / days);

 /* 標準偏差を求める */
 hyoujun = sqrt( bunsan / days );
 printf("標準偏差: %f\n", hyoujun);

 /* 中間値を求める */
 tyuukan = temp[(i - 1) / 2];
 printf("中間値: %f\n", tyuukan);

 return 0;
}
