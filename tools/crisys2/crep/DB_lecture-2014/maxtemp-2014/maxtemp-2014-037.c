#include <stdio.h>
#include <math.h>

int main() {
  int days=7;
  int a,b,i;
  double c;
  double avg,max,min,std,var,med; //平均、最大、最小、標準偏差、分散、中央値
  //  double temp[days]={ 30.7 , 32.3 , 29.7 , 25.7 , 27.9 , 30.3 , 27.4 };
  double temp[days];

  //入力させる
  for (i=0;i<days;i++){
    printf("%d日目の最高気温を入力してください : ",i+1);
    scanf("%lf",&temp[i]);
  }
  printf("以下にデータを導出します\n");

  //平均
  avg=0.0;
  for (i=0;i<days;i++)
    {
      avg=avg+temp[i];
    }
  avg=avg/days;
  printf("平均気温 %lf 度\n",(double) avg);

  //最高最低
  min=200.0;
  max=0.0;
  for (i=0;i<days;i++)
    {
      if (min>temp[i])
	{
	  min=temp[i];
	}
      if (max<temp[i])
	{
	  max=temp[i];
	}
    }
  printf("最高気温 %lf 度\n",max);
  printf("最低気温 %lf 度\n",min);

  //標準偏差・分散
  var=0.0;
  std=0.0;
  for(i=0;i<days;i++){
    var=var+(temp[i]-avg)*(temp[i]-avg);
  }
  var=var/days;
  std=sqrt(var);
  printf("分散 %lf\n",var);
  printf("標準偏差 %lf\n",std);

  //中央値
  for(a=1;a<days;a++){
    for(b=days-1;b>=a;b--){
      if (temp[b-1]>temp[b]) {
	  //b-1とbを入れ替え
	  c=temp[b-1];
	  temp[b-1]=temp[b];
	  temp[b]=c;
	}
     }
  }
  med=temp[(days-1)/2];
  printf("中央値 %lf\n",med);
  return 0;
}
