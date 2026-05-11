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
ATTENDANCE sum(ATTENDANCE d[MAX], int size);
void sort(ATTENDANCE item[MAX], int count);

int main(int argc, char *argv[])｛
ATTENDANCE students[MAX], avg;
int i,size;

if( argv < 2 ) {
  printf("Usage: %s filename1 filename2 filename3\n);
exit(1);}
for (i = 1;i < argc;i++){
  size = load(students,argv[i],size);
}

avg = sum(students,size);
sort(students,size);
print(students,size,avg);

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

int load(ATTENDANCE d[MAX],char *filename, int size)
{
  FILE *fp;
  char buf[LEN],subject[LEN];
  int len,id,attendance,i;

  if((fp=fopen(filename,"r"))==NULL)
{
printf("ファイル%sのオープンに失敗しました",filename);
exit(1);
}
fgets(buf,LEN,fp);len=strlen(buf);
if(len>0&&buf[len-1]=='\n')buf[len-1]='\0';
strcpy(attendance,&buf[1]);

size=0;
while
(fgets(buf,LEN,fp)!=NULL){
len=strlen(buf);
if(len>0&&buf[len-1]=='\n')
buf[len-1]='\0';
sscanf(buf,"%d%d",&id,&attendance);
id=id-1;
size++;

if(strcmp(human,"alice")==0) d[id].alice=attendance;
elseif(strcmp(human,"bob")==0) d[id].bob=attendance;
elseif(strcmp(human,"carol")==0) d[id].carol=attendance;
else printf("Wrong human error:%s\n",human);
}
return size;

}

ATTENDANCE sum(ATTENDANCE d[MAX], int size) {
int i,alice, bob, carol, total;

for (i = 0;i < size;i++){
  d[i].total = d[i].alice + d[i].bob + d[i].carol;
}

void sort(ATTENDANCE item[MAX], int count)
{
  int a,b;
  ATTENDANCE t;
  for (a = 1; a < count; a++)
    for (b = count-1; b >= a; b--) {
      if (item[b-1].total < item[b].total) {
       t = item[b-1];
       item[b-1] = item[b];
       item[b] = t;
      }
    }
  }
