#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

typedef struct todo TODO;

TODO list[MAX];

int fileRead(char *filename, TODO list[], int length); /* listの長さを返す */

int main(int argc, char *argv[])
{
  FILE *fp;
  int year, month, day, hour, minute, i, j;

  if (argc != 3){
    printf("error!\n");
    printf("<year/month/day><file name>\n");
    exit(1);
  }

  sscanf(argv[1], "%d/%d/%d", &year, &month, &day);

  i = fileRead(argv[2], list, MAX);

  for (j = 0; j <= i; j++){
    if (list[j].year > year){
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n", 
	     list[j].year, 
	     list[j].month, 
	     list[j].day, 
	     list[j].hour, 
	     list[j].minute, 
	     list[j].content
	     );
    }else if (list[j].year == year && 
	     list[j].month > month)
{
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n", 
	     list[j].year, 
	     list[j].month, 
	     list[j].day, 
	     list[j].hour, 
	     list[j].minute, 
	     list[j].content
	     );
    } else if (list[j].year == year && 
	     list[j].month == month && 
	     list[j].day > day)
      {
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n", 
	     list[j].year, 
	     list[j].month, 
	     list[j].day, 
	     list[j].hour, 
	     list[j].minute, 
	     list[j].content
	     );
      }
  }


  return 0;
}


int fileRead(char *filename, TODO list[], int length)
{
  FILE *fp;
  char ch[256], content[256];
  int year, month, day, hour, minute, i = 0;
  if ((fp = fopen(filename, "r")) == NULL){
    printf("file can not open\n");
    exit(1);
  }

  while (feof(fp) == 0){ 	/* ファイルの内容を読み込む */
    fgets(ch, 260, fp);
    if (feof(fp) == 0){
      sscanf(ch, "%4d/%2d/%2d %2d:%2d %s", &year, &month, &day, &hour, &minute, content);

      list[i].year = year;
      list[i].month = month;
      list[i].day = day;
      list[i].hour = hour;
      list[i].minute = minute;
      strncat(list[i].content, content, 256);
      i++;
    }
  }
  return i;
}
