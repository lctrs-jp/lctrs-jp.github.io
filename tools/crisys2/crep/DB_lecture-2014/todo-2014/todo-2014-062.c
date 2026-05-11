#include <stdio.h>
#include <string.h>
#define MAX 100 //最大限

sruct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

struct catalog todo[MAX];

int main(int argc,char *argv[])
{
  char buf[256];
  int len, size,i,n,m,l;
  FILE *fp;
  
  if ((fp = fopen(file1, "r")) == NULL){
    printf("オープン失敗\n");
    exit(1);
  }
  while (fgets(buf, 256, fp) != NULL){
    for(i=0; i<MAX; i++)
    sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s\n", &item.year[i], &item.month[i],
	   &item.day[i], &item.hour[i], &item.minute[i], item.content[i] );


    len = strlen(buf);
    if (len > 0 && buf[len-1] =='/n')
      buf[len-1] = '/0';

    argc = {"%d/%d/%d",&n,&m,&l};
    for(i = 0;i < MAX;i++){
      if(n < item.year[i]){
	printf("%d/%d/%d %d:%d %s\n",item.year[i],item.month[i], item.day[i], item.hour[i], item.minute[i], item.content[i] );
      }else if{


 

    for(i=/*?*/;i 
    printf()

  }    
    
  fcloss(fp);
  return;
  
 


  /*struct todo item = { 2014, 12, 10, 17, 0, "プログラミング課題提出" };
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
	 item.day, item.hour, item.minute, item.content );
  return 0;
  */
}

