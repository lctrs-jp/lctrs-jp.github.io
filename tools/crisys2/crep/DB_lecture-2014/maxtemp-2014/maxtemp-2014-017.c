#include<stdio.h>
#include<math.h>

int main()
{
  double temp[31],avg,x;
  double max,min;
  double y[31],y2[31],z;
  double sum = 0.0;
  double R2,t;
  int i,days,month;
  int s;

  printf("今月は何月?[月]");
  scanf("%d", &month );

  printf("今日は何日?[日]");
  scanf("%d", &days );

  for ( i = days; i > days - 7; i--){
    printf("%d 日の最高気温を入力してください", i );
    scanf("%lf", &temp[i]);
  }

  //最高気温の平均を求める
  avg = 0;
  for( i = days; i > days - 7; i--){
    avg = avg + temp[i];
  }
  
  x = avg / 7;
  printf("最高気温の平均は%lf\n",x );

  //最高気温の最大、最少を求める
  min = 200;
  max = 0;    //min,max 初期化

  for( i = days; i > days - 7; i--){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }
  printf("最高気温の最高は%lf\n",max);
  printf("最高気温の最低は%lf\n",min);

  //標準偏差、分散を求める
  for( i = days; i > days - 7; i--){
    y[i] = temp[i] - x;
    y2[i] = y[i] * y[i];
    }
  for( i = days; i > days - 7; i--){
    sum += y2[i];
  }
  
  R2 = sum / 7;
  printf("分散は%lf\n",R2);
  
  printf("標準偏差は%lf\n",sqrt(sum/7));
 
  for( i = days - 6;i < days + 1; i++)     
    for( s = days; s >= i; s--){
      if(temp[s-1] > temp[s]){
	t = temp[s-1];
      temp[s-1] = temp[s];
      temp[s] = t;
    }
  }

  printf("中央値は%lf\n",temp[days-3]);

 return 0;
}   
