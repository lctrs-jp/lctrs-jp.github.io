#include <stdio.h>
#include<math.h>

int main(void)
{ 
  float temp[7],t;
  int i,j;
  float min,max,avg;
  int days;
  double bunsan,hyojunhensa;
  
  for(i = 0; i < 7 ; i++ ){
    printf("%d 日の最高気温を入力してください:",i + 1);
    scanf("%f",&temp[i]);
  }

  /* 平均を求める */

  avg = 0;
  for(i = 0; i< 7; i++)
    avg = avg + temp[i];
  printf("平均気温: %f\n",avg / 7);
  /* 最高気温と最低気温を求める */
  min = 200;
  max = 0;
  for(i = 0; i < 7; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }
 
  printf("最高気温: %f\n", max); 
  printf("最低気温: %f\n", min);

  /* 分散および標準偏差を求める */
  
  bunsan = 0;
  for(i = 0; i<7; i++){
      bunsan = bunsan + ( (avg / 7) - temp[i] ) * ( (avg / 7) - temp[i] );
  }
   printf("分散値: %f\n", bunsan / 7);
   bunsan = bunsan / 7;
   hyojunhensa = sqrt(bunsan);
     printf("標準偏差: %f\n",hyojunhensa);

     /*中間値を求める*/
          for(i = 0; i < 7; i++){
       for(j=6; j>=i ; --j){
	 /*隣接する項を比べる*/
	 if (temp[j-1] > temp[j]){
         t= temp[j-1];
         temp[j-1]=temp[j];
         temp[j]=t;
	   }
       }
     }

     printf("中間値: %f\n",temp[3]);
     

 return 0;
}
