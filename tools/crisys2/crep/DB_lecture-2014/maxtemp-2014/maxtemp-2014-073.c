#include <stdio.h>
#include <math.h>

int main(void)
{
  double temp[7], min, max, avg, det,x, t;
  int days, i, j ;
  days=7;
 
  
  for (i=0; i<days; i++ ){
    printf("週の%d 日目の最高気温を入力してください:", i+1);
    scanf("%lf",&temp[i]);
  }

  avg=0;
  for (i=0; i<days; i++) 
    avg=avg + temp[i];
  printf("平均最高気温: %lf\n", avg/days);


  min=200;
  max=0;
  for (i=0;i<days; i++ ){
    if(min>temp[i])
      min=temp[i];
    if(max<temp[i])
      max=temp[i];
  }


  printf("最高気温の最小値: %lf\n", min);
  printf("最高気温の最大値: %lf\n", max);
  
 
  
  det=(temp[0]-avg)*(temp[0]-avg)+(temp[1]-avg)*(temp[1]-avg)+(temp[2]-avg)*(temp[2]-avg)+(temp[3]-avg)*(temp[3]-avg)+
    (temp[4]-avg)*(temp[4]-avg)+(temp[5]-avg)*(temp[5]-avg)+(temp[6]-avg)*(temp[6]-avg);
  printf("分散: %lf\n", det/days);
  x=det/7.0;
  printf("標準偏差: %lf\n", sqrt(x) );

  for (i=1; i<days; ++i)
    for (j =days -1; j>=i; --j){
      if (temp[j-1]>temp[j]){
	t=temp[j-1];
        temp[j-1] =temp[j];
        temp[j] = t;
      }
    }
  printf("中央値: %lf\n" ,temp[3]);
  return 0;
}
