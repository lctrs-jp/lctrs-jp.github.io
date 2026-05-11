//11月6日課題２
//入力された文字列を空白で分割しその数を返す関数を作成
//分割した文字列のポインタも作成
//きれいに書くのが難しい
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
  int i, j, num = 0;	//numは何個に分割されたかを保持する変数
  int len = strlen(buf);

  //先頭のスペースは考えない
  for (i = 0; i < len; i++){
    if (buf[i] != ' '){
      out[0] = &buf[i];
      num++;
      break;
    }
  }

  //スペース以外の文字がヌル文字なら0を返す
  if (*out[0] == '\0'){
    return 0;
  }

  //スペース　＋　スペースやヌル文字以外の文字を区切りとする
  for (; i < len; i++){
    if (buf[i] == ' ' && buf[i+1] != ' ' && buf[i+1] != '\0'){
      out[num] = &buf[i+1];
      num++;
    }
  }

  //*out[]の最初のスペースをヌル文字に置き換える
  for (i = 0; i < num; i++){
    for (j = 0; j < strlen(out[i]); j++){
      if (*(out[i] + j) == ' '){
	*(out[i] + j) = '\0';
	break;
      }
    }
  }

  return num;
}
