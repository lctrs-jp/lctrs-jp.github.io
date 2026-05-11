#include <stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
  FILE *f1,*f2;
  char ch;

  //読み込みのためにf1を開く
  if((f1 = fopen(argv[1],"r")) == NULL){
    printf("１番目のファイルのオープンに失敗しました\n");
    exit(1);
  }
  //f2が存在した場合処理を中止
  if((f2 = fopen(argv[2],"r")) != NULL){
    printf("２番目のファイルが存在します\n");
    fclose(f2);
    exit(1);
  }

  //書き込みのためにf2を開く
  if((f2 = fopen(argv[2],"w")) == NULL){
    printf("２番目のファイルのオープンに失敗しました\n");
    exit(1);
  }

  //f1をf2にコピー
  while(!feof(f1)){
    ch = fgetc(f1);
    if(!feof(f1))
      fputc(ch,f2);
  }
  fclose(f1);
  fclose(f2);

  return 0;
}
