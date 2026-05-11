#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{

  FILE *fp1;
  FILE *fp2;
  char ch;



  /* 判定*/
  if((fp1 = fopen(argv[1], "rb")) == NULL)   
    {
      printf("ファイルのオープンに失敗しました\n");
      exit(1);
    }

  if((fp2 = fopen(argv[2], "rb")) != NULL)
    {
      printf("%sはすでに作成されています。\n", argv[2]);
      exit(1);
    } 

  fp2 = fopen(argv[2], "wb");

    /* 読み書き込み */
  while(!feof(fp1))
    {
      ch = fgetc(fp1);
      if(ferror(fp1))
	{
	  printf("読み込みに失敗しました。\n");
	  exit(1);
	}
 
      if(!feof(fp1))
	if(fputc(ch, fp2) == EOF)
	  {
	    printf("書き込みに失敗しました。\n");
	    exit(1);
	  }
    }

  /* ファイルを閉じる */
  if(fclose(fp1) == EOF)
    {
      printf("%sを閉じる際にエラーが発生しました。",argv[1]);
      exit(1);
    }


  if(fclose(fp2) == EOF)
    {
      printf("%sを閉じる際にエラーが発生しました。",argv[2]);
      exit(1);
    }


  printf("コピーは正常に実行されました。\n");


}
