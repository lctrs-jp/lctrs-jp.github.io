#include <stdio.h>
#include <stdlib.h>


struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};


int main(int argc, char *argv[])
{

  char buf[256];
  int y, m, d;

  struct todo item[100];

  if(argc != 3) {
    fprintf(stderr,"使用法：%s 日にち ファイル名.txt\n", argv[0]);
    exit(1);
  }


  FILE *fp;
  if((fp = fopen(argv[2], "r+")) == NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }


  int num = 0;

  while(fgets(buf,256,fp) != NULL)
    {
      sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s\n", &item[num].year, &item[num].month, &item[num].day, &item[num].hour, &item[num].minute, item[num].content);
      num++;
    }

  sscanf(argv[1], "%4d/%2d/%2d", &y, &m, &d);


  int i = 0;

     while(i < num)
  {
    if(item[i].year > y )
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month, item[i].day, item[i].hour, item[i].minute, item[i].content);
    else if(item[i].year = y)
      {
	if(item[i].month > m )
	  printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month, item[i].day, item[i].hour, item[i].minute, item[i].content);
	else if(item[i].month = m)
	  {
	    if(item[i].day >= d )
	      printf("%4d/%2d/2%d %2d:%.2d %s\n", item[i].year, item[i].month, item[i].day, item[i].hour, item[i].minute, item[i].content);	      
	  }
      }
    i++;
  }
  
  return 0;
}
