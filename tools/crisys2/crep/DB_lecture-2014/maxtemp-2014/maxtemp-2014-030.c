#include <stdio.h>
#include <math.h>

  int main(void)
{
  double temp[7],  min, max,avg, sum , temp2;
  int days, i, n  ,b ;
  
  printf("月の日数は？　");
  scanf("%d", &days);

  for (i = 0; i < days; i++) {
    printf("%d 日の最高気温を入力してください: ", i + 1);
    scanf("%lf", &temp[i]);
  }

  /*　平均を求める*/
  avg = 0;
  for (i = 0; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %lf\n", avg / days);

  /*最高気温と最低気温を求める*/
  min = 200.00; /* minとmaxを初期化*/
  max = 0.0;
  for(i= 0; i<days; i++){
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }
  
  printf("最低値: %lf\n", min);
  printf("最高値: %lf\n", max);
 
  
  for(i=0; i<7; i++)
    {sum=0;
    sum = sum+(temp[i]-avg/7)*(temp[i]-avg/7);
    }
    printf("分散　%lf \n", sum);
    

  printf("標準偏差　%lf\n", sqrt(sum));


  for(i=0;i<7-1;i++)
   {
    for(b=7-1; b>i;b--) 
     {
      if(temp[b-1]>temp[b])
       {
	temp2=temp[b];
	temp[b]=temp[b-1];
	temp[b-1]=temp2;
      }
    }
  }

  printf("中央値 :%lf \n" ,temp[3]);



  return 0;
 }
