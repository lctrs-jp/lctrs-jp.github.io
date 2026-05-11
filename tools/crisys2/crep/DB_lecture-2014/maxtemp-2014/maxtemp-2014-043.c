#include <stdio.h>
#include <math.h>

int main(void)
{
  int i, j;
  double b, h, k, bun, temp[7], avg, min, max;

  for (i = 0; i < 7; i++) {
    printf("%d 日目の最高気温を入力してください:", i + 1);
    scanf("%lf", &temp[i]);
}

  avg = 0;
  for (i = 0;i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %.1f\n", avg / 7);

  min = 200;
  max = 0;
  for (i = 0; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最小値: %.1f\n", min);
  printf("最大値: %.1f\n", max);

  b = 0;
  for (i = 0; i < 7; i++)
    b = (temp[i] - (avg / 7)) * (temp[i] - (avg / 7)) + b;
    bun = b / 7;
      
    printf("分散は: %.3f\n", bun);   

    h = sqrt( bun );      
      printf("標準偏差は: %.3f\n", h);

      for (i = 1; i < 7; i++)
	for (j = 6; j >= i; --j) {
	  if (temp[j-1] > temp[j]) {
            k = temp[j-1];
            temp[j-1] = temp[j];
            temp[j] = k;
	  }
	}
      printf ("中間値: %.1f\n", temp[3]);
      
      return 0;
}
