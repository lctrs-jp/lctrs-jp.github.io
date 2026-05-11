#include <stdio.h>
#include<string.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo TODO;


int main(void){
  TODO list[100];
  FILE *fp;
  int x,y,z,len,i=0;
  char buf[256];
  char str[15];
  
  gets(str);
  sscanf(str,"%d/%d/%d",&x,&y,&z);
  

  if((fp=fopen("mytodo.txt","r"))==NULL){
    printf("ファイルを開けません\n");
    exit(1);
  }
  while (fgets(buf,256,fp) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d/%d/%d %d:%d %c",&list[i].year,&list[i].month,&list[i].day,&list[i].hour,list[i].minute,list[i].content);
    i++;
      }
    

  
  return 0;
}
