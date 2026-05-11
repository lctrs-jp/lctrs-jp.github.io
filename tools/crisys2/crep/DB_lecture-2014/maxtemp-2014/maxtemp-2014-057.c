#include<stdio.h>
#include<math.h>

int main (void)
{
  int i, j, days = 7;
  double temp[7], min, max, avg, h, k;

  /*最高気温の入力*/
  for(i = 0; i < days; i++){
    printf("%d 日目の最高気温を入力してください ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /*平均値を求める*/
   avg = 0;
      for(i = 0; i < days; i++){
       avg = avg + temp[i];
      }    
  printf("最高気温の平均値 %lf\n", avg / days);
    
  /*平均を格納*/
  avg = avg / days;  

  /*最大値と最小値を求める*/ 
      min = 200;  /*min,maxの初期化*/
    max = 0;
    for (i = 0; i < days; i++){
      if (min > temp[i])
        min = temp[i];
      if (max < temp[i])
	max = temp[i];
    }
    
    printf("最高気温の最小値 %lf\n", min);
    printf("最高気温の最大値 %lf\n", max);

    /*分散を求める*/
    h = 0;
    for (i = 0; i < days; i++)
      h = h + pow(temp[i] - avg, 2);
    h = h / days;
    printf("標準偏差 %lf\n", sqrt(h));
    printf("分散 %lf\n", h);
 

    /*中央値を求める並び替え*/
    for (i = 1; i < days; ++i)
      for (j = days - 1; j >= i; --j){
	if (temp [j - 1] > temp[j]){
	  k = temp[j - 1];
	  temp[j - 1] = temp[j];
	  temp[j] = k;
	}
      }
    printf("中央値 %lf\n", temp[3]);
    return 0;
} 
      







