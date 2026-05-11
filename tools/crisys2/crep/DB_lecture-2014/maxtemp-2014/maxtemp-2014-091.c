#include <stdio.h>
#include <math.h>
int main(void)
{
  double temp[7];
  int i, j, t;
  double min, max, avg;
  double sumv, squ, bunsan, hensa, med;
  int days;

  days = 7;


  for (i =0; i < days; i++){
    printf("%d 日目の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /* 平均を求める */
  avg = 0.0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %lf\n", avg / days);

  /* 最高気温と最低気温を求める*/
  min = 200;  /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %lf\n", min);
  printf("最高気温: %lf\n", max);

  /*標準偏差、分散を求める*/
  sumv = 0.0;  
  for (i = 0; i < days; i++)
  sumv = sumv + temp[i] * temp[i];/*２乗和*/
  squ = 0.0;
  squ = sumv - (avg * avg / days );/*平方和*/
  bunsan = 0.0;
  bunsan = squ / days; /*分散*/
  hensa = 0.0;
  hensa = sqrt(bunsan);/*標準偏差*/

  printf("標準偏差: %lf\n", hensa);
  printf("分散: %lf\n", bunsan);

  /*データを大きさの順に並べる*/
  for (i = 1; i < days; i++)
    {
      for (j = 0; j < days - i; j++)
	{
	  if (temp[j] > temp[j + 1])
	    {
	      t = temp[j];
	      temp[j] = temp[j + 1];
	      temp[j + 1] = t;
	    }
	}
    }
   

/*中央値を求める（データ数は奇数なので）*/
  med = temp[(days - 1)/ 2]; /*中央値*/

  printf("中央値: %lf\n", med);

  return 0;
}
	 
