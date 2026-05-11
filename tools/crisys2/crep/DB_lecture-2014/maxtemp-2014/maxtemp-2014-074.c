#include <stdio.h>
#include <math.h>

int main(void)
{
  float temp[7], min, max, avg, dev, n;
  int i, s, days = 7;
    

  for (i = 0; i < days; i++) {
    printf("%d 日目の最高気温を入力してください： ", i + 1 );
    scanf("%f", &temp[i]);
  } 

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n", avg / days);

  /* 最低気温と最高気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("週間の最高気温の最少値: %f\n", min);
  printf("週間の最高気温の最大値: %f\n", max);

  /* 標準偏差を求める */
  dev = 0;
  for (i = 0; i < days; i++)
    dev = dev + (temp[i] - avg / days) * (temp[i] - avg / days);
  printf("最高気温の標準偏差: %f\n", sqrt (dev / days));

  /* 分散を求める */
  printf("最高気温の分散: %f\n", dev / days);

  /* 最高気温を順番に並べる */
  for (i = 1; i < days; ++i)
    for (s = days - 1; s >= i; --s) {
      if (temp[s - 1] > temp[s] ) { 
	n = temp[s - 1];
	temp[s - 1] = temp[s];
	temp[s] = n;
      }
    }
  /* 中央値（4番目の数字）を表示 */


  printf("最高気温の中央値: %f\n", temp[3]);
 
 return 0;
}

 
