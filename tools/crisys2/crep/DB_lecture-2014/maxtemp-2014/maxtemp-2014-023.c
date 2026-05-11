#include <stdio.h>
#include <math.h>

double main()
{
  int i,b,j;
  double tem[i] , min, max, dou[i],  avg = 0, bun=0 ;
  
  for(  i=0 ; i < 7 ; i++ ){
    printf("%d日目の最高気温を入力\n" , i+1 );
    scanf("%lf", &tem[i] );
  }

  // 最高気温と最低気温を求める//
  min = 530000;
  max = 0;
  for (i = 0; i < 7 ; i++ ){
    if (min > tem[i])
      min = tem[i];
    if (max < tem[i])
      max = tem[i];
  }

  printf("最低気温: %lf\n", min);
  printf("最高気温: %lf\n", max);

  //平均値を求める//
  for(i = 0; i < 7 ; i++){
    avg = avg + tem[i];
  }
    printf("平均気温: %lf\n", avg/7);

  //分散と標準偏差を求める(//∇//) テレテレ//
  for(i = 0; i < 7 ; i++ ){
   dou[i] = (tem[i]-avg/7)*(tem[i]-avg/7);
    bun = bun + dou[i];
 }
  printf("分散: %lf\n", bun/7);
  printf("標準偏差: %lf\n", sqrt(bun/7) );

  //後は中間値だけだ!!//
  for(i = 0; i < 7 ; i++ )
    for (b = 6; b > i; --b ) {
      if (tem[b -1] > tem[b] ) {
        j = tem[b - 1];
        tem[b - 1] = tem[b];
        tem[b] = j;
      }
    }
  
    { printf("中間値: %lf\n", tem[3] ); } 

  return 0;
}
