#include<stdio.h>
#include<math.h>

int main(void)
{
  int i,j;
  double temp[31],min,max,avg,bun,std,med,junban;
  int days=7;
  
  
  for(i=0;i<days;i++){
    printf("%d 日の正午の気温を入力してください:",i+1);
    scanf("%lf",&temp[i]);
  }
  avg=0;
  for(i=0;i<days;i++)
    avg=avg+temp[i];
  printf("平均気温: %lf\n",avg/days);
  
  min=200;
  max=-200;
  for(i=0;i<days;i++){
    if(min>temp[i])
      min=temp[i];
    if(max<temp[i])
      max=temp[i];
  }
  printf("最低気温: %lf\n",min);
  printf("最高気温: %lf\n",max);
  
  for(i=0;i<days;i++)
    bun=((temp[i]-avg/days)*(temp[i]-avg/days))/days;
  std=sqrt(bun);
  
  printf("標準偏差: %lf\n",std);
  printf("分散: %lf\n",bun);
  
  for(j=0;j<days;j++){
    for(i=0;i<days-j;i++){
      if(temp[i]>temp[i+1]){
        junban=temp[i];
        temp[i]=temp[i+1];
        temp[i+1]=junban;
      }
    }
  }
  med=temp[4];
  printf("中央値: %lf\n",med);
  return 0;
}
