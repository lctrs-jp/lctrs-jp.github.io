#include <stdio.h>
#include <stdlib.h>
#define MAX 256

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[MAX];
};

int main(int argc, char *argv[])
{
  struct todo item[100];

    FILE *fp;
    char buf[MAX];

    int year,month,day,hour,minute;
    char content[MAX];
    int len;

   
    if ((fp = fopen(argv[2], "r")) ==NULL){
      printf("ファイルの読み込みに失敗しました\n");
      exit(1);
    }
    while(fgets(buf,MAX,fp) != NULL){
      if(buf[strlen(buf)-1]='\n')
	buf[strlen(buf)-1] ='\0';
      len = strlen(item);
	     
      sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s", &year, &month, &day, &hour, &minute, &content[MAX]);
      //     strcpy(item[len],year&buf


      printf("buf, %4d/%2d/%2d %2d:%.2d %s", item.year, item.month, item.day, item.hour, item.minute, item.content[MAX]);
    }

    fclose(fp); 
    return 0;
}
