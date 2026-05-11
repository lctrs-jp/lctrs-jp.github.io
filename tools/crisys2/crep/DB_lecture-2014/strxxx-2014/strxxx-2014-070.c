#include <stdio.h>
#include <string.h>


void mystrcpy(char trg[80], char src[80]);
void mystrcat(char trg[80], char src[80]);
int mystrlen(char trg[80]);

int main(void)

{
  char str1[80], str2[80];
  int i;

  printf("第1の文字列を入力してください: ");
  fgets(str1, 80, stdin);
  printf("第2の文字列を入力してください: ");
  fgets(str2, 80, stdin);
  


  /*文字列の長さを確認する*/
  printf("%s は %d　文字の長さです\n", str1, (mystrlen(str1) -1));
  printf("%s は %d　文字の長さです\n", str2, (mystrlen(str2) -1));

  /*文字列を比較する*/
  i = strcmp(str1, str2);
  if (!i)
    printf("文字列は等しい\n");
  else if(i < 0)
    printf("%s は %s より小さい\n", str1, str2);
  else
    printf("%s は %s より大きい\n", str1, str2);

  /*十分なスペースがあれば、str2をstr1の最後に連結する*/
  if((mystrlen(str1) + strlen(str2)) < 80){
    mystrcat(str1, str2);
    printf("%s \n", str1);
  }


  /*strを2str1にコピーする*/     
  mystrcpy(str1, str2);
  printf("%s%s\n", str1, str2);
  
  return 0;
}

    
void mystrcpy(char trg[], char src[])
{
  int A = 0;
  while (src[A] !=  '\0'){
    trg[A] = src[A];
    A++;
} 
  trg[A] = '\0';
    }


void mystrcat(char trg[], char src[]){
  int A =0,B=0;
  while(trg[A] !='\0'){
    A++;
  }
  while(src[B] !='\0'){
    trg[A]=src[B];
    A++;
    B++;
      }
  trg[A]='\0';
}

int mystrlen(char trg[])
{
  int A = 0;
  while(trg[A] != '\0')A++;
 return A;
}
