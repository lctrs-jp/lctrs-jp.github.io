
#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char *argv[]) {
  if (argc=!3) {
    printf("引数個数不適です\n");
    exit(1);
  }

  FILE *fp1;
  FILE *fp2;
  char ch;

  //コピー元読み込み
  if ((fp1=fopen(argv[1],"r"))==NULL) {
    printf("コピー元ファイルの読み込みに失敗しました\n");
    exit(1);
  }

  ///コピー先ファイルが既に存在するならば終了する
  if ((fp2=fopen(argv[2],"r"))!=NULL){
    printf("コピー先ファイルが既に存在します\n");
    fclose(fp2);
    exit(1);
  }

  //コピー先読み込み
  if ((fp2=fopen(argv[2],"w+"))==NULL) {
    printf("コピー先ファイルの作成に失敗しました\n");
    exit(1);
  }

  while(1) {
    if ((ch=fgetc(fp1))==EOF) {//chに文字を出力しつつEOF判定
      //EOFなら読み込み・書き込み終了する。
	break;
    }
    if ((fputc(ch,fp2))==EOF) {//chをコピー先へ入力しつつEOF判定   
      //EOFなら入力に失敗、強制終了。
      //中途半端に作成されたコピー先ファイルも破棄する。
      printf("コピーに失敗しました。\n");
      remove(argv[2]);
      exit(1);
    }
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
