#include <stdio.h>
#include <stdlib.h>



void load(FILE *fp);
#define MAX 100


struct todo {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char content[256];
};

struct todo list[MAX];

int main(int argc, char *argv[])
{
  FILE *fp;

  /* 起動時引数が指定されている場合の処理 */
  if( argc == 2 ){ /* ファイル名1つが指定された場合 */
    if( (fp = fopen(argv[1],"r")) == NULL ){
      fprintf(stderr,"Error: can't open %s.\n", argv[1]);
      exit(1);
    }
    load( fp ); /* ファイルからデータを読み込み */
    fclose( fp );
  }else if( argc > 2 ){ /* 2つ以上の引数を指定された場合 */
    fprintf(stderr,"Usage: %s [filename]\n", argv[0] );
    exit(1);
  }

  
  return 0;



}

void load(FILE *fp)
{
  int len, ye, mo, da, ho, min;
  char buf[MAX], con;

  if( fgets( buf, MAX, fp ) > 0 ){
    /* 末尾の改行記号を除去 */
    if( (len = strlen(buf)) > 0 && buf[len-1] == '\n' ){
      len --;
      buf[len] = '\0';
    }
    
    sscanf(buf, "%d/%d/%d/%d:%d%s, &ye, &mo, &da, &ho, &min,con");
      printf("%d/%d/%d/%d/%d%s",ye, mo, da, ho, min,con);

      }
}
