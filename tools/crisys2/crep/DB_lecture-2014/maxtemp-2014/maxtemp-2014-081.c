#include <stdio.h>
#include<math.h>
float main(void)
{
  float temp[6], min, max, avg, hyoujyun, bunsan, chuukan;
  int days;
  int a,b,t,i;

  days = 7;

  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%f", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("最高気温の平均気温: %f\n", avg / days);

  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  /* 標準偏差を求める */
  {
    hyoujyun = sqrt(((temp[0]-avg/7)*(temp[0]-avg/7)+(temp[1]-avg/7)*(temp[1]-avg/7)+(temp[2]-avg/7)*(temp[2]-avg/7)+(temp[3]-avg/7)*(temp[3]-avg/7)+(temp[4]-avg/7)*(temp[4]-avg/7)+(temp[5]-avg/7)*(temp[5]-avg/7)+(temp[6]-avg/7)*(temp[6]-avg/7))/7);
  }
  /* 分散を求める */

  bunsan = ((temp[0]-avg/7)*(temp[0]-avg/7)+(temp[2]-avg/7)*(temp[2]-avg/7)+(temp[3]-avg/7)*(temp[3]-avg/7)+(temp[4]-avg/7)*(temp[4]-avg/7)+(temp[5]-avg/7)*(temp[5]-avg/7)+(temp[6]-avg/7)*(temp[6]-avg/7)+(temp[1]-avg/7)*(temp[1]-avg/7))/7;

  /* 中間値を求める */
  for (a = 0; a < 7; ++a)
    for (b = 7 - 1; b >= a; --b) {
      if (temp[b-1] > temp[b]) {
	t = temp[b-1];
	temp[b-1] = temp[b];
	temp[b] = t;
      }
    }

  chuukan = temp[3];

  printf("最高気温の最低値: %f\n", min);
  printf("最高気温の最高値: %f\n", max);
  printf("最高気温の標準偏差: %f\n", hyoujyun);
  printf("最高気温の分散: %f\n", bunsan);
  printf("最高気温の中間値: %f\n", chuukan);

  return 0;
}
