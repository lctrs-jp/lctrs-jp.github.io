#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 30


struct attendance {
  char date[9]; // 日にち
  char alice;   // Aliceの都合
  char bob;     // Bobの都合
  char carol;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int main(int argc,char *argv[])
{
  struct attendance item[30]; 
  int n, year, month, day,i,len;
  FILE *fp;
  char buf[MAX],name[MAX] ;/*MAXの値を宣言#define MAX 30*/

  printf("date\t\tAlice\tBob\tCarol\n");

  for(i=1;i!=argc;i++)//日付で比べる
    { if((fp=fopen(argv[i],"r"))==NULL)/*ファイル名を入力*/
   {printf("コピー元のファイルが存在しません\n");
     exit(1);}/*error表示*/
      fgets(buf,MAX,fp) != NULL;/*書き込み先.限界.ファイル名*/
   len=strlen(buf);
     if(len>0 &&buf[len-1]=='\n')
       buf[len-1] = '\0';
     sscanf(buf,"%d %c",&item.date[i-1],&item.argv[1]);
     fclose(fp);}
  /*日付に記入の無いものを除外*/
   if(item.date[1]==item.date[2]&&item.date[2]!=item.date[3])
     item.argv[3]="\t";
      if(item.date[1]!=item.date[2]&&item.date[2]==item.date[3])
     item.argv[1]="\t";
      if(item.date[1]==item.date[3]&&item.date[2]!=item.date[3])
     item.argv[2]="\t";

      

	sscanf (item.date, "%d", &n);
  day = n %100 ;
  month = (n / 100) % 100;
  year = n / 10000;
       
   

  printf("%4d/%2d/%2d\t%c\t%c\t%c\n",
	 year, month, day,
	 item.alice, item.bob, item.carol
	  );
  
  return 0;
}
