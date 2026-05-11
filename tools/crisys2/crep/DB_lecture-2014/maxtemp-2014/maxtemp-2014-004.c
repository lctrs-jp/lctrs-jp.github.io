//10月23日の課題1
//例5.1-1を変更して一週間の最高気温を入力し
//最高気温の最大値、最小値、平均、標準偏差、分散、および中間値
//を出力するプログラム
#include <stdio.h>
#include <math.h>

int days = 7;
double Average(double temp[7]);		//平均を求める関数
double Standard_Deviation(double temp[7], double avg);	//標準偏差を求める関数
double Median(double temp[7]);		//中間値を求める関数

int main()
{
  double temp[7];
  double max, min, avg, standard_deviation, variance, median;
  int i;

  //一週間の最高気温を標準入力する
  for (i = 0; i < days; i++){
    printf("%d 日目の最高気温を入力してください: ", i+1);
    scanf("%lf", &temp[i]);
  }

  //最高気温と最低気温を求める
  max = 0;
  min = 100;
  for (i = 0; i < days; i++){
    if (max < temp[i]){
      max = temp[i];
    }
    if (min > temp[i]){
      min = temp[i];
    }
  }

  //平均、標準偏差、分散、中間値を求める
  avg = Average(temp);
  standard_deviation = Standard_Deviation(temp, avg);
  variance = sqrt(standard_deviation);
  median = Median(temp);

  //各値を標準出力する
  printf("最大　　: %4.1lf\n", max);
  printf("最小　　: %4.1lf\n", min);
  printf("平均　　: %4.1lf\n", avg);
  printf("標準偏差: %4.1lf\n", standard_deviation);
  printf("分散　　: %4.1lf\n", variance);
  printf("中間値　: %4.1lf\n", median);

  return 0;
}

//平均を求める関数
double Average(double temp[])
{
  int i;
  double avg;

  for (i = 0; i < days; i++){
    avg = avg + temp[i];
  }
  avg = avg / i;

  return avg;
}

//標準偏差を求める関数
double Standard_Deviation(double temp[], double avg)
{
  double s = 0;
  int i;

  for (i = 0; i < days; i++){
    s = s + pow((temp[i] - avg), 2);
  }
  s = s / days;

  return s;
}

//バブルソートを使用して中間値を求める関数
double Median(double temp[])
{
  double m, t;
  int a, b;

  for (a = 1; a < days; ++a){
    for (b = days - 1; b >= a; --b){
      if (temp[b - 1] > temp[b]){
	t = temp[b - 1];
	temp[b - 1] = temp[b];
	temp[b] = t;
      }
    }
  }
  m = temp[3];

  return m;
}
