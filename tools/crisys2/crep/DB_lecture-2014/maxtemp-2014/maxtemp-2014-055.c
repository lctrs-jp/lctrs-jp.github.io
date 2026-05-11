#include <stdio.h>
#include <math.h>

int main()
{
  float temp[7], min, max, avg, d[7], dd[7], vsum, v, s, m;
  int i, j, days = 7;

 
  for( i = 0; i < days; i++){
    printf("%d 日目の最高気温を入力してください: ", i + 1 );
    scanf("%f", &temp[i] );
  }

  // 最大値と最小値を求める
  min = 300;
  max = -300;
  for( i = 0; i < days; i++){
    if( min > temp[i] )
      min = temp[i];
    if( max < temp[i] )
      max = temp[i];
  }
  
  printf("最高気温の最大値: %f 度\n", max );
  printf("最高気温の最小値: %f 度\n", min );
	 

  // 平均を求める
  avg = 0;
  for( i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %f 度\n", avg / days );


  // 分散を求める
  vsum = 0;
  for( i = 0; i < days; i++){
    d[i] = temp[i] - (avg / days);
    dd[i] = d[i] * d[i];
    vsum = vsum + dd[i];
  }
  v = vsum / days;
  printf("分散: %f\n", v );


  //標準偏差を求める
  s = sqrt( v );
  printf("標準偏差: %f\n", s );


  //中央値を求める
  for( j = 1; j < 7; ++j)
    for( i = 6; i >= j; --i){
      if( temp[i-1] > temp[i]){
	m = temp[i-1];
	temp[i-1] = temp[i];
	temp[i] = m;
      }
    }
  printf("中央値: %f\n", temp[3] );


  
  return 0;
}
