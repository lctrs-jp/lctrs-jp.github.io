#include <stdio.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

typedef struct todo MEMBER;

int main(int argc, char*argv[])
{
  int y, m, d, size,len;
  MEMBER list[100];
  FILE *fp;
  int i;
  char buf[100];

  if ((fp = fopen(argv[2], "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました",argv[2]);
    exit (1);
  }
  for (i=0;i<100;i++)
    if (list[i].year > y)
      fscan(fp, "%4d/%2d/%2d %2d:%.2d %s\n", list[i].year, list[i].month,
	    list[i].day, list[i].hour, list[i].minute, list[i].content );
      printf("%4d/%2d/%2d %2d:%.2d %s\n", year, month,
             day, hour, minute, content );
    else if(list[i].year >= y && list[i].month >= m && list[i].day > d)
	fscan(fp, "%4d/%2d/%2d %2d:%.2d %s\n", list[i].year, list[i].month,
	      list[i].day, list[i].hour, list[i].minute, list[i].content );
	printf("%4d/%2d/%2d %2d:%.2d %s\n", year, month,
		day, hour, minute, content );
  return 0;
}
