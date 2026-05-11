#include <stdio.h>
#include <math.h>

int main()
{
  int i, j;
  float temp[31], avg, hensa, std, sumavg, cent ;
  
    for(i = 0; i < 7; i++){
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  }

  /*平均を求める*/
  sumavg = 0;
  for (i = 0; i < 7; i++){
    sumavg = sumavg + temp[i];
  }
  avg = sumavg / 7;
  printf("平均気温: %f\n", avg );

  /*最高気温と最低気温と中央値を求める*/
  
  for (i=0; i<6; i++){
    for (j=i+1; j<7; j++){
      if(temp[i]>temp[j]){
        cent=temp[i];
        temp[i]=temp[j];
        temp[j]=cent;
      }
    }
  }
  printf("中央値: %f\n", temp[3]);
  printf("最高気温: %f\n", temp[6]);
  printf("最低気温: %f\n", temp[0]);

  //分散を求める
  std = 0;
  for (i = 0; i < 7; i++){
    std = std + (( temp[i] - avg ) * ( temp[i] - avg ));
  }
  hensa = std / 7;
  printf("分散: %f\n", hensa);


  //標準偏差を求める
  
  printf("標準偏差: %f\n", sqrt(hensa));

  return 0;
  
}
