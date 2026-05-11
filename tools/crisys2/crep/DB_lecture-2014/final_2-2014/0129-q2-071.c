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

typedef struct attendance ATT;

void load(char *filename);

int main(int argc, char *argv[])
{
  ATT d[MAX];
  int i;
  

  if(argc<2){ printf("Usage:%sfilename1...filename2...filename3\n",argv[0] );
    exit(1);

    for (i=1;i<argc;i++)
      load(argv[i]);
  
    printf("date\t\tAlice\tBob\tCarol\n");
    printf("----------------------------------------\n");
    for(i=0; i<9; i++)
      printf("%c\t%c\t%c\t%c\t[o:%d, ?:%d]\n",d[i].date[i], d[i].alice,
	     d[i].bob, d[i].carol  );
    printf("----------------------------------------\n");
    return 0;
 }  
  // struct attendance item = { "20150129", 'o', '?', 'x', 1, 1 };
  //int n, year, month, day;


  
  void load(char *filename){
  FILE  *fp;
  ATT d[MAX];
  char  buf[LEN],name[LEN],att;
  int  len,i,n;
  int year,month,day;
  if  ((fp=fopen (filename,"r"))==   NULL)  {
    printf  ("ファイル%sのオープンに失敗しました", filename);
    exit  (1);
  }
  fgets(buf,LEN,fp);
  len=  strlen(buf);
  if(len>0&&buf[len-1]=='\n')
    buf[len-1]=  '\0';
   strcpy(name,&buf[1]);
   
   // size= 0;
   while  (fgets(buf,LEN,fp)!= NULL){
   len= strlen(buf);
   if(len>0&&buf[len-1]=='\n')
   buf[len-1]= '\0';
 
 sscanf( buf, "%d %s", &n ,&att);
  day = n % 100;
  month = (n / 100) % 100;
  year = n / 10000;
  d[i].date[i] = year/month/day;
  if (name=="Alice")
  d[i].alice = att;
  else if(name=="Bob")
    d[i].bob= att;
  else if (name=="Carol")
    d[i].carol= att;
    i++;
 }
 return ; 
  } 
}
  
