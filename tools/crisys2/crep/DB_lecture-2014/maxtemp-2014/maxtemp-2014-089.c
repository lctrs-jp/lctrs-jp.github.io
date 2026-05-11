#include <stdio.h>
#include <math.h>

int main(void)
{
  double temp[7], min, max, avg, sd, v, m; 
  int i, j; 
   for (i = 0; i < 7; i++) {
    printf("%d 日の正午の気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  avg = 0;
  for (i = 0; i< 7; i++) 
    avg = avg + temp[i];
  avg = avg / 7;
  printf("平均気温: %lf\n" ,avg);

  min = 200;
  max = 0;
  for (i = 0; i< 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %lf\n", min);
  printf("最高気温: %lf\n", max);

  sd = 0;
  for(i = 0; i < 7; i++)
    sd = sd + pow(temp[i] - avg, 2);
  sd = sd / 7; 
  v = sqrt(sd);
  printf("分散　　: %lf\n", sd);
  printf("標準偏差: %lf\n", v);

  for(i = 1; i < 7; ++i)
    for(j = 7 - 1; j >= i; --j){
      if(temp[j - 1] > temp[j]) {
	m = temp[j - 1];
	temp[j = 1] = temp[j];
	temp[j] = m;
      }
    }
  printf("中央値　: %lf\n", temp[3]);

 return  0;
}
