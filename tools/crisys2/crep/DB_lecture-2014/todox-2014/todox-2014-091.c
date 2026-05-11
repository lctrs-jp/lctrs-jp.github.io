#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
struct todo item[100];

int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[256];
  int year1, month1, day1;
  int year2, month2, day2, hour2, minute2;
  char content2[256];
  int i = 0, n = 0;

  if (argc != 3){
    printf("年月日とファイルを指定してください\n");
    exit(1);
  }
  sscanf(argv[1], "%d/%d/%d", &year1, &month1, &day1);
  if ((fp = fopen(argv[2], "r")) == NULL){
    printf("ファイルが開けません\n");
    exit(1);
  }
  while (fgets(buf, MAX, fp) != NULL){
    sscanf(buf, "%d/%d/%d %d:%d %s", &year2, &month2, &day2, &hour2, &minute2, content2);
    if (((year1 < year2) || ((year1 == year2) && (month1 < month2))) || ((year1 == year2)) && (month1 == month2) && (day1 <= day2)){
      item[n].year	 = year2;
      item[n].month	 = month2;
      item[n].day	 = day2;
      item[n].hour	 = hour2;
      item[n].minute = minute2;
      strncpy(item[n].content, content2, 256);
      if (strlen(content2) > 0 && content2[strlen(content2)-1] == '\n'){
	content2[strlen(content2)-1] = '\0';
      }
      n++;	  
    }
  }
  for (i = 0; i < n; i++){
    printf("%4d/%.2d/%.2d %.2d:%.2d %s\n", item[i].year, item[i].month, item[i].day, item[i].hour, item[i].minute, item[i].content);
  }

  return 0;
}
