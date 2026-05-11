#include <stdio.h>
#include <stdlib.h>
struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content [256];
};
typedef struct todo CONTENT;


int main (int argc, char *argv[]){

  CONTENT list[100];
  int op,size;
  char temp[256],*filename;
  filename = argv[1];

  size = load(filename,list);
}


int load(char *filename, CONTENT list[]){
  FILE *fp;
  char buf[256];
  int len,size = 0;

  if ((fp = fopen(filename,"r")) == NULL){
    printf("ファイル%sのオープンに失敗しました",filename);
    exit(1);
  }
  while (fgets(byf,LEN,fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0'


