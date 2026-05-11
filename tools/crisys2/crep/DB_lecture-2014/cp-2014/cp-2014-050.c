#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  FILE *fp;
  FILE *fp2;
  char str[80];
  int i;

  if(argc != 3){
    printf("エラー:ファイル名を2つ指定してください。\n");
    exit(1);
  }

  if((fp = fopen(argv[1],"r")) == NULL){
    printf("エラー:コピー元のファイルを開くことができません。\n");
    exit(1);
  }

  if((fp2 = fopen(argv[2],"w")) == NULL){
    printf("エラー:コピー先のファイルを開くことができません。\n");
    exit(1);
  }

  do{
    fgets(str,80,fp);
    fputs(str,fp2);
  }while(!feof(fp));
  fclose(fp);
  fclose(fp2);

  return 0;
}
