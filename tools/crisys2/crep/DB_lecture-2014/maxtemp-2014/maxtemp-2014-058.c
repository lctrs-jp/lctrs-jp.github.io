#include <stdio.h>
#include<math.h>

int main(void)
{
  int i;
  float temp[7],min,max,avg;
  double v;

  for (i = 0; i < 7; i++){
    printf("%d 日の最高気温を入力してください: ", i+1);
    scanf("%f", &temp[i]);
  }

  printf("中央値: %f\n", temp[3]);

  min=200;
  max=0;
  for (i=0; i<7 ;i++){
    if( min > temp[i] )
      min=temp[i];
    if( max < temp[i] )
      max=temp[i];
  }
  printf("最低気温: %f\n",min);
  printf("最高気温: %f\n",max);

  avg = 0;
  for (i = 0; i< 7; i++)
    avg = avg + temp[i];
 printf("平均気温: %f\n", avg /7 );

  v = 0;
  for (i=0; i<7 ;i++)
    v = v + (temp[i] - avg/7)*(temp[i] - avg/7);
  printf("分散: %lf\n", v/6);
  printf("標準偏差: %lf\n", sqrt(v/6) );


  return 0;
}
