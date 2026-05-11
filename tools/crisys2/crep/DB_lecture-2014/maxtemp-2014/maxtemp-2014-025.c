#include<stdio.h>

#include<math.h>/*根号の計算を用いるために必要、コンパイル時に-lmを用いる*/

int main(void)



{
  int i , j , days;
  float temp [6],  sum , min , max , avg , sd , var ,  med , tmp ; /*sd=標準偏差　var=分散　med=中間値*/

  for ( i = 0; i < 7; i++ ) {
    printf("10/%dの最高気温を入力してください\n", i + 1 );
    scanf("%f" , & temp[i]);
  }


  /*最高気温と最低気温を求める*/

  min = 200.0; /*minとmaxを初期化*/
  max = 0.0;

    for ( i = 0 ; i < 7; i++ ){
      if( min > temp[i] )
        min = temp[i] ;
      if( max < temp[i] )
        max = temp[i];
    }

    printf("最高気温 : %0.1f\n", min );
    printf("最低気温 : %0.1f\n", max );

    /*平均、分散、標準偏差、中間値を求める*/
    /*平均、分散、標準偏差、中間値を初期化*/
    avg = 0.0;
    days = 7;
    sd = 0.0;
    var = 0.0;
    med = 0.0;


    avg =(temp[1]+temp[2]+temp[3]+temp[4]+temp[5]+temp[6]+temp[0]) / days; /*平均値の計算*/

    var = (  (temp[0] - avg) *(temp[0] - avg) + (temp[1] - avg) *(temp[1] - avg) + (temp[2] - avg) * (temp[2] - avg) + (temp[3] - avg) * (temp[3] - avg) + (temp[4]- av\
g) * (temp[4] - avg) + (temp[5]- avg) * (temp[5] - avg) + (temp[6] - avg) * (temp[6]- avg)) / days ;/*分散の計算*/

    sd = sqrtf(var); /* 標準偏差の計算*/

    /*値のソート*/
    for(i = 0; i < 7; i++)
      {
        for(j = 0; j < 7 - i; j++)
          {
            if(temp[j] > temp[j+1])
              {
                tmp = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tmp;
              }
          }
      }

    med = temp[4];


    printf("平均気温: %0.2f\n" ,   avg );
    printf("分散: %0.2f\n" , var );
    printf("標準偏差: %0.2f\n" , sd);
    printf("中間値: %0.1f\n" , med);
                     return 0;
}
