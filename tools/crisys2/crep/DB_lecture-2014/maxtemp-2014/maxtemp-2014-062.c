#include <stdio.h>
#include <math.h>

int main()
{
	//temp[1～7]を使用予定
	int i;
	double temp[8] ,min,max,avg;
	//分散と標準偏差
	double var,stddev;
	
	printf("一週間分の最高気温を入力して下さい\n");
	
	//temp[1～7]を使用
	for (i=1 ; i<8 ; i++){
		printf("Day_%d : " , i );
		scanf("%lf" , &temp[i]);
	}
	
	//平均を求める
	avg = 0;
	for (i=1 ; i<8 ; i++)
	avg = avg + temp[i];
	avg = avg/7;
	printf("最高気温の平均: %lf\n" , avg );
	
	//最高気温の最大と最少を求める
	min = 200; /*minとmaxを初期化*/
	max = 0;
	for (i=1 ; i<8 ; i++){
		if (min>temp[i])
		min=temp[i];
		if (max<temp[i])
		max=temp[i];
	}
	printf("最高気温の最大値: %lf\n" , min);
	printf("最高気温の最大値: %lf\n" , max);
	
	//分散を求める
	var=0;
	for (i=1; i<8 ; i++)
	var=var+(temp[i]-avg)*(temp[i]-avg);
	var=var/7;
	printf("分散: %lf\n" , var);
	
	//標準偏差を求める
	stddev= sqrt(var);
	printf("標準偏差: %lf\n" , stddev);
	
	//中間値を求める
	int a, b;
	double c;
	
	//バブルソート
	for(a=1;a<8;a++){
		for(b=7;b>a;b--){
			if(temp[b-1]>temp[b]){
				c=temp[b-1];
				temp[b-1]=temp[b];
				temp[b]=c;
			}
		}
	}
	printf("中間値: %lf\n" , temp[4]);
	
	
	
	return 0;
}
  
   
