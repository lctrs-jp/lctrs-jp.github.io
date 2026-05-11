#include <stdio.h>
#include <math.h>
int main(void)
{
  int i,j;
  double temp[8], min, max, avg, fcet;
  double fstd;

  for (i = 0; i < 7; i++){
    printf("%d日目の最高気温を入力してください: ",i + 1);
    scanf("%lf", &temp[i]);
  }
  //最高気温の平均を求める
  avg = 0;
  for ( i = 0; i< 7; i++)
    avg = avg + temp[i];
  printf("最高気温の平均値: %lf\n", avg / 7);
  //最高気温の最高値と最低値を求める
  min = 200.0; //minとmaxを初期化
  max = 0.0;
  for( i = 0; i < 7; i++){
    if(max < temp[i])
      max = temp[i];
    if(min > temp[i])
      min = temp[i];
  }
  printf("最高気温の最高値: %lf\n", max);
  printf("最高気温の最低値: %lf\n", min);
  //標準偏差を求める
  fstd = 0.0;
  for( i = 0; i < 7; i++){
    fstd = fstd + pow(temp[i] - avg / 7, 2.0);
  }
  printf("最高気温の標準偏差: %lf\n", sqrt(fstd / 7));
  //分散を求める
  printf("最高気温の分散: %lf\n", fstd / 7);
  //中央値を求める
  for( i = 1; i < 7; ++i)
    for( j = 6; j >= i; --j){
      if( temp[j - 1] > temp[j]){
	fcet = temp[j - 1];
	temp[j - 1] = temp[j];
	temp[j] = fcet;
      }
    }
  printf("最高気温の中間値: %lf\n", temp[3]);
  
  return 0;
}
