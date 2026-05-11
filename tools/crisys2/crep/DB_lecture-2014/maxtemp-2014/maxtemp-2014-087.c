#include <stdio.h>
#include <math.h>

int main(void)
{
  int temp[31];
  int i,min,max,ave,avg;
  int days;
  int stdev;
  int spr;
  int intm;

  printf("月の日数は");
  scanf("%d",&days);

  for(i = 0; i < days; i++)
    {    printf("%d 日の最高の気温", i + 1);
      scanf("%d",&temp[i]);
}    
  /* 平均を求める */

  ave = 0;
  for (i = 0; i< days; i++)
    ave = ave + temp[i];
      avg = ave / days;

  printf("平均気温: %d\n",avg);
  /*　最大、最小を求める　*/

  min = 200;                  /*max,min 初期化*/
  max = 0;
  for(i = 0; i < days; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];}
    /*標準偏差*/
  {
  
    stdev = sqrt(((temp[0]-avg)*(temp[0]-avg)+(temp[1]-avg)*(temp[1]-avg)+(temp[2]-avg)*(temp[2]-avg)+(temp[3]-avg)*(temp[3]-avg)+(temp[4]-avg)*(temp[4]-avg)+(temp[5]-avg)*(temp[5]-avg)+(temp[6]-avg)*(temp[6]-avg))/ 7);  
  }
  /*分散*/
  
{
  spr = pow( stdev,2);
}
/*中間値*/
 if(fabs(temp[0] - avg) > fabs(temp[1] - avg))
   { intm = temp[1];
}else{
  intm = temp[0];
 }
 if(fabs(intm - avg) > fabs(temp[2] - avg))
   { intm = temp[2];
}
 if(fabs(intm - avg) > fabs(temp[3] - avg))
   { intm = temp[3];
}
 if(fabs(intm - avg) > fabs(temp[4] - avg))
   { intm = temp[4];
}
 if(fabs(intm - avg) > fabs(temp[5] - avg))
   { intm = temp[5];
}
 if(fabs(intm - avg) > fabs(temp[6] - avg))
   { intm = temp[6];
}
 if(fabs(intm - avg) > fabs(temp[7] - avg))
   { intm = temp[7];
}
 
 

  printf("最低気温: %d\n",min);
  printf("最高気温: %d\n",max);
  printf("標準偏差: %d\n",stdev);
  printf("分散: %d\n",spr);
printf("中間値: %d\n",intm);
   return 0;
  }
