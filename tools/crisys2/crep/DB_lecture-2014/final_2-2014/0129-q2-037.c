#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct   attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance ATTENDE;
void print(ATTENDE d[100]);

int main(int argc, char *argv[])  {
  FILE *fp;

  ATTENDE a[100];
  char buf[256],date[100],name[111];
  int i,attendance,len;

  for(i=1;i<argc;i++){//FILEの読み込み
    if((fp=fopen(argv[i],"r"))== NULL)  {
      printf  ("ファイル%sのオープンに失敗しました",argv[i]);
      exit (1);
    }

    fgets(buf,256,fp);
    len =  strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]=  '\0';
    strcpy(name,&buf[1]);

    while   (fgets(buf,256,fp)!=    NULL){
      len =  strlen(buf);
      if(len>0&&buf[len-1]=='\n')
	buf[len-1]=  '\0';

      sscanf(buf,"%s %d",date,&attendance);
    }
  }
  print(a);

  return 0;
}
 
void print(ATTENDE d[100])
{
  int i;
  printf("date\tAlice\tBob\tCarol\n");
  for(i=0;i<13;i++){
    printf("%s\t%d\t%d\t%d\n",d[i].date,d[i].alice,d[i].bob,d[i].carol);
  }
  printf("--------------------------------------\n");
}
