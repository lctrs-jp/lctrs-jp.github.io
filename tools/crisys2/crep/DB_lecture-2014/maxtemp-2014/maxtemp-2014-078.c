#include <stdio.h>

int main(void)
{
  int  i, k ;
  double avg, vara[7], varb, max, min, tep, temp[7];
  float j;


  for (i = 0 ; i < 7; i++) {
    printf("%d 日の最高気温を入力してください： ",i + 1);
    scanf("%lf", &temp[i]);
  }

    for(i = 1; i < 7; i++)
    {
        for(k = 0; k < 7 - i; k++)
        {
            if(temp[k] > temp[k + 1])
            {
                tep = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = tep;
            }
        }
    }
/*最高気温と最低気温を求める*/

    max = 0;
    min = 200;
    for(i =0 ;i < 7 ; i++){
      if (max < temp[i])
	max = temp[i];
      if (min >temp[i])
	min = temp[i];
 }

    printf("最高気温： %lf\n", max);
    printf("最低気温： %lf\n", min);

   /*平均を求める*/
  
  avg = 0.0;
    for(i = 0; i < 7 ; i++)
      avg = avg + temp[i];
    printf("平均気温： %lf\n",avg/7);

    /*分散を求める*/

    for(i =0 ;i < 7 ; i++){
      vara[i] = (avg/7 - temp[i])*(avg/7 - temp[i]);}
    varb = 0;
    for(i =0 ;i < 7 ; i++)   
      varb = varb + vara[i];
    printf("分散： %lf\n", varb/7);

    /*標準偏差を求める*/

    for(j = 0;j < 10000; j= j+0.000001) {
      if(varb/7-j*j<0.000001)
	break;}
    printf("標準偏差： %lf\n" , j);

    /*中央値を表示*/
    printf("中央値： %lf\n",temp[3]);
    
   return 0;
 }
