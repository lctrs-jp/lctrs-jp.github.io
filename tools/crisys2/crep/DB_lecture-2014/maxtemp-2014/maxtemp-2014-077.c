#include <stdio.h>
#include <math.h>
#define DATA_NUM 7

int main(void)
{
  double temp[7], min, max, avg, bu, tmp, med;
  int i, j;

  for (i = 0; i < 7; i++){
    printf("%d日目の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

//最高気温と最低気温を求める
min = 200;  //minとmaxを初期化
max = 0;
for (i = 0; i < 7; i++){
  if (min > temp[i])
    min = temp[i];
  if (max < temp[i])
    max = temp[i];
 }
 printf("最高気温: %lf\n", max);
 printf("最低気温: %lf\n", min);

 //平均を求める
 avg = 0;
 for (i = 0; i < 7; i++)
   avg = avg + temp[i];
 printf("平均気温: %lf\n", avg / 7);

 //分散と標準偏差を求める
bu = 0;
for (i = 0; i < 7; i++){
  bu = bu + ( temp[i] - avg/7 )*( temp[i] - avg/7 );
}

 printf("標準偏差 = %lf\n", sqrt( bu/7 ));
 printf("分散 = %lf\n", bu/7 );

//中間値を求める
 for(i = 1; i < DATA_NUM; i++){
   for(j = 0; j < DATA_NUM - i; j++){
     if(temp[j] > temp[j + 1]){
       tmp = temp[j];
       temp[j] = temp[j + 1];
       temp[j + 1] = tmp;
     }
   }
 }

 med = temp[(DATA_NUM - 1) / 2];

 printf("中間値 = %lf\n", med);

return 0;
}
