#include <stdio.h>
#include <math.h>

double max(double x[7]);//最高
double min(double x[7]);//最低
double ave(double x[7]);//平均
double dis(double x[7]);//分散
double div(double x[7]);//標準偏差
double med(double x[7]);//メジアン

int main(void){
	double tpl[7];
	printf("１週間の各日の最高気温を入力してください。\n");
	int i = 0;
	while(i <= 6){
		printf("Day %d :", i + 1);
		scanf("%lf", &tpl[i]);
		i++;
	}
	
	printf("週の最高気温の最　　高は%fです。\n", max(tpl));
	printf("週の最高気温の最　　低は%fです。\n", min(tpl));
	printf("週の最高気温の平　　均は%fです。\n", ave(tpl));
	printf("週の最高気温の分　　散は%fです。\n", dis(tpl));
	printf("週の最高気温の標準偏差は%fです。\n", div(tpl));
	printf("週の最高気温のメジアンは%fです。\n", med(tpl));
	return 0;
}

double max(double x[7]){
	double max = x[0];
	int i = 1;
	while(i <= 6){
		if(x[i] >= max) max = x[i];
		i++;
	}
	return max;
}

double min(double x[7]){
	double min = x[0];
	int i = 1;
	while(i <= 6){
		if(x[i] <= min) min = x[i];
		i++;
	}
	return min;
}

double ave(double x[7]){
	double sum = 0;
	int i = 0;
	while(i <= 6){
		sum += x[i];
		i++;
	}
	double ave = sum / 7;
	return ave;
}

double dis(double x[7]){
	double sum = 0;
	int i = 0;
	while(i <= 6){
		sum += x[i];
		i++;
	}
	double ave = sum / 7;//ここまでaveと一緒
	double dif = 0;
	int k = 0;
	while(k <= 6) {
		dif += ((x[k] - ave) * (x[k] - ave));
		k++;
	}
	dif /= 7;
	return dif;
}

double div(double x[7]){
	double sum = 0;
	int i = 0;
	while(i <= 6){
		sum += x[i];
		i++;
	}
	double ave = sum / 7;
	double dif = 0;
	int k = 0;
	while(k <= 6){
		dif += ((x[k] - ave) * (x[k] - ave));
		k++;
	}
	dif /= 7;//ここまでdisと一緒
	
	double div;
	div = sqrtl(dif);
	return div;
}
//ここまでクリアー！
double med(double x[7]){
	int i = 6, j = 0, k;
	while(i >= 3){
		while(j <= i - 1){
			if(x[j] > x[j+1]){
				k = x[j];
				x[j] = x[j+1];
				x[j+1] = k;
			}
			j++;
		}
		i--;
	}
	return x[3];
}
