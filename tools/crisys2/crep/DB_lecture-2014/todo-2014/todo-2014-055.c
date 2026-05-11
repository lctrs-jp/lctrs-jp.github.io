#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
} ; 

typedef struct todo TODO;
int main(int argc ,int *argv)
{
  TODO cat[100];
  int i,l,k;
  FILE *fp;
  char str[100];

  if((fp=fopen(argv[1],"rb"))==NULL){
    printf("ファイルオープンに失敗しました。");
    exit(1);
  }
  i=1;
  k=0;
  while(fgets(str,100,fp)!=NULL){
    l=strlen(str);
    if(l>0&&str[l-1]=='\n')
      str[l-1]='\0';
    sscanf(str,"%d/%d %d:%d ",cat[i].&year,cat[i].&month,cat[i].&day,cat[i].&hour,cat[i].&minute);
    printf("%d/%d %d:%d ",cat[i].year,cat[i].month,cat[i].day,cat[i].hour,cat[i].minute);
      i++;
  }
  fclose(fp);
  return 0;
}
