#include <stdio.h>
#include<math.h>

float main(void)
{
  int i, b;
  float temp[7], min, max, avg, hyou, t;
  float days;

  days = 7;

  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
}

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];

  /* 最高気温と最低気温を求める */
  min = 200;   /* minとmaxの初期化 */
  max = 0;
  for (i = 0; i < days; i++){
    if(min >= temp[i])
      min = temp[i];
    if(max <= temp[i])
      max = temp[i];
  }


  /* 標準偏差の求め方 */
  hyou = 0;
  for(i = 0; i < days; i++){
    hyou = hyou + (temp[i] - avg/days)*(temp[i] - avg/days);
  }

  for(i = 0; i < days; ++i){
    for(b = days-1; b >= i; --b){
      if(temp[b-1]>temp[b]){
	t = temp[b-1];
	temp[b-1] = temp[b];
	temp[b] = t;
      }
    }
  }


  printf("標準偏差: %f\n", sqrt(hyou / days));
  printf("分散: %f\n", hyou / days);
  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);
  printf ("平均気温: %f\n", avg / days);
  printf("中間値: %f\n", temp[3]);

  return 0;
}
