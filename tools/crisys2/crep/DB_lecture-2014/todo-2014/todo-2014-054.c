#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100;

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};


int main(int argc, char *argv)
{
  int i, j;
  FILE *fp;

  struct todo item[10];

  item[0].year = 2014;
  item[0].month =12;
  item[0].day = 10;
  item[0].hour = 17;
  item[0].minute = 0;
  strcpy(item[0].content,"プログラミング課題提出");

  item[1].year = 2014;
  item[1].month = 12;
  item[1].day = 24;
  item[1].hour = 13;
  item[1].minute = 0;
  strcpy(item[1].content, "レポート提出");

  if(argc != 3)
    {
      printf("使用法：＜プログラム名＞　＜ファイル名＞　＜年,月,日,時,分,内容＞");
      exit(1);
    }


  if((fp = fopen(argv[1], "r")) == NULL)
      {
	printf("Can't open");
	exit(1);
      }

    for(i = 0; i < 10; i++)
      {
	if(argv[2] = item[i]) /* i番目のitemと一致したとき、それ以降のitemを表示する */
	{ 
	  for(j = i;j < 10; j++)
	    printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month,
		   item[i].day, item[i].hour, item[i].minute, item[i].content );
	}
      }
    fclose(fp);
 
  return 0;
}
