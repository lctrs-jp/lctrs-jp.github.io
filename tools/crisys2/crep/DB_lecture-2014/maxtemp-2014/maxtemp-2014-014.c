#include<stdio.h>

int main (void)
{
  int  i, j, a, tmp;
  double temp[7] , min, max, avg, stan, vari, med, x ;
   
  for(i = 0; i < 7 ; i++ ) {
    printf("%d 日の最高気温を入力してください:", i + 1);
    scanf("%lf", &temp[i]);
  }

  //平均を求める
  avg = 0;
  for(i = 0; i < 7 ; i++ )
    avg = avg + temp[i];
  printf("平均気温:%lf\n", avg / 7);

  //最大値と最小値を求める
  min =200; //min と max を初期化
  max = 0;
  for(i = 0; i < 7 ; i++ ) {
    if(min > temp[i])
      min =temp[i];
    if(max < temp[i])
      max = temp[i];
  }


  printf("最小値: %lf\n", min);
  printf("最大値: %lf\n", max);

  //標準偏差と分散を求める
  x = 0;
  for(i = 0; i < 7 ; i++ )
    x = x + ( ( temp[i] - (avg / 7) ) ^ 2.0 );
  stan = 0;
  stan = ( x / 7 ) ^ 0.5;
  printf("標準偏差: %lf\n", stan);
  vari = 0;
  vari = stan ^ 2.0;
  printf("分散: %lf\n", vari);

  //中間値を求める
  med = 0;
  a = 0;
  j = 0;
  tmp = 0;

  //データを大きさの順に並べ替え
  for( a = 1; a < i ; a++ ){
    for(j = 0; j < i - a ; i++ ){
      if(temp[j] > temp[j + 1]){
	tmp = temp[j];
	temp[j] = temp[j + 1];
	temp[j + 1] = tmp;
      }
    }
  }

  med = temp[(i - 1) / 2];//メジアン
  printf("中間値: %lf\n", med);




  return 0 ;
}
