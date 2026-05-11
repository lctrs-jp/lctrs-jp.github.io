#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define LEN 256

int main(int argc, char *argv[])
{
  FILE *fp;
  char buf[LEN];
  int x, y, z;

  if(argc != 2){
    printf("使用法: 年/月/日 ファイル名\n");
    exit(1);
  }

  if((fp = fopen(argv[2],"r")) == NULL){
    printf("ファイルを開くことができません\n");
    exit(1);
  }
 
  while(fgets(buf, LEN, fp) != NULL){
    printf("%s", buf);    
  }

 
  fclose(fp);

  return 0;
}
