#include <stdio.h>
#include <math.h>

int main(void)
{
  int temp[8], i, j, min, max, avg, mid;
  double var;


    for (i=0; i < 7; i++){
    printf("%d 日目の最高気温を入力してください: ", i+1);
    scanf("%d", &temp[i]);  
  }

  /*平均を求める*/
  avg = 0;
  for (i = 0; i< 7;i++)
    avg = avg + temp[i];
  printf("平均最大気温: %d\n" , avg / 7);

  /*最大値と最小値を求める*/
  min = 200 ; /*minとmaxを初期化*/
  max = 0;
  for (i = 0; i < 7; i++){
    if (min>temp[i])
      min = temp[i];
    if (max<temp[i])
      max = temp[i];
  }

  printf("最小値: %d\n" , min);
  printf("最大値: %d\n" , max);

  /*分散・標準偏差を求める*/
  var = 0;
  for (i = 0; i < 7; i++){
    var = var + pow((temp[i]-avg / 7),2);
  }
      

  printf("分散: %lf\n" , var / 7);
  printf("標準偏差: %lf\n" , sqrt(var / 7));

 
 /*中間値を求める*/
  for(i=0;i<6;i++){
    for(j=6;j>i;j--){
      if(temp[j-1]>temp[j]){
	mid=temp[j];
	temp[j]=temp[j-1];
	temp[j-1]=mid;
      }
    }
  }
   printf("中間値: %d\n" , temp[3]);

 return 0;
}

	 
	 


