#include <stdio.h>
#include <math.h>

int main(void)
{
  int temp[31], i, min, max, avg, t, b;
  double var ;
 

  for (i = 0; i < 7; i++){
    printf("%d 月%d 日の最高気温を入力してください: ", 10,  i + 1);
    scanf("%d", &temp[i]);
  }
  /*平均を求める*/
  avg =0;
  for(i = 0; i < 7; i++)
    avg =avg +temp[i];
  printf("最高気温の平均: %d\n", avg / 7);

/*最高気温と最低気温を求める*/
  min = 200;  /*minとmaxを初期化*/
  max = 0;
  for (i  = 0; i < 7; i++){
    if (min > temp[i])
      min = temp[i];

    if (max < temp[i] )
      max = temp[i];
  }

  printf("一週間における最低気温: %d\n", min);
  printf("一週間における最高気温: %d\n", max);

  /*分散、標準偏差を求める*/
  for (i = 0; i < 7; i++ ){
    var = var + pow((temp[i] - avg / 7), 2);
    
    }
  printf("分散:　%lf\n", var / 7 );
    printf("標準偏差: %lf\n", sqrt( var / 7 ));

  /*中間値を求める*/
    /*バブルソートで整列*/
    for( i = 0; i < 7; i++ )
      for( b = 6; b >= i; --b){
	if( temp[b - 1] > temp[b]){
	  t = temp[b -1];
	  temp[b - 1] = temp[b];
	  temp[b] = t;
	}
      }
    /*中間値を表示する*/    
      printf("中間値は　%d\n", temp[3] );

   
    
 
  return 0;
}
