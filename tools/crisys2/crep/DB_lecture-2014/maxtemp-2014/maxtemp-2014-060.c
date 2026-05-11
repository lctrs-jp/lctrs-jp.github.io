#include <stdio.h>

int main(void)
{

  int i, j, v;
  float temp[7], min, max, avg, s, k;

  for( i = 0; i < 7; i++ ){
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i] ); 
  }

  /* 平均を求める */
  avg = 0;
  for ( i = 0; i < 7; i++ ){
    avg = avg + temp[i];
  }  
  printf("平均気温: %f\n", avg / 7 );
  
 
  /* 最高気温と最低気温を求める */
  min = 200;
  max = 0;
  for ( i = 0; i < 7; i++ ){
    if ( min > temp[i] )
      min = temp[i];
    if ( max < temp[i] )
      max = temp[i];
  }

  printf("最高気温: %f\n ", max );
  printf("最低気温: %f\n ", min );
 
  /* 分散と標準偏差を求める */
  v = 0;
  for (i = 0; i < 7; i++ ){
    v = v + ( temp[i] - ( avg / 7 ) ) * ( temp[i] - ( avg / 7 ) );
  }
  printf("分散: %f\n", (float) v / 7);
  s = 0;
  while( s*s < (float) v / 7 ){
    s = s + 0.01;
    if ( s*s >= (float) v / 7)
      printf("標準偏差: %f\n", s );
      
  }

  /* 中間値を求める */
  for ( i = 1; i < 7; ++i )
    for ( j = 6; j >= i ; --j ){
      if ( temp[j-1] > temp[j] ){
	k = temp[j-1];
        temp[j-1] = temp[j];
	temp[j] = k;
      }
    }
   
  printf("中間値: %f\n", temp[3] );
 
  return 0;

}
