#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 100

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数

};

typedef struct attendance ATTENDANCE;

void print(ATTENDANCE d[MAX], int size, ATTENDANCE avg);
int load(ATTENDANCE d[MAX], char *filename);
ATTENDANCE sum(ATTENDANCE d[MAX], int size);

int main(int argc, char *argv[])
{
  ATTENDANCE students[MAX], avg;
  int i, size;
  
  if( argc < 4 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }
for (i = 1 ; i < argc ; i++ ){
  size = load(students, argv[i]);
 }

print(students, size);

return 0;
}

int load(ATTENDANCE d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN],subject[LEN];
  int len, id, score, size;

  if( (fp = fopen (filename, "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", filename);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(subject, &buf[1]);

  size = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0'; 
    sscanf(buf,"%d %d", &id, &attendance );
    id = id - 1;
    size++;
    
    if(strcmp(subject,"Alice") == 0)
      d[id].alice = attendance;
    else if(strcmp(subject,"Bob") == 0)
      d[id].bob = attendance;
    else if(strcmp(subject,"Carol") == 0)
      d[id].carol = attendance;
    else
      printf("Wrong subject error: %s\n", subject );
  }

  return size; // データの個数を返す
}



void print(ATTENDANCE d[MAX], int size )
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  for( i = 0 ; i < size ; i++ ){
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	   i+1, d[i]. year, d[i].month, d[i].day,
	      d[i].alice, d[i].bob, d[i].carol,
	      d[i].ok, d[i].unfixed );	  
   }
  printf("--------------------------------------\n");
 
}
