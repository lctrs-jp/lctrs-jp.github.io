#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

struct attendance {
  int date;     // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int main(int argc, char *argv[]){
  struct attendance item[MAX];
  int i, n, len, year, month, day, o=0, un=0;
  FILE *fp;
  char buf[256], name[256];

  //起動時引数の確認
  if(argc < 2){
    printf("使い方:<プログラム名> <ファイル名1> <ファイル名2> ...\n");
    exit(1);
  }

  //ファイルを順に処理していく
  for(i = 1; i < argc; i++)
    {
      if((fp=fopen(argv[i],"r"))==NULL){
	fprintf(stderr, "Error:<%s>が開けませんでした\n", argv[i]);
	exit(1);
      }
         
      //1行目を格納
      fgets(buf, 256, fp);
      len = strlen(buf);
      if(len>0 && buf[len-1]=='\n')
        buf[len-1] = '\0'; //先頭の#を消す
      strcpy(name, &buf[1]);
      
      //2行目以降を格納
      n = 0;
      while(fgets(buf, 256, fp) != NULL){
	len = strlen(buf);
	if(len>0 && buf [len-1]=='\n')
	  buf[len-1] = '\0';
	if(*name == 'A')
	  sscanf(buf, "%d %c", &item[n].date, &item[n].alice);
	if(*name == 'B')
          sscanf(buf, "%d %c", &item[n].date, &item[n].bob);
	if(*name == 'C')
          sscanf(buf, "%d %c", &item[n].date, &item[n].carol);
	n++;
      };
      
      fclose(fp); //ファイルを閉じる
    }
  
  //人数をカウント
  for(i=0; i<n-1; i++){
    if(item[i].alice=='o')o++;
    if(item[i].bob=='o')o++;
    if(item[i].carol=='o')o++;
    if(item[i].alice=='?')un++;
    if(item[i].bob=='?')un++;
    if(item[i].carol=='?')un++;
  }


  //表示する
  printf("n=%d\n",n);
  printf("date\t\tAlice\tBob\tCarol\n");     
  printf("-----------------------------\n");
  
  for(i=0; i<n-1; i++){ 
    
    day = (item[i].date) % 100 ;
    month = ((item[i].date) / 100) % 100;
    year = (item[i].date) / 10000;
    
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	   year, month, day,
	   item[i].alice, item[i].bob, item[i].carol);
  };
  
  printf("-----------------------------\n");

  for(i=0; i<n-1; i++){
    
    day = (item[i].date) % 100 ;
    month = ((item[i].date) / 100) % 100;
    year = (item[i].date) / 10000;
    
    printf("%4d/%2d/%2d  [ok:%d, ?:%d]\n",
	   year, month, day, o, un);
  };  
  return 0;
}


