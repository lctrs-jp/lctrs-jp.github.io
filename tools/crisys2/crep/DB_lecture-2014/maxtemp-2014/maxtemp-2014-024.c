#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <bits/nan.h>

double getDouble(FILE* in, size_t bufsize){
	int i=0;
	char *buf;
	double temp=NAN;

	buf = (char *)malloc(sizeof(char)*bufsize);
	if(buf==NULL){
		return temp;
	}
	memset(buf,0,sizeof(char)*bufsize);
	if(fgets(buf,bufsize,stdin) == NULL){
		free(buf);
		return temp;
	}
	if(strchr(buf,'\n') == NULL){
		while(getc(stdin) != '\n');
	}else{
		*( buf+(strlen(buf)-1) ) = 0;
	}
	errno^=errno;
	temp = strtod(buf,(char **)NULL);
	if(errno!=0){
		temp=(double)NAN;
	}
	return temp;
}

#define __DEBUG_LEVEL__ 100
#define DATA_COUNT 7
#define CALC_COUNT 6

int main(int nCmd, char* sCmd[]){
	double data[DATA_COUNT];
	double calc[CALC_COUNT];
	double tmp;
	int j;

//double getDouble(FILE* in, size_t bufsize);
	for (j = 0; j < DATA_COUNT; j++){
		fprintf(stdout, "最高気温を入力[%d日目]:",j+1);
		tmp = getDouble(stdin, 32);
		if (fpclassify(tmp) == FP_NORMAL){
			data[j] = tmp;
		}
		else{
			fprintf(stdout, "[WARN]\t不正な値なので0.0を使用\n");
			data[j] = 0.0;
		}
	}
	/*バブルソート*/
	{
		int i,j;
		double tmp;
		for(j=0;j<DATA_COUNT;j++){
			for(i=0;i<(DATA_COUNT-1);i++){
				if(data[i] > data[i+1]){
					tmp = data[i+1];
					data[i+1] = data[i];
					data[i] = tmp;
				}
			}
		}
	}
/*最大値:	CALC_COUNT=0
ソート後は一番最後にある*/
	calc[0]=data[6];

/*最小値:	CALC_COUNT=1
ソート後は一番前にある*/
	calc[1] = data[0];

/*平均:		CALC_COUNT=2*/
	calc[2]=data[0];
	for(j=1;j<DATA_COUNT;j++){
		calc[2]+=data[j];
	}
	calc[2] /= DATA_COUNT;

/*標準偏差:	CALC_COUNT=3
 *分散:		CALC_COUNT=4*/
	calc[4] = pow(data[0]-calc[2],2.0);

	for(j=1;j<DATA_COUNT;j++){
		calc[4]+=pow(data[j]-calc[2],2.0);
	}
	calc[4] /= DATA_COUNT;
	calc[3] = sqrt(calc[4]);

/*中央値:	CALC_COUNT=5
定義上，ソート後データの真ん中にある*/
	calc[5] = data[3];

/*計算結果表示*/
	fprintf(stdout,"最高気温データにおいて，\n");
	fprintf(stdout,"最大値は%3.3lf\n",calc[0]);
	fprintf(stdout,"最小値は%3.3lf\n",calc[1]);
	fprintf(stdout,"平均は%3.3lf\n",calc[2]);
	fprintf(stdout,"偏差は%3.3lf\n",calc[3]);
	fprintf(stdout,"分散は%3.3lf\n",calc[4]);
	fprintf(stdout,"中間値は%3.3lf\n",calc[5]);
	return 0;
}
