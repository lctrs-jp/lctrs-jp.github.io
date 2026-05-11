#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define LEN 273

struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

typedef struct attendance SCORE;

void print(SCORE d[MAX],int size,SCORE avg);
int load(SCORE d[MAX],char *filename, int size);
  int main(int argc, char *argv[]) {
  SCORE students[MAX], avg;
  int i,size;

  if(argc<2){
    printf("Usage:%sfilename1...filename2\n",
	   argv[0]);
    exit(1);
  }
for (i = 1;i < argc;i++){//データの読み込み
size = load(students,argv[i],size);
 }
 print(students,size,avg);
 return 0;
}

int load(SCORE d[MAX],char *filename, int size) {
FILE *fp;
char buf[LEN],subject[LEN];
 char date[50];
int len,id , i;
 char score;

if  ((fp = fopen (filename, "r")) == NULL) {
printf ("ファイル %s のオープンに失敗しました", filename);
exit (1);
  }

 fgets(buf,LEN,fp);
len =  strlen(buf);
 if(len >0 && buf[len-1]=='\n')
buf[len-1] = '\0';
 strcpy(subject,&buf[1]);

size = 0;
 while (fgets(buf,LEN,fp) != NULL){
len = strlen(buf);
 if( len >0 && buf[len-1]=='\n')
buf[len-1] = '\0';
 sscanf(buf,"%s %s", date, &score);
 for (i = 0; i < size;i++){
   if (strcmp(date,d[i].date) ==0)
id = i;
   break;
 }
 }
 if (i== size){//新規の名前の追加
  strcpy(d[i].date,date);
id = size;
 size++;
 }

if (strcmp(subject,"Alice")==0)
d[id].alice = score;
 else if (strcmp(subject,"Bob")==0)
d[id].bob = score;
 else if (strcmp(subject,"Carol")==0)
d[id].carol = score;
 else
   printf("Wrong subject error: %s\n",subject);

return size; 
}

void print(SCORE d[MAX],int size,SCORE avg){
int i;
 printf("date\t\tAlice\tBob\tCarol\n");
 printf("--------------------------------------\n");
for (i= 0;i < size;i++){
  printf("%s\t%c\t%c\t%c\n",
	 d[i].date,d[i].alice,d[i].bob,
	 d[i].carol);
 }
 printf("--------------------------------------\n");
 
 }

