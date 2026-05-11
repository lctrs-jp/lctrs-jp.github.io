#include <stdio.h>
#include <string.h>

int mystrlen(char trg[]);
int mystrcmp(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
void mystrcpy(char trg[], char src[]);


int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください：");
  gets(str1);
  printf("第二の文字列を入力してください：");
  gets(str2);

  /* 文字列の長さを確認する */
  printf("%s は %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%s は %d 文字の長さです\n", str2, mystrlen(str2));

  /* 文字列を比較する */
  i = mystrcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if (i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if ((mystrlen(str1) + mystrlen(str2)) < 80){
      mystrcat(str1, str2);
      printf("%s\n", str1);
    }

    /* str2をstr1にコピーする */
    mystrcpy(str1, str2);
    printf("%s %s\n", str1, str2);

    

    return 0;
}

int mystrlen(char trg[])
{
  int i = 0;
  while (trg[i] != '\0'){
    i++;
  }
  return i;

}

int mystrcmp(char trg[], char src[])
{
  int i = 0,t = 1;
  while (trg[i] ==src[i]){  //文字が一致している間繰り返す
    if (trg[i] == '\0'){
      if (src[i] == '\0'){
	t = 0;
	break;              //どちらも終端に達したらループを抜ける
      }
    }
    i++;  
  }

  // t == 0 なら一致しているとする
  // t == 1 なら一致していないとしてどちらが辞書的に大きいか（後に来るか）を調べる 
  //一致していない最初の文字を比べる
  if (t == 1){  
    if (trg[i] < src[i]){
      t = -1;
    }
    if (trg[i] > src[i]){
      t = 1;
    }
  }
  

  return t;
}

void mystrcat(char trg[], char src[])
{
  int i = 0,t = 0;
  while (trg[i] != '\0'){
    i++;
  }
  while (src[t] != '\0'){
    trg[i] = src[t];
    i++;
    t++;
  }
  trg[i] ='\0';

}

void mystrcpy(char trg[], char src[])
{
  int i = 0;
  while (src[i] != '\0'){
    trg[i] = src[i];
    i++;
  }
  trg[i] = '\0';


}
