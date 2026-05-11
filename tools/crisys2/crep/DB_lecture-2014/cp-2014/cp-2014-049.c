#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{FILE *fp1,*fp2;
  char ch,*ch2;
  int i,n=0;
if((fp1 = fopen(argv[1],"r"))==NULL){
    printf("コピー元のファイルが存在しません\n");
    exit(1);}
 if((fp2=fopen(argv[2],"r"))!=NULL)
   {
     printf("コピー先にファイルが存在します\n");
     exit(1);}

if((fp2=fopen(argv[2],"w"))==NULL)
{
    printf("コピー先のファイルがオープンできません\n");
      exit(1);}

 for(;;){  
   if(ch==EOF)
     break;
 ch=fgetc(fp1);
   ch2[n]=ch;
   n++;
   }
   ch2[n-1]='\0';
  while(*ch2)
   {if(fputc(*ch2,fp2)==EOF){
       printf("コピー失敗\n");
       exit(1);}
     ch2++;}
 fclose(fp1);
 fclose(fp2);
return 0;}

