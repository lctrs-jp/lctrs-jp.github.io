#include<stdio.h>
#include<math.h>

int main(void)
{
 float temp[7], k, min, max, avg, bus;
  int i,j;
  for (i = 0; i < 7; i++){
    printf("%d 日の最高気温を入力してください:", i + 1);
    scanf("%f" , &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i =0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n" , avg / 7);
  /* 最高気温と最低気温を求める */
  min = 200;  /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < 7; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);

  /* 分散、標準偏差、中間値を求める */
  bus = 0;
  for( i = 0; i < 7; i++)
    bus = bus + (temp[i] - (avg/7)) * (temp[i] - (avg/7));
  printf("分散: %f\n" , (bus / 7));
  printf("標準偏差: %f\n" , sqrt(bus / 7));

  for(i = 1; i < 7; i++)
    for (j = 6; j >= i; --j){
      if (temp[j-1] > temp[j]){
	k = temp[j-1];
	temp[j-1] = temp[j];
	temp[j] = k;
      }
    }
  printf("中間値: %f\n" , temp[3]);

  return 0;
}
