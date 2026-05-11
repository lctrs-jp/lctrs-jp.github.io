#include <stdio.h>
#include <math.h>

int main (void)
{
	double temp[7], max, min, avg, ss, t;
	int i,j,k;
	for(i = 0; i < 7; i++){
		printf("%d日目の最高気温を入力", i + 1);
		scanf("%lf", &temp[i]);
	}//最高気温の入力が終了


	//max,min,avgの計算
	for(i = 0, max = 0, min = 80, avg = 0; i < 7; i++){
		if(max < temp[i])
			max = temp[i];//maxの検証
		if(min > temp[i])
			min = temp[i];//minの検証
		avg = avg + temp[i];
	}
	avg = avg / 7.0;

	//ss,tの計算
	ss = 0;
	for(i = 0; i < 7; i++){
		ss = ss + pow(temp[i] - avg, 2);
	}
	ss = ss / 7;

	for (i = 1; i < 7; ++i)
		for (j = 6; j >= i; --j) {
			if (temp[j - 1] > temp[j]) {
				t = temp[j - 1];
				temp[j - 1] = temp[j];
				temp[j] = t;
			}
		}
	
	
	
	//各計算終了

	//結果の表示
	printf("最大値は%lf\n", max);
	printf("最小値は%lf\n", min);
	printf("平均値は%lf\n", avg);
	printf("標準偏差は%lf\n",sqrt(ss));
	printf("分散は%lf\n",ss);
	printf("中間値は%lf\n",temp[3]);

return 0;
}