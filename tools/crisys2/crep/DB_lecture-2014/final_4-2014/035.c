#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define LEN 273

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATT;
int load(ATT d[MAX], char *filename, int size);
void print(ATT d[MAX], int size);

int load(ATT d[MAX], char *filename, int size)
{
  FILE *fp;
  char buf[LEN], name[50];
  char date[9];
  char mark;
  int len, i, id;

  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);

  size = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0'; 
    sscanf(buf,"%s %c", date, &mark);
	 for( i = 0 ; i < size ; i++ ){
    if(strcmp(date, d[i].date) == 0){
	id = i;
	break;
      }
	 }
  }
  
  if ( i == size ){// 新規の名前の追加
      strcpy(d[i].date, date);
      id = size;
      size++;
  }
	if(strcmp(name,"Alice") == 0)
      d[id].alice = mark;
	else if(strcmp(name,"Bob") == 0)
      d[id].bob = mark;
	else if(strcmp(name,"Carol") == 0)
      d[id].carol = mark;
    else
      printf("Wrong subject error: %s\n", name );
  
  return size; // データの個数を返す
}





int main(int argc, char *argv[])
{
	ATT dat[MAX];
 int i, size;
 if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for(i = 1 ; i < argc ; i++ ){ // データの読み込み
    size = load(dat, argv[i], size);
  }
  print(dat, size);

  return 0;
}
void print(ATT d[MAX], int size)
{
	char *j;
	int i, year, month, day, n;

	printf("date\t\tAlice\tBob\tCarol\n");

	for( i = 0 ; i < size ; i++ ){
		j = d[i].date;
		n = atoi(j);
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;

  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 year, month, day, d[i].alice, d[i].bob, d[i].carol );
	}
}