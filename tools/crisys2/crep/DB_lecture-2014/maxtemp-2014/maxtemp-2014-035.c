#include <stdio.h>
#include <math.h>

int main(void)
{
  float temp[31], min, max, avg, sum1;
  int days = 7, i, j;
  float median, t;
  /*printf("月の日数は？");        *
   * scanf("%d", &days);           *
   *１週間の平均なので７で固定する */
  /* for (i = 0; i < days; i++){ */
  /*   printf("%d日目の最高気温を入力してください", i + 1); */
  /*   scanf("%f", &temp[i]); */
  /* } */
  /* 名古屋の決まった日の最高気温なので入力は省く */

  /* 10月1-7日の最高気温 */
  /* http://weather.goo.ne.jp/past/9999/12/636/ *
   * の物を参照した                             */

  temp[0] = 30.0;
  temp[1] = 25.9;
  temp[2] = 28.8;
  temp[3] = 26.3;
  temp[4] = 21.5;
  temp[5] = 27.9;
  temp[6] = 25.3;

  /* 平均を出す */
  avg = 0;
  for (i = 0; i < days; i++){
    avg = avg + temp[i];
  }
  printf("平均値:%f\n", avg / days);
  

  /* 最小値、最高値をだす */
  min = 200;
  max = 0;
  
  for (i = 0; i < days; i++){
    if (min > temp[i]){
      min = temp[i];
    }
    if (max < temp[i]){
      max = temp[i];
    }
  }
  printf("最小値:%f\n", min);
  printf("最高値:%f\n", max);
  
  /* 分散を求める             *
   * o^2 = 1/N NZi=0 (xi - m)^2 */

  sum1 = 0;
  for (i = 0; i < days; i++){
    sum1 = sum1 + (temp[i] - avg / days) * (temp[i] - avg / days) ;
  }
  printf("分散:%f\n", sum1 / days);

  /* 標準偏差を求める 
   * root(o^2)        */

  printf("標準偏差:%f\n", sqrt(sum1 / days));

  /* 中央値を求める */

  for (i = 1; i < days; ++i)  

    for (j = days - 1; j >= i; --j) {

      /* 隣接する要素を比較する */ if (temp[j - 1] > temp[j]) {

	/* 要素を交換する */
	t = temp[j - 1]; 

	temp[j - 1] = temp[j]; 

	temp[j] = t;

      } } 

  median = temp[3];

  printf("中央値:%f\n", median);
  return 0;
}
