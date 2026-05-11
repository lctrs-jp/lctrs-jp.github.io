#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(int argc, char *argv[]) {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[MAX];
  char buf[MAX];
  FILE *fp;

  if((fp = fopen ("time.txt", "r")) == NULL ){
    printf("ファイルのオープンに失敗しました");
    exit(1);
  }
  while( fgets(buf,MAX,fp) != NULL ){
   sscanf(buf,"%4d/%2d/%2d %2d/:%.2d %s",&year,&month,&day,&hour,&minute,
         &content); 
  printf("%4d/%2d/%2d %2d:%.2d %s\n",year,month,day,hour,minute,content );
  }
return 0;
}
