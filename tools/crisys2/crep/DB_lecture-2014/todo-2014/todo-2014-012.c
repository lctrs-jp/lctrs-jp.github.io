#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[])
{ 
  FILE *mytodo; 
  int x,y,z;
  int t=0;
  char ch[60];
  char buf[60];
  char *line[256];
  char la[256];
  char lb[256];
  char lc[256];
  char ld[256];
  char le[256];
  char lf[256];

  if(argc!=3){
    printf("使い方：%s ＜日付＞＜ファイル名＞\n",argv[0]);
    printf("（例）%s　2014/12/10　mytodo.txt\n",argv[0]);
    exit(1);
  }

  *ch = argv[1];
  sscanf(ch,"%d/%d/%d",&x,&y,&z);

  if((mytodo = fopen(argv[2], "r")) == NULL){
    printf("%s というファイルは存在しません\n",argv[2]);
    exit(1);
  }
 
  fgets(buf,256,mytodo);

  while (!feof(mytodo)) {
    if(ferror(mytodo)){
      printf("ファイルを読み取る際にエラーが発生しました\n");
      exit(1);
      for(int i=0　; i<256;i++){
	if(buf[i] == '\n'){
	  buf[i] = '\0';
	    }
	else if(i==0　|| buf[i-1]=='\0'){
	  line[t] = buf +i;
	}
      }
    }
  }
  for(t=0; t<256 ;t++){
    sscanf(*line, %d/%d/%d/ %d:%d %s,&la[t],&lb[t],&lc[t],&ld[t],&le[t],&lf[t]);

      while(t<256){
	if(la[t]<x){ t++; break;}
	else if(lb[t]<y){ t++; break;}
	else if(lc[t]<z){ t++; break;}
	else {printf("%4d/%2d/%2d %2d:%.2d %s\n",la[t],lb[t],lc[t],ld[t],le[t],lf[t]);
	  t++;}
}
  
  if(fclose(mytodo) == EOF) {
    printf("ファイルを閉じる際にエラーが発生しました");
    exit(1);
  }

  return 0;

}
