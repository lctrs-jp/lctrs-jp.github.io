#include <stdio.h>
#define MAX 30
#include <stdlib.h>
#define LONG 300
#include<string.h>
struct attendance {
  char date[9]; //日にち
  char alice ; // Aliceの都合
  char bob; // Bobの都合
  char carol; // Carolの都合
  int ok; //参加可能な人数
  int unfixed; //参加未定（?）の人数
  };
typedef struct attendance ATTEND;
void print(ATTEND a[MAX], int siz);
int load(ATTEND a[MAX], char *filename);
int main(int argc, char *argv[])
{
  ATTEND person[MAX];
  int i, siz;
 if (argc < 2)
    { printf("Usage: %s<filename>\n", argv[0]);
	exit(1);
}
 for (i = 1;i < argc;i++)
   { siz = load(person,argv[i]);
   }
 print(person,siz);
 return 0;

 int load(ATTEND a[MAX], char *filename)
 {
   FILE *fp;
   char buf[LONG];
   siz = 0;
   int len, n, year,day,month, ok ;
   if ((fp = fopen (filename, "r")) == NULL)
   {
     printf("fail %s to open the file", filename);
     exit(1);
   }
   while (fgets(buf,LONG,fp) != NULL)
     {
       len = strlen(buf);
       if( len > 0 && buf[len - 1] == 'n')
	 buf[len - 1] = '\0';
   
       return siz;
     }
   sscanf( attendance[siz].date, "%d", &n );
   day = n % 10; month = (n / 100) % 100; year = n / 1000;
   sscanf(buf,"%4d/%2d/%2d %s",	  attendance[siz].year,  attendance[siz].month, attendance[siz].day, attendance[siz].ok );
   printf("-----------------------------------------\n");
 printf("%4d/%2d/%2d %s\n", attendance[siz].year, attendance[siz].month, attendance[siz].day, attendance[siz],ok );
 }
return 0;
}
