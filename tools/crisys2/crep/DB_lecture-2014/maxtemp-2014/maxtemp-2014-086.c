#include <stdio.h>
#include <math.h>

int main(void)
{
  double temp[7], min, min2, min3, middle, max, avg, m, r, s;
  int i, k, l;

  for(i = 0; i < 7; i++){
    printf("%d 日目の最高気温を入力してください:", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for(i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %3.1lf\n", avg / 7);

  /* 分散を求める */
  m = avg / 7;
  r = 0;
  for(i = 0; i < 7; i++)
    r = r + pow((temp[i] - m), 2);
  printf("分散: %3.1lf\n", r / 7);

  /* 標準偏差を求める */
  printf("標準偏差: %3.1lf\n", sqrt(r / 7));

  /* 最高気温と最低気温を求める */
  min = 200;
  max = 0;
  for(i = 0; i < 7; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  /* 中間値を求める */
  for(k = 0; k < 6; k++){
    for(l = 0; l < 6-k; l++){
      if(temp[l+1] < temp[l]){
	s = temp[l];
	temp[l] = temp[l+1];
	temp[l+1] = s;
      }
    }
  }
  printf("中間値: %3.1lf\n", temp[3]);

  /* 最高気温と最低気温を表示する */

  printf("最低気温: %3.1lf\n", min);
  printf("最高気温: %3.1lf\n", max);

  return 0;
}
