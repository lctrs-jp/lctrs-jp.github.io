#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct todo{
   int year;
int month;
int day;
int hour;
int minute;
char content[256];
};
typedef struct todo WORK;
WORK list[MAX];

void load(FILE *fp);

int main(int argc,char *argv[])
{
  FILE *fp;

  if((fp=fopen(argv[1],"r"))==NULL){
      fprintf(stderr,"Error: can't open %s.\n",argv[1]);
      exit(1);
    }
    load(fp);
    fclose(fp);  

return 0;
}

  void load(FILE *fp)
  {
    int len;
    char buf[MAX], id[MAX], name[MAX];

    while( fgets( buf, MAX, fp ) > 0 ){
      /* 末尾の改行記号を除去 */
      if( (len = strlen(buf)) > 0 && buf[len-1] == '\n' ){
	len --;
	buf[len] = '\0';
      }
    }
    return;
  }
