#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
}det[20],*p;

void main(int argc, char *argv[])
{
  FILE *fp;
  char str[100],*sub[3];
  int i, t, n , day[MAX], year[MAX], month[MAX];

  if(argc != 4){
    printf("ファイルを３つ指定して実行してください\n");
    exit(1);
  }

  if(argc < 4){
    printf("ファイルを３つ指定して実行してください\n");
    exit(1);
  }
  
  
  for(i = 0; i < argc-1; i++){
    
    p = det;
    
    if((fp = fopen(argv[i+1], "rb")) == NULL){
      printf("ファイルがディスク上にありません\n");
      exit(1);
    }
    
    fgets(str,100,fp);
    if (strcmp(argv[i], "alice.txt") == 0){
      while(fgets(str,100,fp) != NULL){
	sscanf(str,"%s %s", &(p->date),&(p->alice));
	p++;
      }
    }else if(strcmp(argv[i], "bob.txt") ==0){
      while(fgets(str,100,fp) != NULL){
	sscanf(str,"%s %s", &(p->date),&(p->bob));
	p++;
      }
    }else if(strcmp(argv[i], "carol.txt") ==0){
      while(fgets(str,100,fp) != NULL){
	sscanf(str,"%s %s", &(p->date),&(p->carol));
	p++;
      }
    }
    fclose(fp);
  }
  
  for(i = 0; i < 13; i++, p++){
    day[i] = atoi(p->date) % 100;
    month[i] = (atoi(p->date) / 100) % 100;
    year[i] = atoi(p->date) / 10000;
  }
  
  printf("date\t\talice\tbob\tcarol\n");
  printf("-------------------------------------------------\n");
  
  p = det;
  
  for(i = 0; i < 13; i++,p++)    
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",year[i],month[i],day[i],p->alice,p->bob,p->carol);
  
  
  return;
}
