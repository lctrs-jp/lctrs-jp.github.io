#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 100

struct product {
  int date[9];
  int alice;
  int bob;
  int carol;
  int ok;
  int unfixed;
  int year;
  int month;
  int day;
};

typedef struct product PRODUCT;

void print(PRODUCT d[MAX], int size);
int load(PRODUCT d[MAX], char *filename);

int main(int argc, char *argv[])
{
  PRODUCT item[MAX];
  int i, size;
  
  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0]);
    exit(1);
  }

  for (i = 1 ; i < argc ; i++ ){
    size = load(item, argv[i]);
  }
  print(item, size);

  return 0;
}

int load(PRODUCT d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN],member[LEN], date, join;
  int len, size, i=0;

  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(member, &buf[1]);

  size = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0'; 
    sscanf(buf,"%s %s", &date, &join );
    size++;
    
    if(strcmp(member,"#Alice") == 0)
      d[i].alice = join;
    else if(strcmp(member,"#Bob") == 0)
      d[i].bob = join;
    else if(strcmp(member,"#Carol") == 0)
      d[i].carol = join;
    else
      printf("Wrong name error: %s\n", member );
    
    if(strcmp(join,"o")==0)
      d[i].ok++;
    else if(strcmp(join,"?")==0)
      d[i].unfixed++;
    else
      printf("Wrong join error: %s\n", join);
	      
  }

  return size; // データの個数を返す
}


void print(PRODUCT d[MAX], int size)
{
  int i, n;
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("------------------------------------\n");
  
  for( i = 0 ; i < size ; i++ ){
    sscanf(d[i].date, "%d", &n);
      d[i].day=n%100; d[i].month=(n/100)%100; d[i]=n/10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d,?:%d]\n",
	   d[i].year,d[i].month,d[i].day,d[i].alice,d[i].bob,d[i].carol,d[i].ok,d[i].unfixed);
    printf("--------------------------------------\n");
  }
}
