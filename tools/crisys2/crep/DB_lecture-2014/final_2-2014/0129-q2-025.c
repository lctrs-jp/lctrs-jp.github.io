#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30

struct attendance {
  char date[9]; // 日にち
  char a;   // Aliceの都合
  char b;     // Bobの都合
  char c;   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
};

int main(int argc,char *argv[])
{
  struct attendance item[30],det;
  int n, year, month, day,i,k,j;
  FILE *fp;
  char name1[10],name2[10],name3[10],str[20],a[10],b[10],c[10],wh,date2[9]\
    ;

  for(k=1;k<argc;k++){
    if ((fp = fopen(argv[k], "rb")) == NULL){
      printf("ファイル(%s)がディスク上に存在しません。\n",argv[k]);
      exit(1);
    }
    if(k=1){
      fgets(str,MAX,fp);
      sscanf(str,"#%s",&name1);
      while (fgets(str,100,fp) != NULL){
	sscanf(str,"%d %c",&item[i].date,&item[i].a);
      }}
    else if(k=2){
      fgets(str,MAX,fp);
      sscanf(str,"#%s",&name2);
      while (fgets(str,100,fp) != NULL){
        sscanf(str,"%d %c",&date2,&wh);
        for (j=0;fgets(str,100,fp) != NULL;j++){
	  if(strcmp(date2,item[j].date)!=0)
	    item[j].b=wh;
        }
      }
    }
    else if(k=3){
      fgets(str,MAX,fp);
      sscanf(str,"#%s",&name3);
      while (fgets(str,100,fp) != NULL){
        sscanf(str,"%d %c",&date2,&wh);
        for (j=0;fgets(str,100,fp) != NULL;j++){
          if(strcmp(date2,item[j].date)!=0)
            item[j].c=wh;
        }
      }
    }
  }
  printf("%s  %s  %s",name1,name2,name3);
  for(j=0;j<2;j++)
    printf("%c  %c  %c",item[j].a,item[j].b,item[j].c);
  return 0;
}



