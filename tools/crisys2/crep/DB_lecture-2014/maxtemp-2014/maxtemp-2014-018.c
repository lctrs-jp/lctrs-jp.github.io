#include <stdio.h>

#include <math.h>
  
int main()
{
 float tep,temp[7],min,max,avg,e,e2,h,a;
 int days;
 int i, j;
 days = 7;
  

 for (i = 0; i < days; i++) {
  printf("%d 日の最高気温を入力してください: ", i + 1);
  scanf("%f", &temp[i]);
  }

  /* 平均を求める */
  avg = 0;
  for (i = 0; i < days; i++)
   avg = avg + temp[i];
  printf("平均気温 : %f\n" , avg / days);


  /* 最高気温と最低気温を求める */
  min = 200; /* minとmaxを初期化 */
  max = 0;
   for (i = 0; i< days; i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  printf("最低気温: %f\n", min);
  printf("最高気温: %f\n", max);

  /* 分散を求める */
   e = 0;
   e2 = 0;
   h = 0;
  
   for(i = 0; i< days; i++){
    h = (temp[i] - avg / days);
    e = h * h;
    e2 = e2 + e;
   }

   printf("分散: %f\n", e2 / days);

  /* 標準偏差を求める */
  printf("標準偏差 : %f\n", sqrt(e2 / days));


  /* 中間値を求める */
  for (i = 0; i < days ; ++i){
    for(j = days - 1; j >= i; --j){
      if(temp[j - 1]> temp[j]){
       tep = temp[j-1];
       temp[j - 1] = temp[j];
       temp[j] = tep;
      }
    }
    }


  printf("中間値 ; %f\n", temp[3]);
  

  return 0;
}			       
