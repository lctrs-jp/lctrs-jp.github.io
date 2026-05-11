#include<stdio.h>
#include<math.h>
int main(void){
  
  double max,min,avg = 0,bun,hensa,med;
  double temp[7];
  int i,j;
  double k,l;
  char days[7][4] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
  
  //入力
  puts("その曜日の最高気温を入力してください");
  for(i = 0;i < 7;i++){
    printf("%s:",days[i]);
    scanf("%lf",&temp[i]);
  }

  //最大値
  max = temp[0];
  for(i = 1;i < 7; i++){
    if(max < temp[i]){
      max = temp[i];
	}
  }
  //最小値  
  min = temp[0];
  for(i = 1; i < 7;i++){
    if(min > temp[i]){
      min = temp[i];
    }
  }
  //平均
  for(i=0;i < 7;i++){
    avg += temp[i];
      }
  avg = avg / 7;
  //分散
  for(i = 0; i < 7;i++){
    l = temp[i] - avg;
    bun += l * l;
  }
  bun = bun / 7;
  //標準偏差
  hensa = sqrt(bun);
  //中央値
  for(i = 1;i < 7;i++){
    for(j = 6;j >= i ;j--){
      if(temp[j-1] > temp[j]){
	k = temp[j] ;
	temp[j] = temp[j-1];
	temp[j-1] = k;
      }
    }
  }
  med = temp[3];
  
  printf("最大値:%lf\n",max);
  printf("最小値:%lf\n",min);
  printf("平均:%lf\n",avg);
  printf("分散:%lf\n",bun);
  printf("標準偏差:%lf\n",hensa);
  printf("中間値:%lf\n",med);
  return 0;
}
  
