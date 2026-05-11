#include <stdio.h>
#include <math.h>

int main(void)
{
  int i,j;
  float bnsn,temp[7],min,max,avg,t;


  for (i = 0;i< 7; i++) {
    printf("%d 日目の最高気温を入力してください:",i+1);
    scanf("%f", &temp[i]);
  }
  
  avg = 0;
  for (i = 0; i < 7; i++){
    avg = avg + temp[i];
  }
  printf("平均気温: %f\n",avg / 7);
  min = 200;
  max = 0;
  for (i = 0;i<7; i++) {
    if (min>temp[i])
      min=temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %f\n",min);
  printf("最高気温: %f\n",max);

  bnsn=0;
    for (i=0; i < 7; i++){
      bnsn = bnsn +(temp[i]-(avg/7))*(temp[i]-(avg/7));
    }
  printf("分散: %f\n",bnsn/ 7);
  printf("標準偏差: %f\n",sqrt(bnsn/7));

  for (j=7; j>0 ; j--){
   for (i=0; i < 7; i++)
     if(temp[i]<temp[i+1]){
            t=temp[i+1];
   temp[i+1]=temp[i];
   temp[i]=t;}
  }	     
  printf("中間値: %f\n",temp[3]);

  return 0;
}
