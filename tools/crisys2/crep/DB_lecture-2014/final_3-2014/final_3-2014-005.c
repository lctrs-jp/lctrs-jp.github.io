#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
}att[30];

int main(int argc,char *argv[]){
  FILE *fp;
  int i,k,len,n,year,month,day,date=0;
  char buf[256],name[256];

  if((fp=fopen(argv[1],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  fgets(buf,256,fp);
  strcpy(name,&buf[1]);

  for(k=0;fgets(buf,256,fp)!=NULL;k++){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
    sscanf(buf,"%d %c",&att[k].date,&att[k].alice);
    if(att[k].alice=='o')
      att[k].ok++;
    else if(att[k].alice=='?')
      att[k].unfixed++;}
  fclose(fp);

  if((fp=fopen(argv[2],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  fgets(buf,256,fp);
  strcpy(name,&buf[1]);

  for(k=0;fgets(buf,256,fp)!=NULL;k++){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
    sscanf(buf,"%d %c",&att[k].date,&att[k].bob);
    date++;
    if(att[k].bob=='o')
      att[k].ok++;
    else if(att[k].bob=='?')
      att[k].unfixed++;}
  fclose(fp);

  if((fp=fopen(argv[3],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  fgets(buf,256,fp);
  strcpy(name,&buf[1]);

  for(k=0;fgets(buf,256,fp)!=NULL;k++){
    len=strlen(buf);
    if(len>0&&buf[len-1]=='\n')
      buf[len-1]='\0';
    sscanf(buf,"%s %c",att[k].date,&att[k].carol);
    if(att[k].carol=='o')
      att[k].ok++;
    else if(att[k].carol=='?')
      att[k].unfixed++;}
  fclose(fp);

  printf("date\t\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");
  for(i=0;i<date;i++){
    sscanf(att[i].date,"%d",&n);
    day=n%100;
    month=(n/100)%100;
    year=n/10000;
    printf("%4d/%2d/%2d\t%c\t%c\t%c\n",year,month,day,att[i].alice,att[i].bob,att[i].carol);}

  printf("-------------------------------------\n");
  for(i=0;i<date;i++){
    sscanf(att[i].date,"%d",&n);
    day=n%100;
    month=(n/100)%100;
    year=n/10000;
    printf("%4d/%2d/%2d [ok:%d, ?:%d]\n",year,month,day,att[i].ok,att[i].unfixed);}

  return 0;
}
