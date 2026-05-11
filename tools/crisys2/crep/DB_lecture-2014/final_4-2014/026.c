#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       //参加可能な人数
  int unfixed;  //参加未定(?)の人数
};

int load( struct attendance d[MAX], char *filename, int size);

int main(int argc, char *argv[])
{
  struct attendance  item[MAX];
  int n, year, month, day;
  int i, j, k, size;

  if(argc < 2) {
    printf("Usage: %s filename1 ... filename2\n", argv[0]);
    exit(1);
  }

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------------\n");

  for(i = 1; i < argc; i++)
    size = load(item,argv[i],size);
  for(j = 0; j < size; j++){
    sscanf ( item[j].date,"%d",&n );
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   item[j].alice, item[j].bob, item[j].carol);
  }
  printf("-------------------------------------------\n");
  for(k = 0; k < size; k++){
    item[k].ok = 0;
    item[k].unfixed = 0;
    if(item[k].alice == '○')
      item[k].ok = item[k].ok + 1;
    if(item[k].bob == '○')
     item[k].ok = item[k].ok + 1;
    if(item[k].carol == '○')
     item[k].ok = item[k].ok + 1;
    if(item[k].alice == '?')
      item[k].unfixed = item[k].unfixed + 1;
    if(item[k].bob == '?')
      item[k].unfixed = item[k].unfixed + 1;
    if(item[k].carol == '?')
      item[k].unfixed = item[k].unfixed + 1;
    printf("%4d/%2d/%2d [○:%d, ?:%d]\n",
	   year, month, day, item[k].ok, item[k].unfixed);
  }
  return 0;
}

 int load(struct attendance d[MAX], char *filename, int size)
  {
    FILE *fp;
    char buf[256], name[50], date[9], att;
    int len, i= 0;

    if ((fp = fopen(filename, "r")) == NULL) {
      printf("ファイルの %s オープンに失敗しました", filename);
      exit(1);
    }
    fgets(buf,256,fp);
    len = strlen(buf);
    if( len>0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    strcpy(name, &buf[1]);
    while(fgets(buf,256,fp) != NULL){
      len = strlen(buf);
      if( len>0 && buf[len-1] == '\n')
	buf[len-1] = '\0';
      sscanf(buf,"%s %c", d[i].date, att);
      if(strncmp(name,"Alice", 5) == 0)
	d[i].alice = att;
      else if (strncmp(name,"Bob", 3) == 0)
	d[i].bob = att;
      else if (strncmp(name,"Carol", 5) == 0)
	d[i].carol = att;
      else
	printf("Wrong name error: %s\n", name);
      i++;
    }
    size = i;
    return size;
  }
	  
