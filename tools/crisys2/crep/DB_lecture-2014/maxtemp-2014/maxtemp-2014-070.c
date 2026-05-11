#include <stdio.h>
#include <math.h>

int main()
{
  double temp[7],sort[7],max,min,ave,var,tmp;
  int i,j;

  /*気温入力*/
  for(i = 0; i <= 6; i++)
    {
      printf("%d日の気温は?",i+1);
      scanf("%lf",&temp[i]);
    }

  max = 0;
  min = 200;
  ave = 0;
  for(i = 0; i <= 6; i++)
    {
      if(min >= temp[i])
        min = temp[i];
      if(max <= temp[i])
	max = temp[i];
      ave = ave + temp[i];
      sort[i]=temp[i];
    }
  ave = ave / 7;
  printf("最大値 %lf\n",max);
  printf("最小値 %lf\n",min);
  printf("平均値 %lf\n",ave);

  for( i = 0; i <= 6; i++)
    {
      var = (temp[i] - ave) * (temp[i] - ave) + var;
    }
  var = var / 7;
  printf("分散 %lf\n",var);
  printf("標準偏差 %lf\n",sqrt(var));

  for(i=1;i<=6;i++)
    {
      for(j=6;j>=i;j--)
	{
          if(sort[j-1]>sort[j])
	    {
	      tmp=sort[j-1];
	      sort[j-1]=sort[j];
	      sort[j]=tmp;
	    }
	}
    }

    printf("中央値 %lf\n",sort[3]);
    return 0;
}
