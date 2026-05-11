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

int split(char buf[], char *out[])
{
  int m, n, count;

  count = 0; // countの初期化

  for(m=0; buf[m]!='\0';)
    {
      for(n=m; buf[n]==' '; n++); // 先頭の文字を探す

      if(buf[n]!='\0'){ // ヌル文字でないならout[]に代入しcountを１増やす
	 out[count] = &buf[n];
	 count++; 
      }

      if(buf[n]=='\0') // ヌル文字なら終わり
	return count;

      for(; buf[n]!=' ' && buf[n]!='\0'; n++); // 次のスペースorヌル文字を探す

      if(buf[n]=='\0') // ヌル文字なら終わり      
	return count;

      if(buf[n]!='\0'){ // スペースならヌル文字にする
	buf[n] = '\0';
	m = n + 1; // mを更新し先頭の文字探しへ戻る
      }
    }
  return count;
}  
