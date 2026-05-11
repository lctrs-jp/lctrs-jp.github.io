#include <stdio.h>
#include <string.h>

void reverse(char trg[],char src[]); /* 文字列を逆順にする関数 */

/* main()関数は変更しない */
int main(void)
{
  int i;
  char test[][2][40] = { /* 入力と正しい出力のペア*/
    {"STRING", "GNIRTS"},
    {"string", "gnirts"},
    {"abc", "cba"},
    {"a", "a"},
    {"bb", "bb"},
    {"level","level"},
    {"akasaka","akasaka"},
    {"", ""},
    {"***end***", ""}  /* テストの終わり．このテストは実行されない */
  };
  char output[40];

  i = 0;
  while (strcmp(test[i][0],"***end***")){
    reverse(output,test[i][0]);
    if (!strcmp(output,test[i][1]))
      printf("テスト%d は成功\n",i+1);
    else{
      printf("テスト%d は失敗!!\n",i+1);
      printf("  作った関数の出力: %s\n",output);
      printf("  期待される結果  : %s\n",test[i][1]);
    }
    i++;
  }

  return 0;
}

/* 以下の関数を変更する */
void reverse(char trg[],char src[])
// src の内容を逆順にしたものが trg に入る
{

  int i,k,a;
  
  i=strlen(src);
  if(i>=2)  
    {      
    for(k=0;k<i;k++)
         trg[k]=src[i-k-1];
    trg[i]='\0';
    }  
  else if(i==1)
    {
    for(a=0;a<i;a++)   
         trg[a]=src[a];
    trg[1]='\0';    
}
 else if(i==0)
   {
     trg[0]='\0';
   }
  return;
}
