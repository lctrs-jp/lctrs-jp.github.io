#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIGIT_SIZE 10
#define BUFFER_SIZE 128

int main(){
	unsigned int counter[DIGIT_SIZE];
	unsigned int i;
	unsigned char *buf;

	i^=i;

	memset(counter,0,sizeof(unsigned int)*DIGIT_SIZE);

	buf = (unsigned char*)malloc(sizeof(unsigned char)*BUFFER_SIZE);

	if(buf==NULL){
		fprintf(stderr,"[ABOT]\tcannot allocate memory\n");
		return 1;
	}

	fprintf(stdout,"数字列を入力してください。(長さ127以下):");
	memset(buf,0,sizeof(unsigned char)*BUFFER_SIZE);
	if(fgets(buf,BUFFER_SIZE,stdin) == NULL){
		fprintf(stderr,"[ABOT]\tcannot read input\n");
		free(buf);
		return 2;
	}
	if(strchr(buf,'\n') == NULL){
		while(getc(stdin) != '\n');
	}else{
		*( buf+(strlen(buf)-1) ) = 0;
	}

	while( *(buf+i) ){
		if( 0x30<=*(buf+i) && *(buf+i) <= 0x39){
			counter[( *(buf+i)-0x30 )]+=1;
		}
		i++;
	}

	for(i^=i; i<DIGIT_SIZE; i++){
		fprintf(stdout,"%dは%3d個含まれています。\n",i,counter[i]);
	}

	free(buf);
	return 0;
}
