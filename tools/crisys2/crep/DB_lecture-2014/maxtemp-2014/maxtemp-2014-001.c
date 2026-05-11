#include <stdio.h>
#include <math.h>

#define DAYS 7	// 自然数

float calcVariance(float* array);
float calcMedian(float* array);
void sort(float* array);

int main(void)
{
  float temp[DAYS];
  int i;
  // 最小値, 最大値, 平均, 標準偏差, 分散, 中央値
  float min, max, avg, dev, var, med;

  for(i=0; i<DAYS; i++){
    printf("%d 日の最高気温を入力してください: ", i+1);
    scanf("%f", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for(i=0; i<DAYS; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n", avg / DAYS);

  /* 最高気温と最低気温を求める */
  min = 200;	/* minとmaxを初期化 */
  max = 0;
  for(i=0; i<DAYS; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }
  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);

  /* 分散, 標準偏差, 中央値を求める */
  var = calcVariance(temp);
  dev = sqrtf(var);
  med = calcMedian(temp);
  printf("標準偏差: %f\n", dev);
  printf("分散　　: %f\n", var);
  printf("中央値　: %f\n", med);

  return 0;
};

float calcVariance(float* array)
{
  int i;
  float sum, square_sum;

  square_sum = 0;
  sum = 0;
  for(i=0; i<DAYS; i++){
    square_sum += array[i] * array[i];
    sum += array[i];
  }

  return (square_sum/DAYS - (sum/DAYS)*(sum/DAYS));	// V(x) = E(X^2) - (E(x))^2
};

float calcMedian(float* array)
{
  sort(array);
  if(DAYS % 2)
    return array[DAYS/2];
  else
    return (array[DAYS/2-1] + array[DAYS/2]) / 2;
};

void sort(float* array)
{
  int i, j;
  float tmp;

  for(i=0; i<DAYS; i++){
    for(j=DAYS-1; j>i; j--){
      if(array[j-1] > array[j]){
        tmp = array[j-1];
        array[j-1] = array[j];
        array[j] = tmp;
      }
    }
  }
};
