#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}list[100];

int main(int argc,char *argv[]){
  FILE *fp;
  char buf[256];
  int len,i=0,a=0,b=0,c=0,j=0;
 
  sscanf(argv[1],"%d/%d/%d",&a,&b,&c);
  if((fp=fopen(argv[2],"r"))==NULL){
    printf("ファイルを開けません\n");
    exit(1);
  }
  while(fgets(buf,256,fp)!=NULL){
    len = strlen(buf);
    if(len>0 && buf[len-1] == '\n')
      {buf[len-1]='\0';}
    sscanf(buf,"%d/%d/%d %d:%d %s",&list[i].year,&list[i].month,&list[i].day,&list[i].hour,&list[i].minute,&list[i].content);
   i++;}
  fclose(fp);
  while(j<i){
    if(list[j].year>=a &&  list[j].month>=b && list[j].day>c)     
      printf("%d/%.2d/%.2d %.2d:%.2d %s\n",list[j].year,list[j].month,list[j].day,list[j].hour,list[j].minute,list[j].content);
 j++; 
 }
  return 0;
}
    
    

