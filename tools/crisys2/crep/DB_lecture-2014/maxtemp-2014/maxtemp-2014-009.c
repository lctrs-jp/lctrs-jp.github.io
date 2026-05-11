#include<stdio.h>
#include<math.h>

int main(void)
{
  int temp[31] , i , j ,  avg , max , min , a ;
  double sta , hyo , ou ,t ;
  int days;

  printf("月の日数は？");
  scanf("%d",&days);

  for (i=0;i<days;i++){
    printf("%d 日の正午の気温を入力してください:  ",i+1);
    scanf("%d",&temp[i]);
  }

  avg = 0;
  for(i=0;i < days;i++)
    avg = avg + temp[i];
  printf("平均気温: %d\n",avg / days);

  min = 200;
  max = 0;
  for( i=0 ; i < days;i++){
    if(min > temp[i])
      min = temp[i];
    if(max < temp[i])
      max = temp[i];
  }

  printf("最低気温：%d\n" , min);
  printf("最高気温：%d\n" , max);

  for(i=0 ; i < days;i++){
   
    sta += ( temp[i] - avg/days ) * ( temp[i] - avg/days) / days;

  }
  printf("分散：%f\n ", sta);
 
  printf("標準偏差:%f\n", hyo = sqrt(sta));

  for(i = 1;i<days;++i)
    for(j = days-1;j>=i;--j){
      if(temp[j-1]>temp[j]){
        t=temp[j-1];
        temp[j-1] = temp[j];
        temp[j]=t;
      }
    }

  printf("中央値：%d", temp[3]);

  return 0;
}
