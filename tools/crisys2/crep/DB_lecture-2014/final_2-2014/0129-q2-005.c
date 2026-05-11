#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 60

struct attendance {
  char date[9]; // 日にち
  char alice[2];   // Aliceの都合
  char bob[2];     // Bobの都合
  char carol[2];   // Carolの都合
}data[MAX];

typedef struct attendance DATE;

int main(int argc,char *argv[]){

  int num,i,len;  
  char buf[MAX];
  FILE *fp1,*fp2,*fp3;

  if(argc != 4){
    printf("使用法: ./ <ファイル名(1)> <ファイル名(2)> <ファイル名(3)>\n");
    exit(1);
  }

  /* それぞれのファイルを開く */
  if((fp1 = fopen (argv[1], "r")) == NULL){
    printf ("ファイル %s のオープンに失敗しました", argv[1]);
    exit (1);
  }
  if((fp2 = fopen (argv[2], "r")) == NULL){
    printf ("ファイル %s のオープンに失敗しました", argv[2]);
    exit (1);
  }
  if((fp3 = fopen (argv[3], "r")) == NULL){
    printf ("ファイル %s のオープンに失敗しました", argv[3]);
    exit (1);
  }

  num = 0;

  while (fgets(buf,MAX,fp1) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%s %s",data[num].date, data[num].alice);
    num++;
  }

  num = 0;

  while (fgets(buf,MAX,fp2) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%s %s",data[num].date, data[num].bob);
    num++;
  }

  num = 0;

  while (fgets(buf,MAX,fp3) != NULL){
    len = strlen(buf);
    if( len >0 && buf[len-1]=='\n')
      buf[len-1] = '\0';
    sscanf(buf,"%s %s",data[num].date, data[num].carol);
    num++;
  }


  printf("date\tAlice\tBob\tCarol\n");
  printf("-----------------------------------");
  for(i = 0; i < num; i++){ 
    printf("%s\t%s\t%s\t%s\n",data[i].date, data[i].alice, data[i].bob, data[i].carol);
  }

  return 0;
}
