#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char text;

  if( argc != 3 ){
    printf(" copy コピー元 コピー先 を入力ください。\n");
    exit(1);
  }

  if( ( fp1 = fopen( argv[1], "r" )) == NULL ){
    printf("コピー元のファイルのオープンに失敗しました。\n");
    exit(1);
  }

  if( ( fp2 = fopen( argv[2], "r" )) != NULL ){
    printf("コピー先のファイルがすでに存在します。\n");
    exit(1);
  }

  fp2 = fopen( argv[2], "w" );
    
  while( !feof(fp1) ){
    text = fgetc( fp1 );
    if( !feof(fp1) )
      fputc( text, fp2 );
  }

  fclose( fp1 );
  fclose( fp2 );

  return 0;
}
