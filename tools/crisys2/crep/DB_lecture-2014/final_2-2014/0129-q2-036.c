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

int main(int argc, char *argv[]){
  struct attendance item[30];
  int i, size, year[30], month[30], day[30], len, j, d[30];
  char buf[253], date;
  char name[20], kigou;
  FILE *fp;

  if( argc != 4 ){
    fprintf(stderr,"Usage: %s filename1 filename2 filename3\n", argv[0] );
    exit(1);
  }

  for( i = 0; i < 3 ; i++ ){
    if( (fp = fopen(argv[i+1],"r")) == NULL ){
      fprintf(stderr,"Error: can't open \"%s\".\n", argv[i+1]);
      exit(1);
    }

    if( fgets(buf,256,fp) == NULL ){
      fprintf(stderr,"Error: can't read line 1 (%s).\n", argv[i+1] );
      fclose( fp );
      exit(1);
    }

    if( sscanf(buf, "#%s", &name[i] ) != 1 ){
      fprintf(stderr,"Syntax error (%s): %s\n", argv[i+1], buf );
      fclose( fp );
      exit(1);
    }
  }

    while (fgets(buf,256,fp) != NULL){
      len = strlen(buf);
      if(len > 0 && buf[len-1] =='\n')
	buf[len-1] = '\0';
      sscanf(buf,"%s %s", date, kigou);
      for (i= 0;i< size;i++){
	if(strcmp(date,item[i].date)==0){
	  date=item[i].date;
	  break;
	}
      }
      if (i== size){
	strcpy(item[i].date,date);
	date=item[i].date;
	size++;
      }
    }
    fclose(fp);

    d[j] = atoi(item[j].date);
    for(j = 0; j < size ;j++ ){
      day[j] = item[j].date % 100;
      month[j] = (item[j].date / 100) % 100;
      year[j] = item[j].date / 10000;
    }
    printf("date\t\tAlice\tBob\tCarol\n");
    printf("----------------------------------------------\n");
    for(j = 0; j < size ;j++ ){
      printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
	     year[j], month[j], day[j], 
	     item[j].alice, item[j].bob, item[j].carol, 
	     item[j].ok, item[j].unfixed );
    }
    printf("----------------------------------------------\n");

  return 0;
}
