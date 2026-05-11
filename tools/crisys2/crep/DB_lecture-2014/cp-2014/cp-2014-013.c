#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char ch, *p;

  if(argc == 3){

    if((fp1 = fopen(argv[1], "rb")) == NULL){
      printf("コピー元のファイルが存在しません。\n");
      exit(1);
	}

    if((fp2 = fopen(argv[2], "wb")) == NULL){
      printf("コピー先のファイルがすでに存在しています。\n");
      exit(1);
        }

    while((ch = fgetc(fp1)) != EOF){
      fputc(ch, fp2);
        }
    fclose(fp1);
    fclose(fp2);
  }

    return 0;
}  
