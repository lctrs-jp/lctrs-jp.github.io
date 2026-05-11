/**********************************
*
* ex07-*********.c
* ******* *********
*
* 2014/11/22 10:02 作成
*
* Excel列名変換問題
*********************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUF_SIZE 32

/*文字列中の小文字を大文字に変換する関数*/
void upcase(char src[])
{
        size_t l_src, i;
        l_src^=l_src;
        i^=i;
        l_src = strlen(src);
        for(i=0; i<l_src; i++){
                if( 0x61<=src[i] && src[i]<=0x7A){
                        src[i]-=0x20;
                }
        }
        return;
}

/*基数変換を行う関数*/
double ExcelConvBase26to10(const char* src, size_t dig)
{
	double temp;
	temp=0.0;

	if(dig<strlen(src))
	/*文字列の範囲内なら計算*/
	{
		/*対象の桁の数*/
		temp  = *(src+dig)-0x40;

		/*重みづけ*/
		temp  = temp * pow(26.0, (strlen(src)-dig-1) );

		/*蓄積*/
		temp += ExcelConvBase26to10(src, (dig+1));
	}else
	/*インデックスが境界を超えたらアクセスしない*/
	{
		temp=0.0;
	}
	return temp;
}

int main(int nCmd, char* cCmd[]){
	char *buf;
	unsigned int ans;

	if(nCmd<2){
		fprintf(stderr,"[ABOT]\t引数が足りません");
		return 1;
	}
	buf = (char *)malloc(sizeof(char)*BUF_SIZE);

/*ABOT	メモリ確保失敗*/
	if(buf==NULL){
		return 2;
	}

	/*作業領域にコピー*/
	strcpy(buf,cCmd[1]);
	upcase(buf);
	*(buf+5)=0;

	ans^=ans;
	ans = ExcelConvBase26to10(buf,0);

	fprintf(stdout,"%d\n",ans);

	free(buf);
	return 0;
}
