#include <stdio.h> /* 課題9　ファイルをコピーする */
#include <stdlib.h>


int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;

  /* コマンドライン引数の数が正しいかどうかを確認する */
  if(argc !=3){
    printf("実行できません。\n");
    exit(1);
  }

  /* コピー元のファイルを開く */
  if((from = fopen(argv[1], "r")) == NULL){
    printf("%sは存在しません。\n", argv[1]);
    exit(1);
  }

  /* コピー先のファイルを作成 */
  if((to = fopen(argv[2], "r")) != NULL){
    printf("%sは既に存在しています。\n", argv[2]);
      exit(1);
  }
  else{
    to = fopen(argv[2], "w");
    printf("%sを新規作成しました。\n", argv[2]);
  }

  /* ファイルをコピーする */
  while((ch = fgetc(from)) != EOF){
    fputc(ch, to);
    }
  printf("ファイルをコピーしました。\n");


  fclose(from);
  fclose(to);

  return 0;
}
