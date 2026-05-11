#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

unsigned int getInt(FILE* in, size_t bufsize){
	char *buf;
	unsigned int temp=0;

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
	temp = (unsigned int)strtol(buf,(char **)NULL,10);
	if(errno!=0){
		temp=0;
	}
	free(buf);
	return temp;
}

/*unsigned intを使えば 3x2^(53)以下の整数であることが保証できる。*/
int main(){
	unsigned int n;
	n^=n;

	/*入力値をもらう*/
	while(n<2){
		fprintf(stdout,"2以上の整数を入力してください:");
		n=getInt(stdin,32);
	}

	/*初期表示*/
	fprintf(stdout,"%d",n);

	while(n!=1){
		/*奇数の場合*/
		if(n&1){
			/*3倍して1を加える*/
			n*=3;/*n+=(n<<1);*/
			n++;
		}
		/*偶数の場合*/
		else{
			n/=2;/*n>>1;*/
		}
		fprintf(stdout," --> %d",n);
	}
	fputc('\n',stdout);
	return 0;
}
