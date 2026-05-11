#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *from, *to;
  char ch;
  /*コピー元のファイルを開く*/
  if ((from = fopen(argv[1], "r")) == NULL){
    printf("コピー元ファイルがありません\n");
    exit(1);
  }
 
  /*コピー先ファイルを作成する*/
  if ((to = fopen(argv[2], "r")) != NULL){
    printf("コピー先ファイル既に存在しています\n");
      exit(1);
  }  
  if ((to = fopen(argv[2], "w")) == NULL){
      exit(1);
}   
  
  /*ファイルをコピーする*/
  for(;;){ /*chにfgetsを代入する*/
    ch = fgetc(from);
    if (ch == EOF) 
      break;
     fputc(ch, to);
    }
    fclose(from);
    fclose(to);

    return 0;
    }
