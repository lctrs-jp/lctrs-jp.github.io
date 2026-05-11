/**********************************
*
* 
* 
*
* 2014/11/27 10:54 作成
*
* 第9回講義の課題 mycopy
*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUF_SIZE
	/*一度にコピーしようとするサイズ
	メモリ制限の厳しい環境では1にすることを推奨*/
	#define BUF_SIZE 32
#endif

void usage(void);

int isFileExist(const char* filename);

/*[bin] [source] [destination]*/
int main(int nCmd, char* cCmd[]){
	FILE *src, *dest;
	void *buf;
	size_t read_size, write_size;

	src  = NULL;
	dest = NULL;
	buf  = NULL;
	read_size^=read_size;
	write_size^=write_size;

	if(nCmd<3){
		usage();
		return 1;
	}

/*srcは本当に存在するか*/
	if(!isFileExist(cCmd[1]))/*not存在*/
	{
		fprintf(stderr,"[ABOT]\tFile doesn't exist. [%s]\n",cCmd[1]);
		return 2;
	}

/*destがすでに存在するかどうか*/
	if(isFileExist(cCmd[2]))/*すでに存在*/
	{
		fprintf(stderr,"[ABOT]\tAlready file exists. [%s]\n",cCmd[2]);
		return 3;
	}else/*まだない*/
	{
		buf = malloc(BUF_SIZE);
		if(buf==NULL){
			fprintf(stderr,"[ABOT]\tCannot allocate memories.\n");
			return 4;
		}

		src  = fopen(cCmd[1],"rb");
		dest = fopen(cCmd[2],"wb");

		while(!feof(src)){
			memset(buf,0,BUF_SIZE);
			read_size  = fread(buf,1,BUF_SIZE,src);
			write_size = fwrite(buf,1,read_size,dest);
			if(read_size != write_size || ferror(src) || ferror(dest)){
				fprintf(stderr,"[ABOT]\tCannot write file. [%s]\n",cCmd[2]);
				free(buf);
				fclose(dest);
				fclose(src);
				return 5;
			}
		}
		free(buf);
		fclose(dest);
		fclose(src);
	}
	return 0;
}

int isFileExist(const char* filename){
	FILE *fp;
	fp = fopen(filename,"rb");
	if(fp!=NULL)/*存在*/
	{
		fclose(fp);
		return 1;
	}else{/*not存在*/
		return 0;
	}
}

void usage(void){
	fprintf(stdout,"Usage: [bin] [Source] [destination]\n");
	return;
}
