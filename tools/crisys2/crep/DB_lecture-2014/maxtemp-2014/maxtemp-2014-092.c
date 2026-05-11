#include <stdio.h>
#include <math.h>


int main()
{
  double temp[31],min,max,avg,var,SD,t;
  int i,j,days,month;

  //使用者に月を尋ねる。
  printf("What's month？");
  scanf("%d" , &month );

  //使用者に日にちを尋ねる。
  printf("What's day？");
  scanf("%d" , &days );

  //尋ねた日から一週間分の最高気温をそれぞれ尋ねる。
  for (i = days ; i < days + 7 ; i ++ ){
    printf("%d What degrees maximum temp?:", i);
    scanf("%lf",&temp[i]);

  }
  //一週間の平均気温をだす。
  avg = 0;
  for(i = days; i < days + 7 ; i++)
    avg = avg + temp[i];
  printf("One week of average temperature: %lf\n", avg / 7 );


  //一週間の最低気温と最高気温をだす。
  min = 200;
  max = 0;
  for(i = days; i < days + 7 ; i++ ){
    if( min > temp[i] )
      min = temp[i];
    if( max < temp[i] )
      max = temp[i]; 
    }

  printf("min temp: %lf\n", min );
  printf("max temp: %lf\n", max );


  //分散値をだす。
  var = 0;
  for (i = days; i < days + 7 ; i++ ){
  var = var + (temp[i] - (avg / 7) )*(temp[i] - (avg / 7) ) / 7;
  }   
  printf("Variance: %lf\n" , var );


  //標準偏差をだす。
  SD = sqrt (var);
  printf("Standard Deviation: %lf\n", SD);
 

  //中間値を出す。
  for (i = days; i < days + 7 ; i++ )
    for (j = days + 6 ; j >= i ; j--){
      if (temp[j-1] > temp[j] ){
        t = temp[j-1];
        temp[j-1] = temp[j];
        temp[j] = t;
      }}

    printf("Median: %lf\n", temp[days + 3]);

  return 0;
}
