#include <stdio.h>
#include <math.h>

int main(void)
{
  float  temp[7],   min, max, avg,avg2, med,var,var2,mid;
  int days,i,j,k ;

  days = 7;
  
  for (i = 0; i < days ; i++)
    {printf ("%d 日の最高気温を入力してください;", i + 1);
      scanf("%f", &temp[i]);}

  avg= 0;
  for (i = 0; i < days;i++)
    avg = avg + temp[i];
  avg2= avg/days;
  printf("平均気温:%f\n",  avg2);
  /*最高 最低 気温を求める*/
  min = 200; /*minとmax　を初期化*/
  max=0   ;
  for (i = 0; i < days;i++)
    {if(min > temp[i]    )
	min = temp[i];
if (max < temp[i])
	max= temp[i]; }
  printf("最低気温:%f\n",  min);
  printf("最高気温:%f\n",  max);

  /*分散と標準偏差*/
  var=0;
  for(i=0;i< days;i++)
    var=var+(temp[i]-avg2)*(temp[i]-avg2);
  var2=(var/days);
  mid=sqrt(var2);

  printf("分散:%f\n",  var2);
  printf("標準偏差:%f\n", mid);
    
  
for( j= 1 ; j < days ;j++)
  for(k= days - 1 ;k>=j ; k--) 
    {if(temp[k-1]>temp[k])
	{med=temp[k-1];
	  temp[k-1]=temp[k];
	  temp[k]=med;
}}
  printf("中央値:%f\n",
 temp[3]);

 return 0;}
