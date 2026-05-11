#include<stdio.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}list[100];

int main(char *argc,char *argv)
{
  FILE *fp;
  char buf[256],a[100];
  int x,y,z,i=0,j=0,k=0;

  for(;k<*argc;k++)
    a[k]=*(argv+k);
  sscanf(a,"%d/%d/%d %c",&x,&y,&z,&fp);
  fopen("mytodo","r");
  
  if((fp=fopen("mytodo","r"))==NULL){
    printf("仕事ファイルがディスク上にありません。\n");
    return;
  }

  while(fgets(buf,256,fp)!=NULL){
    sscanf(buf,"%d/%d/%d %d:%d %c",&list[i].year,&list[i].month,&list[i].day,&list[i].hour,&list[i].minute,&list[i].content);
    i++;}

  for(;j<100;j++)
    if(list[j].year>x)
      printf("%d/%d/%d %d:%d %s",list[j].year,list[j].month,list[j].day,list[j].hour,list[j].minute,list[j].content);
    else if(list[j].year==x&&list[j].month>y)
      printf("%d/%d/%d %d:%d %s",list[j].year,list[j].month,list[j].day,list[j].hour,list[j].minute,list[j].content);
    else if(list[j].year==x&&list[j].month==y&&list[j].day>z)
      printf("%d/%d/%d %d:%d %s",list[j].year,list[j].month,list[j].day,list[j].hour,list[j].minute,list[j].content);
   
  fclose(fp);
  return 0;
}
