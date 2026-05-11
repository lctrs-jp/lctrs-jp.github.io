#include <stdio.h>
#include <stdlib.h>

int main(int as, char *arg[])
{
  FILE *fp;
  int i = 0;
  char ch, *p, f[100];

  if((fp = fopen(arg[1], "r")) == NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);
  }

  for(;;){
    if((ch = fgetc(fp)) == EOF)
      break;
    f[i] = ch;
    i++;   
  }

  fclose(fp);
   
  if((fp = fopen(arg[2], "w+")) == NULL){
    printf("コピー先ファイルの作成に失敗しました\n");
    exit(1);
  }
  fclose(fp);

  if((fp = fopen(arg[2], "w")) == NULL){
    printf("コピー先のファイルが開けませんでした\n");
    exit(1);
  }

  p = f;
  while(*p){
    if(fputc(*p, fp) == EOF){
      printf("コピーに失敗しました\n");
      exit(1);
    }
    p++;
  }

  fclose(fp);

  return 0;
}  
    
