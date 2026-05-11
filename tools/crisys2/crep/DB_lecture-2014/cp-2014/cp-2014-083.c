#include <stdio.h>

int main(void)
{
  char str[80];
  char ch,*p;
  FILE *fp1,*fp2;
  //FILE1を開いて読み込み
  if((fp1 = fopen("sourse.txt","r")) == NULL){
    printf ("ファイルを開くことができません\n");
      exit(1);
  }
  for(;;){
    if((ch = fgetc(fp1)) == EOF)
      break;
    putchar(ch);
}
  fclose(fp1);
  //FILE2を開いてそれに書き込み
 if((fp2 = fopen("dest.txt","w")) == NULL){
   printf ("ファイルを開くことができません\n");
      exit(1);
  }
 p = str;
 while(*p){
   if(fputc(*p,fp2) == EOF){
     printf("error: output\n");
     exit(1);}
  p++;
}
  fclose(fp2);
  return 0;
}
