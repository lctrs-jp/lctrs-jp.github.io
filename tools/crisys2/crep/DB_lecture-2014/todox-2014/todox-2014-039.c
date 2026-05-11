#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct todo {
  int year[MAX];
  int month[MAX];
  int day[MAX];
  int hour[MAX];
  int minute[MAX];
  char content[256];
} sche;
void print(int i);

int main(int argc, char *argv[])
{
  int x[MAX], y[MAX], z[MAX], a, b, c, len;
  char buf[MAX];
  FILE *fp;

  if((fp = fopen(argv[2],"r")) == NULL){
    fprintf(stderr,"エラー：ファイルを開けません");
    exit(1);
  }

  sscanf(argv[1], "%d/%d/%d", a, b, c);
    while( fgets( buf, MAX, fp) > 0){
      if((len = strlen(buf)) > 0 && buf[len-1] == '\n'){
	len --;
	buf[len] = '\0';
      }
    }
  sscanf(argv[2], "%d/%d/%d", &x, &y, &z );

  return 0;
}

void print(int i)
{
  fprintf(stderr,"%4d/%.2d/%.2d %.2d:%.2d %s\n", sche.year[i], sche.month[i], sche.day, sche.hour[i], sche.minute[i], sche.content[i] );
  return;
}
