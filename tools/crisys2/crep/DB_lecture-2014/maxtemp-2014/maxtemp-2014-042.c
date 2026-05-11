#include<stdio.h>
#include<math.h>

int main(void)
{
  int i,j;
  double temp[7], min,max,avg,hensa,bunsan,tyukan;
  int days;

  double q;
   
  for (i = 0;i < 7; i++) {
    printf("%d 日目の気温を入力してください。:", i + 1);
    scanf("%lf", &temp[i]);
  }
  /*平均*/
  avg = 0;
  for (i = 0; i < 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %lf\n", avg /7); 
  /**/
  min = 200;  /**/
  max = 0;
  for (i = 0; i < 7; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
	 }

  printf("最低気温: %lf\n", min);
  printf("最高気温: %lf\n", max);
   
  for (i=0;i<7;i++)
    for(j=7;j>=i;--j){
      if(temp[j-1]>temp[j]){
	tyukan=temp[j-1];
        temp[j-1]=temp[j];
        temp[j]=tyukan;
      }
    }

  printf("中央値;%lf",(temp[4]));
	 printf("\n");

	 avg=avg/7;
         bunsan=0;
         for(i = 1; i < 7; i++){
	   bunsan=bunsan+(temp[i]-avg)*(temp[i]-avg);
	 }
	 bunsan=bunsan/7;
         q=bunsan;
         printf("分散は:%lf",bunsan);                        
         printf("\n");

         printf("標準偏差は:%lf",sqrt(q));
         printf("\n");
         return 0;
	 }
	 
