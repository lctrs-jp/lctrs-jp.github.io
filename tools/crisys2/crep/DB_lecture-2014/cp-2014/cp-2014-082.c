#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char str;

  /* コピー元のファイルを開く */
  if((fp1 = fopen(argv[1], "r")) == NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);
  }
  /* コピー先のファイルが既にあったら終了 */
  if((fp2 = fopen(argv[2], "r")) != NULL){
    printf("コピー先のファイルが既に存在します\n");
    exit(1);
  }
  /* コピー先のファイルを作成・開く */
  if((fp2 = fopen(argv[2], "w")) == NULL){
    printf("コピー先のファイルを作成できません\n");
    exit(1);
  }

  /* "feof(fp1) = 0"になったらコピー終了 */
  while(!feof(fp1)){
    str = fgetc(fp1);
    if(str != EOF)
      if(fputc(str, fp2) == EOF){
	printf("出力できませんでした\n");
	exit(1);
      }
  }

  /* ストリームを閉じる */
  fclose(fp1);
  fclose(fp2);

  printf("%s を %s にコピーしました\n", argv[1], argv[2]);

  return 0;
}
