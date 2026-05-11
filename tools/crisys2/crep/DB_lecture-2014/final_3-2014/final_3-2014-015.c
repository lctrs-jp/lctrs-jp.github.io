#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 30

struct attendance {
  int date; // 日にち
  int date1;
  char alice[LEN];   // Aliceの都合
  char bob[LEN];     // Bobの都合
  char carol[LEN];   // Carolの都合
  int ok;       // 参加可能な人数
  int unfixed;  // 参加未定（?）の人数
  int year;
  int month;
  int day;
  char temp[LEN];
}item[LEN];

int main(int argc, char *argv[]){
  FILE *fp1,*fp2,*fp3;
  int len1,len2,len3;
  char buf1[LEN],buf2[LEN],buf3[LEN];
  int n,num=0,i,j,date=0,a,b,c=0,d=0;


  if(argc!=4){
    printf("ERROR!:Please use%s <filename1> <filename2> <filename3>\n",argv[0]);
    exit(1);
  }
  if((fp1=fopen(argv[1],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  if((fp2=fopen(argv[2],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }
  if((fp3=fopen(argv[3],"r"))==NULL){
    printf("ファイルのオープンに失敗しました\n");
    exit(1);
  }

  printf("date\tAlice\tBob\tCarol\n");
  printf("-------------------------------------\n");

  if(fp1!=NULL){
    fgets(buf1,LEN,fp1);
  }
  if(fp2!=NULL){
    fgets(buf2,LEN,fp2);
  }
  if(fp3!=NULL){
    fgets(buf3,LEN,fp3);
  }

  while(fgets(buf1,LEN,fp1)!=NULL){
    len1 = strlen(buf1);
    if(len1 > 0&& buf1[len1-1]=='\n')
      { buf1[len1-1]='\0';
	sscanf(buf1,"%8d %s",&item[num].date,item[num].alice);
	num++;}}

  while(fgets(buf2,LEN,fp2)!=NULL){
    len2 = strlen(buf2);
    if(len2 > 0&& buf2[len2-1]=='\n')
      buf2[len2-1]='\0';
    sscanf(buf2,"%8d %s",&date,item[c].temp);//　一時的に読み込む
    for(a=0;a<num;a++){
      if(date==item[a].date){
	strcpy(item[a].bob,item[c].temp);
	c++;
      }}

  }

  while(fgets(buf3,LEN,fp3)!=NULL){
    len3 = strlen(buf3);
    if(len3 > 0&& buf3[len3-1]=='\n')
      buf3[len3-1]='\0';
    sscanf(buf3,"%8d %s",&date,item[d].temp);//　一時的に読み込む
    for(a=0;a<num;a++){
      if(date==item[a].date){
	strcpy(item[a].carol,item[d].temp);
	d++;
      }}
  }


  for(i=0;i<num;i++){
    item[i].day = item[i].date % 100;
    item[i].month = (item[i].date / 100) % 100;
    item[i].year = item[i].date / 10000;
  }


  for(j=0;j<num;j++){
    printf("%4d/%2d/%2d\t%s\t%s\t%s\n",item[j].year,item[j].month,item[j].day,item[j].alice,item[j].bob,item[j].carol);
  }
  printf("-------------------------------------\n");

  int k,l;
  
  for(l=0;l<num;l++){
    if(strcmp(item[l].alice,"o")==0)
      item[l].ok++;
    if(strcmp(item[l].bob,"o")==0)
      item[l].ok++;
    if(strcmp(item[l].carol,"o")==0)
      item[l].ok++;
    if(strcmp(item[l].alice,"?")==0)
      item[l].unfixed++;
    if(strcmp(item[l].bob,"?")==0)
      item[l].unfixed++;
    if(strcmp(item[l].carol,"?")==0)
      item[l].unfixed++;
  }
      for(k=0;k<num;k++){
	printf("%4d/%2d/%2d\t[ok:%d,?:%d]\n",item[k].year,item[k].month,item[k].day,item[k].ok,item[k].unfixed);
  }


  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;
}
