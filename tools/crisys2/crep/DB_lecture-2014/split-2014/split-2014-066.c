#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(char buf[], char *out[]); // 文字列を空白で分割する関数

/* main()関数は変更しない */
int main(void)
{
  int i,j,size,ans,flag;
  char *out[80];
  char test[][10][40] = { /* 入力と正しい出力のペア*/
    {"ab cd ef", "3", "ab","cd","ef"},
    {"ab   cd", "2", "ab","cd"}, // 空白が連続した場合，1個の空白として扱う
    {"  ab cd", "2", "ab","cd"}, // 先頭に空白がある場合，その空白を無視
    {"ab cd  ", "2", "ab","cd"}, // 末尾の空白も無視する
    {" ab cd ", "2", "ab","cd"}, 
    {"string", "1", "string"},
    {"AB + CD = 5", "5", "AB","+","CD","=","5"},
    {"   ", "0", ""},            // 空白しか無い場合は 0 を返す
    {"", "0", ""},               // ヌル文字列の場合も 0 を返す
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  
  for (i = 0;strcmp(test[i][0],"***end***");i++){
    size = split(test[i][0],out);
    ans = atoi(test[i][1]);
    if (size == ans){
      flag = 1;
      for (j = 0; j < size;j++){
	if (strcmp(test[i][j+2],out[j])!=0){
	  flag = 0;
	  printf("テスト%d は失敗!!\n",i+1);
	  printf("  作った関数の out[%d]: %s\n",j,out[j]);
	  printf("  期待される結果      : %s\n",test[i][j+2]);
	  break;
	}
      }
      if (flag)
	printf("テスト%d は成功\n",i+1);
    }
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の返り値: %d\n",size);
      printf("  期待される結果    : %d\n",ans);
    }
  }

  return 0;
}

int split(char buf[], char *out[]){
  
  char *p;
  int a, i, j;
  a=0; i=0; j=0;
  p = buf;
  if(buf[0]==' ')
   for(i=0; i<strlen(buf); i++)
     buf[i]=buf[i+1];
  for(i=0; i<strlen(buf); i++){
    if(buf[i]==' ' && buf[i+1]==' '){
      for(j=i; j<strlen(buf); j++)
      buf[j]=buf[j+1];
    }
    if(buf[strlen(buf)]==' ')
      buf[strlen(buf)]='\0';
  }

  j=0; i=0;
    while(buf[i]){
    if(buf[i]==' ' && buf[i+1]!=' ' && buf[i+1]!='\0'){
      buf[i]='\0';
      out[j]=&buf[i];
      i++;
      j++;  
      a=a+1;
       }
    else
      i++;     
  }  
    for(i=0; i<strlen(buf); i++){ 
    if(buf[i]==' ')
      a=-1;    
    }
    if(buf[0]=='\0')
      a=-1;      
  
      
          
  return a+1;
 
}
