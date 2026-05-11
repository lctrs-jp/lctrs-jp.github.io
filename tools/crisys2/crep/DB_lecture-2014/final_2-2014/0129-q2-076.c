#include(stdio.h)
#define MAX 30

struct attendance {
  char date[9];
  char alice;
  char bob;
  char carol:
  int ok;
  int unfixed;
};
typedef struct attendance ATTN ;
void print(ATTN d[MAX],int size);
int load();

int main(int argc. char *argv[]){
 if(argc != 4){
    printf("引数エラー\n");
      exit(1);
 }
 print()}

int load(, char *filename)
{
  FILE *fp;
  char buf[LEN],name[LEN],ok;
  int len,ymd,size,i,;

  while(i=3){  
    if((fp = fopen(argv[i], "r")) == NULL){
    printf("ファイルが開けません");
    exit(1);}
    else i++
	   }
  fgets(buf,LEN,fp);
  len = stlen(buf);
  if(len>0 && buf[len-1]=='\n')
    buf{len-1] = '\0';
  strcpy(name,&buf[1]);
  
  size=0;
  while(fgets(buf,LEN,fp != NULL){
      len = stlen(buf);
      if(len>0 && buf[len-1]=='\n')
	buf[len-1] = '\0';
      sscanf(buf, "%d %s",&ymd,&ok);
      day=ymd%100;
      month=(ymd/100)%100;
      year=ymd/10000;
      if(strcmp(name,"")==0)
