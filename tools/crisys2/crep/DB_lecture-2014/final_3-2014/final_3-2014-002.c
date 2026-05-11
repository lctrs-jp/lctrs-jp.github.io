#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 255

int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[LEN],subject[LEN];
  int len,id,score,size,total;

  if(argc != 2){
    printf("引数エラー");
      exit(1);
    }

  if((fp = fopen(argv[0], "r")) == NULL){
    printf("ファイルが開けません");
      exit(1);
      }

  fgets(buf,LEN,fp);
  len = sizeof(buf);
  if(len>0 && buf[len-1]=='\n')
    buf[len-1] = '\0';
  strcpy(subject,&buf[1]);
  printf("%s\n",subject);

  size = 0;
  total = 0;
  while(fgets(buf,LEN,fp) != NULL){
    len = sizeof(buf);
    if(len > 0 && buf[len-1] == '\n')
      buf[len-1] = '\0';
    sscanf(buf,"%d %d",&id,&score);
    total = total + score;
    size = size + 1;
    printf("id:%2d\t%3d\n",id,score);
  }
  printf("AVG = %3d\n",total/size);


  return 0;
}
