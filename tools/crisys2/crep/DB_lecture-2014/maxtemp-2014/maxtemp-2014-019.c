#include<stdio.h>
#include<math.h>
int main()
{
  int i,j,k,l;
  double a[7],max,min,sum,avg, bns, tyu, stdar;
  printf("一週間のそれぞれの日の最高気温を入力してください。\n");
  for(i = 0;i <7;i++){
    printf("%d 日目\n",i + 1);
    scanf("%lf",&a[i]);//気温の入力
  }

  sum = 0;
  for(i = 0;i < 7; i++){
    sum = sum+ a[i];//気温の合計を算出
  }
  avg = sum / 7 ;//平均を出す式
  printf("平均気温は %lf度です。\n", avg);
  min = a[0];//温度がマイナスでも対応できるように
  max = a[0];
  for (i = 0;i < 7; i++){
    if (min >= a[i]){
      min = a[i];
    }
  }
  for(i = 0; i < 7; i++){
    if(max <= a[i]){
      max = a[i];
    }
  }
  printf("最高気温は %lf度です。", max);//最高気温を書く
  printf("最低気温は %lf度です。", min);//最低気温を書く
  stdar = 0;
  for(i = 0;i < 7; i++){
    stdar = stdar+ (a[i] - avg)* (a[i] - avg);
  }
  bns = stdar / 7;//偏差を出す。
  printf("分散は %lfです。\n", bns);
  printf("標準偏差は %lfです。\n", sqrt(bns));
  for(i = 0;i < 7; i++){
    k=0;
    l=0;
    for(j = 0;j < 7;j++){
      if(a[i] <= a[j]){
	k = k + 1 ;
      }
      if(a[i] >= a[j]){
	l = l + 1 ;
      }
      if(k==4&& l==4){
	tyu = a[i];
	break;
      }}}
  printf("中間値は %lfです。", tyu);
  return 0;
}
