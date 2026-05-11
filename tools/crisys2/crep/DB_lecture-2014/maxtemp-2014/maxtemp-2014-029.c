#include <stdio.h>
#include<math.h>
int main(void)
{
  int i,a,b;
  float tem[7],min,max,ave,sum,total,t;
  for(i=0;i<7;i++)
    {
      printf("%d日の最高気温を入力してください。",i+1);
  scanf("%f",&tem[i]);
    }

  min=1000;
  max=0;
  for(i=0;i<7;i++)
    {
  if(min>tem[i])
      min=tem[i];
  if(max<tem[i])
    max=tem[i];
    }
  printf("最高気温の最大　%f℃      最高気温の最小　%f℃     ",max,min);
  sum=0;
  for(i=0;i<7;i++)
    sum=sum+tem[i];

  printf("最高気温の平均　%f     ",sum/7);
  ave=sum/7;

  total=0;
  for(i=0;i<7;i++)
    {
      total=total+(tem[i]-ave)*(tem[i]-ave);
    }
  printf("最高気温の分散　%f     ",total/7);
  printf("最高気温の標準偏差　%f     ",sqrt(total/7));


  /* 中間値*/
  for(i=0;i<7;i++)
    for(b=6;b>=a;b--)
      {
	if(tem[b-1]>tem[b])
	  {
	  t=tem[b-1];
	tem[b-1]=tem[b];
	tem[b]=t;
	  }
      }
  printf("最高気温の中間値　%f",tem[3]);


  return 0;
}
