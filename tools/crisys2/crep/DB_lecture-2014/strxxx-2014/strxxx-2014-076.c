#include <stdio.h>
#include <string.h>

int mystrlen(char p[]);
void mystrcat(char q1[], char q2[]), mystrcpy(char r1[], char r2[]);

int main(void)
{
  char str1[80], str2[80];
  int i;

  printf("1つめの文字列を入力してください:");
  fgets(str1, 80, stdin);
  printf("2つめの文字列を入力してください:");
  fgets(str2, 80, stdin);

  /* 文字列の長さを確認する */
  printf("%sは %d 文字の長さです\n", str1, mystrlen(str1));
  printf("%sは %d 文字の長さです\n", str2, mystrlen(str2));

  /* 文字列を比較する */
  i = strcmp(str1, str2);
  if(!i)
    printf("文字列は等しい\n");
  else
    if(i < 0)
      printf("%sは%sより小さい\n", str1, str2);
    else
      printf("%sは%sより大きい\n", str1, str2);

  /* 十分なスペースがあれば、str2をstr1の最後に連結する */
  if((mystrlen(str1) + mystrlen(str2)) < 80){
    mystrcat(str1, str2);
    printf("2つめを1つめに連結させると %s\n", str1);
  }

  /* str2をstr1にコピーする */
  mystrcpy(str1, str2);
  printf("2つめを1つめにコピーすると str1:%s, str2:%s\n", str1, str2);

  return 0;
}

int mystrlen(char p[])
{
  int j, len;

  for(j = 0; p[j] != 0; j++){
    len = j;
  }

  return len;
}

void mystrcat(char q1[], char q2[])
{
  int l, m;

  l = mystrlen(q1);
  for(m = 0; q2[m] != 0; m++)
    q1[l + m] = q2[m];
}

void mystrcpy(char r1[], char r2[])
{
  int n;

  for(n = 0; n < 80; n++)
    r1[n] = r2[n];
}