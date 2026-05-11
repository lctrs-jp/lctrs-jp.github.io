#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct Alice{
  char date[9];
  char alice;
}a;

struct Bob{
  char date[9];
  char bob;
}b;

struct Carol{
  char date[9];
  char carol;
}c;

struct attendence {
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

int main (int argc, char *argv[]){
  FILE *fp1, *fp2, fp3;
  char buf1[MAX], buf2[MAX],buf3[MAX];
  char date1, date2, date3;
  char date, alice, bob, carol;
  int ok, unfixed;
  int i;

  if((fp1 = fopen ( "Alice.txt", "r")) == NULL ){
    printf("ファイル１のオープンに失敗しました。");
    exit(1);
  }
  
  if((fp2 = fopen ( "Bob.txt", "r")) == NULL ){
    printf("ファイル２のオープンに失敗しました。");
    exit(1);
  }
  
  if((fp3 = fopen( "Carol.txt","r")) == NULL ){
    printf("ファイル３のオープンに失敗しました。");
    exit(1);
  } 
  for(i=0;i<MAX;i++){
    fgets(buf1,MAX,fp1);
    sscanf(buf1,"%c %c", &date1, &alice);
    struct Alice a = {date1, alice};
    
    item.date = a.date1; 
    item.alice = a.alice;
    
    while((fgets(buf2,MAX,fp2) != NULL){
	  sscanf(buf2,"%c %c", &date2, &bob);
	  struct Bob b = {date2, bob};
	  
	  fgets(buf3,MAX,fp3);
	  sscanf(buf3, "%c %c", &date3, &carol);
	  struct Carol c = {date3, carol};
	  
	  if(b.date2 == item.date){
	    item.bob = b.bob;
	  }
	  if(c.date3 == item.date){
	    item.carol = c.carol;
	  }
	  struct attendance item = {date, alice, bob, carol};
      }
  }
