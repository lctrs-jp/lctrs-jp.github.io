#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
#define LEN 7
/* ? */struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTEND;

int load (ATTEND d[MAX], char *filename);
void print(ATTEND d[MAX]);
int count(ATTNED d[MAX]);




int main(int argc, char *argv[])
{
  if(argc!=4){
    printf("正しいテキストではない",argv[0]);
    exit(1);
    load(ATTEND d[MAX],*filename);
    print(ATTEND d[MAX]);
    count(ATTEND d[MAX]);

    return 0;
  }


  int load(ATTEND d[MAX], char *filename)
  {
    FILE *fp;
    char buf[LEN],name[LEN],str ;
    int len,  i=0;


    if( (fp = fopen (filename, "r")) == NULL ){
      printf ("ファイル %s のオープンに失敗しました\n", filename);
      exit(1);
    }

    fgets(buf, LEN, fp);
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    strcpy(str,&buf[1]);


    while( fgets(buf, LEN, fp) != NULL ){
      len = strlen(buf);
      if( len >0 && buf[len-1] == '\n' )
        buf[len-1] = '\0';
      sscanf(buf,"%s", str );


      if(strcmp(name,"arice") == 0)
        d[i].alice =str ;
      else if(strcmp(name,"bob") == 0)
        d[i].bob = str;
      else if(strcmp(name,"carol") == 0)
        d[i].carol = str;
      else
        printf("Wrong name error: %s\n", name );
      i++;
    }

    return i;
  }

  int count(ATTEND d[MAX])
  {
    int a,j;
    for(j=0:j<i;j++){
      if(strcmp((o,%s),str))==0)
      }

 

  void print(ATTEND d[MAX])
  {
    int j,i;
    printf("----------------------------------------\n");
    printf("date      Aleice  Bob  Carol\n");
    for(j=0;j<i;j++){
      printf("%s",d[i].alice,d[i].bob,d[i].carol);
    }
    printf("----------------------------------------\n");

    printf("[ok:%d, ?:%d]",ok,unfixed);
  }





