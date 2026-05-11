#include <stdio.h>
#include <stdlib.h>
#define MAX 100
 
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
  int i;
  FILE *fp;
  char buf[MAX];

  struct todo item = { 2014, 12, 10, 17, 0, "プログラミング課題提出" };
   printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
	  item.day, item.hour, item.minute, item.content );

  if( (fp = fopen( "argv[1]", "r" )) == NULL ) {
    printf( "ファイルがオープンできません\n" );
    exit( 1 );
  }
  /*構造体配列への読み込み*/
  for( i = 0; i < MAX; i++ ){ 
    sscanf(buf, "%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
          item.day, item.hour, item.minute, item.content);
  printf("%4d/%2d/%2d %2d:%.2d %s\n", item.year, item.month,
          item.day, item.hour, item.minute, item.content );
  break;
  fclose(fp);
}
  return 0;
}



