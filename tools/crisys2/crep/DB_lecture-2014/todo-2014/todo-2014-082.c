#include <stdio.h>
#include <stdlib.h>

struct todo{
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char exam[256];
}item[100];

int main(int argc, char *argv[])
{
  FILE *fp;

  int i = 0;
  int j;
  int y, m, d, h, min;
  char buf[256];

  if(argc != 2){
    printf("ファイル名を指定してください\n");
    exit(1);
  }

  if((fp = fopen(argv[1], "r")) == NULL){
    printf("ファイルを開くことができません\n");
    exit(1); 
   }

  while(fgets(buf, 256, fp) != NULL){
     sscanf(buf, "%d/%d/%d %d:%d %s", &item[i].year, &item[i].month, 
           &item[i].day, &item[i].hour, &item[i].minute, &item[i].exam);
     i++;
      }
  fclose(fp);

  printf("年月日と時間を入力してください\n");
  scanf("%d%d%d%d%d", &y, &m, &d, &h, &min);

  for(j = 0; j < i; j++){
    if(item[j].year > y)
      printf("%d/%d/%d %d:%d %s", &item[j].year, &item[j].month,
             &item[j].day, &item[j].hour, &item[j].minute, &item[j].exam);
    else if(item[j].year == y && item[j].month > m)
      printf("%d/%d/%d %d:%d %s", &item[j].year, &item[j].month,
             &item[j].day, &item[j].hour, &item[j].minute, &item[j].exam);
    else if(item[j].month == m && item[j].day > d)    
      printf("%d/%d/%d %d:%d %s", &item[j].year, &item[j].month,
             &item[j].day, &item[j].hour, &item[j].minute, &item[j].exam);
    else if (item[j].day == d && item[j].hour > h)
      printf("%d/%d/%d %d:%d %s", &item[j].year, &item[j].month,
             &item[j].day, &item[j].hour, &item[j].minute, &item[j].exam);
    else if(item[j].hour == h && item[j].minute > min)
      printf("%d/%d/%d %d:%d %s", &item[j].year, &item[j].month,
             &item[j].day, &item[j].hour, &item[j].minute, &item[j].exam);
  }

  return 0;
}
