#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char cp;


  /* コマンドラインに指定された引数の数が正しいかどうか調べる */
  if(argc != 3)
    {
      printf("./<プログラム名> <コピー元> <コピー先>の順で入力してください\n");
      exit(1);
    }

  /* コピー元のファイルを開く */
  if(( from = fopen(argv[1] , "rb")) == NULL)
    {
      printf("コピー元のファイルを開くことができませんでした \nファイルが存在しない可能性があります\n");
      exit(1);
    }

  /* コピー先ファイルが存在している場合 */
  if((to = fopen(argv[2], "rb")) != NULL)
    {
      printf("コピー先のファイルが既に存在しています\n");
      exit(1);
    }

  /* コピー先ファイルが存在しない場合はファイルを新しく作成する */
  if(( to = fopen(argv[2] , "wb")) == NULL)
    {
      printf("コピー先のファイルを開くことができませんでした\n");
      exit(1);
    }
  

  /*　ファイルをコピーする */ 
 while(!feof(from))
    { 
      cp = fgetc(from);
      if(ferror(from))
	{
	  printf("コピー元ファイルの読み込みエラー\n");
	  exit(1);
	}
      if(!feof(from))
	fputc(cp, to);
      if(ferror(to))
	{
	  printf("コピー先ファイルの書き込みエラー\n");
	  exit(1);
	}
    }

 /* ファイルを閉じる */
 if(fclose(from) == EOF)
   {
     printf("コピー元ファイルを閉じる際にエラーが発生しました\n");
     exit(1);
   }

 if(fclose(to) == EOF)
   {
     printf("コピー先ファイルを閉じる際にエラーが発生しました\n");
     exit(1);
   }

  return 0;
}
