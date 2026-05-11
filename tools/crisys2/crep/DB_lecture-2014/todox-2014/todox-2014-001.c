#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 100

struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
}s;


int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[LEN];
  int len, size = 0;
  int y, m, d;


  if((fp = fopen(argv[4], "r")) == NULL){
    printf("ファイルを開くことができません\n" );
    exit(1);
  }

 while(fgets(buf, LEN, fp) != NULL){
    len = strlen(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf, "%d/%d/%d", &s.year, &s.month, &s.day);
    printf("%d %d %d\n", s.year, s.month, s.day);
  }
  y = atoi(argv[1]);
  m = atoi(argv[2]);
  d = atoi(argc[3]);



  return 0;
}


