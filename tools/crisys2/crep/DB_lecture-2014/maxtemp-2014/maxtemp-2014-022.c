#include <stdio.h>
#include <math.h>

int main()
{
  int i, j;
  double temp[6], avg, avgx, min, max, disp, t;

  for (i = 0; i < 7; i++) {
    printf("第%d日目の最高気温を入力してください: ", i + 1 );
    scanf("%lf", &temp[i]);
  }

/* 平均を求める */
  avg = 0;
  for (i = 0; i < 7; i++) {
    avg = avg + temp[i];
  }

  avgx = avg / 7;
  printf("平均は %lf\n", avgx);

/* 最高・最低気温を求める */
  max = 0;
  min = 200;
  for (i = 0; i <7; i++) {
    avg = avg + temp[i];
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最大は %lf\n", max);
  printf("最小は %lf\n", min);

/* 標準偏差・分散を求める */
  disp = 0;
  for(i = 0; i < 7; i++) {
    disp = disp + ((temp[i] - avgx)*(temp[i] -avgx));
  }
    disp = disp / 7;

  printf("標準偏差は %lf\n", sqrt(disp));
  printf("分散は %lf\n", disp);

/* 中央値を求める */
  for (i = 1; i < 7; ++i)
  for (j = 7 - 1; j >= i; --j) {
  /* 隣接する要素を比較する */
    if (temp[j - 1] > temp[j]) {
    /* 要素を交換する */
    t = temp[j - 1];
    temp[j - 1] = temp[j];
    temp[j] = t;
    }
  }

  printf("中央値は %lf\n", temp[3]);

  return 0;
}
