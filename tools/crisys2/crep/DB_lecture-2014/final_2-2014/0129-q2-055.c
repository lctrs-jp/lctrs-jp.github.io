#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 273
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
}item[100];


int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[LEN],name[LEN];
  int len,id,n,year,month,day,i,j,k;
  char num[50],some[50];

  if( argc < 2 ){
    printf("Usage: %s filename1 ... filename2\n", argv[0] );
    exit(1);
  }

  for (i = 1 ; i < argc ; i++ ){
  
  if( (fp = fopen (argv[i], "r")) == NULL ){
    printf ("ファイル %s のオープンに失敗しました\n", argv[i]);
    exit(1);
  }

  fgets(buf, LEN, fp);
  len = strlen(buf);
  if( len >0 && buf[len-1] == '\n' )
    buf[len-1] = '\0';
  strcpy(name, &buf[1]);

  id = 0;
  while( fgets(buf, LEN, fp) != NULL ){
    len = strlen(buf);
    if( len >0 && buf[len-1] == '\n' )
      buf[len-1] = '\0';
    sscanf(buf,"%s %s", num, some );
           
    if(strcmp(name,"Alice") == 0){
      strcpy(&item[id].alice,some);
    strcpy(item[id].date,num);
    }
    else if(strcmp(name,"Bob") == 0){
      for(j=0;j<k;j++)
	if(strcmp(num,item[j].date)==0){
      strcpy(&item[id].bob,some);
      break;
	}
    }
    else if(strcmp(name,"Carol") == 0){
if(strcmp(num,item[j].date)==0){
      strcpy(&item[id].carol,some);
      break;
	}
    }
      else
      printf("Wrong person error: %s\n", name );
    
    
    id++;
    
  }
    if(strcmp(name,"Alice") == 0)
      k=id;
  }

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-----------------------------------\n");
  
  for(i=0;i<id;i++){
    
    sscanf(item[i].date,"%d",&n);
    day = n % 100;
    month = (n / 100) % 100;
    year = n / 10000;

    printf("%4d/%2d/%2d\t%s\t%s\t%s\n",year,month,day,&item[i].alice,&item[i].bob,&item[i].carol);
  }
    printf("-----------------------------------\n");
  return 0;
}



