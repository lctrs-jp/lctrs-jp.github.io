#include<stdio.h>
#include<math.h>

int main()
{
  int i, j;
  float temp[7], min, max, avg, std, k, v, t;

  for( i = 0; i < 7; i++ ){
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %.1f\n", avg / 7 );

  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for ( i = 0; i < 7; i++){
    if (min > temp[i])
	min = temp[i];
	if(max < temp[i])
	  max = temp[i];
  }

    printf("最低気温: %.1f\n", min);
    printf("最高気温: %.1f\n", max);

    /* 分散を求める */
    k = avg / 7;
    v = 0;
    for ( i = 0; i < 7; i++){
      v = v + pow( k - temp[i], 2 );
	}

    v = v / 7;

    printf("分散: %.2f\n", v);

    /* 標準偏差を求める */
    std = sqrt( v );

    printf("標準偏差: %.2f\n", std);

    /* バブルソートで数値を整列 */
    for(i = 1; i < 7; ++i)
      for(j = 6; j >= i; --j){
	if(temp[j - 1] > temp[j]){
	  t = temp[j - 1];
	  temp[j - 1] = temp[j];
	  temp[j] = t;
	}
      }

    /* 中間値を表示 */
    printf("中間値: %.1f\n", temp[3]);

    return 0;
  }
