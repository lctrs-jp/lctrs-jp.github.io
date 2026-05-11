#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *source , *dest;
	char ch;
	
	if(argc != 3)
	{
		printf("入力エラー\n");
		printf("＜mycopy＞ ＜コピー元＞ ＜コピー先＞\n");
		exit(1);
	}
	
	if((source = fopen(argv[1], "r"))== NULL)
	{
		printf("Can not open source\n");
		exit(1);
	}
	
	if((dest = fopen(argv[2], "w"))== NULL)
	{
		printf("Can not open dest\n");
		exit(1);
	}
	
	while(!feof(source))
	{
		ch = fgetc(source);
		if(ferror(source))
		{
			printf("Can not read source\n");
			exit(1);
		}
		if(!feof(source))
		{
			fputc(ch,dest);
		}
		if(ferror(dest))
		{
			printf("Can not write to dest\n");
			exit(1);
		}
	}
	
	if(fclose(source) == EOF)
	{
		printf("Can not close source\n");
		exit(1);
	}
	
	if(fclose(dest) == EOF)
	{
		printf("Can not close dest\n");
		exit(1);
	}
	
	return 0;
	
	
}

