#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 273
#define MAX 30


struct attendance {
  int date; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
  int year;
  int month;
  int day;
}item[MAX];


int main(int argc , char *argv[])
{
  FILE *fp;
  int len, i, j, id, n = 0, num , size = 0 ;
  char buf[LEN];
  char name[MAX];
  char answer[MAX];

  if(argc != 4){
    printf("ファイルの指定がないか、もしくは足りません\n");
    exit(1);
  }

  for( i = 1 ; i < argc ; i++){

    if((fp =fopen(argv[i] , "r")) == NULL){
      printf("ファイル%sが開けません\n", argv[i]);
      exit(1);
    }

    fgets(buf,LEN,fp);
    len = strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]= '\0';
    strcpy(name,&buf[1]);

    num = 0;
    while(fgets(buf,LEN,fp) != NULL){
      len = strlen(buf);
      if(len>0&&buf[len-1]=='\n')
	buf[len-1] = '\0';
      sscanf(buf,"%d %s", &n, answer );

      if(i==1){
	item[num].date = n ;
	id = num;
	num++;
	size++;
      }
      else if( i==2 || i==3 ){
	for( j=0 ; j<size ; j++){
	  if(n == item[j].date){
	    id = j;
	    break;
	  }
	}
	if(j==size){
	  item[j].date = n;
	  id = j;
	  size++;
	}
      }

      item[id].day = n % 100;
      item[id].month = (n / 100) % 100;
      item[id].year = n / 10000;

      if(strcmp(name,"Alice")==0){
	item[id].alice = *answer;
	if(item[id].alice == 'o')
	  item[id].ok++;
	else if(item[id].alice == '?')
	  item[id].unfixed++;
      }
      else if(strcmp(name,"Bob")==0){
	item[id].bob = *answer;
	if(item[id].bob == 'o')
          item[id].ok++;
        else if(item[id].bob == '?')
          item[id].unfixed++;
      }
      else if(strcmp(name,"Carol")==0){
	item[id].carol = *answer;
	if(item[id].carol == 'o')
          item[id].ok++;
        else if(item[id].carol == '?')
          item[id].unfixed++;
      }
      else
	printf("名前が違います。");

      
    }

  }

  









  printf("date\t\tAlice\tBob\tCarol\n");
  printf("------------------------------------------------\n");

  for(i=0 ; i < size ; i++){

    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",item[i].year,item[i].month,item[i].day, item[i].alice, item[i].bob, item[i].carol );

  }

  printf("-----------------------------------------------\n");

  for(i=0;i<size;i++)
    printf("%4d/%2d/%2d\t[ok:%d, ?:%d]\n",item[i].year,item[i].month,item[i].day, item[i].ok, item[i].unfixed);

  return 0;
}
