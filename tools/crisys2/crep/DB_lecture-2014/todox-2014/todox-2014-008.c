#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct event{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

int main(int argc, char *argv[]){
  struct event item[100];
  int i,j,k=0,n,date,time,len;
  FILE *fp;
  char *out[100],buf[256];
  
  if(argc < 2){
    printf("USAGE: %s filename1 ... filename2\n", argv[0]);
    exit(1);
  }
  for(i=1;i<argc;i++){
    if((fp=fopen(argv[i],"r")) == NULL){
      len = strlen( buf );
      if( len > 0 && buf[len-1] == '\n')buf[len-1]='\0';
      n = split(buf, out);
      if(n == 0) continue;
      else if(n < 3) fprintf(stderr,"Error(%s):%s/n",argv[i],buf);
      else{
	date = atoi(out[0]);
	item[k].year = date / 10000;
	item[k].month = (date % 10000) / 100;
	item[k].day = (date % 100);
	time = atoi(out[1]);
	item[k].hour = time /100;
	item[k].minute = time % 100;
	strncpy( item[k].content,out[2],256);
	k++;
      }
    }
    fclose(fp);
  }   
  for(i=0;i<k;i++)
    printf("%4d/%2d/%2d %2d:%.2d %s\n",item[i].year,item[i].month,item[i].day,item[i].hour,item[i].minute,item[i].content);
  return 0;
}
