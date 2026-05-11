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
  /*
    先頭空白・二連続空白・最終字空白を無視して、分割を
    行った場合、
    文字列""を分割文字列の一つとして保持してしまう
    したがって、分割結果の文字列が""であれば、
    それを分割文字列として保持しないように
    すればよい。アルゴリズムは以下のようになる。
    指定文字列の先頭から空白" "かどうかを判定する。
    空白を見つけたら、その空白をNULLに置き換えて、
    一つ前に見つけた空白の次の位置もしくは元の文字列開始位置から
    今発見した空白の手前までの文字列について、""である、
    すなわち'\0'であるかを判定し、
    真ならば分割として保持しない。偽ならば分割として保持する。
    また、文字列の最後に存在するNULLを、
    便宜上空白とみなすことにする。
  */

  //ポインタ定義
  char*bufp=buf;//文字列のポインタ
  char*memo=buf;//以前発見した空白のあったアドレス+1を確保しておくためのポインタ

  //変数定義
  int splitN=0;//返り値用
  int breakf=0;//ループを抜けるためのフラグ
  
  do{
    if (*bufp==' ' || *bufp=='\0') {
      if (*bufp=='\0') {
	breakf=1;//文字列末尾なら、ループを抜けるフラグを立てる。
      }
      *bufp='\0';//空白ないしNULLをNULLに
      /*
	分割されて出力される文字列が""であるか、
	すなわちNULLのみであるかどうかの判定により、空白二連続、
	引数文字列の初めが空白、引数文字列の最後が空白である場合を弾く。
      */
      if ((*memo)!='\0') {
	out[splitN]=memo;//分割文字列として保持
	splitN+=1;//分割数を+1
      }
      memo=bufp+1;//次に生成される分割文字列の始まりのポインタを保持
    }
    bufp+=1;
  }while(breakf==0);
  return splitN;
}
