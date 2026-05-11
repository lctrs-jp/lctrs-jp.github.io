#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

typedef struct todo TODO;

TODO list[MAX];

int load(char *filename, TODO list[]);

int main(int argc, char *argv[])
{
  int size, i;
  char temp[LEN], *filename;
  filename = argv[2];

  size = load(filename, list);

  for(i = 0; i < size; i++)
    if(atoi(argv[1]) <= ("%d/%d/%d", list[i].year, list[i].month, list[i].day))
      printf("%.4d/%.2d/%.2d %.2d:%.2d %s\n",list[i].year, list[i].month,
	     list[i].day, list[i].hour, list[i].minute, list[i].content);
  return 0;
}

int load(char *filename, TODO list[]) 
{
  FILE *fp;
  char buf[LEN];
  int len, size = 0;

  if ((fp = fopen(filename, "r")) == NULL){
    printf("ファイル %s のオープンに失敗しました", filename);
    exit(1);
  }

  while (fgets(buf, LEN, fp) != NULL){
    len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf (buf, "%d/%d/%d %d:%d %s", &list[size].year, &list[size].month, 
	    &list[size].day, &list[size].hour, &list[size].minute,
	    &list[size].content);
    size++;
  }
  fclose(fp);
  return size;
}
    
