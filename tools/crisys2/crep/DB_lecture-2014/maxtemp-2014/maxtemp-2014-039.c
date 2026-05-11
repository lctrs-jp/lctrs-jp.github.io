#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, a, b;  
  double temp[7], min, max, avg,var, stdevp, t;

  for (i = 0; i < 7; i++) {
    printf("%d日目の最高気温を入力してください[℃]: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  
  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  /* 分散を求める */
  var = 0;
  for (i = 0; i < 7; i++) 
    var = var + ( temp[i] - avg / 7 )*( temp[i] - avg /7 );

  /* 標準偏差を求める */
  stdevp = sqrt( var / 7 );

  /*ここでバブルソートを使用して数値を整列させる */
  for (a = 1;  a < 7; ++a)
    for (b = 6; b >= a; --b) {
      /* 隣接する要素を比較する */
      if (temp[b - 1] > temp[b]) {
	/* 要素を交換する */
	t = temp[b - 1];
	temp[b - 1] = temp[b];
	temp[b] = t;
      }
    }

  printf("最高気温の最大値: %5.2f\n", max);
  printf("最高気温の最小値: %5.2f\n", min);
  printf("最高気温の平均: %5.2f\n", avg / 7 );
  printf("標準偏差: %5.2f\n", stdevp);
  printf("分散: %5.2f\n", var / 7 );
  printf("中間値: %5.2f\n", temp[3]);

  return 0;
}
