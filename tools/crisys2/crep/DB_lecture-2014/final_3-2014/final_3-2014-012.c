#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char name;
  char marubatu;
  int ok;       // 参加可能な人数
  int unfixed;
};

typedef struct attendance attend;

int load(attend d[MAX],char *filename)

int main(int argc, char *argv[])
{attend menber[MAX];
  int i,size,day,month,year;
  for (i = 1;i < argc;i++)
    size = load(member,argv[i]);
  sscanf( item.date, "%d", &n );
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("---------------------------------------");
  for(i = 1;i < size;i++)
    printf("%4d/%2d/%2d%t%c%t%c%t%c\n",
	   year, month, day,mamber[0].marubatu,
	   member[1].marubatu,member[2].marubatu);
}
for(i = 1;i < size;i++)
  printf("%4d/%2d/%2d%t[ok:%c ?;%c]\n", year, month, day,
	 attend.ok,attend.unfixed);

int load(attend d[MAX],char *filename)
{char buf;
  FILE *fp;
  if ((fp=fopen(filename, "r")) == NULL) {
    printf("ファイル%sのオープンに失敗しました",filename);
    exit (1);
  }
  fgets(buf,MAX,fp);
  len=strlen(buf);
  if(len>0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  size = 0;
  sscanf(buf,"#%c ",&name);
  while (fgets(buf,MAX,fp) != NULL){
    len=strlen(buf);
    if(len>0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf," %d %d",&date,&marubatu);
    size++;
  }
  while(fgets(buf,MAX,fp) != NULL)
    len=strlen(buf);
  if(len>0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  sscanf(buf,"%d %d",&ok,&unfixed);
  return size;
}
