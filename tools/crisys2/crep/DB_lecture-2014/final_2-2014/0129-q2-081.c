#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 273
#define MAX 30

struct attendance ｛
   char date[9]; // 日にち
   char alice;   // Aliceの都合
   char bob;     // Bobの都合
   char carol;   // Carolの都合
   int ok;       // 参加可能な人数
   int unfixed;  // 参加未定（?）の人数
｝;

typedef struct attendance ATTENDANCE;

void print(ATTENDANCE d[MAX], int size);
int load(ATTENDANCE d[MAX], char *filename);

int main(int argc, char *argv[])
｛
   ATTENDANCE days[MAX];
   int i,size;

   if( argv < 2 ) {
     printf("Usage: %s filename1 filename2 filename3\n",argv[0]);
     exit(1);
 }
 for (i = 1;i < argc;i++){
  size = load(days,argv[i]);
 }

struct attendance item = ｛ "20150129", 'o', '?', 'x', 1, 1 ｝;
int n, year, month, day;

sscanf ( item.date, "%d", &n );
day = n % 1 ; month = (n / 100) % 100; year = n / 10000;

printf("date\t\tAlice\tBob\tCarol\n");
printf("%4d/%2d/%2d\t%c\t%c\t%c\t[o:%d, ?:%d]\n",
       year, month, day, 
       item.alice, item.bob, item.carol, 
       item.ok, item.unfixed );

return 0;
｝

int load(ATTENDANCE d[MAX],char *filename)
{
  FILE *fp;
  char buf[LEN],human[LEN];
  int len,id,attendance,size;

  if ((fp = fopen (filename,"r")) == NULL) { 
    printf("ファイル %s のオープンに失敗しました", filename);
    exit(1);
  }

  fgets(buf,LEN,fp);
  len=strlen(buf);
  if( len >0 && buf[len-1] == '\n')
    buf[len-1] = '\0';
  strcpy(attendance,&buf[1]);

size=0;
while
  (fgets(buf,LEN,fp) != NULL){
  len=strlen(buf);
  if(len>0&&buf[len-1]=='\n')
    buf[len-1]='\0';
  sscanf(buf,"%d %d",&id,&attendance);
  id = id - 1;
  size++;

if(strcmp(human,"alice")==0) 
  d[id].alice = attendance;
 else if(strcmp(human,"bob")==0) 
  d[id].bob = attendance;
 else if(strcmp(human,"carol")==0) 
  d[id].japanese = attendance;
else printf("Wronghumanerror:%s\n",human);
}
return size;

}
