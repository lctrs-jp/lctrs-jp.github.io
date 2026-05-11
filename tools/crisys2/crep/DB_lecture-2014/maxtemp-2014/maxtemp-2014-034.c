#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, j;
  double temp[7], min ,max, avg, bunsan = 0;

  for(i = 0; i < 7; i++){
    printf("10月%d日の最高気温を入力してください: ", i+1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for(i = 0; i < 7; i++)
    avg = avg + temp[i];
  avg /= 7;
  printf("平均気温: %f\n", avg);

  /* 最高気温と最低気温を求める */
  min = 200;
  max = 0;
  for(i = 0; i < 7; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  /* 分散を求める */
    for(i = 0; i < 7; i++){
    bunsan = bunsan +  pow(temp[i] - avg, 2);
  }
   /* 中央値を求める */
  for(i = 0; i < 7; ++i){
    double t;
    for(j = 0; j < 7; ++j){
      if(temp[j] > temp[j+1]){
	t = temp[j];
	temp[j] = temp[j+1];
	temp[j+1] = t;
      }
    }
  }

  printf(" 最低値: %f\n", min);
  printf(" 最大値: %f\n", max);
  printf("標準偏差: %f\n", sqrt(bunsan / 7));
  printf(" 分散: %f\n", bunsan / 7);
  printf(" 中央値: %f\n", temp[4]);


  return 0;


}
