//11月27日課題
//自作のcp
//コピー元のファイルが存在しない場合と
//コピー先のファイルが存在する場合中止する
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch;

  if (argc != 3){
    printf("引数は２つです\n");
    exit(1);
  }
  //読み込みでコピー元を開く
  if ((fp1 = fopen(argv[1], "r")) == NULL){
    printf("Can't open %s\n", argv[1]);
    exit(1);
  }
  //書き込みでコピー先を開く
  //コピー先が存在していたら中止
  if ((fp2 = fopen(argv[2], "r")) != NULL){
    printf("%s already exists\n", argv[2]);
    exit(1);
  }else{
    fp2 = fopen(argv[2], "w");
  }
  //先頭から１文字読んで書き込む　を繰り返す
  for (;;){
    if ((ch = fgetc(fp1)) == EOF){
      break;
    }
    fputc(ch, fp2);
  }
  fclose(fp1);
  fclose(fp2);

  return 0;
}
