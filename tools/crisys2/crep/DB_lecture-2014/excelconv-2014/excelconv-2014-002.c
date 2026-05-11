/*
********* ** **
入力されたアルファベットを 26 進数の捉えて対応する
10 進数の数字に変換するプログラム
(変換例)
A = 1
B = 2
Z = 26
AA = 27  (1*26+ 1 = 27)
XFD = 16384 (24*26*26 + 6*26 + 4 = 16384)
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
int a;

int conv(int len,char *str[]);   //関数convのプロトタイプ宣言

//main関数
int main(int argc,char* argv[]){
	int i;
	int c;
	int len;   //桁数
	int ans;   //返す値(10進数)

	len = strlen(argv[1]);   //桁数計算

	//引数が２個でなければエラーを返す
	if((argc<2)||(argc>3)){
		printf("useage: ./execlconv ALPHABET\n");
		return -1;
	}
	//文字列が５桁以上ならエラーを返す
	if(len>5){
		printf("stringlength is below 5.\n");
		return -1;
	}
	c = *argv[1];
	//文字列が小文字ならエラーを返す
	if((c>=97)&&(c<=122)){
		printf("please write in capitals.\n");
		return -1;
	}else{	
			ans = conv(len,&argv[1]);   //列名変換したものをansに代入
	}
	printf("%d\n",ans); 	

	return 0;
}

//列名変換　conv関数
int conv(int len,char *str[]){
	int i,n,m;
	char *p;
	char t[64];
	
	p = *str;
	
	//再帰部分
	if(len==1){
		t[0] = *p;
		t[1] = '\0';
		//printf("%d   %c    %d\n",len ,t[0],t[0]-64);
		a =  a +  (int)t[0] - 64;
	}else if(len>1){
		strncpy(t,p,1);
		t[1]='\0';
		//printf("%d   %c    %d\n",len,t[0],t[0]-64);
		n = (int)t[0] - 64;
		m =  (int)pow(26,len-1);
		//printf("%d\n",m);
		a += n * m;
		//printf("%d\n",a);
		len--;
		p++;
		strncpy(t,p,len);
		t[len]='\0';
		conv(len,&p);
	}
	return a;
}
