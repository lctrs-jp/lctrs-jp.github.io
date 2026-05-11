#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};typedef struct attendance ATTENDANCE;


void print (ATTENDANCE d[MAX]);
int load (ATTENDACE d[MAX], char *filename);

int main(int argc, char *argv[])
{

  ATTENDANCE students[MAX];
  int i, size;
  
  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for (i = 1 ; i < argc ; i++ ){
    size = load(students, argv[i]);
  }
 
  print(students);
  
  return 0;
}


int load(ATTENDANCE d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN],name[LEN];
  int len, date, size;

  //ファイルの読み込み、エラーの表示  
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
    sscanf(buf,"%d", &date );
    date = date - 1;
   
size++;


void print(ATTENDANCE d[MAX], int size,)
{
  int i;
  printf("date\t\tAlice\tBob\tCarol\n");
   printf("--------------------------------------\n");
   
   for( i = 0 ; i < 29 ; i++ ){
    printf("%4d\t%s\t%s\t%s\n", 
	   date, item[i].alice, item[i].bob, item[i].carol );
  }
  printf("--------------------------------------\n");

}
