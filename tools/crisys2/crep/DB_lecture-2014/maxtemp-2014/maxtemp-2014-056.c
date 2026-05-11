#include <stdio.h>
#include <math.h>

int main(void)
{
  float temp[7], min, max, sum, e, v, s, c;
  int days, i, j;

  days = 7;

  for(i = 0; i < days; i++)
    {
      printf("%d日目の正午の気温を入力してください: ", i + 1);
      scanf("%f", &temp[i]);
    }

  /* 平均を求める */
  sum = 0;
  for (i = 0; i < days; i++)
    sum = sum + temp[i];
  printf("平均気温: %f\n", sum / days);


  /* 最高気温と最低気温を求める */
  min = 200;  // minとmaxを初期化
  max = 0;
  for(i = 0; i < days; i++)
    {
      if(min > temp[i])
	min =temp[i];
      if(max < temp[i])
	max = temp[i];
    }

  printf("最小値: %f\n", min);
  printf("最大値: %f\n", max);

  /* 分散を求める */
  for(i = 0; i < days; i++) 
    e = e + ( sum / days - temp[i] ) * ( sum / days - temp[i] );
  v = e / days;

  printf("分散: %f\n", v);

  /* 標準偏差を求める */
   s = sqrt(v) ;
  printf("標準偏差: %f\n", s);

  /* 中間値を求める */

  float t;

  for(i = 1; i < days; i++)
    for(j = days - 1; j >= i; --j)
      {
	if(temp[j - 1] > temp [j])
	  {
	    t = temp[j];
	    temp[j] = temp[j - 1];
	    temp[j - 1] = t;
	  }    
      }

  printf("中間値: %f\n", temp[3]);

  return 0;
}
