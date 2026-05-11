#include<stdio.h>
#include<math.h>

int main(void)
{
  double temp[7] , min , max , avg , bun , m ;
  int days , i , t , n ;

  days = 7;

  for ( i=0 ; i < days ; i++) {
    printf("%d 日の正午の気温を入力してください: ", i + 1);
    scanf("%lf" , &temp[i]);
  }

  /* 平均を求める*/

  avg = 0 ;
  for(i=0 ; i < days; i++)
    avg = avg + temp[i];
  printf("平均気温: %lf\n" , avg / days);

    /*最高気温と最低気温を求める*/

  min = 200; /*minとmaxを初期化*/
  max = 0;
  for(i = 0 ; i< days ; i++) {
    if (min > temp[i])
      min = temp[i];
    if (max < temp[i])
      max = temp[i];
  }

  /* 標準偏差と分散を求める*/

  m = avg / days;
  bun=0;
  for(i=0 ; i < days ; i++){
    bun = bun +(temp[i] - m) * (temp[i] - m);
       }
  printf("分散: %lf\n" , (double) bun / days);
  printf( "標準偏差: %lf\n" , (double) sqrt(bun / days) );

   /*中央値を求める*/
 
  for(i=0 ; i < 7 ; i++)
    for( n =7 -1 ; n >= i ; n--)  {
       /*隣接する要素を比較する*/
      if(temp[n-1] > temp[n]) {
	 t = temp[n-1];
	 temp[n-1] = temp[n];
	 temp[n] = t;
       }
     }

  printf("最低気温: %lf\n" , min);
  printf("最高気温: %lf\n" , max);
  printf("中央値: %lf\n" , temp[3]);


  return 0;
}
