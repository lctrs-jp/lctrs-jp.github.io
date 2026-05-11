#include <stdio.h>
#include <math.h>

int sort(double temp[7]);
double average(double temp[7]);
double variance(double temp[7], double avg);
double median(double temp[7]);

int main()
{
  int i;
  double temp[7], min, max, avg, stdev, varia, med;

  // 入力
  for(i = 0; i < 7; i++) {
    printf("%d日の最高気温を入力してください:", i + 1);
    scanf("%lf", &temp[i]);
  }

  //昇順に並べ替え
  sort(temp);

  // 結果セット
  avg = average(temp);
  min = temp[0];
  max = temp[6];
  varia = variance(temp, avg);
  stdev = sqrt(varia);
  med = temp[3];

  // 結果の表示
  printf("平均気温:%.1lf\n", avg);
  printf("最低気温:%.1lf\n", min);
  printf("最高気温:%.1lf\n", max);
  printf("標準偏差:%.2lf\n", stdev);
  printf("分散　　:%.2lf\n", varia);
  printf("中間値　:%.1lf\n", med);

  return 0;
}

// バブルソート
int sort(double temp[7])
{
  int i, j;
  double work;

  for (i = 0; i < 6; i++) {
    for (j = 6; j > i; j--) {
      if (temp[j - 1] > temp[j]) {
        work = temp[j];
        temp[j] = temp[j - 1];
        temp[j - 1] = work;
      }
    }
  }
  return 0;
}

// 平均を求める
double average(double temp[7])
{
  int i;
  double total = 0.0;

  for(i = 0; i < 7; i++)
    total = total + temp[i];

  return total / 7;
}

// 分散を求める
double variance(double temp[7], double avg)
{
  int i;
  double varia = 0.0;
  double sa;

  avg = average(temp);

  for(i = 0; i < 7; i++) {
    sa = temp[i] - avg;
    varia = varia + sa * sa;
  }
  return varia / 7;
}
