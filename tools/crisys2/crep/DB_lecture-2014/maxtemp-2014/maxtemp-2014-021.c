#include<stdio.h>
#include<math.h>

int main(void)
{
  int i,j,b;
  float temp[7],k,var,avg,dev,min,max;
  double a;

  for(i=1;i<8;i++)
    {
      printf("%d日目の気温を入力してください:",i);
      scanf("%f",&temp[i-1]);
    }

  avg=0;
  for(i=1;i<8;i++)
    avg=avg+temp[i-1];
  printf("平均気温は%fです\n",avg/7);
 
  printf("中央値は%fです\n",temp[3]);
 
 min=200;
  max=0;
  for(i=1;i<8;i++){
    if(min>temp[i-1])
      min=temp[i-1];
    if(max<temp[i-1])
      max=temp[i-1];

  }

  printf("最高気温は%fです\n",max);
  printf("最低気温は%fです\n",min);

  for(i=1;i<8;i++)
    for(j=7;j>=i;--j){
      if(temp[j-2]>temp[j-1]){
	k=temp[j-2];
	temp[j-2]=temp[j-1];
	temp[j-1]=k;
      }
    }

  avg=avg/7;
  dev=0;
  for(i=1;i<8;i++){
    dev=dev+(temp[i-1]-avg)*(temp[i-1]-avg);
  }
  dev=dev/7;
  a=dev;
  printf("分散は%fです\n",dev);
  
  printf("標準偏差は%fです\n",sqrt(a));
    return 0;
}

