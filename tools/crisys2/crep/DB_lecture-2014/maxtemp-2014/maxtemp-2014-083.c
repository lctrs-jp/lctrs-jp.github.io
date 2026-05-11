#include <stdio.h>
#include <math.h>

int main(void)
{
  int temp[7], i, min, max, avg, med;
  double var, std;
  int days;

  days = 7;

  for (i = 0; i < days; i++) {
    printf("%d 日の正午の気温を入力してください: ", i + 1);
    scanf("%d", &temp[i]);
  }


  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %d\n", avg / days); 

  min = 200;
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }		

  printf("最低気温: %d\n", min);
  printf("最高気温: %d\n", max);

  med = 0;
  med = temp[4];
  printf("中間値: %d\n", med);

  var = 0;
  for (i = 0; i < days; i++) {
    var = var + (temp[i] - med) * (temp[i] - med);
  }
  printf("分散: %f\n", var / 6);

  std = 0;
  std = sqrt(var);
  printf("標準偏差: %f\n", std);

  return 0;
}
