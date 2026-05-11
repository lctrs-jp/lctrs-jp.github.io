#include <stdio.h>
#include <math.h>

int main()
{
  double temp[7],min,max,avg,a,b,m,bun,sd,hensa,t;
  int days,i,j;

  days = 7;
  
  for (i = 0; i< days; i++) {
    printf("10月%d日の最高気温を実数で入力してください: ",i+1);
    scanf("%lf", &temp[i]);
  }
  
  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++){
    avg = avg + temp[i];
  }
  m = avg / days; 
  printf("平均気温: %lf\n", m);

  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
  for (i = 0; i < days; i++) {
    if (min > temp[i])
      min = temp[i];
    if ( max < temp[i])
      max = temp[i];
  }
  printf("最高気温: %lf\n",max);
  printf("最低気温: %lf\n",min);

  /*分散を求める*/
  b = 0;
  for (i = 0; i < days; i++) {
    a =  temp[i] - m; 
    b = b + ( a * a );
  }
  bun = b / days;
  printf("分散: %lf\n", bun);

  /*標準偏差を求める*/
  hensa = sqrt(bun);
  printf("標準偏差: %lf\n", hensa);

  /*中間値を求める*/
  for (i = 0; i < days; ++i)
    for (j = days - 1; j >= i; --j) {
      if ( temp[j - 1] > temp[j] ) {
	t = temp[j - 1];
	temp[j - 1] = temp[j];
	temp[j] = t;
      }
    }
  printf("中間値: %lf\n", temp[3]);

  return 0;
}
