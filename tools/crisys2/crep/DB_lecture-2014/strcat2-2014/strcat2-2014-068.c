#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mystrcat(char *s1, char *s2); // s1 = s1 + s2

/* main()関数は変更しない */
int main(void)
{
  int i;
  char out[80];
  char test[][10][40] = { /* 正解と入力のペア*/
    {"abcdef", "abc","def"},
    {"abc", "", "abc"},
    {"abc", "abc", ""},
    {"", "", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  
  for (i = 0;strcmp(test[i][0],"***end***");i++){
    strcpy(out,test[i][1]);
    mystrcat(out,test[i][2]);
    if (strcmp(out,test[i][0])==0){
      printf("テスト%d は成功\n",i+1);
    }
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の結果: %s\n",out);
      printf("  期待される結果  : %s\n",test[i][0]);
    }
  }

  return 0;
}

void mystrcat(char *s1, char *s2)
{
  char a, len1 , len2;

  //s1とs2の長さを調べる
  for(len1 = 0; *(len1 + s1) != '\0'; len1++);
  for(len2 = 0; *(len2 + s2) != '\0'; len2++);
  
  //s1の末尾からs2をコピーする
  for(a = 0; a <= len2 +1; a++)   
    *(s1 + len1 + a) = *(s2 + a);   

  return;
}
