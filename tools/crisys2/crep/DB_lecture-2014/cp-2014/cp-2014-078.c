#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  FILE *fp1,*fp2;
  char str[100],*p,ch;

  /* 引数が3以外の時は処理しない */
  if (argc != 3)
    return 0;

  /* コピー元のファイルを開く(読み込み) */
  if((fp1 = fopen(argv[1],"r+")) == NULL){
    printf("コピー元のファイルが存在しません。\n");
    exit(1);
  }

  /* コピー先のファイルが存在しているか調べる */
  if((fp2 = fopen(argv[2],"r")) != NULL){
    printf("コピー先のファイルが既に存在しています。\n");
    fclose(fp2);
    exit(1);
  }


  /* コピー先のファイルを開く(書き込み) */
  if((fp2 = fopen(argv[2],"a+")) == NULL){
    printf("Can't open file\n");
    exit(1);
  }

  /* コピー内容をstrに書き込む */
  for(i = 0;;i++){
       if((ch = fgetc(fp1)) == EOF)
      break;
    str[i] = ch;
  }

  /* strをコピー先のファイルに書き込む */
  p = str;
  while (*p) {
    if(fputc(*p, fp2) == EOF){
      printf("Error: output\n");
      exit(1);
    }
    p++;
  }

  fclose(fp2);
  fclose(fp1);

  return 0;
}
