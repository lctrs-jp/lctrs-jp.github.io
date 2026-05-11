#include <stdio.h>
#include <math.h>/*コンパイル時に-lmオプションが必要*/

int main(void)
{
  int i;
  double temp[7], min, max, sum, med, var; 
  int days = 7;
  int a, b, item[7];

  for (i = 0; i < days; i++){
    printf("%d日目の最高気温を入力してください: ", i+1);
    scanf("%lf", &temp[i]);
  }

  /*平均を求める*/
  sum = 0;
  for (i = 0; i < days; i++)
    sum = sum + temp[i];
  printf("平均気温: %f\n", sum/days);

  /* 最高気温と最低気温を求める*/
  min = 200.0;/* minとmaxを初期化*/
  max = 0.0;
  for (i = 0; i < days; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最高気温の最小値: %f\n", min);
  printf("最高気温の最大値: %f\n", max);

  /*分散*/
  var = 0.0;
  for (i = 0; i < days; i++) {
    var = var + (temp[i] - (sum / days))*(temp[i] - (sum / days));
  }
  var = var / days;
  printf("分散: %f\n", var);

  /*標準偏差*/
  printf("標準偏差: %f\n", sqrt(var));

  /*中間値*/
  /*バブルソートを使用して数値を整列させる*/
  for (i = 0; i < days; i++)
    item[i] = temp[i];
  for (a = 1; a < days; ++a)
    for (b = days - 1; b >= a; --b) {
      /*隣接する要素を比較する*/
      if (item[b-1] > item[b]) {
	/*要素を交換する*/
	i = item[b-1];
	item[b-1] = item[b];
	item[b] = i;
      }
    }

  /*中間値の表示*/
  if (days%2)
    med = item[days/2];
  else
    med = (item[days/2] + item[(days/2)+1]) / 2;
  printf("中間値: %f\n", med);

  return 0;
}
