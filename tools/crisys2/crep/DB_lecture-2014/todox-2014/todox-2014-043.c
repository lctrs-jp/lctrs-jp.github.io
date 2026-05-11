#include <stdio.h>

#define MAX 100
#define LEN 256

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
  struct todo item[MAX];
  int i=0, y, m, d;
  char temp[LEN];
  FILE *fp;

  if(argc != 3){
    printf("引数が正しくありません\n");
    return 0;
  }
  if((fp = fopen(argv[2], "r")) ==NULL){
    printf("ファイルが開けません\n");
    return 0;
  }

  sscanf(argv[1], "%d/%d/%d", &y, &m, &d);

  while(!feof(fp)){
    fgets(temp, LEN, fp);
    if(temp =="\n")
      continue;

    sscanf(temp, "%4d/%2d/%2d %2d:%2d %s\n", &item[i].year, &item[i].month,
	   &item[i].day, &item[i].hour, &item[i].minute, &item[i].content );

    /* 指定された年月日より後なら表示*/
    if((item[i].year > y) || ((item[i].year == y) && (item[i].month > m)) || 
       ((item[i].year == y) && (item[i].month == m) && (item[i].day >= d))){
      printf("%4d/%2d/%2d %2d:%.2d %s\n", item[i].year, item[i].month,
	     item[i].day, item[i].hour, item[i].minute, item[i].content );
    }
    i++;
  }
  return 0;
}
