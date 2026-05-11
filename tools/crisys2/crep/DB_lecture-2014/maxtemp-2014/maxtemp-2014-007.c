#include <stdio.h>
#include <math.h>

int main(void)
{
  int  i, min, max ;
  float  temp[31], avg, sd, var, med; /*sd:標準偏差 var:分散 med:中間値*/
  int days, sort,j ;

  printf("記録の日数は？" ) ;
  scanf("%d", &days) ;
  
  for(i = 0; i < days; i++)
    {
      printf( "%d 日の最高気温を入力してください: ", i + 1 ) ;
      scanf("%f", &temp[i]) ;
    }

  /*平均を求める*/
  avg = 0;
   
  for(i = 0; i < days; i++)    
  avg = avg + temp[i];
  printf("平均気温: %f\n  ", avg / days ) ;
      
 
 /*気温の最大値と最小値を求める*/
  min = 300;
  max = -100; /*最大値と最小値の初期値*/

  for(i = 0; i < days; i++)
    {
      if( min > temp[i] ) min = temp[i] ;
      
      if( max < temp[i] ) max = temp[i] ;
    }

  printf("最高気温: %d\n ",max ) ;
  printf("最低気温: %d\n ",min ) ;

  /*分散を求める*/
  var = 0;

    for(i = 0; i < temp[i]; i++)
    var = var + (temp[i] - avg/days)*(temp[i] - avg/days);
    
    printf("分散: %f\n ", var /( days - 1));
  
   /*標準偏差を求める*/
    sd = sqrt(var /( days - 1));
    printf("標準偏差: %f\n ", sd);

    /*中間値を求める*/
    for(i = 0;i < days; i++)
    
    /*まず、データを整列する*/
{
    min = i;
    for(j = i + 1;j < days; j++)
     
    if(temp[min] > temp[j]) min = j;
 
    sort = temp[min];
    temp[min] = temp[i];
    temp[i] = sort;
}

    /*ここで中間値を求める*/ 
    if(days % 2 == 0) 
      printf("中央値: %f\n ",(temp[days / 2]+temp[days / 2 + 1]) / 2);
    else
      printf("中央値: %f\n ",temp[(days + 1) / 2] ) ;

 
return 0;
}
