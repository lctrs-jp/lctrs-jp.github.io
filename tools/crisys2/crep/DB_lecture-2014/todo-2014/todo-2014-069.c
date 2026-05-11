#include <stdio.h>
#include <stdlib.h>
#define MAX 256
int main(int argc, char *argv[]){
  int year, month, day, hour, minute;
  char content[MAX], buf[MAX];
  FILE *fp;
  if((fp = fopen ("mytodo.txt", "r")) == NULL ){
    printf("ファイルのオープンに失敗しました");
    exit(1);
  }
  while( fgets(buf,MAX,fp) != NULL ){
    sscanf(buf,"%d/%2d/%2d %2d:%2d %s", &year, &month, &day, &hour, &minute, &content );
    printf("%2d/%2d/%2d %2d:%2d %s \n", year, month, day, hour, minute, content );
  }
  return 0;
}



