#include <stdio.h>
#include <math.h>

int main(void)
{
  float temp[7], min, max, avg=0, xn, t;
  int i, b;
  
    for (i = 0; i < 7; i++) {
      printf("%d 日目の最高気温を入力してください: ", i + 1);
      scanf("%f", &temp[i]);
    }

  /*平均を求める*/
    for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n", avg / 7);

  /*最高気温と最低気温を求める*/
  min = 200;
  max = 0;
  for (i = 0; i < 7; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);

  /*標準偏差を求める*/
  for (i = 0; i < 7; i++)
    xn = xn + ( temp[i] - avg / 7 )*( temp[i] - avg / 7 );
  printf("分散: %f\n", xn / 7 );
  printf("標準偏差: %f\n", sqrt( xn / 7 ));

  /*中間値を求める*/
  for ( i = 1; i < 7; ++i )
    for ( b = 6; b >= i; --b){

      if (temp[b-1] > temp[b]) {
        t = temp[b-1];
        temp[b-1] = temp[b];
        temp[b] = t;
      }
    }
  printf("中間値: %f\n", temp[3]);


  return 0;
}
