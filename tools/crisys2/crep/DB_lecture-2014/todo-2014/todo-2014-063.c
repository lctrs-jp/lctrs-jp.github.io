#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define LEN 256

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[LEN];
};

typedef struct todo TODO;

int main(int argc, char *atgv[])
{   if( argc != 3)
     return 0;

	TODO item[MAX];
	char *filename;
	filename = arg[2];

	load(filename, TODO item[]);

	printf("%4d/%.2d/%.2d%.2d:%.2d%s¥n", item.year, item.month, item.day, item.hour, item.minute, item.content);
	return 0;
}
  
   
  }
void load(char *filename, TODO item[])
{ FILE *fp;
  int len;

  if  ((fp = fopen (filename, "r")) == NULL) {
    printf ("ファイル %s のオープンに失敗しました",filename);
    exit (1);
  }


  while (fgets(item,MAX,fp) != NULL){
    len = strlen(item);
	if( len >0 && item[len-1]=='\n')
      item[len-1] = '\0'; 
    sscanf("%4d/%.2d/%.2d%.2d:%.2d%s", item.year, item.month, item.day, item.hour, item.minute, item.content);
  }
  fclose(fp);
}
 
