#include <stdio.h>
#include <math.h>

int main (void)
{

  double  temp[7], min, max, avg, sum, var,  x, dev, med,t  ;
  int i, j;


  for(i = 0; i < 7 ; i++) {
    printf("%d日目の最高気温を入力してください : ", i + 1 );
    scanf("%lf", &temp[i]);
  }

  /* 最大値と最小値を求める */

  min = 100, max = 0; /* minとmaxの初期化 */

  for(i = 0; i < 7 ; i++) {
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }
  printf("最高気温の最大値は%lfです\n", max);
  printf("最高気温の最小値は%lfです\n", min);

  /* 平均値を求める */

  for( i = 0; i < 7; i++ ) {
   sum = sum + temp[i];
   avg = sum/7 ;

  }
  printf("最高気温の平均値は%lfです\n" , avg);

  /* 標準偏差と分散を求める */

  for( i = 0; i < 7; i++ ) {
    x = x + ((temp[i] - avg)*(temp[i] - avg));
    var = x/7;
    dev = sqrt(var);

  }
  printf("最高気温の標準偏差は%lfです\n" , dev);
  printf("最高気温の分散は%lfです\n" , var);

  /* 中央値を求める */
  for (i = 1; i < 7; ++i)
    for (j = 6; j >= i; --j) {
      if (temp[j - 1] > temp[j]) {
        t = temp[j - 1];
        temp[j - 1] = temp[j];
        temp[j] = t;
      }
    }
  printf("最高気温の中央値は%lfです\n", temp[3]);








  return 0;
}
