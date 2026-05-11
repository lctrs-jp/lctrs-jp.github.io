#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
  FILE *sorce,*cop,*copy;
  char p,q;


  if((sorce=fopen(argv[1],"rb"))==NULL){//ヌルになるのは読み取りミスか、ファイルがないかなのだがそれを分割できなかった。
    printf("error(コピー元のファイルがありません。)\n");
    exit(1);
}


  if((cop=fopen(argv[2],"rb"))!=NULL){
    printf("error(コピー先のファイルが存在しています。)\n");
    exit(1);
      }

  
  if((copy=fopen(argv[2],"wd"))==NULL){
    printf("error(コピー先のファイルが開けません。)\n");
    exit(1);
  }


  while(1){
    p=fgetc(sorce);
    if(p==EOF)//whileの中の条件文を!feofにすると末尾がおかしくなっていたので修正。
      break;


    //一応エラー対策
    if(ferror(sorce)){
      printf("error(ファイルが読み取れませんでした。)\n");
      exit(1);
      }
    else{
      fputc(p,copy);
      if(ferror(copy)){
	printf("error(ファイルが書き込めませんでした。)\n");
	exit(1);	
    }}
}


  if(fclose(sorce)==EOF){
    printf("error(コピー元のファイルが閉じられません。)\n");
    exit(1);
	 }


  if(fclose(copy)==EOF){
    printf("error(コピー先のファイルが閉じられません。)\n");
    exit(1);
  }


  return 0;
}
