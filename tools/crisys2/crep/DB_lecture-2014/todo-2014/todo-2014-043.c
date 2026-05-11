#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];};
typedef struct todo date;

int main(int argc,char *argv[])
{ date list[100];
int i,len;
    char buf[300];
    FILE *fp;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    char content[256];
    if((fp = fopen (argv[1],"r"))== NULL){
	  printf("ファイル開かず");
	  exit(1);}
    while(fgets(buf,300,fp)!= NULL)
      {len=strlen(buf);
	if(len>0&&buf[len-1]=='\n')
	  buf[len-1]='\n';
	sscanf(buf,"%d/%d/%2d %2d:%2d %s", &year, &month,
	       &day, &hour,&minute,content);   
	printf(buf,"%d/%d/%2d %2d:%2d %s",year,month, day, hour,minute,content);}
	fclose(fp);
	return 0;       

}
