#include<string.h>
#include<stdio.h>

char mystrcpy(char trg1[],char src1[]);
char mystrcat(char trg2[],char src2[]);
int mystrlen(char ch[]);
int mystrcmp(char trg3[],char src3[]);

int main(void)

{
  char str1[80], str2[80];
  int i;

  printf("第一の文字列を入力してください(８０文字未満): ");
  fgets(str1,80,stdin);
  printf("第二の文字列を入力してください(８０文字未満): ");
  fgets(str2,80,stdin);

  //文字列の長さを確認する。
  printf("%s は %d 文字の長さです\n", str1, strlen(str1));
  printf("%s は %d 文字の長さです\n", str2, strlen(str2));

  //文字列を比較する。
  i = mystrcmp(str1, str2);
  if (i > 0)
    printf("%sは%sより大きい\n",str1,str2);
  else if(i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("文字列は等しい\n");

  //十分なスペースがあれば、str2をstr1の最後に連結する。
  if ((mystrlen(str1) + mystrlen(str2)) < 80 ) {
    mystrcat(str1, str2);
    printf("%s\n", str1);
  }

  //str2をstr1にコピーする。
  mystrcpy(str1,str2);
  printf("%s %s\n", str1, str2);

  return 0;
}

//コピーのユーザー定義関数
char mystrcpy(char trg1[],char src1[])
{
  int i = 0;
  for (i = 0; trg1[i]!='\0'; i++){
    trg1[i] = src1[i];
  }
  return trg1[i];
}
//連結のユーザー定義関数
char mystrcat(char trg2[],char src2[])
{
  int i,j;
  i = 0;
  j = 0;
  while (trg2[i]!='\0'){
    i++;
  }
  do {
    trg2[i]=src2[j];
    i++;
    j++;
  }while (trg2[j]!='\0');
  return trg2[i];
}
//文字列の長さをはかるユーザー定義関数
int mystrlen(char ch[])
{
  int i;
  i = 0;
  do{
    i++;
  } while(ch[i]!='\0');
  return i - 1;
}
//比較のユーザー定義関数
int mystrcmp(char trg3[],char src3[])
{
  int i,j;
  i = 0;
  do {
    if (trg3[i] < src3[i]){
      j = -1;
      break;
    }
    else
      j = 0;
    i++;
  } while(trg3[i] = src3[i]);

  return j;
}
