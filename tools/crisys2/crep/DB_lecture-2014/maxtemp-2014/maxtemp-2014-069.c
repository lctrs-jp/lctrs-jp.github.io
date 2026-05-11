#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, y;
  float temp[7], min, max, avg, x, z;

  for(i = 0; i < 7; i++) {
    printf("週の %d 日目の最高気温を入力してください:", i + 1);
    scanf("%f", &temp[i]);
  }

  avg = 0;
  for(i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("最高気温の平均: %f\n", avg / 7);


  min = 200;
  max = 0;
  for(i = 0; i < 7; i++) {
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }
  printf("最高気温の最小値: %f\n", min);
  printf("最高気温の最大値: %f\n", max);


  x = 0;
  for(i = 0; i< 7; i++)
    x = x + (temp[i] - (avg / 7) ) * (temp[i] - (avg / 7) );
  printf("最高気温の分散: %f\n", x / 7);
  printf("最高気温の標準偏差: %f\n", sqrt(x / 7) );


  for(i = 1; i < 7; ++i)
    for(y = 7 - 1; y >= i; --y)
      {
	if(temp[y - 1] > temp[y] )
	  {
	    z = temp[y - 1];
	    temp[y - 1] = temp[y];
	    temp[y] = z;
	  }
      }

  printf("最高気温の中間値: %f\n", temp[3]);



  return 0;
}
