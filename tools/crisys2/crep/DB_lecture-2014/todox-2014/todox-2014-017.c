#include <stdio.h>
#include <stdlib.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}item;

int main(int argc, char *argv[]){
  int year2, month2, day2; /* 指定年月日を格納 */
  char buf[256];
  FILE *fp;

  sscanf(argv[1],"%4d/%2d/%2d", &year2, &month2, &day2);

  if((fp = fopen (argv[2], "r")) == NULL ){
    printf("ファイルのオープンに失敗しました");
  }

  while(fgets(buf, 256, fp) != NULL){
    sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s", &item.year, &item.month, &item.day, &item.hour, &item.minute, item.content );

    if(year2 < item.year)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month, item.day, item.hour, item.minute, item.content );
    else if(year2 = item.year && month2 <= item.month)
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month, item.day, item.hour, item.minute, item.content );
    else if(year2 = item.year && month2 = item.month && day2 <= item.day) 
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month, item.day, item.hour, item.minute, item.content );
  }
  return 0;
}
