#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 300
#define LEN 300

struct attendance{
  int date; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance AT;

int load(AT d[MAX], char *filename);
void print(AT d[MAX], int size);

int main(int argc, char *argv[])
{
  int i, size;
  AT at[MAX];

  if(argc < 2){
    printf("error");
    exit(1);
  }

  for(i = 1; i < argc; i++)
    size = load(at, argv[i]);

  print(at, size);

  return 0;
}

int load(AT d[MAX], char *filename)
{
  FILE *fp;
  char buf[LEN], name[MAX], tugo[MAX], t[MAX];
  int size = 0, len, i, n, j;

  if((fp = fopen(filename, "r")) == NULL){
    printf("ファイル%sのオープンに失敗しました",filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len = strlen(buf);
  if(len>0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(name,&buf[1]);
  printf("name = %s\n",name);

  i = 0;
  while(fgets(buf,LEN,fp)!=NULL){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
    //    strcpy(tugo,&buf[9]);
    sscanf(buf,"%d", &n);
    //    printf("tugo = %s\n",tugo);
    strcpy(tugo,&buf[9]); 
    /*
    if(n==20150126)
      j = 0;
    else if(n==20150127)
      j = 1;
    else if(n==20150128)
      j = 2;
    else if(n==20150129)
      j = 3;
    else if(n==20150130)
      j = 4; 
    else if(n==20150131)
      j = 5;
    else if(n==20150201)
      j = 6;
    else if(n==20150202)
      j = 7;
    else if(n==20150203)
      j = 8;
    else if(n==20150204)
      j = 9;
    else if(n==20150205)
      j = 10;
    else if(n==20150206)
      j = 11;
    else if(n==20150207)
      j = 12;
    else if(n==20150208)
      j = 13;
    else 
      j = 100;
    */
    d[j].date = n;

    //    if(n != 100){
    strcpy(tugo,&buf[9]);
    if(strcmp(name,"Alice")==0)
      d[j].alice = tugo;
    else if(strcmp(name,"Bob")==0)
      d[j].bob = tugo;
    else if(strcmp(name,"Carol")==0)
      d[j].carol = tugo;
    else{
      printf("name of person is wrong");
      exit(1);
    }
  }
  i++;
  size++;
}

  return size;
}


void print(AT d[MAX], int size)
{
  int i, n;
  int day,month,year;

  printf("\tdate\tAlice\tBob\tCarol\n");
  printf("--------------------------------------\n");

  for(i = 0; i < size; i++){
    n = d[i].date;
    //    sscanf(d[i].date, "%d", &n);
    day = n % 100; month = (n / 100) % 100; year = n / 10000;
    //    printf("tugo = %sです\n",);
    
    printf("%d/%d/%d\t%s\t%s\t%s\t[o:%d, ?:%d]\n",
	   year, month, day, 
	   d[i].alice, d[i].bob, d[i].carol, 
	   d[i].ok, d[i].unfixed );

  }
  printf("--------------------------------------\n");
}  

