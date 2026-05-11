#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100;

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc,char *argv[])
{
  struct todo event[100];
  FILE *fp;
  char buf[100];
  int len;
  int n = 0,i;


  if(argc < 2){
    printf("ファイルを指定してください");
    exit(1);
  }
  if((fp = fopen(argv[1],"r")) != NULL){
    while((fgets(buf,100,fp)) != NULL){
	len = strlen(buf);
	if(buf[len - 1] == '\n')buf[len - 1] = '\0';
	sscanf(buf,"%d/%d/%d %d:%d %s",&event[n].year,&event[n].month,&event[n].day,&event[n].hour,&event[n].minute,event[n].content);
	n++;
      }
  }else{
    printf("エラーが発生しました");
    exit(1);
  }
    
  for(i = 0;i < n;i++){
    printf("%d/%.2d/%.2d %.2d:%.2d %s\n",event[i].year,event[i].month,event[i].day,event[i].hour,event[i].minute,event[i].content);
  }

 return 0;
}
