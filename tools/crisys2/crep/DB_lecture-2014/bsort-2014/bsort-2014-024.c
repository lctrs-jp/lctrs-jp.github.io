/*********************************************
* 
* 
* 
* -----更新履歴-----
* 2014/10/23 09:12 作成
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <bits/nan.h>

double getDouble(FILE* in, size_t bufsize){
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
	free(buf);
	return temp;
}
signed long getLong(FILE* in, size_t bufsize){
	char *buf;
	signed long temp=0;

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
	temp = strtol(buf,(char **)NULL,10);
	if(errno!=0){
		temp=0;
	}
	free(buf);
	return temp;
}

int main(int nCmd, char* sCmd){
	signed long *data;
	signed long tmp;
	signed int j;
	unsigned int count;

	fprintf(stdout,"数をいくつ入力しますか：");
	tmp = getLong(stdin,32);
	count = (unsigned int)tmp;


	data = (signed long *)malloc(sizeof(long)*count);
	if(data==NULL){
		return 1;
	}
	memset(data,0,sizeof(long)*count);

	for (j = 0; j < count; j++){
		*(data+j) = getLong(stdin, 32);
	}

	/*バブルソート*/
{
	int i,j;
	unsigned int k;
	signed long tmp;
	for(i = 1; i < count; ++i){
		for(j = count - 1; j >= i; --j){
			if( *(data+j-1) > *(data+j) ){
				tmp = *(data+j-1);
				*(data+j-1) = *(data+j);
				*(data+j) = tmp;
			}
			for(k=0;k<count;k++){
				fprintf(stdout,"%d ",*(data+k));
			}
			fprintf(stdout,"\n");
		}
	}
}
	free(data);
	return 0;
}
