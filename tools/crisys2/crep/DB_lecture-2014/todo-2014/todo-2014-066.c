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

int main(void)
{
  struct todo item;
  char buf[100];
  char *p;
  FILE *file;
  file = fopen("mytodo.txt","r");
  // fscanf(file,"%s",&buf);
 fgets(buf, sizeof(buf), file);

  fclose(file);
   p = strchr(buf, '\n');
   if(p != NULL)
{ *p = '\0';
}
 sscanf(buf,"%4d/%2d/%2d %2d:%2d %s\n", &item.year, &item.month,
	 &item.day, &item.hour, &item.minute, &item.content );
 printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
	item.day, item.hour, item.minute, item.content );
  return 0;
}
