#include <stdio.h>

void mystrcpy(char trg[], char src[]);
void mystrcat(char trg[], char src[]);
int mystrlen(char trg[]);

int main(void)
{
  char trg[80], src[80];
  int i;

  printf("第一の文字列を入力してください \n");
  fgets(trg, 80, stdin);
  printf("第二の文字列を入力してください \n");
  fgets(src, 80, stdin);

  //文字列を比較する
  i = strcmp(trg, src);
  if (!i)
    printf("文字列は等しい\n");
  else if ( i < 0)
    printf("%s は %sより小さい\n", trg, src);
  else
    printf("%s は %sより大きい\n", trg, src);

  //文字列の長さを確認する
  printf("%s は %d 文字の長さです\n", trg, mystrlen(trg));
  printf("%s は %d 文字の長さです\n", src, mystrlen(src));

  //十分なスペースがあれば、文字列を連結する
  if ((mystrlen(trg) + mystrlen(src)) < 80) {
      mystrcat(trg, src);
      printf("%s\n", trg);
  }

  //srcをtrgにコピーする
  mystrcpy(trg, src);
  printf("%s %s\n", trg, src);

  return 0;
}

//strcpy()と同じ処理をする関数
void mystrcpy(char trg[], char src[])
{
  int a;
  for( a = 0; a < 80; a++)
    trg[a] = src[a];
}
//strcat()と同じ処理をする関数
void mystrcat(char trg[], char src[])
{
  int b = 0, c = 0;
  for(; trg[b] != 0 ;)
    b++;
  for(; c <= mystrlen(src); ) {
    trg[b - 1] = src[c];
    b++;
    c++;
  }

}

//strlen()と同じ処理をする関数
int mystrlen(char trg[])
{
  int d = 0;
  for(; trg[d] != 0 ;)
    d++;
  return d - 1;
}