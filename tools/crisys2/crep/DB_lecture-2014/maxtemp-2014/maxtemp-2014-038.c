#include <stdio.h>
#include <math.h>

int main()
{
  double temp[7],min,max,avg,bunsan;
  int i,days=7;

  for(i=0;i<days;i++){
    printf("%d 日の最高気温を入力してください。\n",i+1);
    scanf("%lf", &temp[i]);
  }

  max=0;
  min=200;
  for(i=0;i<days;i++){
    if(max<temp[i])
      max=temp[i];
    if(min>temp[i])
      min=temp[i];
  }
  printf("最高気温の最大値 %lf\n",max);
  printf("最高気温の最低値 %lf\n",min);

  avg=0;
  for(i=0;i<days;i++)
    avg=avg+temp[i];
  printf("最高気温の平均値 %lf\n",avg/days);

  bunsan=0;
  double bun1[i],bun2[i];
  for(i=0;i<days;i++){
    bunsan=bunsan+pow(temp[i]-avg/days,2);
  }
  printf("分散 %lf\n",bunsan/days);
  printf("標準偏差 %lf\n",sqrt(bunsan/days));

  int j;
  float t;
  for(i=0;i<days;++i)
    for(j=days-1;j>=i;--j){
      if(temp[j]<temp[j-1]){
	t=temp[j-1];
	temp[j-1]=temp[j];
	temp[j]=t;
      }
}
  printf("中央値 %f\n",temp[3]);

  return 0;
}
