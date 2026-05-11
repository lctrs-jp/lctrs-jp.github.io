#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ITEM 100
#define LOADMAX 65535
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo WORK;

WORK item[ITEM];

int load(char fname[]);

int main(int argc,char *argv[])
{
  //適切な引数でなければ弾く
  if (argc!=3) {
    printf("起動時引数が不適です(%d)\n",argc);
    return 0;
  }
  char buf[LOADMAX];
  int size,i;
  //ファイル読み込み
  size=load(argv[2]);

  //表示
  for(i=0;i<ITEM;i++) {
    if (strlen(item[i].content)!=0) {
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month,
	     item[i].day, item[i].hour, item[i].minute, item[i].content );
    }
  }
  return 0;
}


int load(char fname[]) {
  FILE *fp;
  int i=0;
  char buf[LOADMAX];

  if ((fp=fopen(fname,"r"))==NULL) {
    fprintf(stderr,"ファイル読込に失敗しました\n");
    exit(1);
  }
  while((fgets(buf,LOADMAX,fp)!=NULL) && (i<ITEM)){
    sscanf(buf,"%d/%d/%d %d:%d %s\n",&item[i].year, &item[i].month,
	   &item[i].day, &item[i].hour, &item[i].minute, &item[i].content );
    i+=1;
  }
  fclose(fp);
  return i;
}
