#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 256

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo TODO;


int main(int argc, char *argv[])
{
  TODO list[100];
  FILE *fp;
  char buf[LEN];
  int i = 0;
  int len;

  if((fp = fopen(argv[2],"r")) == NULL){
    printf("ファイルを開けませんでした!\n");
    exit(1);
  }
  
    while(fgets(buf,LEN,fp) != NULL){
      sscanf(buf,"%d/%d/%d %d:%d %c", &list[i].year, &list[i].month, &list[i].day
	     , &list[i].hour, &list[i].minute, list[i].content); /* 日付を読み込む */
    
      printf("%d/%d/%d %d:%.2d %c\n", list[i].year, list[i].month, list[i].day, list[i].hour, list[i].minute, list[i].content);
      i++;
    }
    return 0;
}
  
