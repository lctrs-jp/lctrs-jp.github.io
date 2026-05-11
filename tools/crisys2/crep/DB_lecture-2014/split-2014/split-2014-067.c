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
  int j, k, l, m, n, o, ren;
  char via[10];
/* 返り値の算出を行う */
  if(buf[0] == ' ' || buf[0] == '\0' ) 
/* 最初の文字が空白およびヌル文字の場合は返り値の初期値を0とする */
    ren = 0;  
  else
/* それ以外の場合は初期値を1とする */
    ren = 1;
  for(k = 0; buf[k]; k++)
  if(buf[k] == ' ' && buf[k + 1] != ' ' && buf[k + 1] != '\0' )
/* k番目の文字が空白かつ次の文字が空白、ヌル文字でない場合返り値を1つ増やす */
     ren++; 

/* outを導出する */
  strcpy(via,buf); 
/* 最初の文字が空白およびヌル文字でない場合out[0]のアドレスをbuf[0]とする */
  if(buf[0] != ' ' && buf[0] != '\0'){
    out[0] = &buf[0];
/* 下のループのoutの初期値を1として始める */
  m = 1;
  }
  else  
/* 最初が空白の時、初期値を0として始める(ヌル文字の場合ループせず終了する) */
  m = 0;

  for(l = 0; buf[l] != '\0'; l++){
 
    if(buf[l] != ' ' && buf[l - 1] == ' '){
   out[m] = &buf[l];
   m++;
  }
  }
  for(n = 0; buf[n]; n++)
    if(buf[n] == ' ')
/* 空白部分をヌル文字に変更する (ポインタ以前のヌル文字は無視される) */
      buf[n] = '\0';
   return ren;
}
