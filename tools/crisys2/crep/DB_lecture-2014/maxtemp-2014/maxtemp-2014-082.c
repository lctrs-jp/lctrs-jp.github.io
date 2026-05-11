#include <stdio.h>
#include <math.h>

int main(void)
{
  double temp[7], min, max, avg;
  int days = 7, i;
  double a,b[7],c,d;

  /* 最高気温の入力 */
  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください。：", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 最高気温の最大値を求める */
  max = -50;
  for (i=0; i < days; i++) {
    if (max < temp[i])
      max = temp[i];
}
  printf("最大値：%lf\n", max);

  /* 最高気温の最低値を求める */
  min = 100;
  for (i=0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
  }
  printf("最小値：%lf\n", min);

  /* 最高気温の平均値を求める */
  avg = 0;
  for (i=0; i < days; i++)
    avg = avg + temp[i];
  a = avg / days;
  printf("平均値：%lf\n",  a);

  /* 分散・標準偏差の計算 */
  c=0;
  for(i=0; i < days; i++) {
    b[i] = (temp[i] - a) * (temp[i] - a);
    c = c + b[i];
  }

  printf("分散：%lf\n標準偏差：%lf\n", c / days, sqrt(c / days));

  /* 中央値(メディアン)の計算 */
  int j,check;
  double x;
    for (i=0; i<7; i++) {
      min = 100;
      for (j=i; j<7; j++) {
	if (temp[j] < min) {
	  min = temp[j];
	  check = j;
	}
      }
  x = temp[i];
  temp[i] = min;
  temp[check] = x;
    }

  printf("中央値：%lf\n", temp[3]);

  return 0;
}
