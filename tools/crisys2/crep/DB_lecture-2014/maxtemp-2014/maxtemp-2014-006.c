#include <stdio.h>
#include <math.h>

int main()
{
  int i, j;
  double temp[7], min, max, avg, nijou[7];
  double bunsan,hensa,k;

  for (i = 0; i < 7; i++)
    {
    printf("%d日目の最高気温を入力してください:", i+1);
    scanf("%lf", &temp[i]);
    }

  //平均を求める
  avg = 0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n", avg / 7);

  //最高と最低を求める
  min = 200;
  max = 0;
  for (i= 0; i < 7; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  printf("最高気温: %f\n", max);
  printf("最低気温: %f\n", min);


  //分散,標準偏差を求める

  for (i = 0;i < 7;i++)
    {
      nijou[i] = (temp[i]-avg) * (temp[i]-avg);
      bunsan = bunsan + nijou[i];
    }
  printf("分散:%f\n",bunsan);
  hensa = sqrt( bunsan );
  printf("標準偏差:%f\n",hensa);

  //中間値を求める

  for (j = 0; j < 7; j++)
    for(i = 6; i >= j; i--)
      {
	if (temp[i-1] > temp[i])
	  {
	    k = temp[i-1];
	    temp[i-1] = temp[i];
	    temp[i] = k;
	  }
      }
  printf("中央値:%f\n",temp[3]);

  return 0;

}
