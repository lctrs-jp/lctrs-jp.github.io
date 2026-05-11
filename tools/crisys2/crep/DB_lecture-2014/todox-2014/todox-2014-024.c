#include <stdio.h>
#include <stdlib.h>

typedef
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
} todo;

int main(int argc, char *argv[256])
{
  FILE *fp;
  char buf[256];
  if((fp = fopen("argv", "r")) == NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  };
  while( fgets(buf,256,fp) != NULL ){
    sscanf(buf,"%4d/%2d/%2d %2d:%.2d %s",&todo.year,&todo.month,&todo.day,
	 &todo.hour,&todo.minute,&todo.content);
    printf("%4d/%2d/%2d %2d:%.2d %s\n",todo.year,todo.month,
	   todo.day,todo.hour,todo.minute,todo.content);
  }
  fclose(fp);
  return 0;
}
