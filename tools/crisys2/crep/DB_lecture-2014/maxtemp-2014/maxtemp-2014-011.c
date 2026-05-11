#include <stdio.h>
#include <math.h>

int main()
{
  double temp[31],min,max,avg,var,dev,t;
  int i,j,days,month;

  printf("何月？");
  scanf("%d", &month );

  printf("何日？");
  scanf("%d", &days );

  for (i = days ; i < days + 7 ; i++ ){
    printf("%d 日の最高気温を入力してください: ", i );
    scanf("%lf", &temp[i]);

  }



  avg = 0;
  for (i = days; i < days + 7 ; i++ )
    avg = avg + temp[i];
      printf("一週間の平均気温: %lf\n", avg / 7 );



   min = 200;
   max = 0;
   for (i = days; i < days + 7 ; i++ ) {
     if (min > temp[i])
       min = temp[i];
     if (max < temp[i])
       max = temp[i];
    }
 
     printf("最低気温: %lf\n", min );
     printf("最高気温: %lf\n", max );


    
     var = 0;
     for (i = days; i < days + 7 ; i++) {
       var = var + (temp[i] - avg / 7 )*(temp[i] - avg / 7 ) / 7;
     }
      
       printf("分散: %lf\n", var );

     
       dev = sqrt (var);
       printf("標準偏差: %lf\n", dev ); 
 
      
      
     for (i = days; i < days + 7 ; i++ ) 
       for (j = days + 6 ; j >= i ; j-- ){
         if (temp[j-1] > temp[j] ) {
           t = temp[j-1];
           temp[j-1] = temp[j];
           temp[j] = t; 	  
                               
	  }         
	 }

	 printf("中央値: %lf\n", temp[days + 3] );
  
  return 0;
}  
