#include <stdio.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATT;

void print(ATT d[MAX], int size, ATT avg);
int load(ATT d[MAX], char *filename, int size);



int main(int argc, char *argv[])
{
  ATT items[MAX];
  int n, year, month, day;

  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for(i = 1 ; i < argc ; i++ ){ // データの読み込み
    size = load(items, argv[i], size);
  }
  print(items, size, avg);

  return 0;
}

int load(ATT d[MAX], char *filename, int size)
{
  FILE *fp;
  char buf[LEN],name[LEN];
  char date[50];
  char attendance;
  int len, id,i;

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
    sscanf(buf,"%d %s", &date, attendance );
    for( i = 0 ; i < size ; i++ ){
      if(date == d[i].date){
	id = i;
	break;
      }
    if ( i == size ){// 新規の日付の追加
      d[i].date = date;
	  id = size;
      size++;
    }
    
    if(strcmp(name,"Alice") == 0)
	  strcpy(d[id].alice, attendancce);
    else if(strcmp(subject,"Bob") == 0)
      strcpy(d[id].bob, attendancce);
    else if(strcmp(subject,"Carol") == 0)
      strcpy(d[id].carol, attendancce);
    else
      printf("Wrong name error: %s\n", name );
  }

  return size; // データの個数を返す
}

void print(SCORE d[MAX], int size, SCORE avg)
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");
  for( i = 0 ; i < size ; i++ ){
    printf("%4d/%2d/%2d\t%c\t%c\t%c",year, month, day,
	 items.alice, items.bob, items.carol)
	   d[i].date, d[i].alice, d[i].bob, d[i].carol );
  }
  printf("--------------------------------------\n");
  
}