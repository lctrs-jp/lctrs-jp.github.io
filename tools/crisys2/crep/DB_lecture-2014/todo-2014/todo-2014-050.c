#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};
typedef struct todo TODO;  /* 構造体の名前を定義 */

void display(char *fp, TODO list[100], int size, int dy, int dm, int dd );

int main(int argc, char *argv[])
{
  TODO list[100];
  int size;
  char *filename;
  filename = argv[2];

  size = load(filename,list); /* ファイル・アイテム数をロード */

  int dy,dm,dd;  /* 日時指定用の変数 */

  sscanf(argv[1], "%d/%d/%d", &dy, &dm, &dd);

  display(filename,list,size,dy,dm,dd);

  return 0;
}


/* 入力ファイルからの読み込み用の関数 */
int load(char *filename, TODO list[100],int dy,int dm,int dd) {
  FILE *fp;
  char buf[256];
  int len,size = 0;

  /* ファイルのオープン */
  if ( ( fp = fopen (filename, "r") ) == NULL ) {
    printf ("Can't open.");
    exit(1);
  }

  /* 項目が指定日時以降ならば表示 */
  while ( (fgets(buf,256,fp)) != NULL ) {
    len = strlen(buf);
    if ( len > 0 && buf[len-1] == '\n') {
      buf[len-1] = '\0';
      if((dy >= list[size].year)&&(dm >= list[size].month)&&(dd >= list[size].day)) {
      sscanf(buf,"%d/%d/%d %d:%d %s", &list[size].year, &list[size].month, &list[size].day, &list[size].hour, &list[size].minute, &list[size].content);
      size++;
      }
      else{
      	printf("Format Error\n");
      exit(1);
      }
    }

  fclose(fp);
  return size;
  fprintf(stdout,"%d",size);
  }
}

/* 出力用の関数 */ 
void display(char *fp, TODO list[100], int size, int dy, int dm, int dd ) {
  int i;
  for ( i = 0; i < size; i++) {
    if ((dy >= list[size].year)&&(dm >= list[size].month)&&(dd >= list[size].day))
      printf("%d/%d/%d %d:%d %s\n", list[size].year, list[size].month, list[size].day, list[size].hour, list[size].minute, list[size].content);
  }
}
