#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
  FILE *p,*q,*r;
  char a,c1,c2;
  
  if((p=fopen(argv[1],"r"))== NULL){/*コピーするファイルが存在するか確認*/
    printf("コピー元のファイルを開けません\n");
    exit(1);
  }
  if((r=fopen(argv[2],"r"))!= NULL){/*同じ名前のファイルが存在していないかを確認する(読み込むからrで開く)*/
    printf("同名のファイルが既に存在します\n");
    exit(1);
  }
  
  q=fopen(argv[2],"w");/*書き込みのためにファイルを開く*/ 

  /*以下でファイルをコピーしている*/
while(!feof(p)){
    c1=fgetc(p);
    if(!feof(p))
      fputc(c1,q);
  }
/*コピー終了*/

 fclose(p);/*ファイルを両方閉じる*/
 fclose(q);
 fclose(r);

return 0;
}


