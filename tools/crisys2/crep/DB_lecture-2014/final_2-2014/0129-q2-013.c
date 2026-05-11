#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int main(int argc,char *argv[]){
  struct attendance item[MAX];
  int n, year, month, day, i, j, k;
  FILE *fp;
  char buf[256],a[10];
  
  if(argc<3){
    printf("使い方:%s filename(Alice) filename(Bob) filename(Carol) \n", argv[0]);
    exit(1);
  }

  k=0;
  for(i=1;i<argc;i++){
    if((fp=fopen(argv[i],"r"))==NULL){
      printf("エラー: cannot open \"%s\".\n",argv[i]);
      exit(1);
    }

    while(fgets(buf,256,fp)!=NULL){
      if(buf[0]=='\0' || buf[0] =='\n')
	continue;

      if(i=1){
	sscanf(buf,"%d %s",&j,a);
	for(k=0;k<MAX;k++){
	  if(strncmp(item[k].date,j,9)==0){
	    strcpy(item[k].alice,a)}
	  else {
	    strcpy(item[k].date,j);
	    strcpy(item[k].alice,a);}
	}
      }
      if(i=2){
	sscanf(buf,"%d %s",&j,a);
	for(k=0;k<MAX;k++){
	  if(strncmp(item[k].date,j,9)==){
	    strcpy(item[k].bob,a)}
	  else {
	    strcpy(item[k].date,j);
	    strcpy(item[k].bob,a);}
	}
      }
      if(i=3){
	sscanf(buf,"%d %s",&j,a);
	for(k=0;k<MAX;k++){
	  if(strncmp(item[k].date,j,j){
	      strcpy(item[k].carol,a)}
	    else {
	      strcpy(item[k].date,j);
	      strcpy(item[k].carol,a);}
      }
      }

}
  }	       
  sscanf ( item.date, "%d", &n );
  day = n % 100; month = (n / 100) % 100; year = n / 10000;
  
  printf("date\t\tAlice\tBob\tCarol\n");

  for(k=0;k<MAX;k++){
    n=0; day=0; month=0; year=0;
    sscanf( item[k].date,"%d", &n );
    day = n % 100; month = (n / 100) % 100; year = n / 10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	year, month, day, 
	item[k].alice, item[k].bob, item[k].carol, 
	item[k].ok, item[k].unfixed );
 return 0;
  }
