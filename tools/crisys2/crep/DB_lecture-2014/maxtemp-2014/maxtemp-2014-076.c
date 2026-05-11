#include <stdio.h>
#include <math.h>



int i,t;			/* カウント用  */

int main(void)
{
  double temp[7];
  double min,max,avg,var,dev,med,dum;
  //最小値、最大値、平均、分散、標準偏差、中間値、一時記憶場所



  //int days;

  //printf("月の日数は？");
  //scanf("%d",&days);

  printf("\nまず");

  for (i = 0; i < 7; i++ ){
    printf("%d日目の最高気温を実数で入力してください：", i + 1 );
    scanf("%lf",&temp[i]);
    if (i < 5 )    
      printf("\n次に");
    else {
      if ( i == 5 )
	printf("\n最後に");
    }  
  }

  /* 平均を求める*/

  avg = 0;
  for (i = 0; i < 7; i++){
    avg = avg + temp[i];
    
  }
  avg = avg / 7; 
  
  printf("最高気温の");
  printf("\t平均： %lf\n", avg );

/* 最高気温と最低気温を求める*/
//  min = 200.0; 			/* min と　max　を初期化*/
//  max = 0;
// for (i = 0; i < 7; i++){
//    if (min > temp[i])
//      min = temp[i];
//    if (max < temp[i])
//      max = temp[i];
//  }



//小さい順に並べ替えて最小値、最大値、中央値を調べる

  for (i = 0; i < 6; i++){
    for (t = 0; t < 6 - i; t++){
      if ( temp[t] > temp[t + 1] ){
	dum = temp[t];
	temp[t] = temp[t + 1];
	temp[t + 1] = dum;
      }
    }
  }
  max = temp[6];
  min = temp[0];
  med = temp[3];


  printf("\t\t最小値： %lf\n", min );
  printf("\t\t最大値： %lf\n", max );
  printf("\t\t中間値： %lf\n", med );
  //分散と標準偏差を求める

  var = 0.0;
  dev = 0.0;
  for (i = 0; i < 7; i++){
    var = var + (temp[i] - avg) * (temp[i] - avg);
  } 
  var = var / 7;

  dev = sqrt(var);

  printf("\t\t分散： %lf\n", var );
  printf("\t\t標準偏差： %lf\n", dev );


  return 0;
}




  

  
