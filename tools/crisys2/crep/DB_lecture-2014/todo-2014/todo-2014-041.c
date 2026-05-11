#include<stdio.h>
#include<stdlib.h>
#define MAX 256

int main(int argc, char *argv[]){
  int year, month, day, hour, minute;
  char content[MAX];
  FILE *fp;

  if((fp = fopen ("mytodo.txt", "r")) == NULL ){
    printf("ファイルのオープンに失敗しました");
    exit(1);
  }
  while( fgets(content,MAX,fp) != NULL ){
    sscanf(content,"%4d/%.2d/%.2d %.2d:%.2d", &year, &month, &day, &hour, &minute );
    printf("%4d/%2d/%2d %2d:%.2d\n", year, month, day, hour, minute);
  }
  return 0;
}
