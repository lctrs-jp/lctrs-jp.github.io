#include <stdio.h>
#include <math.h>

int main(void)
{
  int i,j;
  double temp[7], avg, dev, dis, x, min, max, a, media;
  
  for(i=0;i<7;i++){
    printf("10月%d日の最高気温を入力してください:" ,i+1);
    scanf("%lf", &temp[i]);
  }

  avg=0;
  for(i=0;i<7; i++)
    avg=avg+temp[i];
    printf("平均気温：%lf\n", avg/7);

  min=200;
  max=0;
  for(i=0;i<7;i++){
    if(min>temp[i])
      min=temp[i];
    if(temp[i]>max)
      max=temp[i];
  }

  printf("最高気温の最大値：%lf\n", max);
  printf("最高気温の最小値：%lf\n", min);

  dev=0;
  dis=0;
  x=0;
  for(i=0;i<7;i++){
    x=(temp[i]-(avg/7))*(temp[i]-(avg/7));
    dis=dis+x;
  }

  dev=sqrt(dis/7);
  printf("分散：%lf\n", dis/7);
  printf("標準偏差：%lf\n", dev);
  
  for(i=0;i<7;i++)
    for(j=6;j>i;j--){
      if(temp[j-1]>temp[j]){
      a=temp[j];
      temp[j]=temp[j-1];
      temp[j-1]=a;
    }
  }
  media=temp[3];
  printf("中央値は%lfです\n",media);
        
  return 0;
}

    
