#include <stdio.h>
#include <math.h>

int main(void)
{
  float temp[7], min, max, avg, bunsan, t;
  int i, j;

    for(i = 1; i <= 7; i++){
      printf("%d 日目の最高気温を入力してください；", i);
      scanf("%f", &temp[i-1]);
    }

  /*　平均を求める　*/
  avg = 0;
  for (i = 0; i <7; i++)
    avg = avg + temp[i];
  printf("最高気温の平均: %f\n", avg / 7);


  /*  最高気温最大値と最小値を求める　*/
 
  min = 200;
  max = 0;
  for (i = 0; i < 7; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }
  
  printf("最高気温の最小値： %f\n", min);
  printf("最高気温の最大値： %f\n", max);

  /* 分散を求める　*/
  bunsan = 0;
  for (i = 0; i < 7; i++)
    bunsan = bunsan + (temp[i] - avg / 7) * (temp[i] - avg / 7);
  printf("分散: %f\n", bunsan / 7);
 
  /* 標準偏差を求める */
  printf("標準偏差：%f\n", sqrt(bunsan / 7));


  /* 中間値を求める */
  for (i = 1; i < 7; i++)
    for(j = 6; j >= i; j--){
      if (temp[j - 1] > temp[j]){
	t = temp[j - 1];
	temp[j - 1] = temp[j];
	temp[j] = t;
      }
    }
  printf("中間値: %f\n", temp[3]);

  return 0;
}
