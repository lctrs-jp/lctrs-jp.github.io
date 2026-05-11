#include<stdio.h>
#include<math.h>

int main(void)
{
  int i,j,b;
  float temp[7],k,var,avg,dev,min,max;

  double a;

  /*一週間の最高気温を入力*/
  for(i=0;i<7;i++)
    {
      printf("%d日目の最高気温を入力",i+1);
      scanf("%f",&temp[i]);
    }
  /*平均気温を表示*/
  avg=0;
  for (i=0;i<7;i++)
    avg=avg+temp[i];
  printf("平均気温:%f",avg/7);

  /*最高温度、最低温度を表示*/
  min=200;
  max=0;
  for(i=0;i<7;i++)
    {
      if(min>temp[i])
	min=temp[i];
      if(max<temp[i])
	max=temp[i];
    }
  printf("最高気温:%f\n",max);
  printf("最低気温:%f\n",min);

  /*分散を表示*/
  avg=avg/7;
  dev=0;
  for(i=0;i<7;i++)
    {
      dev=dev+(temp[i]-avg)*(temp[i]-avg);
    }
  dev=dev/7;
  a=dev;
  printf("分散:%f\n",dev);

  /*標準偏差を表示*/
  printf("標準偏差:%f\n",sqrt(a));

  /*中央値の値を表示*/
  for(i=0;i<7;i++)
  for(j=6;j>=i;--j)
    {
      if(temp[j-1]>temp[j])
	{
	  k=temp[j-1];
	  temp[j-1]=temp[j];
	  temp[j]=k;
	}
    }
  printf("中央値:%f\n",temp[3]);

   return 0;
}
