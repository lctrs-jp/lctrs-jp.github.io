#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from,*to;
  char ch;


  if(argc!=3)
    {
      printf("使用法：<プログラム名> <コピー元> <コピー先>");
      exit(1);
    }


  if ((from=fopen(argv[1],"rb"))==NULL)
    {
      printf("コピー元ファイルを開くことができません");
      exit(1);
    }

  if ((to=fopen(argv[2],"rb"))!=NULL)
    {
      printf("コピー先ファイルを開くことができません");
      exit(1);
    }

  if ((to=fopen(argv[2],"wb"))==NULL)
    {
      printf("コピー先ファイルを開くことができません");
      exit(1);
    }





  while (!feof(from))
    {
      ch=fgetc(from);
      if(ch=='\0')
	{
	  printf("中身がないよ");
	  break;
	}

      if(ferror(from))
	{
	  printf("コピー元ファイルの読み込みエラー");
	  exit(1);
	}
      if (!feof(from))
	fputc(ch,to);
      if(ferror(to))
	{
	  printf("コピー先ファイルの読み込みエラー");
	  exit(1);
	}
    }

  if (fclose(from)==EOF)
    {
      printf("コピー元ファイルの書き込みエラー");
      exit(1);
    }
  if (fclose(to)==EOF)
    {
      printf("コピー先ファイルを閉じる際のエラー");
      exit(1);
    }

  return 0;
}
