#include<stdio.h>
#include<math.h>
int main()
{
  float temp[7],t, min, max, avg, sd, vari, med;
  int i, a, b;
  
  printf("1週間の各日の最高気温からいくつかのデータを出します。¥n");
  
  //1週間分の最高気温の入力
  for(i = 0; i < 7; i++){
    printf("%d日目の最高気温を入力してください:", i + 1);
    scanf("%f", &temp[i]);
  }
  
  //平均
  avg = 0;
  for(i = 0; i < 7; i++){
    avg = avg + temp[i];
  }
  avg = avg / 7;
  
  //最大最小
  min = 200;
  max = 0;
  for (i = 0; i < 7; i++){
    if(min > temp[i]){
      min = temp[i];
    }
    if(max < temp[i]){
      max = temp[i];
    }
  }
  //分散、標準偏差
  vari = 0;
  for(i = 0; i < 7; i++){
    vari = vari + (temp[i] - avg) * (temp[i] - avg);
  }
  vari = vari / 7.0;
  sd = sqrt(vari);
  
  //中央値(バブルソート→中央）
  for(a = 1; a < 7; ++a){
    for(b = 6; b >= a; --b){
      if(temp[b -1] > temp[b]){
      	t = temp[b - 1];
      	temp[b - 1] = temp[b];
      	temp[b] = t;
      }
    }
  }
  med = temp[3];
  
  //結果の出力
  printf("最高気温の¥n");
  printf("平均値: %f¥n", avg);
  printf("最大値: %f¥n", min);
  printf("最大値: %f¥n", max);
  printf("分散 : %f¥n", vari);
  printf("標準偏差: %f¥n", sd);
  printf("中央値: %f¥n", med);
  
  return 0;
}
