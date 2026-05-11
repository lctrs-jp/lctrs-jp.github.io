#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

struct todo item[MAX];

int main(int argc, char *argv[]){
	FILE *f;
	if((f = fopen(argv[2], "r")) == NULL){
		printf("ファイルのオープンに失敗しました。\n");
		exit(1);
	}//ファイルを開く
	
	char buf[MAX][300];
	int i;
	for(i = 0;fgets(buf[i], 300, f) != NULL; i++){
		if(strncmp(buf[i], argv[1], 10) >= 0) printf("%s", buf[i]);
	}
	
	fclose(f);
	return 0;
}
