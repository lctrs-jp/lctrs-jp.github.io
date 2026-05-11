#include <stdio.h>
#include <math.h>
 
int main(void)
{
  float temp[31], min, max, avg, a, k;
  int i,j, days = 7;
  
  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください：", i + 1);
    scanf("%f", &temp[i]);
  }

  //平均を求める
  avg = 0;
  for ( i = 0; i < days; i++){
    avg = avg + temp[i];
  }
  printf("平均気温: %f\n", avg/days);

  //最高気温と最低気温を求める
  min = 200;  //minとmaxを初期化
  max = 0;
  for(i = 0; i < days; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
}
  //分散を求める
  a = 0;
  for(i = 0; i < days; i++){
    a = a + (temp[i] * temp[i]);
  } 
  printf("分散: %f\n", (a/days)-(avg/days)*(avg/days));     


  printf("最低気温：%f\n", min);
  printf("最高気温：%f\n", max);
  printf("標準偏差:　%f\n", sqrt((a/days)-(avg/days)*(avg/days)));
  //中央値を求める
  for(i = 1; i < days; i++)
    for(j = 6; j >= i; j--){
      if(temp[j-1]> temp[j]){
	k = temp[j-1];
	temp[j-1] = temp[j];
	temp[j] = k;
      }
    }
  printf("中央値: %f\n", temp[3]);

  return 0;
}
