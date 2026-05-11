/*********************************************
* bmi.c
* 
* 
* -----更新履歴-----
* 2014/10/09 21:32 初版
* 2014/10/16 09:04 体重の単位をkgに修正
*                  BMIの表示形式を変更
*            10:41 プロンプト部を親切に改善
*            11:11 ２版一応完成
*            11:18 学籍番号間違いを修正
* 2014/10/17 18:40 数値入力を外部関数化
*            19:15 ３版完成。ここで提出。
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*NANを扱う関係で必要*/
#include <math.h>
#include <bits/nan.h>

/*入力を求めるかどうかのフラグ*/
#define FLAG_T 1
#define FLAG_W 2

/*入力バッファサイズ*/
#define BUF_SIZE 32

/*数値入力関数
* inからdouble型の数値を返す。
* この時bufsizeで指定されたサイズの入力バッファを使う。
* エラーが発生した場合はNANを返す。
*/
double getDouble(FILE* in, size_t bufsize){
	int i=0;
	char *buf;
	double temp=NAN;

	buf = (char *)malloc(sizeof(char)*bufsize);
/*ABOT	メモリ確保失敗*/
	if(buf==NULL){
		return temp;
	}
	memset(buf,0,sizeof(char)*bufsize);
/*ABOT	IOエラー（たぶんメモリ関係）*/
	if(fgets(buf,bufsize,stdin) == NULL){
		free(buf);
		return temp;
	}

	/*バッファ掃除*/
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

int main(int nCmd, char* cCmd[]){
	double height=-1.0, weight=-1.0, bmi=-1.0;
	char flag = (FLAG_T | FLAG_W);
	int looplimit=3;

	/*[exec] [身長] [体重]*/
	if(nCmd >= 3){
		/*身長を処理*/
		{
			errno^=errno;
			height=strtod(cCmd[1],(char **)NULL);
			if(errno==0 && height>0.0){
				flag^=FLAG_T;
				fprintf(stdout,"[info]\tusing [%2.2lf m] as your hight\n",height);
			}else{
				fprintf(stderr,"[warn]\tinvalid value as height(%s)\n",cCmd[1]);
			}
		}
		/*次は体重を処理*/
		{
			errno^=errno;
			weight=strtod(cCmd[2],(char **)NULL);
			if(errno==0 && weight>0.0){
				flag^=FLAG_W;
				fprintf(stdout,"[info]\tusing [%2.2lf m] as your wight\n",weight);
			}else{
				fprintf(stderr,"[warn]\tinvalid value as weight(%s)\n",cCmd[2]);
			}
		}
	}

	/*身長を聞くフラグが立っていたら入力を求める*/
	while(flag&FLAG_T){
		fprintf(stdout,"Hight[m]:");

		/*WARN	以前はABOT。何らかの原因で入力を受け付けられなかった。リトライ。*/
		height = getDouble(stdin,32);
		if(isnan(height)){
			fprintf(stderr,"[warn]\tFailed to get number!\n");
			flag|=FLAG_T;
		}

		/*WARN	意味*/
		if(height<=0.0){
			/*身長は正の値だと思われるため，0以下の場合Loopします。0除算対策も兼ねています。*/
			fprintf(stderr,"[warn]\tinvalid value as height(%2.2lf)\n",height);
			flag|=FLAG_T;
		}else{
			flag^=FLAG_T;
		}

		/*ABOT	ワーニング多発*/
		looplimit--;
		if(looplimit<1){
			fprintf(stderr,"[abot]\tToo many warnings!\n");
			return 1;
		}
	}

	/*身長とほぼ同じ処理を体重に対しても行います。*/
	looplimit=3;
	while(flag&FLAG_W){
		fprintf(stdout,"Weight[kg]:");

		/*WARN	以前はABOT。何らかの原因で入力を受け付けられなかった。リトライ。*/
		weight = getDouble(stdin,32);
		if(isnan(weight)){
			fprintf(stderr,"[warn]\tFailed to get number!\n");
			flag|=FLAG_W;
		}

		/*WARN	意味*/
		if(weight<=0.0){
			fprintf(stderr,"[warn]\tinvalid value as weight(%2.2lf)\n",weight);
			flag|=FLAG_W;
		}else{
			flag^=FLAG_W;
		}

		/*ABOT	ワーニング多発*/
		looplimit--;
		if(looplimit<1){
			fprintf(stderr,"[abot]\tToo many warnings!\n");
			return 2;
		}
	}

	bmi = weight/(height*height);

	fprintf(stdout,"あなたはBMIが%2.2lfなので",bmi);
	if(bmi<18.5){
		fprintf(stdout,"痩せ");
	}else if(bmi<25.0){
		fprintf(stdout,"標準");
	}else if(bmi<30.0){
		fprintf(stdout,"肥満");
	}else{
		fprintf(stdout,"高度肥満");
	}
	fprintf(stdout,"です。\n");
	return 0;
}
