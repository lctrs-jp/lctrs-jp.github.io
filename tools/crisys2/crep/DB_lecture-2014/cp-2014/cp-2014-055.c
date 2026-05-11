#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
 FILE *fp1,*fp2;
 char ch;

 if(argc!=3){
   printf("コマンドライン引数が3つではありません。\n");
   return 0;
 }
 
 /*コピー元のファイルを開く*/
 if((fp1=fopen(argv[1],"rb"))==NULL){
   printf("コピー元のファイルが開けない、または、存在しません。\n");
     exit(1);
 }
 /*コピー先のファイルの有無*/
 if((fp2=fopen(argv[2],"rb"))!=NULL){
   printf("コピー先のファイルが既に存在します。\n");
   exit(1);
 }
 /*コピー先のファイルを開く*/
 if((fp2=fopen(argv[2],"wb"))==NULL){
   printf("コピー先のファイルが開けない、または、存在しません。\n");
   exit(1);
 }
 /*ファイルをコピーする*/
 while(!feof(fp1)){
   ch=fgetc(fp1);
   if(ferror(fp1)){
     printf("コピー元のファイルの読み込みエラー\n");
     exit(1);
   }
   if(!feof(fp1))
     fputc(ch,fp2);
   if(ferror(fp2)){
     printf("コピー先のファイルの書き込みエラー\n");
     exit(1);
   }
 }
 
 if(fclose(fp1)==EOF){
   printf("コピー元のファイルを閉じるときのエラー\n");
   exit(1);
 }

 if(fclose(fp2)==EOF){
   printf("コピー先のファイルを閉じるときのエラー\n");
   exit(1);
 }

 return 0;
}
 
