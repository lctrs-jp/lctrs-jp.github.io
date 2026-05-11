#include <stdio.h>

int main(void)
{
  double temp[6];
  double min, max, avg, ss, t;
  int days = 7;
  int i, j, k;

  //printf("月の日数は? ");
  //scanf("%d", &days);

  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++){
    avg = avg + temp[i];
  }
  printf("平均: %lf\n", avg / days);
  
  /* 最高気温と最低気温を求める */
  min = 50;  
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低: %lf\n", min);
  printf("最高: %lf\n", max);

  /*分散を求める*/
  ss = 0;
  for(i = 0; i < days; i++){
    ss = ss + (temp[i] - avg/days) * (temp[i] - avg/days);
  }
  printf("標準偏差: %lf\n", sqrt(ss/days));
  printf("分散:%lf\n", ss/days);

  /*中央値を求める*/
  for (i = 1; i < days; ++i)
    for (j = days - 1; j >= i; --j) {
      if (temp[j - 1] > temp[j]) {
	t = temp[j - 1];
	temp[j - 1] = temp[j];
	temp[j] = t;
      }
    }
  printf(" 中央値: %lf\n", temp[3]);
  return 0;
}
