#include <stdio.h>
#include<math.h>

int main(void)
{
  int t;
  double v,s,avg,temp[8],max,min;

  for(t=0;t<7;t++){
    printf("10月%d日の最高気温",t+1);
    scanf("%lf",&temp[t]);
  }

  avg=0;
    for(t=0;t<7;t++)
      avg=avg+temp[t];
    printf("平均気温 %lf\n",avg/7);

    s=0;
    for(t=0;t<7;t++)
      s=s+(temp[t]-avg/7)*(temp[t]-avg/7);
    v=sqrt(s/7);

    printf("分散 %lf\n",s/7);
    printf("標準偏差 %lf\n",v);

   min=500;
    max=0;
    for(t=0;t<7;t++){
      if(min>temp[t])
        min=temp[t];
      if(max<temp[t])
        max=temp[t];
    }

    printf("最高気温 %lf\n",max);
    printf("最低気温 %lf\n",min);

   double data[8],j,med,tmp;
    tmp=0;
    med=0;
      j=0;
      for(j=0;j<7;j++){
        for(t=0;t<7-j;t++){
          if(temp[t]>temp[t+1]){
            tmp=temp[t];
            temp[t]=temp[t+1];
            temp[t+1]=tmp;
          }
        }
      }

      med=temp[4];
      printf("中央値 %lf\n",med);

    return 0;

}
