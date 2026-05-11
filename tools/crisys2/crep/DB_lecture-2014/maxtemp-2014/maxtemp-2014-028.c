#include<stdio.h>
#include<math.h>

int main(void)
{
  double tempmax[6],min,max,avg,bs,hh,tk,t;
  int i,k;

  for(i=0;i<7;i++){
    printf("10月%d 日の最高気温を入力してください:",i+1);
    scanf("%lf",&tempmax[i]);
  }

  avg=0;
  for(i=0;i<7;i++)
    avg=avg+tempmax[i];
  printf("平均気温:%lf\n",avg/7);

  min=200;
  max=0;
  for(i=0;i<7;i++){
    if(min>tempmax[i])
      min=tempmax[i];
    if(max<tempmax[i])
      max=tempmax[i];
  }
  printf("最大値:%lf\n",max);
  printf("最小値:%lf\n",min);

  bs=0;
  for(i=0;i<7;i++)
    bs=bs+(tempmax[i]-avg)*(tempmax[i]-avg);
  printf("分散:%lf\n",bs);

  for(k=0;k<7;k++){
   for(i=0;i<7;i++){
    if(tempmax[k]>tempmax[i]){
      t=tempmax[i];
      tempmax[i]=tempmax[k];
      tempmax[k]=t;
    }}}

  tk=(tempmax[2]+tempmax[3])/2;
  printf("中間値:%lf\n",tk);

  return 0;
}
