#include <stdio.h>
#include <stdlib.h>

void error(int check);  //値に対応したエラーメッセージ

int main(int argc,char *argv[])
{
  FILE *fp1;//コピー元ファイルのストリーム
  FILE *fp2;//コピー先ファイルのストリーム
  char ch;//コピーの際に経由する変数
  
  if(argc != 3)
    error(0);
  else
    {
      //コピー元が空だったらエラー表示
      fp1=fopen(argv[1],"r");
      if(fp1 == NULL)
	{
	  error(1);
	  exit(1);
	}

      //コピー先が存在したらエラー表示
      fp2=fopen(argv[2],"w");
      if(fgetc(fp2) != EOF)
	{
	  error(2);
	  exit(1);
	}

      //ファイルを一文字ずつコピー
      while((ch=fgetc(fp1)) != EOF)
	fputc(ch,fp2);
    }
  return 0;
}

void error(int check)
{
  switch(check)
    {
    case 0:
      printf("ファイルの数は二つにしてください。");
      break;
    case 1:
      printf("コピー元のファイルが空です。");
      break;
    case 2:
      printf("コピー先のファイルが存在します。");
      break;
    }
}
