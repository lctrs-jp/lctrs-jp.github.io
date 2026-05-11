#include<stdio.h>
#define MAX 30
#include<string.h>
#include<stdlib.h>
struct attendance{
  char date[9];
  char alice;
  char bob;
  char carol;
  int ok;
  int unfixed;
};

int main(int argc, char *argv[]){
  
  int i,j,k;
  if(argc<4){
    printf("ERROR;3つのファイルを入力してください\n\a");
    exit(1);
  }
  FILE *fp[3];
  for(i=0,j=0;i<3;i++)
    if((fp[i] = fopen(argv[i+1],"r"))==NULL)
      j++;
  if(j==2){
    printf("ERROR:All file can not open\n\a");
    exit(1);
  }else if(j>0)
    printf("警告:%d個のファイルが開けませんでした\n",j);

  
   struct attendance item[MAX];
   
  char buf[256];

  k=0;
  fgets(buf,256,fp[0]);
  while(fgets(buf,256,fp[0])){
    sscanf(buf,"%s %c",item[k].date,&item[k].alice);
    k++;
  }
  printf("%s\n",item[1].date);
  char day[9];
  char maru;
  fgets(buf,256,fp[1]);
  while(fgets(buf,256,fp[1])){
    sscanf(buf,"%s %c",day,&maru);
    for(i=0;i<k;i++){
      if(strcmp(item[i].date,day)==0){
	strcpy(&item[i].bob,&maru);
	break;
      }
      else if(i==k-1){
	strcpy(item[k].date,day);
	strcpy(&item[k].bob,&maru);
	k++;
      }
    }
  }
  printf("%s\n",item[1].date);
  fgets(buf,256,fp[2]);
  while(fgets(buf,256,fp[2])){
    sscanf(buf,"%s %c",day,&maru);
    for(i=0;i<k;i++){
      if(strcmp(item[i].date,day)==0){
        strcpy(&item[i].carol,&maru);
        break;
      }
      else if(i==k-1){
        strcpy(item[k].date,day);
	strcpy(&item[k].carol,&maru);
        k++;
      }
    }
  }
  printf("%s\n",item[1].date);
  printf("date\t\tAlice\tBob\tCarol\n");
  printf("----------------------------------------\n");

  int n, year,month,hiniti;
  for(i=0;i<=k;i++){
    sscanf(item[i].date,"%d",&n);
  hiniti = n%100;  month = (n/100)%100;  year = n/10000;

  printf("%4d/%2d/%2d\t%c\t%c\t%c\t\n",year, month, hiniti,item[i].alice,item[i].bob,item[i].carol);
  }
  return 0;
}
