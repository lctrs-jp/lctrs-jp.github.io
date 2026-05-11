#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct todo{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	char content[256];
}item[MAX];



int main(int argc, char *argv[])
{

	int i;
	int year, month, day;
	int len;

	/*ファイルを開く*/
	FILE *fp;
	
	if((fp = fopen(argv[2], "r")) == NULL){
		printf("ファイルを開けません\n");
		exit(1);
	}
	
	sscanf(argv[1], "%d/%d/%d", &year, &month, &day);
	
	/*ファイルを読み込む*/
	for(i = 0; i < MAX - 1; i++){
	while( fgets(item[i].content, MAX, fp) != NULL){
		/*末尾の改行記号を削除する*/
		len = strlen(item[i].content);
		if(len > 0 && item[i].content[len-1] == '\n')
			item[i].content[len-1] = '\0';
		
		sscanf(item[i].content, "%d/%d/%d", &item[i].year, &item[i].month, &item[i].day);
		
		if(year < item[i].year)
			printf("%s\n", item[i].content);
		else if((month <= item[i].month) && (day <= item[i].day))
			printf("%s\n", item[i].content);
	}
	}
	
	/*ファイルを閉じる*/
	fclose(fp);
	
	
	return 0;
}
