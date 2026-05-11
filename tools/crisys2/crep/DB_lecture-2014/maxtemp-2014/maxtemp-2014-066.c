#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, j, b;
  float temp[7], k, avg, var, dev, max, min;
  double a;

  for(i = 1; i < 8; i++)
    {
      printf("%d日目の気温:", i);
      scanf("%f", &temp[i-1]);
    }

  avg = 0;
  for(i = 1; i < 8; i++)
    avg = avg + temp[i-1];
  printf("平均気温:%f", avg / 7);
  printf("\n");

  max = 0;
  min = 200;
  for(i = 1; i < 8; i++){
    if(max < temp[i-1])
      max = temp[i-1];
    if(min > temp[i-1])
      min = temp[i-1];
  }
  printf("最高気温:%f", max);
  printf("\n");
  printf("最低気温:%f", min);
  printf("\n");

  for(i = 1; i < 8; i++)
    for(j = 7; j >= i; --j){
      if(temp[j-2] > temp[j-1]){
	k = temp[j-2];
	temp[j-2] = temp[j-1];
	temp[j-1] = k;
      }
    }

  b = temp[3] * 10;
  printf("中央値:%f",(float)b / 10.0);
  printf("\n");

  avg = avg / 7;
  dev = 0;
  for(i = 1; i < 8; i++){
      dev = dev + (temp[i-1] - avg) * (temp[i-1] - avg);
    }
	dev = dev / 7;
      a = dev;
      printf("分散:%f", dev);
      printf("\n");

      printf("標準偏差:%f", sqrt(a));
      printf("\n");
      return 0;
      }
